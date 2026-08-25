class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int x = nums[i];

            int tempMax = currMax;

            currMax = max({x, currMax * x, currMin * x});

            currMin = min({x, tempMax * x, currMin * x});

            ans = max(ans, currMax);
        }

        return ans;
    }
};
