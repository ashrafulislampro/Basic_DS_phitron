#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            getPerms(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums;
    int n, val;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>val;
        nums.push_back(val);
    }
    vector<vector<int>> result = obj.permute(nums);
    for(const auto& prem: result){
        for(int vl: prem){
            cout<<vl<<" ";
        }
        cout<<endl;
    }
    return 0;
}