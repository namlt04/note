grant create on *.* to 'namltd'@'localhost'
flush privileges;


Kiểm tra quyền của user
show grants for 'namltd'@'localhost'; 


grant usage on *.* to 'namltd'@localhost'; 
==> Lệnh này không có quyền gì cả, chỉ đảm bảo tài khoản này tồn tại và có thể đăng nhập


==> Giới hạn quyền trong 1 database
Giả sử có Database là NhanVien 

GRANT ALL PRIVILEGES ON NhanVien.* TO 'namltd'@'localhost' 
flush privileges;

==> Xem có bao nhiêu database trong mysql
show database; 

==> Tạo database trong mysql
create database name;

==> tạo table 
create table if not exists ten_bang(
	
); 


## Xem có những tài khoản nào trong mysql
select user,host from mysql.user;

## thêm tài khoản trong mysql
create user 'user'@'localhost' IDENTIFIED BY 'password';

## kiểm tra tài khoản kết nối, tài khoản dùng để kiểm tra quyền
select user(), current_user(); 

# DATETIME TRONG MYSQL
DATETIME TRONG MYSQL PHẢI CÓ ĐỊNH DẠNG YYYY-MM-DD HH-mm-SS
tức nếu muốn truyền string vào, ít nhất phải có dạng YYYY-MM-DD


# Lấy ID cuối ( ID là số nguyên tự tăng) của Record vừa thêm vào
Select last_insert_id(); 


# insert trong vector
insert(vt.begin(), gia_tri); 