
class MyClass {

}
MyClass* obj = new MyClass(); 

- gọi constructor của My Class
- cấp phát bộ nhớ cho đối tượng trên heap 
- Trả về con trỏ MyClass* trỏ tới vùng nhớ được cấp phát 

delete obj;  // giải phóng bộ nhớ

=> Cách này được gọi là khởi tạo động ( dynamic allocation )

# Khởi tạo tĩnh ( stack allocation)
MyClass obj 
Nơi lưu sẽ là stack và được quản lý 1 cách tự động

# STACK VÀ HEAP 
STACK :
- Lưu các biến cục bộ
- lời gọi hàm
- quản lý tự động bởi trình biên dịch ( compiler) 

void func()
{
    int a = 5; // a sẽ được lưu trên stack
}

HEAP : VÙNG NHỚ CẤP PHÁT ĐỘNG, tự yêu cầu cấp phát và tự giải phóng
dùng `new` để cấp phát và `delete` để giải phóng 


# Tại sao lại cần tới heap 
stack có kích thước nhỏ, ( thường là vài mb ), các biến được xóa sau khi hàm kết thúc

heap : tồn ại cho đến khi được giải phóng 

Stack dùng khi bạn biết trước kích thước, thời gian sống ngắn, an toàn.

Heap dùng khi cần dữ liệu lớn, linh hoạt, sống lâu hơn phạm vi hàm.

# Tăng địa chỉ , giảm địa chỉ
mỗi ô nhớ trong ram, là 1 số nguyên
tăng địa chỉ: đi về phía cuối ram
giảm địa chỉ: đi về phía đầu ram


Stack : giảm địa chỉ 
+----------------------+  ← địa chỉ thấp
|  Code (text)         |
|  Static/Global data  |
|                      |
|  Heap (tăng địa chỉ) |
|      ↑               |
|      |               |
|      |               |
|      ↓               |
|  Stack (giảm địa chỉ)|
|                      |
+----------------------+  ← địa chỉ cao (gần kernel)