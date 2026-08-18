class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int res = 0;
        int zeros = 0;

        for(int high=0; high<n;high++){
            

            if(nums[high]==0){
                zeros++;
            }
            while(zeros>k){
                if (nums[low] == 0) 
                { zeros--;
                
                }
                low++;
            } int len = high - low + 1;

            res = max(res, len);
        }

        return res;
    }
};
