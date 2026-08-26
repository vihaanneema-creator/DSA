class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int currMax = nums[0];
        int maxSum = nums[0];

        int currMin = nums[0];
        int minSum = nums[0];

        for(int i = 0; i < nums.size(); i++) {

            totalSum += nums[i];

            if(i > 0) {
                currMax = max(nums[i], currMax + nums[i]);
                maxSum = max(maxSum, currMax);

                currMin = min(nums[i], currMin + nums[i]);
                minSum = min(minSum, currMin);
            }
        }

        // agar sare no. are negative
        if(maxSum < 0)
            return maxSum;

        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};