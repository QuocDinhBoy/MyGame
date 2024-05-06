#include <bits/stdc++.h>
using namespace std;
int main () {
   int n;
   cin >> n;
   vector <vector<double>> sv(n,vector<double>(4));
   for (int i = 0;i < n;i++) {
    for (int j = 0;j < 3;j++) {
        cin >> sv[i][j];
        if (sv[i][j] < 0 || sv[i][j] > 10) {
        cout <<"invalid";
        return 0;
    }
   }
   }
   for (int i = 0;i < n;i++) {
        sv[i][3] = (sv[i][0] + sv[i][1] + sv[i][2])/3;
   }
   cout <<"Theo diem mon Toan:" << endl;
   cout <<"SV Toan Ly Anh" << endl;
   vector <double> diemToan;
   for (int i = 0;i < n;i++) {
    diemToan.push_back(sv[i][0]);
   }
   sort (diemToan.begin(),diemToan.end());
   for (int i = n - 1;i >= 0;i--) {
        for (int j = 0;j < n;j++) {
            if (diemToan[i] == sv[j][0]) cout <<j+1<< setprecision(1) << fixed <<" " << diemToan[i] <<" "<<sv[j][1] <<" " <<sv[j][2];
        }
        cout << endl;
   }
   cout << endl;
   cout <<"Theo diem mon Anh:" << endl;
   cout <<"SV Toan Ly Anh" << endl;
   vector <double> diemAnh;
   for (int i = 0;i < n;i++) {
    diemAnh.push_back(sv[i][2]);
   }
   sort (diemAnh.begin(),diemAnh.end());
   for (int i = n - 1;i >= 0;i--) {
        for (int j = 0;j < n;j++) {
            if (diemAnh[i] == sv[j][2]) cout <<j+1<< setprecision(1) << fixed <<" "<<sv[j][0] <<" " <<sv[j][1]<<" " <<sv[j][2];
        }
        cout << endl;
   }
   cout << endl;
   cout <<"Theo diem trung binh:" << endl;
   cout <<"SV TB Toan Ly Anh" << endl;
   vector <double> diemTB;
   for (int i = 0;i < n;i++) {
    diemTB.push_back(sv[i][3]);
   }
   sort (diemTB.begin(),diemTB.end());
   for (int i = n - 1;i >= 0;i--) {
        for (int j = 0;j < n;j++) {
            if (diemTB[i] == sv[j][3]) cout <<j+1<< setprecision(1) << fixed<<" "<<sv[j][3]<<" "<<sv[j][0] <<" " <<sv[j][1]<<" " <<sv[j][2];
        }
        cout << endl;
   }
   return 0;
}
