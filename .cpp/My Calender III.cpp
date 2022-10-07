/*
Question: https://leetcode.com/problems/my-calendar-iii/
Author: Mohit Radadiya
*/
class MyCalendarThree {
    map<int, int> times;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        times[start]++; 
        times[end]--; 
        int events_on = 0, ans = 0;
        for (pair<int, int> x : times)
            events_on += x.second;
            ans = max(ans, events_on);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
