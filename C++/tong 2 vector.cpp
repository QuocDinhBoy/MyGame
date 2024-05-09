#include <iostream>
using namespace std;
int triple(int& x) {
  x = x + x + x;
  return x;
}
int main () {
int a = 10;
cout << triple(a) << " "  << triple(1) <<  endl;
cout << triple(1+a) << " " << triple(1+1) << endl;
cout << "a = " << a;
}
