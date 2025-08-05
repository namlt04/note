# Tìm hiểu về bloc
Business logic component
- Là 1 kiến trúc và thư viện dùng để 
    + Quản lí trạng thái 
    + Tách biệt UI với logic xử lí
    + Giao tiếp giữa UI và logic bằng cách gửi event và nhận state
flutter_bloc: ^8.1.3
Cấu trúc thư mục bloc
lib/
├── blocs/                # Chứa các logic BLoC
│   └── auth/
│       ├── auth_bloc.dart
│       ├── auth_event.dart
│       └── auth_state.dart
│
├── models/               # 🧾 Các lớp dữ liệu (User, Message,...)
│   └── user.dart
│
├── repositories/         # 🌐 Giao tiếp với API, database
│   └── auth_repository.dart
│
├── screens/              # 🖼️ UI theo màn hình
│   ├── login_screen.dart
│   └── home_screen.dart
│
├── widgets/              # 🔧 Các widget tái sử dụng
│   └── loading_indicator.dart
│
└── main.dart



3 thành phần cốt lõi của mô hình bloc
- bloc : xử lí logic của 1 tính năng
    + nhận event, chuyển thành state
    UI gửi event => bloc xử lí => phát ra state => UI dựa vào state thay đổi 
- event: sự kiện trong app
    VD: người dùng nhấn nút Gửi -> app phát ra event SendMessage
- State: trạng thái của UI
    Bloc phát ra 1 state mới sau khi xử lí 1 Event
# Hoạt động 
    Khi BLoC emit(state) thì phía UI ( Ví dụ : login screen) sử dụng Blocbuilder để lắng nghe sự thay đổi State
+ Cấu trúc BlocBuilder : 
BlocBuilder<BlocType, StateType>(
  builder: (context, state) {
    // Trả về widget tùy theo state
  },
)
Đây là 1 Widget dùng trong UI để lắng nghe State từ Bloc và cập nhật UI

+ BlocProvider: cung cấp Bloc cho cây widget bên dưới
BlocProvider(
  create: (_) => AuthBloc(),
  child: MyApp(),
)
## Nếu có nhiều Bloc thì sử dùng MultiBlocProvider
> Example: 
MultiBlocProvider(
  providers: [
    BlocProvider<AuthBloc>(
      create: (_) => AuthBloc(),
    ),
    BlocProvider<MessageBloc>(
      create: (_) => MessageBloc(),
    ),
    BlocProvider<ConnectivityBloc>(
      create: (_) => ConnectivityBloc(),
    ),
  ],
  child: MyApp(), // cây widget con
)

# Các từ khóa trong Flutter BLoC
+ emit (state): phát ra 1 trạng thái mới để UI biết để cập nhật
+ on<EventType> : đăng kí xử lí cho một loại Event

# Bổ sung kiến thức OOP
+ Lớp trừu tượng abstract class : lớp chứa các phương thức trừu tượng ( chưa có nội dung ) hoặc phương thức thường, được thiết kế để các lớp con ghi đè và triển khai cụ thể


# Tìm hiểu connectivity_bloc


# Bổ sung kiến thức flutter
- Widget : Giao diện trong flutter đều là widget, từ nút bấm, hình anh , mọi thứ

- Widget con ( child widget ) : là widget nằm trong 1 widget khác 

- Liên hệ với BlocProvider
BlocProvider(
  create: (_) => AuthBloc(),
  child: MyApp(),
)
MyApp() là 1 Child widget trong BlocProvider()
Các Child widget nằm trong MyApp đều có thể sử dụng AuthBloc()


# Bổ sung kiến thức Flutter
Stream : tương tự 1 List, nhưng chứa dữ liệu bất đông bộ

Ví dụ : 
Stream<int> countStream(int max)  async* { 
    for ( int i = 0; i < max; i++ ){
        yield i; 
    }
}
+ hàm trả về 1 Stream chứa các giá trị kiểu int

+ async* : cú pháp đặc biệt trong Dart tạo 1 Stream bất đồng bộ
+ async : Trả về Future<T> , async* trả về nhiều giá trị theo thời gian 
+ yield i
Tương tự return, nhưng yield không kết thúc hàm, yield phát ra giá trị i cho người lắng nghe Stream, sau đó thực hiện vòng lặp

