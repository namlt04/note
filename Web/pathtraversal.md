File file = new File(BASE_DIRECTORY, userInput);
tạo đổi tượng File với đầu vào là base_directory + userInput
BASE_DIRECTORY = "/home/app/uploads"
userInput = "../etc/passwd"
=> file = "/home/app/uploads/../etc/passwd"
-------
file.getCanonicalPath()
Lấy đường dẫn chuẩn của file
( xóa các phần .., . ) giải xóa các symbolic links , ( %2e %252f, ... )

symblic links
ví dụ có file /home/user/real.txt
tạo symlink 
ln -s /home/user/real.txt /home/user/shortcut.txt
=> khi mở /home/user/shorcut.txt tức là đang mở /home/user/real.txt
-------------------------------------
mã hóa url : url encoding  - biểu diễn các kí ty56 đặc biệt trong url bằng định dạng an toàn
mã hóa lặp
| Gốc   | 1 lần mã hóa | 2 lần mã hóa |
| ----- | ------------ | ------------ |
| `/`   | `%2F`        | `%252F`      |
| `.`   | `%2E`        | `%252E`      |
| `%2F` | `%252F`      | `%25252F`    |
| `%`   | `%25`        | `%2525`      |

| Ký tự | Mã hóa | ASCII (thập phân) | Giải thích                        |   |
| ----- | ------ | ----------------- | --------------------------------- | - |
| space | `%20`  | 32                | Dấu cách                          |   |
| "     | `%22`  | 34                | Dấu nháy kép                      |   |
| #     | `%23`  | 35                | Fragment identifier               |   |
| %     | `%25`  | 37                | Dấu phần trăm (rất quan trọng)    |   |
| &     | `%26`  | 38                | Dùng trong query string           |   |
| '     | `%27`  | 39                | Dấu nháy đơn                      |   |
| (     | `%28`  | 40                |                                   |   |
| )     | `%29`  | 41                |                                   |   |
| \*    | `%2A`  | 42                |                                   |   |
| +     | `%2B`  | 43                | Đôi khi thay cho space trong URL  |   |
| ,     | `%2C`  | 44                |                                   |   |
| /     | `%2F`  | 47                | Dấu gạch chéo (phân cách thư mục) |   |
| :     | `%3A`  | 58                | Phân tách giao thức (http:)       |   |
| ;     | `%3B`  | 59                |                                   |   |
| <     | `%3C`  | 60                |                                   |   |
| =     | `%3D`  | 61                | Trong tham số GET                 |   |
| >     | `%3E`  | 62                |                                   |   |
| ?     | `%3F`  | 63                | Bắt đầu query string              |   |
| @     | `%40`  | 64                |                                   |   |
| \[    | `%5B`  | 91                |                                   |   |
| \\    | `%5C`  | 92                | Backslash                         |   |
| ]     | `%5D`  | 93                |                                   |   |
| ^     | `%5E`  | 94                |                                   |   |
| \`    | `%60`  | 96                |                                   |   |
| {     | `%7B`  | 123               |                                   |   |
|       |        | `%7C`             | 124                               |   |
| }     | `%7D`  | 125               |                                   |   |
| \~    | `%7E`  | 126               | (đôi khi không cần mã hóa)        |   |

-------------------------------------
startWith(bast_directory) kiểm tra xem có nằm trong thư mục cơ sở hay không, 