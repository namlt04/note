====
#pragma comment(lib, "userenv.lib")
yêu cầu linker liên kết thư viện userenv.liv vào chương trình khi biên dịch
Userenv.lib là thư viện liên kết tĩnh ( static import library ) cho Userenv.dll, cung cấp các hàm
- Quản lí hồ sơ người dùng
- môi trường người dùng, các hàm đặc biệt
dùng khi các API yêu cầu liên kết với Userenv.dll

Gắn thư viện trực tiếp vào mã nguồn, thay vì phải thiết lập trong IDE
==== 

Userenv.dll thường được dùng khi làm việc với môi trường người dùng : biến môi trường, profile người dùng, 
tạo môi trường cho process mới
====
Môi trường của một process : là tập các biến môi trường
path C:\Windows\System32;... 
username, temp, appdata

các biến này được dùng để : 
- Tìm file thực thi
- Ghi log, tạo ifle tạm
- Dò vị trí cấu hình 
Nếu không cung cấp môi trường (environment ) 
- Không lưu được file tạm
- ứng dụng không mở được
- 1 số app crash vì không tìm thấy profile user
==== 
Khi chạy 1 chương trình ( HelloWord.c ) không cần tạo môi trường vì
- process cha ( đến từ CMD, .bat, .exe,.. ) luôn cung cấp sẵn môi trường
====
extern : biến này được đinh 5nghia4 ở nơi khác, không phải trong file này
dùng để khai báo ( declare ) chứ không định nghĩa ( define ), giúp dùng chung biến hoặc
hàm giữa nhiều file nguồn
ví dụ

#include <iostream>

int counter = 42;  // Định nghĩa (define)

int main() {
    std::cout << "Counter: " << counter << std::endl;
    return 0;
}

extern int counter;  // Khai báo (declare)

void printCounter() {
    printf("Other file counter = %d\n", counter);
}
>>> extern với biến counter

==== 
mặc định, hàm không cần extern, những vẫn có thể viết rõ 
====
Handle : giá trị đại diện cho đối tượng hệ thống ( system object ), 
là 1 định danh trừu tượng mà hdh windows cung cấp để ứng dụng có thể làm việc với các đối
tượng như File, Process, thread, Mutex, event, windows station, registry key 

=> không nên giải mã giá trị trực tiếp
====
lấy access token của người dùng đăng nhập vào 1 session cụ thể

BOOL WTSQueryUserToken(
  _In_  ULONG  SessionId,
  _Out_ PHANDLE phToken
);
==== 
LocalSystem : tài khoản do Windows cung cấp, dùng để chạy các dịch vụ hệ thống ( WindowsServices ) 

tên tài khoản NT AUTHORITY\SYSTEM hoặc LocalSystem
không thể đăng nhập bằng tay
có mọi quyền ( cao hơn administrator ) 
chạy dịch vụ hệ thống
=> thành phần nội tại của WindowsOS
====
CStringW và LPWSTR
CStringW là 1 class, còn lpwstr là 1 con trỏ ( nó là wchar_t* ) 

CStringW lấy con trỏ .GetBuffer() -> trả về con trỏ wchar_t*
====
CreateProcessAsUser để tạo tiến trình trong 1 phiên người dùng tương tác, 
cần chỉ rõ rằng tiến trình mới nên kết nối với desktop mặc định
winsta0 : windows station mặc định mà người dùng tương tác dùng
default : là desktop chính ( nới các cửa sổ gui hiển thị ) 
nêu 1ko gán lpDesktop, tiến trình ko có tương tác với người dùng 
====
DuplicateTokenEx : tạo ra 1 token mới từ token đã tồn tại

BOOL DuplicateTokenEx(
  HANDLE                       hExistingToken,
  DWORD                        dwDesiredAccess, // Token access all, toàn bộ quyền
  LPSECURITY_ATTRIBUTES        lpTokenAttributes, // NULL
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel, // 
  TOKEN_TYPE                   TokenType,
  PHANDLE                      phNewToken
);

Cấp độ	Tên	Mô tả
0	SecurityAnonymous	Không thể xác định danh tính người dùng
1	SecurityIdentification	Biết ai là user nhưng không thể hành động như họ
2	SecurityImpersonation ✅	Có thể hành động như user trên local system
3	SecurityDelegation	Có thể mạo danh user qua cả network


| Loại token | Tên                  | Mô tả                                                                                         |
| ---------- | -------------------- | --------------------------------------------------------------------------------------------- |
| 1          | `TokenPrimary` ✅     | Token **có thể gán cho một process**. Dùng để **tạo hoặc chạy process mới**                   |
| 2          | `TokenImpersonation` | Token chỉ dùng để **mạo danh trong thread hiện tại**, không thể dùng để khởi chạy process mới |
