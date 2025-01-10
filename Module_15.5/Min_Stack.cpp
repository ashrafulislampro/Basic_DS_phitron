#include <bits/stdc++.h>
using namespace std;
// Implement class for minStack.
class minStack
{
    // Write your code here.

public:
    stack<int> st;
    stack<int> st2;
    // Constructor
    minStack()
    {
        // Write your code here.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        // Write your code here.
        st.push(num);
        if (st2.empty())
        {
            st2.push(num);
        }
        else
        {
            if (num <= st2.top())
            {
                st2.push(num);
            }
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (!st.empty())
        {
            int top_ele = st.top();

            if (top_ele == st2.top())
            {
                st2.pop();
            }
            st.pop();
            return top_ele;
        }
        else
        {
            return -1;
        }
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (!st.empty())
        {
            return st.top();
        }
        else
        {
            return -1;
        }
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (!st2.empty())
        {
            return st2.top();
        }
        else
        {
            return -1;
        }
    }
};