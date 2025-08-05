# Dùng để làm gì?
Hiển thị kết nối mạng hiện tại (TCP/UDP), tương tự netstate, nhưng dễ đọc hơn 

Xem được : 
Process name : tiến trình đang mở kết nối
Protocol : TCP/UDP
Local address : địa chỉ IP và port cục bộ
remote address: địa chỉ IP và port đích 
state : trạng thái tcp 
LISTENING : chờ kết nối từ client
ESTABLISHED 
TIME_WAIT : đóng hoàn toàn kết nối, nhưng giữ lại trong 1 thời gian đảm bảo mọi gói đến muộn bị loại
SYN_SENT
SYN_RECEIVED 
ESTABLISHED
FINWAIT_1 : đã gửi fin, chờ ackk từ bên kia
finwait 2: đã gửi fin, sau khi nhận fin, chờ ack cuối cùng để kết thúc
LAST_ACK : đã gửi fin sau khi nhận fin, chờ ack cuối cùng để kết thúc
CLOSING : cả 2 bên gửi fin cùng lúc, đang chờ ack
CLOSED : kết nối đã đóng, và giải phóng tài nguyên 

