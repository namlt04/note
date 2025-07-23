# Mutex mutual exclusion lock
ngăn chặn nhiều luồng cùng truy cập vào tài nguyên dùng chung ( biến, file, bộ nhớ) 

Hoạt động 
- 1 luồng lock
- các luồng khác bị chặn 
- sau khi xong việc, unlock để luồng khác truy cập tài nguyên 
# có nhiều loai mutex khác nhau, được cung cấp bởi
<mutex> và <shared_mutex> (c++17)

```cpp
std::mutext mut // Khai báo 
void thread()
{
    mut.lock(); 
    std::cout << "Working thread ... " << endl; 
    mut.unlock(); 
}
```


# TEMPLATE CLASS
là khuôn mẫu cho phép tạo ra các class có thể hoạt động với nhiều kiểu dữ liệu khác nhau mà không cần viết lại mã nhiều lần

ví dụ :
vector<T> , set<T>, map<K, T> đều là những TEMPLATE CLASS 

# using namepsace
namespace dùng để nhóm các định danh như biến, hàm, lớp lại với nhau dưới 1 tên chung tránh xung đột tên khi sử dụng thư viện lớn hoặc thư viện bên ngoài
=> trùng tên giữa các hàm, các lớp, biến
# namespace std : là namespace chuẩn chứa các thành phần của thư viện chuẩn c++
chứa các hàm, các lớp ( template class), các đối tượng

#
Các #include <iostream> , <vector> là các file tiêu đề, tương tự với file .h

# C++ standard library 
là bộ thư viện chuẩn, đi kèm với ngôn ngữ c++

namespace std giúp 
phân biệt rõ các thành phần của thư viện chuẩn với thư viện do người dùng định nghĩa 

tránh xung đột tên

# <mutex>

## std::mutex
cho phép 1 thread giữ lại mutex ở 1 thời điểm 
không hỗ trợ đệ quy ( 1 thread không thể lockk lại nếu đang lock) 
```cpp
std::mutex mu;
mu.lock(); 
mu.unlock(); 

```
## std::recursive_mutex // ít được sử dụng
cho phép 1 thread lock lại dù đang lock ( phù hợp cho đệ quy ), giúp không bị dead lock
phai gọi unlock đúng với số lần tương ứng
```cpp
std::recursive_mutex r_mu; 
void foo()
{
    r_mu.lock(); 
    foo(); 
    r_mu.unlock();
}
```
## std::timed_mutex
Giống mutex, hỗ trợ timeout khi lock 
try_lock_for(std::chrono)           // cố găng giành lock liên tục trong thời gian 
try_lock_until             // cố gắng giành lock liên tục cho tới khi

## std::recursive_timed_mutex
Đệ quy nhưng có time out


std::lock_guard: khi bạn chỉ cần đơn giản lock một đoạn code.

std::unique_lock: khi bạn cần:

Giao tiếp với std::condition_variable.

Lock/unlock nhiều lần.

Delay lock (khi lock(m, std::defer_lock)).

Tránh dùng mutex.lock()/unlock() trực tiếp, trừ khi bạn cực kỳ cẩn thận và cần hiệu năng rất cao.



