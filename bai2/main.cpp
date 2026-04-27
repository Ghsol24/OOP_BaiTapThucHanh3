#include <iostream>
#include "daGiac.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cDaGiac kc;
    kc.nhap();
    kc.xuat();
    cout <<"Chu vi của đa giác trên là : " << kc.chuVi() <<"\n";
    cout <<"Diện tích của đa giác trên là: " << kc.dienTich() <<"\n";
    db tinhx, tinhy;
    cout <<"Tiến hành tịnh tiến đa giác với x = ";
    cin >> tinhx;
    cout <<"\n";
    cout <<"Với y = ";
    cin>>tinhy;
    cout <<"\n";
    kc.tinhTien(tinhx,tinhy);
    kc.xuat();
    cout <<"\n";
    db g;
    cout <<"Tiến hành quay đa giác 1 góc là : ";
    cin >> g;
    cout <<"\n";
    kc.quay(g);
    kc.xuat();
    cout <<"Tiến hành phóng to đa giác với k = ";
    db k;
    cin >> k;
    cout <<"\n";
    kc.phongTo(k);
    kc.xuat();
    cout <<"Tiến hành thu nhỏ đa giác với m = ";
    db m;
    cin >> m;
    cout <<"\n";
    kc.thuNho(m);
    kc.xuat();
    cout<<"\n";
    cout <<"Kết thúc!"<<"\n";
    return 0;
}