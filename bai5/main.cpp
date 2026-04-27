#include "cDaThuc.h"
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cDaThuc kc;
    kc.nhap();
    cout <<"Nhập giá trị của x: " <<"\n";
    double tmp; cin>>tmp;
    double temp = kc.tinhGiaTri(tmp);
    cout <<"Giá trị của đa thức với x = " << tmp <<" là : "<< temp <<"\n";
    cout <<"\n";
    cout <<"Nhập đa thức thứ 2 để thực hiện cộng trừ đa thức !" <<"\n";
    cDaThuc dt2;
    dt2.nhap();
    cout <<"Tiến hành cộng đa thức !" <<"\n";
    cDaThuc tmp1;
    tmp1 = kc.cong(dt2);
    cout <<"Đa thức sau khi cộng là ";
    tmp1.xuat();
    cout<<"\n";
    cout <<"Tiến hành trừ đa thức ! "<<"\n";
    cDaThuc tmp2;
    tmp2 = kc.tru(dt2);
    cout <<"Đa thức sau khi trừ là ";
    tmp2.xuat();
    cout <<"\n";
    cout <<"Kết thúc! ";
    return 0;
}