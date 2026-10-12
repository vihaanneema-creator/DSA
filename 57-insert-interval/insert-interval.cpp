
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> temp;
        bool inserted = false;

        for (int i = 0; i < intervals.size(); i++) {
            if (!inserted && newInterval[0] < intervals[i][0]) {
                temp.push_back(newInterval);
                inserted = true;
            }

            temp.push_back(intervals[i]);
        }

        if (!inserted) {
            temp.push_back(newInterval);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < temp.size(); i++) {
            if (ans.empty() || temp[i][0] > ans.back()[1]) {
                ans.push_back(temp[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], temp[i][1]);
            }
        }

        return ans;
    }
};
