// problem solving using recursion [Subsets & Subsequences]
#include <bits/stdc++.h>
using namespace std;

// Generate power set 
void solve(vector<int> nums, vector<int> op, int idx, vector<vector<int>> &ans){
    if(idx >= nums.size()){
        ans.push_back(op);
        return;
    }
    
    solve(nums, op, idx+1, ans);
    int element = nums[idx];
    op.push_back(element);
    solve(nums,op,idx+1,ans);
    
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> op;
    int idx = 0;
    solve(nums, op, idx, ans);
    return ans;
}


// Subsequences of a string
void solve(string str, int idx, string op, vector<string> &ans){
    if(idx >= str.length()){
        if(op.length()>0) ans.push_back(op);
        return;
    }
    solve(str, idx+1, op, ans);
    char elem = str[idx];
    op.push_back(elem);
    solve(str, idx+1, op, ans);
}
vector<string> subsequences(string str){
	vector<string> ans;
    int idx = 0;
    string op = "";
    solve(str, idx,op, ans);
	return ans;
}


int main() {
    
}
