// problem solving using recursion [Arrays]
#include <bits/stdc++.h>
using namespace std;

// check if the array is sorted or not
bool check(int arr[], int n){
    if(n==1 || n==0) return true;
    if(arr[0] > arr[1]) return false;
    else return check(arr+1, n-1);
}

// get the sum of the elements of the array
int getSum(int arr[], int n){
    if(n == 0) return 0;
    return arr[0] + getSum(arr+1, n-1);
}

// linear search
bool linearSearch(int arr[], int n, int key){
    if(n==0) return arr[0]==key;
    if(arr[0] == key) return true;
    return linearSearch(arr+1,n-1, key);
}

// binary search -> array must be sorted!!
bool binarySearch(int arr[], int start, int end, int key){
    if(start > end) return false;
    int mid = (start+end)/2;
    if(arr[mid] == key) return true;
    if(arr[mid] > key) binarySearch(arr, start, mid, key);
    return binarySearch(arr, mid+1, end, key);
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool ans = check(arr, n);
    cout<<ans<<endl;
    cout<<getSum(arr,n)<<endl;
    int key = 5;
    ans = linearSearch(arr, n, key);
    cout<<ans<<endl;
    ans = binarySearch(arr, 0, n-1, key);
    cout<<ans<<endl;
}