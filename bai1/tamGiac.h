#ifndef TRIANGLE_H
#define TRIANGLE_H
#define db double
#include <iostream>
#include <cmath>

using namespace std;

class cDiem {
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
    void quay(db goc_do); 
};

class cTamGiac {
private:
    cDiem A, B, C;
public:
    cTamGiac();
    void nhap();
    void xuat();
    int checkTriangleType();
    db chuVi();
    db dienTich();
    void tinhTien(db dx, db dy);
    void quay(db goc_do);
    void phongTo(db zoomIn);
    void thuNho(db zoomOut);
};
#endif