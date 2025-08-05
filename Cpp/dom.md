# một số cú pháp cho MFC
CComPtr<T> con trỏ thông minh, tự động delete sau khi ra khỏi scope ( phạm vi của hàm )
CComQIPtr<T> CCom Query Interface Ptr, con trỏ truy vấn giao diện thông minh
CComBSTR  thay thế cho BSTR cũ
- thường sử dụng đến 
IDHTMLDocument2 
    + GetDHTMLDocument
    + get_Script // Để lấy 1 tên 1 hàm js
IDHTMLDocment3
có lấy element theo ID, phù hợp tương tác với từng input, text 


# COM : COMPONENT OBJECT MODEL
Công nghệ giúp các thành phần đối tượng (object) giao tiếp với nhau dù bất kể chúng sử dụng ngôn ngữ nào di

- Là 1 chuẩn kĩ thuật thiết để các thành phần phần mềm có thể tương tác với nhau bất kể được viết bằng phần mềm nào
tương tự 1 quy tắc và giao thức chuẩn, dựa vào quy tắc này để tạo ra các thành phần cằm vào và chạy trong nhiều chương trình khác nhau

# DOM : document object modle
cho phép truy cập và thao tác với HTML từ c++ và ngược lại 


## query interface

một đối tượng COM (component object model) có thể hỗ trợ nhiều interface
interface : tập hợp các hàm thuần ảo
IID : GUID xác định duy nhất 1 interface 
com object đối tượng thực sự cài đặt interface
IHTMLTable :: <table> :: 	insertRow, deleteRow, get_rows()
IHTMLTableRow :: <tr> :: 	insertCell, deleteCell, get_cells()
IHTMLTableCell :: <td> ::colSpan, rowSpan, align,...

#### ERROR
# Trước khi sử dụng ép kiểu, phải đảm bảo con trỏ đó null
Ví dụ
sPRow->insertCell(-1, (IDispatch**)&sPCell.p)

khi sử dụng inserCell, nó yêu cầu con trỏ nhận kết quả đầu ra phải là 1 con trỏ null 
yêu cầu phải .Release() trước khi gán tiếp
 
# OVERRIDE
void OnCreate


# Khai báo event map
BEGIN_DHMTL_EVENT_MAP(ten_file)
    DHTML_EVENT_ONCLICK(id_button, ham_xu_li) // Nhận sự kiện click của button
END_DHTML_EVENT_MAP()

# OLECHAR : kiểu dữ liệu chuẩn trong lập trình COM
<=> CString

Chuyển CString sang OLECHAR 
CString str = _T("hello");
OLECHAR* strf = str.AllocSysString(); // trả về bstr
// bstr là dạng olechar* dùng trong com 
Cần gọi SysFreeString() để tránh dò rì bộ nhớ
## BSTR
kiểu chuỗi đặc biệt do com định nghĩa
chứa thêm thông tin trước con trỏ
# null-terminated
chuỗi kết thúc bằng null
+ là chuỗi phần tử có kết thúc bằng '\0'
ví dụ
char* s = "hello"; 
trong bộ nhớ 
[ 'h' ][ 'e' ][ 'l' ][ 'l' ][ 'o' ][ '\0' ]
giúp cho strlen, strcpy, biết khi nào dừng lại

# OLECHAR* 
+ định nghĩa kiểu dùng trong COM
+ OLECHAR* là chuỗi UNICODE trong COM ( tương đương wchar_t*)
 tức là naming convention thì nó sẽ là OLECHAR, nếu ko, có thể
dùng là wchar_t* vẫn hoàn toàn đúng (wchar_t dùng 2 byte để mã hóa kí tự unicode-16 )
# _T("")
     Tùy vào chế độ biên dịch mà nó có thể là char* hoặc wchar_t*, do vậy ko để dùng với olechar

# Tra cứu tên của hàm
spScript->GetIDsOfNames(IID_NULL, &szFunc, 1, LOCALE_USER_DEFAULT, &dispid);

gọi phương thức com để lấy dispid ( dispatch identifier) tương ứng với tên hàm javascript muốn gọi
==> muốn gọi hàm javascript, phải lấy được dispatch tương ứng
IDispatch
HRESULT GetIDsOfNames(
    REFIID riid,  // IID_NULL
    LPOLESTR* rgszNames, // con trỏ tới mảng con trỏ chuỗi ( tên hàm )
    UINT CNames, // số lượng tên trong mảng trên
    LCID lcid, // locale identifier, tra tên phù hợp theo ngôn ngữ người dùng, mặc định locale_user_default
    DISPID* rgDispId // con trỏ nhận về ID, dùng để gọi Invoke
);

=>> tra cứu tên hàm javascript để lấy tương ứng, dùng ID tương ứng đó để gọi Invoke()






Example:
```cpp
// Lấy dữ liệu hoặc đẩy dữ liệu vào tag <input>
CComPtr<IHTMLDocument2> spDoc2; 
GetDHTMLDocument(&spDoc2); 
CComQIPtr<IHTMLDocument> spDoc3 = spDoc2; // Chuyển sang sử dụng Doc3 vì Doc3 mới có hàm GetId
CComPtr<IHTMLElement> spEle; 
spDoc3->getElementById(/* Tên kiểu dữ liệu BSTR : CComBSTR(L"")*/, &spEle);
CComQIPtr<IHTMLInputTextElement> spInput; 
CComBSTR value = nullptr;
spInput->get_value(&value); // lấy dữ liệu
spInput->put_value(CComBSTR(L"")); // đẩy dữ liệu
```

```cpp
// Dùng để gọi hàm trong Script
CComPtr<IHTMLDocument2> spDoc2;
CComPtr<IDispatch> spScript; 
spDoc2->get_Script(&spScript); 

OLECHAR* nameFunc = L"nameFunc"; 
DISPID pid; 
spScript->GetIDsOfNames(IID_NULL, &nameFunc, 1, LOCALE_USER_DEFAULT, &pid); 

CComVariant res;
DISPPARAMS dp = {nullptr, nullptr, 0, 0}; 
// dp = { doi_so(nguoc_thu_tu), doi_so_co_ten(it_dung), so_doi_so, so_doi_so_co_ten}

spScript->Invoke(pid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &dp, &result, nullptr, nullptr); // Gọi hàm
CComBSTR bstr = result.bstrVal; // lấy kết quả trả về

CStringW cStrW(bstr); 
```
# Note_1 
Trong truong hợp hàm có 2 đối số . Ví dụ
```javascript
function solve(a, b){

}
```
Ta có thể truyền với DISPPARAM như sau 
```cpp
CComVariant args[2]; 
args[0] = gia_tri_doi_so_1; 
args[1] = gia_tri_doi_so_0; 
```
# Note_2
Trong trường hợp truyền vào String
```javascript
funtion solve(str){

}
```
Ta khai báo 
CComBSTR bstr = L"Mang truyen vao";
CComVariant param(bstr);
// bstr sẽ tự được sắp xếp vào chuẩn param.valBstr
