android native app :
ứng dụng viết bằng công cụ, ngôn ngữ chính thức của android, chạy trực tiếp qua android, tối ưu
yaml: file cấu hình phổ biến: yet another markup language

thụt đầu dòng thể hiện cấu trúc phân cấp
dữ liệu lưu key : value
hỗ trợ list, map, string, int, bool 

pch.cpp : pre-compiled header : tạo file pre-compiled header từ pch.h

biên dịch trước header phổ biên , tái sư 3dung5 kết quả này trong .cpp khác
thường tên là pch.h hoặc stdafx.h

solution : 
tập hợp các project quản lý chung 1 không gian phát triên3

khi tạo 1 button, thì code sẽ thay đổi thế nào trong mô hình mfc

#define : định nghĩa macro, thay thế các biến - một tên thay thế bằng 1 giá trị hoặc đoạn mã trong quá trình
biên dịch

ifdef: nếu macro được định nghĩa thì biên dịch code nếu có macro
ifndef: nếu macro chưa được định nghĩa, thì biên dịch code nếu chưa có macro

tiền xử lí: preprocessor directives xử lí đầu tiên khi biên dịch mã nguồn 
đọc các chỉ thị bắt đầu dấu # trước khi dịch sang mã may 1
chuẩn bị mã nguồn
