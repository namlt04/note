# Custom lại CButton
Hàm DrawItem


# Hiệu ứng di chuột vào, di chuột ra

Di chuột vào ON_WM_MOUSEMOVE
ghi đè hàm 
afx void OnMouseMove(UINT nFlags, CPoint CPoint)
{

}
- Tạo 1 biến bTracking 
 + bTracking = false, khi mà chưa theo dõi, thì ta gọi TrackMouseEvent để theo dõi hành vi chuột 
 + Nếu như nó đang true, tức là nó chưa ra khỏi vùng theo dõi, không gọi TrackMouseEvent để theo dõi nó nữa

Kiến trúc TRACKMOUSEEVENT : WINDOWAPI để lắng nghe sự kiện chuột ( VD WM_MOUSEHOVER, HOẶC MOUSELEAVE )

typedef struct tagTRACKMOUSEEVENT {
  DWORD cbSize; // kích thước của cấu trúc này
  DWORD dwFlags; // Cở kiểu sự kiện muốn theo dõi (hover, leave)
  HWND  hwndTrack; // handle của cửa sổ, control cần theo dõi 
  DWORD dwHoverTime; // thời gian để tính là hover ( miliseconds)
} TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;


** Thông tin thêm

VD
- ghi đè OnMouseMove(UINT nFlags, CPoint point)
{
    if ( !bTracking)
    {
        // Khởi tạo struct 
        TRACKMOUSEEVENT tme = { sizeof(tme)}
        /*
        Khai báo kích thước của struct này
        cách khai báo này có thể cho WINDOW API biết đang sử dụng struct phiên bảo nào
        */
        tme.dwFlags = TME_LEAVE; 
        tme.hwndTrack = this ;// Control này luôn, trong trường hợp là button 
        tme.dwHoverTime = 1; 
        ::TrackMouseEvent(&tme);  // bắt đầu theo dõi
        gán bTracking = true để không gọi lại ::TrackMouseEvent() thừa thãi 


    }
    // gọi hàm gốc để xử lí những phần còn lại 
    CButton::OnMouseMove(nFlags, point); 
}
// Khai báo OnMouseLeave : xử lí khi chuột ra khỏi control 

LRESULT CCButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
    bTracking = false; 

    return 0 ; // Trong trường hợp không sử dụng lResult
}

