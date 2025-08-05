
#include <iostream>
#include <Windows.h> 
int main()
{
    DWORD sessionId = WTSGetActiveConsoleSessionId(); 
    // Trả về sessionId của chương trình đang chạy
    // DWORD WTSGetActiveConsoleSessionId(void); 
    std::cout << sessionId << std::endl;
    return 0; 
}
WTSQueryUserToken(sessionId, &handle)
// Lấy access token của người dùng với 1 token nào đó
// Điều kiện : 
// Tiến trình phải có SeTcbPrivilage
// chạy dưới quyền LocalSystem có đủ đặc quyền quản trị cao

BOOL CreateProcessAsUserW(
  [in, optional]      HANDLE                hToken, // Truyền vào token 
  [in, optional]      LPCWSTR               lpApplicationName, // tên của chương trình
  [in, out, optional] LPWSTR                lpCommandLine, // commandLine, để khởi động chương trinh,2 truyền tham số
  [in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes, // Thường null
  [in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes, // thường NULL
  [in]                BOOL                  bInheritHandles, // false
  [in]                DWORD                 dwCreationFlags, //
  [in, optional]      LPVOID                lpEnvironment, // con trỏ tới khối môi trường
  [in, optional]      LPCWSTR               lpCurrentDirectory, // NULL
  [in]                LPSTARTUPINFOW        lpStartupInfo, // con trỏ tới si
  [out]               LPPROCESS_INFORMATION lpProcessInformation // contro3 tới pi -> giá trị out
);
