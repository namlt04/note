# node.js là gì
là môi trường chạy javascript phía backend , dựa trên V8 engine,
=> giúp viết backend bằng javascript

# express 
express ( express.js ) là một framework nhẹ, linh hoạt dành cho node.js, 
giúp tạo webserver hoặc resfulapi

=> express = thư viện hỗ trợ viết server bằng nodejs dễ hơn

# apollo server
thư viện phổ biến, mạnh mẽ, xây dựng graphql api bằng node.js

express-graphql cũng giúp xây dựng graphql api 

=> để xây dựng graphql api, có thể dùng apollo server hoặc express-graphql

# tạo dự án với node.js
( npm install express nếu chưa cài)
1. Tạo thư mục
2. npm init -y ( tham số -y là tự động tạo ra thông tin, không hỏi)
tạo file package.json 
3. tạo 1 file chính để chạy server
4. chạy server node. ten_file.js


# express
luôn tự động trả về status == 200 nếu không có yêu cầu 

# require 
## dùng để import moudle, tên file hoặc thư viện

VD: 
1. Thư viện có sẵn : 
const fs = require('fs'); 
2. module tự viết 
const myModule = require('./myModule'); 
3. import từ thư viện cài bằng npm
const express = require('express'); 

file chỉ được nạp 1 lần, kết quả lưu trong cache

# require
nạp ( import ) 1 đối tượng hoặc hàm từ module khác, 
nếu không lưu vào biến thì không thể sử dụng lại nó
chỉ gán 1 lần, nên sử const ( giá trị không thay đổi)
