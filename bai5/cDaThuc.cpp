#include "cDaThuc.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

cDaThuc::cDaThuc(){
    n = 0;
    heSo = nullptr;
}
cDaThuc& cDaThuc::operator=(const cDaThuc& khac) {
    // 1. Chặn lỗi tự gán (Ví dụ: tmp1 = tmp1)
    if (this == &khac) {
        return *this; 
    }
    // 2. Dọn rác ở nhà cũ (Giống hệt tư duy trong hàm nhap() của bạn)
    if (heSo != nullptr) {
        delete[] heSo;
    }
    // 3. Xây nhà mới với kích thước của thằng 'khac'
    n = khac.n;
    heSo = new double[n + 1];
    // 4. Chép tay từng món đồ (hệ số) sang nhà mới
    // Viết 1 vòng lặp for từ 0 đến n, gán heSo[i] = khac.heSo[i]
    // 5. Trả về chính nó
    return *this;
}
cDaThuc::cDaThuc(int bac) {
    // 1. Gán bậc mà người dùng muốn khởi tạo vào biến 'n' của class
    n = bac; 
    // 2. Xin hệ điều hành cấp phát một mảng động gồm (n + 1) phần tử.
    // Ví dụ: n = 2 thì xin 3 ô nhớ để chứa hệ số của x^0, x^1, x^2.
    heSo = new double[n+1]; 
    // 3. Vòng lặp đi qua từng ô nhớ vừa xin được
    for (int i = 0; i <= n; i++) {
        // Khởi tạo hệ số bằng 0.0 để "lau chùi" sạch sẽ, tránh bị dính giá trị rác của RAM
        heSo[i] = 0.0; 
    }
    // Sau vòng for, ta sẽ có 0x^n + 0x^(n-1) + ...
}

cDaThuc::~cDaThuc() {
    // Hàm này tự động chạy khi vòng đời của đa thức kết thúc (ví dụ: chạy xong hàm main).
    // Nhiệm vụ: Đem trả lại toàn bộ mảng 'heSo' cho hệ điều hành, chống rò rỉ bộ nhớ.
    delete[] heSo; 
}
void cDaThuc::nhap() {
    cout << "Hãy nhập bậc của đa thức : \n";
    cin >> n;
    if (heSo != nullptr) {
        delete[] heSo;
    }
    heSo = new double [n + 1];
    cout << "Hay nhap cac he so...\n";
    for (int i = 0; i <= n; i++) {
        cin >> heSo[i];
    }
}
void cDaThuc::xuat(){
    cout << "Đa thức : ";
    bool first = true;
    for (int i = n; i >= 0; i--) {
        if (heSo[i] == 0) continue;
        // dấu
        if (!first) {
            cout << (heSo[i] > 0 ? " + " : " - ");
        } else {
            if (heSo[i] < 0) cout << "-";
            first = false;
        }
        double a = abs(heSo[i]);
        if (i == 0) {
            cout << a;
        } else {
            cout << (a == 1 ? "" : to_string(a)) << "x";
            if (i > 1) cout << "^" << i;
        }
    }
    cout << "\n";
}
double cDaThuc::tinhGiaTri(double x){
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += heSo[i] * pow(x, i);
    }
    return sum;
}
    // Cộng đa thức
cDaThuc cDaThuc::cong(const cDaThuc &b) {
    int bacMax = max(n, b.n);
    cDaThuc result(bacMax);
    for (int i = 0; i <= bacMax; i++) {
        double a1 = (i <= n) ? heSo[i] : 0;
        double a2 = (i <= b.n) ? b.heSo[i] : 0;
        result.heSo[i] = a1 + a2;
    }
    return result;
}
    // Trừ đa thức
cDaThuc cDaThuc::tru(const cDaThuc &b) {
    int bacMax = max(n, b.n);
    cDaThuc result(bacMax);
    for (int i = 0; i <= bacMax; i++) {
        double a1 = (i <= n) ? heSo[i] : 0;
        double a2 = (i <= b.n) ? b.heSo[i] : 0;
        result.heSo[i] = a1 - a2;
    }
    return result;
}
