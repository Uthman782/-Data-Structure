// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int linear(int arr[], int size, int ele) {
    for (int i = 0;i < size;i++) {
        if (arr[i] == ele) {
            return 1;
        }
    }
    return 0;
}
int binary(int arr[], int size, int ele) {
    int low(0), high(size - 1),mid;
    while(low<=high){
    mid = (low + high) / 2;
    if (arr[mid] == ele) {
        return mid;
    }
    if (arr[mid] < ele) {
        low = mid + 1;
    }
    else {
        high = mid - 1;
    }
    }
    return 0;
}
int main()
{
    int arr[] = { 6,4,7,9,4,0,3,1 };
    int size = sizeof(arr) / sizeof(int);
    if (linear(arr, size, 9)) {
        cout << "Yes Found!";
    }
    else {
        cout << "Not Found!";
    }
    cout << endl;
    int arr1[] = { 1,2,3,4,5,6,7,8,9};
    size = sizeof(arr1) / sizeof(int);
    cout<<binary(arr1, size, 1);
    return 0;
}
