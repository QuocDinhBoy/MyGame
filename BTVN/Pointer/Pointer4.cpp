
#include <iostream>

int main() {
    int x = 5;  // Biến địa phương x
    int* ptr = &x;  // Con trỏ ptr trỏ đến biến x

    delete ptr;  // Giải phóng con trỏ ptr trỏ đến vùng nhớ của biến x

    // Lỗi xảy ra tại đây. Con trỏ ptr đang trỏ đến một biến địa phương (không được cấp phát bằng toán tử new),
    // không thể giải phóng bằng toán tử delete. Điều này dẫn đến hành vi không xác định.
    // Trong trường hợp này, có thể xảy ra lỗi khi thử truy cập vào vùng nhớ đã được giải phóng, gây ra các vấn đề về bộ nhớ.

    return 0;
}
