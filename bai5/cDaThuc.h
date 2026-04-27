#pragma once
#include <iostream>
class cDaThuc {
private:
    int n; //Lưu bậc
    double* heSo;

public:
    cDaThuc();
    cDaThuc(int bac);
    ~cDaThuc();
    cDaThuc& operator=(const cDaThuc& khac);
    void nhap();
    void xuat();
    double tinhGiaTri(double x);
    cDaThuc cong(const cDaThuc& khac);
    cDaThuc tru(const cDaThuc& khac);
};