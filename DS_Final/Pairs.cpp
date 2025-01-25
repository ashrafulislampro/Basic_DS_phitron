#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int val;
    Student(string name, int val)
    {
        this->name = name;
        this->val = val;
    }
};

bool cmp(Student l, Student r){
    if(l.name < r.name){
        return true;
    }else if(l.name > r.name){
        return false;
    }else{
        return l.val > r.val;
    }
}
int main()
{
    
    vector<Student> vec;
    string name;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> num;
        Student obj(name, num);
        vec.push_back(obj);
        
    }
    sort(vec.begin(), vec.end(), cmp);
    int len = vec.size();

    for(int i = 0; i < len; i++){
        Student parent = vec[i];
        cout<<parent.name <<" "<<parent.val<<endl;
    }
    

    return 0;
}