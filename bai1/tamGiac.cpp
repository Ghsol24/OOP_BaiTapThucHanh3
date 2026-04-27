#include "tamGiac.h"
cDiem::cDiem() {
    x = 0; y = 0;
}
void cDiem::nhap() {
    cin >> x >> y;
}
void cDiem::xuat() {
    cout << "(" << x << ", " << y << ")";
}

db cDiem::getX() { return x; }
db cDiem::getY() { return y; }
db cDiem::distance(cDiem p) {
    return sqrt((p.getX() - x) * (p.getX() - x) + (p.getY() - y) * (p.getY() - y));
}
void cDiem::tinhTien(db dx, db dy) {
    x += dx;
    y += dy;
}
void cDiem::quay(db goc_do) {
    db PI = acos(-1.0);
    db goc_radian = goc_do * PI / 180.0; // Chuyển Độ sang Radian
    db x_moi = x * cos(goc_radian) - y * sin(goc_radian);
    db y_moi = x * sin(goc_radian) + y * cos(goc_radian);
    x = x_moi;
    y = y_moi;
}
cTamGiac::cTamGiac() {}

void cTamGiac::nhap() {
    cout << "Nhập toạ độ đỉnh A (x, y): "; A.nhap();
    cout << "Nhập toạ độ đỉnh B (x, y): "; B.nhap();
    cout << "Nhập toạ độ đỉnh C (x, y): "; C.nhap();
}

void cTamGiac::xuat() {
    A.xuat(); cout << " - ";
    B.xuat(); cout << " - ";
    C.xuat(); cout << "\n";
}

int cTamGiac::checkTriangleType() {
    db AB = A.distance(B);
    db BC = B.distance(C);
    db CA = C.distance(A);
    
    if (AB + BC <= CA || AB + CA <= BC || BC + CA <= AB) return 0; // Lỗi

    if (AB == BC && BC == CA) return 4; // Đều
    if ((AB == BC || BC == CA || CA == AB) && 
        (abs(AB*AB + BC*BC - CA*CA) < 0.0001 || abs(AB*AB + CA*CA - BC*BC) < 0.0001 || abs(BC*BC + CA*CA - AB*AB) < 0.0001)) return 3; // Vuông cân
    if (AB == BC || BC == CA || CA == AB) return 2; // Cân
    if (abs(AB*AB + BC*BC - CA*CA) < 0.0001 || abs(AB*AB + CA*CA - BC*BC) < 0.0001 || abs(BC*BC + CA*CA - AB*AB) < 0.0001) return 1; // Vuông
    return 5; // Thường
}

db cTamGiac::chuVi() {
    return A.distance(B) + B.distance(C) + C.distance(A);
}
db cTamGiac::dienTich() {
    db AB = A.distance(B);
    db BC = B.distance(C);
    db CA = C.distance(A);
    db p = (AB + BC + CA) / 2.0;
    return sqrt(p * (p - AB) * (p - BC) * (p - CA));
}
void cTamGiac::tinhTien(db dx, db dy) {
    A.tinhTien(dx, dy);
    B.tinhTien(dx, dy);
    C.tinhTien(dx, dy);
}
void cTamGiac::quay(db goc_do) {
    A.quay(goc_do);
    B.quay(goc_do);
    C.quay(goc_do);
}
void cTamGiac::phongTo(db zoomIn){
    A.tinhTien(A.getX() * (zoomIn - 1), A.getY() * (zoomIn - 1));
    B.tinhTien(B.getX() * (zoomIn - 1), B.getY() * (zoomIn - 1));
    C.tinhTien(C.getX() * (zoomIn - 1), C.getY() * (zoomIn - 1));
}
void cTamGiac::thuNho(db zoomOut){
    A.tinhTien(A.getX() * (1.0 / zoomOut - 1), A.getY() * (1.0 / zoomOut - 1));
    B.tinhTien(B.getX() * (1.0 / zoomOut - 1), B.getY() * (1.0 / zoomOut - 1));
    C.tinhTien(C.getX() * (1.0 / zoomOut - 1), C.getY() * (1.0 / zoomOut - 1));
}