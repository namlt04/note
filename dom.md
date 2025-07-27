# dom : document object modle

cho phép truy cập và thao tác với HTML từ c++ và ngược lại 
IHTMLDocument2
IHTMLElement



IHTMLElement: interface định danh các phần tử của html
+ Mã GUID định danh IHTMLElement : IDD_IHTMLElement
+ IDD_IHTMLElement được định nghĩa trong mshtml.h

Ví dụ Giá trị cụ thể của IDD
DEFINE_GUID(IID_IHTMLElement, 
0x3050f1ff, 0x98b5, 0x11cf, 0xbb, 0x82, 0x0, 0xaa, 0x0, 0xbd, 0xce, 0xb);

Thường được sử dụng khi QueryInterface 

## query interface

một đối tượng COM (component object model) có thể hỗ trợ nhiều interface
interface : tập hợp các hàm thuần ảo
IID : GUID xác định duy nhất 1 interface 
com object đối tượng thực sự cài đặt interface
<Mỗi phần tử trong trang web được ánh xạ 1 comobject>

Ví dụ: 
<table>
<td>
<tr>

tất cả đều là com object
query interface láy interface khác cùng một đối tượng com

IHTMLElement : là interface cơ bản cho mọi phần tử HTML
các hàm chung của IHTMLElement
get_id
put_innerHTML
click 
put_className
==> CHỈ CÓ CÁC CHỨC NĂNG CHUNG NHẤT
( ví dụ , không thêm thêm dòng insertRow)

IHTMLTable :: <table> :: 	insertRow, deleteRow, get_rows()
IHTMLTableRow :: <tr> :: 	insertCell, deleteCell, get_cells()
IHTMLTableCell :: <td> ::colSpan, rowSpan, align,...

#### ERROR
# Trước khi sử dụng ép kiểu, phải đảm bảo con trỏ đó null
Ví dụ
sPRow->insertCell(-1, (IDispatch**)&sPCell.p)

khi sử dụng inserCell, nó yêu cầu con trỏ nhận kết quả đầu ra phải là 1 con trỏ null 
yêu cầu phải .Release() trước khi gán tiếp
 
# OVERRIDE
void OnCreate


# Khai báo event map
BEGIN_DHMTL_EVENT_MAP(ten_file)
    DHTML_EVENT_ONCLICK(id_button, ham_xu_li) // Nhận sự kiện click của button
END_DHTML_EVENT_MAP()

# OLECHAR : kiểu dữ liệu chuẩn trong lập trình COM
<=> CString

Chuyển CString sang OLECHAR 
CString str = _T("hello");
OLECHAR* strf = str.AllocSysString(); // trả về bstr
// bstr là dạng olechar* dùng trong com 
Cần gọi SysFreeString() để tránh dò rì bộ nhớ
## BSTR
kiểu chuỗi đặc biệt do com định nghĩa
chứa thêm thông tin trước con trỏ
# null-terminated
chuỗi kết thúc bằng null
+ là chuỗi phần tử có kết thúc bằng '\0'
ví dụ
char* s = "hello"; 
trong bộ nhớ 
[ 'h' ][ 'e' ][ 'l' ][ 'l' ][ 'o' ][ '\0' ]
giúp cho strlen, strcpy, biết khi nào dừng lại

# OLECHAR* 
+ định nghĩa kiểu dùng trong COM
+ OLECHAR* là chuỗi UNICODE trong COM ( tương đương wchar_t*)
 tức là naming convention thì nó sẽ là OLECHAR, nếu ko, có thể
dùng là wchar_t* vẫn hoàn toàn đúng (wchar_t dùng 2 byte để mã hóa kí tự unicode-16 )
# _T("")
     Tùy vào chế độ biên dịch mà nó có thể là char* hoặc wchar_t*, do vậy ko để dùng với olechar

# 
spScript->GetIDsOfNames(IID_NULL, &szFunc, 1, LOCALE_USER_DEFAULT, &dispid);

gọi phương thức com để lấy dispid ( dispatch identifier) tương ứng với tên hàm javascript muốn gọi
==> muốn gọi hàm javascript, phải lấy được dispatch tương ứng
IDispatch
HRESULT GetIDsOfNames(
    REFIID riid,  // IID_NULL
    LPOLESTR* rgszNames, // con trỏ tới mảng con trỏ chuỗi ( tên hàm )
    UINT CNames, // số lượng tên trong mảng trên
    LCID lcid, // locale identifier, tra tên phù hợp theo ngôn ngữ người dùng, mặc định locale_user_default
    DISPID* rgDispId // con trỏ nhận về ID, dùng để gọi Invoke
);

=>> tra cứu tên hàm javascript để lấy tương ứng, dùng ID tương ứng đó để gọi Invoke()

// note
// bấm nút add
// gọi dialog, nhập xong dữ liệu, trả về, 
// gửi dữ liệu về , truy vấn lên, đưa vào để add

# MFC LÀ CÔNG NGHỆ CŨ,
không thể sử dụng let cho javascript