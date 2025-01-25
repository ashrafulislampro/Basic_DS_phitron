#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

void insert_into_heap(vector<Student> &vec, Student obj)
{
    vec.push_back(obj);
    int curr_idx = vec.size() - 1;
    while (curr_idx != 0)
    {
        int par_idx = (curr_idx - 1) / 2;

        if ((vec[curr_idx].marks > vec[par_idx].marks) || (vec[curr_idx].marks == vec[par_idx].marks && vec[curr_idx].roll < vec[par_idx].roll))
        {
            swap(vec[par_idx], vec[curr_idx]);
            curr_idx = par_idx;
        }
        else
        {
            break;
        }
    }
}

void delete_into_max(vector<Student> &vec)
{
    if (vec.empty())
    {
        return;
    }
    // cout << vec[0].name << " " << vec[0].roll << " " << vec[0].marks << endl;
    vec[0] = vec.back();
    vec.pop_back();
    int curr_idx = 0;
    while (true)
    {
        int left_idx = (curr_idx * 2) + 1;
        int right_idx = (curr_idx * 2) + 2;

        int par_idx = curr_idx;

        int len = vec.size();
        if (left_idx < len && vec[left_idx].marks > vec[par_idx].marks)
        {
            par_idx = left_idx;
        }
        if (right_idx < len && vec[right_idx].marks > vec[par_idx].marks)
        {
            par_idx = right_idx;
        }

        if (left_idx < len && vec[left_idx].marks == vec[par_idx].marks && vec[left_idx].roll < vec[par_idx].roll)
        {
            par_idx = left_idx;
        }
        if (right_idx < len && vec[right_idx].marks == vec[par_idx].marks && vec[right_idx].roll < vec[par_idx].roll)
        {
            par_idx = right_idx;
        }

        if (par_idx == curr_idx)
        {
            break;
        }

        swap(vec[curr_idx], vec[par_idx]);
        curr_idx = par_idx;
    }
}

void print_info(vector<Student> &v)
{
    cout << v[0].name << " " << v[0].roll << " " << v[0].marks << endl;
    return;
}
int main()
{
    string name;
    int n, roll, marks;
    cin >> n;
    vector<Student> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        insert_into_heap(vec, obj);
    }

    int q, idx;
    cin >> q;
    while (q--)
    {
        cin >> idx;
        if (idx == 0)
        {
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            insert_into_heap(vec, obj);
            print_info(vec);
        }
        else if (idx == 1)
        {
            int len = vec.size();
            if (len != 0)
            {
                print_info(vec);
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if (idx == 2)
        {
            delete_into_max(vec);
            int len = vec.size();
            if (len != 0)
            {
                print_info(vec);
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }
    return 0;
}