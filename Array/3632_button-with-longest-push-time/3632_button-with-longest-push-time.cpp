/*
 * Problem  : 3632. Button with Longest Push Time
 * Difficulty: Easy
 * Topics   : Array
 * URL      : https://leetcode.com/problems/button-with-longest-push-time/
 */

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int max_duration = events[0][1]; 
    int button_index = events[0][0]; 

    for (size_t i = 1; i < events.size(); ++i) {
        int duration = events[i][1] - events[i - 1][1];

        if (duration > max_duration || (duration == max_duration && events[i][0] < button_index)) {
            max_duration = duration;
            button_index = events[i][0];
        }
    }

    return button_index;
    }
};