#include "cNhanVienSX.h"
#include <iostream>
#include <string>
#include <climits>
using namespace std;

cNhanVienSX::cNhanVienSX(){
    maNV = "";
    hoTen = "";
    ngaySinh.nam = 2000;
    ngaySinh.thang = 1;
    ngaySinh.ngay = 1;
    soSP = 0;
    donGia = 0;
}
cNhanVienSX::cNhanVienSX(string maNV, string hoTen, date ngaySinh, int soSP, int donGia){
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->soSP = soSP;
    this->donGia = donGia;
}
cNhanVienSX::~cNhanVienSX(){}
void cNhanVienSX::setmaNV(string _maNV) {
    maNV = _maNV; 
}
void cNhanVienSX::sethoTen(string _hoTen) {
    hoTen = _hoTen; 
}
void cNhanVienSX::setqlyNgaySinh(date _ngaySinh) {
    ngaySinh = _ngaySinh; 
}
void cNhanVienSX::setsoSP(int soSP){
    if (soSP >= 0){
        this->soSP = soSP; 
    } else {
        cout <<"Số sản phẩm không thể là số âm!\n";
        this->soSP = 0;
    }
}
void cNhanVienSX::setdonGia(int donGia){
    if (donGia >= 0){
        this->donGia = donGia;
    } else {
        cout <<"Giá thành sản phẩm không thể là số âm!\n";
        this->donGia = 0;
    }
}
string cNhanVienSX::getmaNV(){ return maNV; }
string cNhanVienSX::gethoTen(){ return hoTen; }
int cNhanVienSX::getSP(){ return soSP; }
int cNhanVienSX::getDonGia(){ return donGia; }
date cNhanVienSX::getNgaySinh(){ return ngaySinh; }
void cNhanVienSX::nhap(){
    cout <<"Nhập mã Nhân viên:\n";
    cin >> maNV;
    cin.ignore();
    cout <<"Nhập họ và tên của Nhân viên có mã là " << maNV <<"\n";
    getline(cin, hoTen);
    do {
        cout <<"Nhập theo cú pháp ngày-tháng-năm hoặc ngày/tháng/năm" <<"\n";
        cin >> ngaySinh.ngay >> ngaySinh.tmp1 >> ngaySinh.thang >> ngaySinh.tmp2 >> ngaySinh.nam;
        bool hopLe = true;
        if (ngaySinh.thang < 1 || ngaySinh.thang > 12) hopLe = false;
        int soNgay;
        switch (ngaySinh.thang) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                soNgay = 31; break;
            case 4: case 6: case 9: case 11:
                soNgay = 30; break;
            case 2:
                if ((ngaySinh.nam % 400 == 0) || (ngaySinh.nam % 4 == 0 && ngaySinh.nam % 100 != 0))
                    soNgay = 29;
                else
                    soNgay = 28;
                break;
            default:
                hopLe = false;
        }
        if (ngaySinh.ngay < 1 || ngaySinh.ngay > soNgay) hopLe = false;
        if (!((ngaySinh.tmp1 == '-' || ngaySinh.tmp1 == '/') &&
            (ngaySinh.tmp2 == '-' || ngaySinh.tmp2 == '/')))
            hopLe = false;
        if (!hopLe) {
            cout << "Ngày không hợp lệ! Nhập lại.\n";
        } else break;
    } while (true);
    cout <<"Nhập số sản phẩm mà nhân viên này đã gia công: "<<"\n";
    cin >> soSP;
    cout << "Nhập đơn giá của sản phẩm đó: " <<"\n";
    cin >> donGia;
    cout <<"Hoàn thành nhập thông tin của nhân viên ! "<<"\n";
}
void cNhanVienSX::xuat(){
    cout <<"Họ và tên: " << hoTen <<"\n";
    cout <<"Mã nhân viên: " << maNV <<"\n";
    cout <<"Ngày tháng năm sinh " << ngaySinh.ngay << ngaySinh.tmp1 << ngaySinh.thang << ngaySinh.tmp2 << ngaySinh.nam <<"\n";
    cout <<"Số sản phẩm mà nhân viên này đã gia công: " << soSP<<"\n";
    cout <<"Đơn giá của mỗi sản phẩm đó: " << donGia <<"\n";
}
int cNhanVienSX::tinhLuong(){
    return donGia * soSP;
}
cQuanLy::cQuanLy(){
    n = 0;
    dsNV = nullptr;
}
cQuanLy::~cQuanLy(){
    if(dsNV != nullptr){
        delete[] dsNV;
        dsNV = nullptr;
    }
}
void cQuanLy::nhapDS(){
    int soNV;
    cout << "Nhập số lượng nhân viên: ";
    cin >> soNV;
    n = soNV;
    dsNV = new cNhanVienSX[n];
    for(int i = 0; i < n; i++){
        dsNV[i].nhap();
    }
}
void cQuanLy::xuatDS(){
    for ( int i = 0 ; i < n ; i++){
        cout <<"Thông tin của nhân viên thứ " << i+1 <<"\n";
        dsNV[i].xuat();
    }
}
void cQuanLy::NVLuongThap(){
    if (n == 0) {
        cout << "Danh sách trống, không có nhân viên lương thấp nhất!\n";
        return;
    }
    int min = INT_MAX;
    int minIndex = 0;
    for (int i = 0 ; i < n ; i++){
        if (dsNV[i].tinhLuong() < min){
            min = dsNV[i].tinhLuong();
            minIndex = i;
        }
    }
    cout <<"Lương của nhân viên có mã Nhân viên " << dsNV[minIndex].getmaNV() << " là thấp nhất ! "<<"\n";
}
long long cQuanLy::sumLuong(){
    long long sum = 0;
    for ( int i = 0; i < n ; i++){
        sum+=dsNV[i].tinhLuong();
    }
    return sum;
}
void cQuanLy::NVTuoiCao() {
    if (n == 0) {
        cout << "Danh sách trống, không có nhân viên tuổi cao nhất!\n";
        return;
    }
    int vt = 0; 
    for (int i = 1; i < n; i++) {
        date ngayI = dsNV[i].getNgaySinh();
        date ngayVt = dsNV[vt].getNgaySinh();
        if (
            (ngayI.nam < ngayVt.nam) ||
            (ngayI.nam == ngayVt.nam &&
             ngayI.thang < ngayVt.thang) ||
            (ngayI.nam == ngayVt.nam &&
             ngayI.thang == ngayVt.thang &&
             ngayI.ngay < ngayVt.ngay)
        ) {
            vt = i;
        }
    }
    cout << "Nhan vien co tuoi cao nhat: ";
    dsNV[vt].xuat();
}
void cQuanLy::xuatDSLuongTangDan(){
    if (n == 0) {
        cout << "Danh sách trống, không thể sắp xếp!\n";
        return;
    }
    cNhanVienSX* temp = new cNhanVienSX[n];
    for (int i = 0; i < n; i++) {
        temp[i] = dsNV[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i].tinhLuong() > temp[j].tinhLuong()) {
                swap(temp[i], temp[j]);
            }
        }
    }
    cout << "Danh sach nhan vien theo luong tang dan:\n";
    for (int i = 0; i < n; i++) {
        cout <<"Nhân viên thứ " << i + 1 <<"\n";
        temp[i].xuat();
    }
    delete[] temp;
}


