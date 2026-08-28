class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int zero = 0;
        int one = 0;
        int ans = 0;

        unordered_map<int, int> mp;

       
        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0)
                zero++;
            else
                one++;

            int diff = one - zero;

            
            if(mp.find(diff) != mp.end()) {

                ans = max(ans, i - mp[diff]);

            }
            else {

                
                mp[diff] = i;
            }
        }

        return ans;
    }
};