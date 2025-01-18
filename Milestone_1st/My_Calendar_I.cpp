#include <bits/stdc++.h>
using namespace std;
class MyCalendar
{
    map<int, int> intervals;

public:
    MyCalendar()
    {
    }

    bool book(int startTime, int endTime)
    {
        auto it = intervals.upper_bound(startTime);
        if (it == intervals.end() || it->second >= endTime)
        { // no overlap condition
            intervals[endTime] = startTime;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */