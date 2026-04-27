#pragma once
#include <iostream>

class cArray{
    private: 
        int *arr;
        int n;
        void heapifyTang(int arr[], int n, int i);
        void heapifyGiam(int arr[], int n, int i);
    public: 
        cArray(int size);
        ~cArray();
        void taoMangNgauNhien();
        void xuat();
        int count(int x);
        bool kiemTraTangDan();
        int timLeNhoNhat();
        int SNTLonNhat();
        void sapXepTangDan();
        void sapXepGiamDan();
};
