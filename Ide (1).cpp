// problem solving using recursion [Phone Keypad problem]
#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string op, int idx, vector<string> &ans, string mapping[]){
    if(idx >= digits.length()){
        ans.push_back(op);
        return;
    }
    int number = digits[idx]-'0';
    string val = mapping[number];
    
    for(int i = 0; i < val.length(); i++){
        op.push_back(val[i]);
        solve(digits, op, idx+1, ans, mapping);
        op.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() == 0) return ans;
    string op = "";
    int idx = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv","wxyz"};
    solve(digits, op, idx, ans, mapping);
    return ans;
}

int main() {
    
}