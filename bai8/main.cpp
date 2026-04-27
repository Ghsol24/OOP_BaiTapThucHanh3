#include "cNhanVienSX.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cQuanLy kc;
    kc.nhapDS();
    cout <<"\n";
    cout <<"Danh sách nhân viên ! " <<"\n";
    kc.xuatDS();
    kc.NVLuongThap();
    long long tongLuong = kc.sumLuong();
    cout <<"Tổng số lương mà công ty cần trả cho toàn bộ nhân viên là : " << tongLuong <<"\n";
    kc.NVTuoiCao();
    kc.xuatDSLuongTangDan();
    cout <<"\n";
    cout <<"Kết thúc ! ";
    return 0;
}