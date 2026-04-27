#pragma once
#include <iostream>
#include <string>
using namespace std;

struct date{ // quản lý ngày tháng năm sinh của nhân viên
    int ngay;
    int thang;
    int nam;
    char tmp1, tmp2;
};
class cNhanVienSX{
    private:
        string maNV;
        string hoTen;
        date ngaySinh;
        int soSP;
        int donGia;
    public:
    // constructor
        cNhanVienSX();
        cNhanVienSX(string maNV, string hoTen, date ngaySinh, int soSP, int donGia);
        ~cNhanVienSX();
    // hàm set
        void setmaNV(string maNV);
        void sethoTen(string hoTen);
        void setqlyNgaySinh(date ngaySinh);
        void setsoSP(int soSP);
        void setdonGia(int donGia);
    // hàm get
        string getmaNV();
        string gethoTen();
        int getSP();
        date getNgaySinh();
        int getDonGia();
    // các hàm thao tác chínhß
        void nhap();
        void xuat(); // xuất nv
        int tinhLuong();
};
class cQuanLy{
    private: 
        int n; // nhập số lượng nhân viên
        cNhanVienSX* dsNV;
    public:
    //constructor
        cQuanLy();
        ~cQuanLy();
    // thao tác chính
        void nhapDS();
        void xuatDS(); // xuất dsnv
        void NVLuongThap();
        long long sumLuong();
        void NVTuoiCao();
        void xuatDSLuongTangDan();

};      