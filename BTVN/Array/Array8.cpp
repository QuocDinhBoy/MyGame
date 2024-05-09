#include <iostream>
#include <string.h>

using namespace std;

char str1[10];
char str2[5] = {"abcd"} ;
//char str3[4] = {"abcd"} ; // lỗi
//char str4[3] = {"abcd"} ; // lỗi
char str5[] = {"abcd"};

int main()
{
    char str_1[10];

    char str_2[5] = {"abcd"};
    for (auto i : str_2) cout << i << " ";  // in ra a b c d
    cout << endl << str_2 << endl; // in ra abcd

    //char str_3[4] = {"abcd"} ; // lỗi vì ngoài 4 kí tự còn có kí tự null ở cuối
    //char str_4[3] = {"abcd"} ; // lỗi


    char str_5[] = {"abcd"};
    cout << sizeof(str_5) << endl; // kích thước mảng = 5 => có kí tự null ở cuối mảng
    for (int i = 0; i < 10; i++) cout << str_5[i] << " "; // in ra: a b c d (null) a b c d (null)
    cout << endl << str_5 << endl; // in ra abcd


    char str_6[10] = {"abcd"};
    cout << sizeof(str_6) << " " << strlen(str_6) << endl; // kích thước mảng = 10, độ dài mảng = 4
    for (int i = 0; i < 10; i++) cout << str_6[i] << " "; //in ra: a b c d
    cout << endl << str_6 << endl; // in ra abcd

    //Mảng kích thước N lưu được string độ dài tối đa là N-1

    return 0;
}
