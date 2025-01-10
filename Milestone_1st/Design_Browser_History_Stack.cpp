#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    stack<string> st;
    stack<string> st2;
    BrowserHistory(string homepage) {
        while(!st.empty()) st.pop();
        while(!st2.empty()) st2.pop();
        st.push(homepage);
    }
    

    void visit(string url) {
       st.push(url);
       while(!st2.empty()){
            st2.pop();
       }      
    }
    string back(int steps) {
        while(steps-- && st.size() > 1){
            st2.push(st.top());
            st.pop();
        }
        return st.top();
    }
    string forward(int steps) {
        while(steps-- && !st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return st.top();
    }

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */