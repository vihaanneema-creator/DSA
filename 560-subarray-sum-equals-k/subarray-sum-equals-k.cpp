class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int Sum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            Sum += nums[i];

            int needed = Sum - k;

            if(mp.find(needed) != mp.end()) {
                ans += mp[needed];
            }

            mp[Sum]++;
        }

        return ans;
    }
};