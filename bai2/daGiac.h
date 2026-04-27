#ifndef DAGIAC_H
#define DAGIAC_H
#define db double
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class cDiem{
    private: 
        db x, y;
    public: 
        cDiem();
        void nhap();
        void xuat();
        db getX();
        db getY();
        db distance(cDiem p);
        void tinhTien(db dx, db dy);
        void quay(db goc);
};
class cDaGiac{
    private: 
        int n;
        vector<cDiem> dsDinh;
    public:
        cDaGiac();
        void nhap();
        void xuat();
        db chuVi();
        db dienTich();
        void tinhTien(db dx, db dy);
        void quay(db goc);
        void phongTo(db k);
        void thuNho(db k);
};
#endif