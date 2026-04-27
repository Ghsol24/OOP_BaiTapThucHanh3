#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void cArray::heapifyTang(int arr[], int n, int i ){
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2 ;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyTang(arr, n, largest);
    }
}
void cArray::heapifyGiam( int arr[], int n, int i) {
       int smallest = i;
       int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyGiam(arr, n, smallest);
    }
}
cArray::cArray( int size) {
    n = size;
    arr = new int[n];
}
cArray::~cArray(){
    if ( arr != nullptr) {
        delete [] arr;
        arr = nullptr;
    }
}
void cArray::taoMangNgauNhien(){
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    } 
}
void cArray::xuat(){
    for ( int i = 0; i < n ; i++){
        if ( i == n -1 ) {
            cout <<arr[i]<<"\n";
        } else {
            cout <<arr[i] <<" ";
        }
    }
}
int cArray::count(int x){
    int ct = 0;
    for ( int i = 0; i < n ; i++){
        if ( arr[i] == x) {
            ct++;
        }
    }
    return ct;
}
bool cArray::kiemTraTangDan(){
    for ( int i = 1 ; i < n ; i++){
        if (arr[i-1] > arr[i]){
            return false;
        }
    }
    return true;
}
int cArray::timLeNhoNhat(){
    int temp = INT_MAX;
    for (int i = 0 ; i < n ; i++){
        if ( arr[i] % 2 != 0 && arr[i] < temp){
            temp = arr[i];
        }
    }
    if ( temp == INT_MAX){
        return -1;
    } else {
        return temp;
    }
}
int cArray::SNTLonNhat(){
    int max = -1;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        if (x >= 2) {
            bool isPrime = true;
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime && x > max) {
                max = x;
            }
        }
    }
    if (max == -1) {
        return -1;
    } else {
        return max;
    }
}
void cArray::sapXepTangDan(){
    for ( int i = n/2 -1  ; i >= 0 ; i--){
        heapifyTang(arr, n, i);
    }
    for ( int i = n -1 ; i > 0 ; i--){
        swap(arr[0], arr[i]);
        heapifyTang(arr, i, 0);
    }
}
void cArray::sapXepGiamDan(){
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyGiam(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyGiam(arr, i, 0);
    }
}