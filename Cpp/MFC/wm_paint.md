virtual : hàm ảo, cho phép ghi đè 

cơ chế WM_PAINT : 
cửa sổ bị thu nhỏ, cập nhật nội dung, đánh dấu vùng cần vẽ lại
- gửi thông điệp WM_PAINT cho cửa sổ trong vòng lặp xử lý thông điệp
- nhận được WM_PAINT, thông báo lại hệ thống đã xử lí xong việc vẽ lại