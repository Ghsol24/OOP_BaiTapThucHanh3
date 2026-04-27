#include <iostream>
#include "tamGiac.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cTamGiac kc;
    kc.nhap();
    
    cout << "\nToạ độ tam giác vừa nhập:\n";
    kc.xuat();

    cout << "\nChu vi của tam giác là: " << kc.chuVi() << "\n";
    cout << "Diện tích của tam giác là: " << kc.dienTich() << "\n";

    int ltg = kc.checkTriangleType();
    cout << "Loại tam giác: ";
    if (ltg == 1) cout << "Tam Giác Vuông\n";
    else if (ltg == 2) cout << "Tam giác Cân\n";
    else if (ltg == 3) cout << "Tam giác Vuông Cân\n";
    else if (ltg == 4) cout << "Tam giác Đều\n";
    else if (ltg == 5) cout << "Tam giác Thường\n";
    else cout << "Không phải tam giác hợp lệ\n";

    cout << "\n";
    db tinhx, tinhy;
    cout << "Tiến hành tịnh tiến tam giác với x là: ";
    cin >> tinhx;
    cout << "với y là: ";
    cin >> tinhy;
    kc.tinhTien(tinhx, tinhy);
    cout << "Toạ độ tam giác sau khi tịnh tiến là:\n";
    kc.xuat();

    cout << "\n";
    db angl; 
    cout << "Tiến hành quay tam giác quanh trục toạ độ 1 góc (Độ) là: ";
    cin >> angl;
    kc.quay(angl);
    cout << "Toạ độ tam giác sau khi quay là:\n";
    kc.xuat();
    cout << "\n";
    cout << "Tiến hành phóng to tam giác với hệ số zoom là: ";
    db zoomIn; cin >> zoomIn;
    kc.phongTo(zoomIn);
    cout << "Toạ độ tam giác sau khi phóng to là:\n";
    kc.xuat();
    cout << "\n";
    cout << "Tiến hành thu nhỏ tam giác với hệ số zoom là: ";
    db zoomOut; cin >> zoomOut;
    kc.thuNho(zoomOut);
    cout << "Toạ độ tam giác sau khi thu nhỏ là:\n";
    kc.xuat();
    cout << "\n";
    cout << "\nKết thúc!\n";
    return 0;
}