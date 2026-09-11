class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                                vector<int>& newInterval) {

        vector<vector<int>> temp;
        bool inserted = false;

        for (auto interval : intervals) {

            if (!inserted && newInterval[0] <= interval[0]) {
                temp.push_back(newInterval);
                inserted = true;
            }

            temp.push_back(interval);
        }

        if (!inserted) {
            temp.push_back(newInterval);
        }

        // LC 56 merge
        vector<vector<int>> ans;

        for (auto interval : temp) {

            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            }
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};