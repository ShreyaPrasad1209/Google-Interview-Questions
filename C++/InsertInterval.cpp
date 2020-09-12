class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t i = 0;
        
        // Left part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        
        // newInterval part (with or without merge)
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        
        // Right part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][0] > newInterval[1]) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};

//LeetCode Link: https://leetcode.com/problems/insert-interval/
//Runtime: 32 ms O(N)
