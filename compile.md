
# Quá trình biên dịch và liên kết trong C++
1. Tiền xử lí : Preprocessing 
các dòng #include, #define,.. 
chèn nội dùng của file vào vị trí file nguồn hiện tại
VD: #include<iostream> 
sẽ chèn nội dung file iostream ( iostream chỉ là file khai báo, và nó chưa có mã thực thi)

2. Biên dịch ( compiling )
Biên dịch dịch từng file .cpp thành mã máy cấp thấp
3. liên kết các object file, liên kết thư viện chuẩn
Ví dụ: 

```cpp
#include "MyClass.h"
```
Khi biên dịch, ở bước Preprocessing, nó sẽ thay thế toàn bộ code của file MyClass.h vào vị trí này
Sau đó, nó biên dịch toàn bộ file cpp thành mã máy cấp thấp 
( .o, .obj )
Cuối cùng, như ví dụ trên, nó sẽ tìm đến MyClass.o ( biên dịch MyClass.cpp ), liên kết lại định nghĩa đã biên dịch


Khi biên dịch main.cpp, tiền xử lý sẽ chèn toàn bộ nội dung MyClass.h vào. Sau đó, main.cpp được biên dịch riêng thành main.o, và MyClass.cpp cũng được biên dịch riêng thành MyClass.o. Cuối cùng, trình liên kết sẽ ghép các .o này lại, nếu main.o cần gọi hàm được định nghĩa trong MyClass.o, linker sẽ gắn kết chúng với nhau để tạo ra chương trình hoàn chỉnh.

# Thư viện chuẩn 

namespace std; 
gom nhóm các thành phần chuẩn của ngôn ngữ, để tránh xung đột tên với định nghĩa của lập trình viên


Thư viện chuẩn: các mã đã được biên dịch thành nhị phân 
trong namespace std sẽ chứa các hàm gọi, logic, implement của header ( iostream, ... ) nhưng không chứa các implement của các template class ( vector, set, map)

Sau khi biên dịch, quá trình liên kết mới liên kết các logic đó vào

std::sort, std::swap là function template → dù không có binary sẵn, nhưng code nằm trực tiếp trong header.