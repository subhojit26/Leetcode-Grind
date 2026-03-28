/*
 * Problem  : 154. Find Minimum in Rotated Sorted Array II
 * Difficulty: Hard
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 */

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (arr[mid] < arr[j]) {
                j = mid; // Minimum is in the left part, including mid
            } else if (arr[mid] > arr[j]) {
                i = mid + 1; // Minimum is in the right part, excluding mid
            } else {
                // arr[mid] == arr[j], reduce the search space
                j--;
            }
        }
        return arr[i]; // i points to the minimum
    }
};
