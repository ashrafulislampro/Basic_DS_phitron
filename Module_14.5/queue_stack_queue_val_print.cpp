#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    stack<int> st;
    queue<int> q2;
    int n, val;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>val;
        q.push(val);
    }
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q2.push(st.top());
        st.pop();
    }
     while(!q2.empty()){
        cout<< q2.front()<<" ";
        q2.pop();
    }
    return 0;
}