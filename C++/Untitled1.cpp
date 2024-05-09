#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main () {
    string filePath;
    cin >> filePath;
    ifstream inputFile(filePath);
    int number;
    int count = 0;
    vector <int> a;
    int b;
    while (inputFile >> number) {
        cout << number <<" ";
        count++;
        a.push_back(number);
    }
     inputFile.close();
     sort(a,a+count);
     if (count % 2 == 1) cout << a[count/2];
     else {
         b = (a[count/2] + a[count/2 - 1])/2;
         cout << b;
     }
}

