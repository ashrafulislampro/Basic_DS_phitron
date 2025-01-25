#include <bits/stdc++.h>
using namespace std;

void insert_into_min_heap(vector<int> &vec, int val)
{
    vec.push_back(val);
    int curr_idx = vec.size() - 1;
    while (curr_idx != 0)
    {
        int par_idx = (curr_idx - 1) / 2;
        if (vec[par_idx] > vec[curr_idx])
        {
            swap(vec[par_idx], vec[curr_idx]);
        }
        else
        {
            break;
        }
        curr_idx = par_idx;
    }
};
void delete_min_val(vector<int> &vec)
{
    if(vec.empty()){
        return;
    }
    vec[0] = vec.back();
    vec.pop_back();
    int curr_idx = 0;
    while (true)
    {
        int left_idx = curr_idx * 2 + 1;
        int right_idx = curr_idx * 2 + 2;

        int left_val = INT_MAX, right_val = INT_MAX;
        int len = vec.size();
        if (left_idx < len)
            left_val = vec[left_idx];
        if (right_idx < len)
            right_val = vec[right_idx];

        if (left_val <= right_val && left_val < vec[curr_idx])
        {
            swap(vec[curr_idx], vec[left_idx]);
            curr_idx = left_idx;
        }
        else if (right_val < left_val && right_val < vec[curr_idx])
        {
            swap(vec[curr_idx], vec[right_idx]);
            curr_idx = right_idx;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int q, n, idx, val;
    cin >> n;
    vector<int> vec;
    
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert_into_min_heap(vec, val);
    }

    cin >> q;
    while (q--)
    {
        cin >> idx;
        if (idx == 0)
        {
            cin >> val;
            insert_into_min_heap(vec, val);
            cout << vec[0] << endl;
        }
        else if (idx == 1)
        {
            int len = vec.size();
            if (len != 0)
            {
                cout << vec[0] << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (idx == 2)
        {
            delete_min_val(vec);
            int len = vec.size();
            if (len != 0)
            {

                cout << vec[0] << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }
    return 0;
}