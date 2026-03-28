/*
 * Problem  : 729. My Calendar I
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Design, Segment Tree, Ordered Set
 * URL      : https://leetcode.com/problems/my-calendar-i/
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
class MyCalendar {
public:
    vector<Event> booking;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto e:booking){
            if(overlap(e,start,end)){
                return false;
            }
        }
        booking.push_back(Event(start,end));
        return true;
    }
    bool overlap(Event e, int start, int end){
        return max(e.start,start)<min(e.end,end);
    }
    Event getOverlap(Event e, int start, int end){
        return Event(max(e.start,start), min(e.end,end));
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */