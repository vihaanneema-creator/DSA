class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = 0;

        int sum = 0;
        int res = INT_MAX;

        while (high < n) {

            sum += nums[high];

            while (sum >= target) {

                int length = high - low + 1;

                res = min(res, length);

                sum -= nums[low];
                low++;
            }

            high++;
        }

        return (res == INT_MAX) ? 0 : res;
    }
};