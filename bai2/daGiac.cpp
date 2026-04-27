#include "daGiac.h"
cDiem::cDiem(){
    x = 0 ;
    y = 0;
}
void cDiem::nhap(){
    cin >> x >> y;
}
void cDiem::xuat(){
    cout <<"("<< x << ", " << y <<")";
}
db cDiem::getX(){ return x; }
db cDiem::getY(){ return y; }
db cDiem::distance(cDiem p){
    return sqrt((p.getX()-x)*(p.getX()-x)+(p.getY()-y)*(p.getY()-y));
}
void cDiem::tinhTien ( db dx, db dy) { 
    x+= dx;
    y+= dy;
}
void cDiem::quay(db goc){
    db PI = acos(-1.0); 
    db goc_radian = goc * PI / 180.0; 
    db x_moi = x * cos(goc_radian) - y * sin(goc_radian);
    db y_moi = x * sin(goc_radian) + y * cos(goc_radian);
    x = x_moi;
    y = y_moi;
}
cDaGiac::cDaGiac(){ n = 0; }
void cDaGiac::nhap(){
    do {
        cout<<"Nhập số lượng đỉnh của đa giác( phải >= 3 ): ";
        cin >>n;
        if ( n < 3 ) cout <<"Vui lòng nhập lại đi.\n"; 
    } while ( n < 3 );
    for ( int i = 0 ; i < n ; i++){
        cout <<"Nhập toạ độ đỉnh thứ " << i+1 <<"\n";
        cDiem temp;
        temp.nhap();
        dsDinh.push_back(temp);
    }
}
void cDaGiac::xuat(){
    cout <<"Toạ độ các điểm là : " <<"\n";
    for ( int i = 0; i < n ; i++){
        cout <<"Đỉnh thứ " << i <<" : ";
        dsDinh[i].xuat();
        cout <<"\n";
    }
}
db cDaGiac::chuVi(){
    db cv = 0;
    for ( int i = 0 ; i < n ;i++){
        if ( i == n - 1 ) {
            cv += dsDinh[i].distance(dsDinh[0]);
        } else {
            cv += dsDinh[i].distance(dsDinh[i+1]);
        }
    }
    return cv;
}
db cDaGiac::dienTich(){
    db dt = 0 ;
    for ( int i = 0; i < n ; i++){
        if ( i == n -1 ){
            dt += (dsDinh[i].getX()* dsDinh[0].getY()) - (dsDinh[0].getX() * dsDinh[i].getY());
        } else {
            dt += (dsDinh[i].getX() * dsDinh[i+1].getY()) - (dsDinh[i+1].getX() * dsDinh[i].getY());
        }
    }
    return abs(dt) / 2.0;
}
void cDaGiac::tinhTien(db dx, db dy){
    for ( int i = 0 ; i< n ; i++){
        dsDinh[i].tinhTien(dx, dy);
    }
}
void cDaGiac::quay(db goc){
    for ( int i = 0 ; i < n ; i++){
        dsDinh[i].quay(goc);
    }
}
void cDaGiac::phongTo(db k) {
    for (int i = 0; i < n; i++) {
        dsDinh[i].tinhTien(dsDinh[i].getX() * (k - 1), dsDinh[i].getY() * (k - 1));
    }
}

void cDaGiac::thuNho(db k) {
    for (int i = 0; i < n; i++) {
        dsDinh[i].tinhTien(dsDinh[i].getX() * (1.0 / k - 1), dsDinh[i].getY() * (1.0 / k - 1));
    }
}