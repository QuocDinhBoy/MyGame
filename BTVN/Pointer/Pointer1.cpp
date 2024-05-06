 int* p = new int;
 int* p2 = p;
 *p = 10;
 delete p;
*p2 = 100; // Khi gán p2 bằng p,p2 trở thành một con trỏ trỏ đến cùng một vùng bộ nhớ mà p đang trỏ đến.
//Sau đó,khi p được giải phóng bộ nhớ bằng delete p, vùng bộ nhớ mà cả p và p2 trỏ đến đều đã được giải phóng.
//Do đó việc truy cập đến vùng bộ nhớ này *p2 = 100 sẽ gây ra lỗi
 cout << *p2;
 delete p2;
