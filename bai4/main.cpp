#include "cArray.h"
#include <cstdlib> 
#include <ctime>
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(NULL));
    cout <<"Nhập số lượng phần tử trong mảng: " <<"\n";
    int n; cin>>n;
    cArray kc(n);
    kc.taoMangNgauNhien();
    cout <<"Mảng được nhập sau khi random là: " <<"\n";
    kc.xuat();
    cout <<"Nhập số x mà bạn muốn tìm số lần nó xuất hiện!!"<<"\n";
    int x; cin>>x;
    cout <<"Số lần số " << x << " xuất hiện là : ";
    cout << kc.count(x) << "\n";
    bool dung = kc.kiemTraTangDan();
    if ( dung == true){
        cout <<"Mảng này là mảng tăng dần ! "<<"\n";
    } else {
        cout <<"Mảng này không là mảng tăng dần ! " <<"\n";
    }
    int sl = kc.timLeNhoNhat();
    if ( sl != -1 ) {
        cout <<"Số lẻ nhỏ nhất trong mảng là số: " << sl <<"\n";
    } else {
        cout <<"Không tìm thấy"<<"\n";
    }
    int snt = kc.SNTLonNhat();
    if ( snt != -1){
        cout <<"Số nguyên tố lớn nhất trong mảng là số: " << snt << "\n";
    } else {
        cout <<"Không tìm thấy! " <<"\n";
    }
    cout <<"\n";
    cout <<"Tiến hành sắp xếp tăng dần mảng với thuật toán HeapSort! " <<"\n";
    kc.sapXepTangDan();
    cout <<"Mảng sau khi sắp xếp tăng dần là: "<<"\n";
    kc.xuat();
    cout<<"\n";
    cout <<"Tiến hành sắp xếp giảm dần mảng với thuật toán HeapSort! " <<"\n";
    kc.sapXepGiamDan();
    cout <<"Mảng sau khi sắp xếp giảm dần là :" <<"\n";
    kc.xuat();
    cout<<"\n";
    cout <<" Kết thúc ! ";
    return 0;
}