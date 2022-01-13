// problem solving using recursion [Strings]
#include <bits/stdc++.h>
using namespace std;

// Reverse a string
void reverseString(string &s, int i, int j){
    if(i > j) return;
    swap(s[i], s[j]);
    reverseString(s, ++i, --j);
}

// Check if the string is palindrome or not
bool checkPalindrome(string s, int i, int j){
    if(i>=j) return true;
    if(s[i] != s[j]) return false;
    return checkPalindrome(s,++i,--j);
}

// Bubble Sort 
void bubbleSort(int *arr, int n){
    if(n==0 || n==1) return;
    
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    
    bubbleSort(arr,n-1);
}

// Calculate a power b 
int power(int a, int b){
    if(b==0) return 1;
    if(b%2==0) return power(a,b/2)*power(a,b/2);
    return a*power(a,b/2)*power(a,b/2);
}

int main() {
    string s = "tattarrattat";
    int n = s.length();
    
    reverseString(s,0,n-1);
    cout<<"reversed string => "<<s<<endl;
    
    if(checkPalindrome(s, 0, n-1)){
        cout<<"It's a palindrome\n";
    }
    else cout<<"No not a palindrome\n";
    
    cout<<power(3,11)<<endl;
    
    int arr[5] = {2,3,1,5,4};
    bubbleSort(arr,5);
    for(int i = 0; i < 5; i++) cout<<arr[i]<<" ";
}