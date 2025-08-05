## GIAO THỨC TCP 
transfer control protocol

quá trình tcp có 2 giai đoạn
1. thiết lập kết nối
3way-handshake
2. truyền dữ liệu
state ESTABLISHED
3. đóng kết nối
4way-handshake 

A  --->  B
Scenario: 
- A muốn đóng kết nối với B : A gửi đi gói tin FIN 
Trạng thái : FINWAIT1
- B xác nhận yêu cầu đóng kết nối của A : gửi đi gói tin ack 
FINT_WAIT2 : TRẠNG THÁI CỦA A
CLOSE_WAIT : TRẠNG THÁI CỦA B
- B cũng muốn đóng, gửi đi gói tin fin 
state TRẠNG THÁI CỦA b : last ack ( )
- a xác nhận rồi kêt thúc
tcp là full-duplex, mỗi bên phải đóng riêng


fullduplex : 2 thiết bị có thể gửi và nhận dữ liệu cùng lúc trên 1 đường truyền