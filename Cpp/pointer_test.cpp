#include<iostream> 

int main()
{
    char* s = "xinchaodaylamochuoi"; // Nếu khai báo char* s như này, nó sẽ tự chuyển chuỗi trên thành mảng const char []
    // tự động chuyển ['x', 'i',..... '\0']; null-terminated : kết thúc bằng \0
    std::cout << s << std::endl;
    return 0; 
}