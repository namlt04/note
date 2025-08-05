# Các loại api ( theo giao thức)

# rest api 
- dựa theo http, nguyên tắc restfull
-> phổ biến

- cho phép client ( web browser, app), gửi yêu cầu đến server, và server trả lại dữ liệu 

các thành phần chính
- http method ( tương ứng với thao tác crud )
- endpoint ( đường dẫn tài nguyên )
    + /user
    + /users/10 -> người dùng có id cụ thể ID = 10
- tài nguyên, mọi thứ đều là tài nguyên
người dùng, bài viết, bình luận, sản phẩm đều là tài nguyên
mỗi tài nguyên thướng có 1 url duy nhất
 http://api.example.com/users/10
- Không lưu trạng thái làm việc => mỗi yêu cầu từ client, phải chứ đủ thông tiin để server xử lí mà không cần nhớ thông tin trước đó

- dữ liệu trả về 
thường là json, đôi khi xml
kèm mã trạng thái http 

# soap api

- xml và giao thức soap
- nặng hơn rest nhưng có tính bảo mật
 
# graphql api 
- do facebook phát triển
- truy vấn dữ liệu linh hoạt
- thay thế rest api, cho phép lcient truy vấn chính xác dữ liệu mình cần
- có 1 endpoint duy nhất
- dữ liệu trả về : tùy ý theo truy vấn
- cập nhật dữ liệu dùng mutation
chuẩn hóa: có schema rõ ràng

- thành phần chính
1. Query - truy vấn dữ liệu
2. mutaition - crud
3. subscription - gửi dữ liệu theo thời gian thực 
# grpc api 
- do google phát triển
- giao tiếp qua http/2 
