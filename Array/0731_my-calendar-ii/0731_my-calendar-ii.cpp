/*
 * Problem  : 731. My Calendar II
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Design, Segment Tree, Prefix Sum, Ordered Set
 * URL      : https://leetcode.com/problems/my-calendar-ii/
 */

class Event{
    public:
    int start;
    int end;
    
    Event(int start, int end){
        this->start=start;
        this->end=end;
    }
};

class MyCalendarTwo {
public:
vector<Event> overlapBooking;
vector<Event> booking;

    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        for(auto e: overlapBooking){
            if(overlap(e, start, end)){
                return false;
            }
        }
        for(auto e:booking){
            if(overlap(e,start, end)){
                overlapBooking.push_back(getOverlap(e,start,end));
            }
        }
        booking.push_back(Event(start,end));
        return true;
    }
    bool overlap(Event e, int start, int end){
        return max(e.start, start)<min(e.end,end);
    }
    Event getOverlap(Event e, int start, int end){
        return Event(max(e.start, start), min(e.end, end));
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */