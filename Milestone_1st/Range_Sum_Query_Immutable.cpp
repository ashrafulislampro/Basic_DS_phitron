#include <bits/stdc++.h>
using namespace std;

class NumArray
{
public:
    vector<int> arr;
    NumArray(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
            this->arr.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        if(left == 0){
            return arr[right];
        }
        return (arr[right] - arr[left-1]);
    }
};

int main()
{
    vector<int> arr = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(arr);
    int res = obj->sumRange(2, 5);
    cout << res << endl;

    return 0;
}