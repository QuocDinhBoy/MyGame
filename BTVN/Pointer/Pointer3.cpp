#include <bits/stdc++.h>

char* a = new char[10];  // Cấp phát một mảng char động có độ dài 10

char* c = a + 3;  // Con trỏ c trỏ đến vị trí thứ 3 trong mảng char a

for (int i = 0; i < 9; i++) a[i] = 'a';  // Gán giá trị 'a' cho 9 phần tử đầu tiên của mảng char a

a[9] = '\0';  // Kết thúc chuỗi a bằng kí tự null

cerr <<"a: " << "-" << a << "-" << endl;  // In chuỗi a ra màn hình

cerr <<"c: " << "-" << c << "-" << endl;  // In chuỗi c ra màn hình, từ vị trí thứ 3 của chuỗi a

delete c;  // Giải phóng bộ nhớ mà con trỏ c đang trỏ đến (lỗi: không được giải phóng vùng nhớ không được cấp phát bằng toán tử new)

cerr << "a after deleting c:" << "-" << a << "-" << endl;  // In lại chuỗi a ra màn hình sau khi giải phóng bộ nhớ của c
