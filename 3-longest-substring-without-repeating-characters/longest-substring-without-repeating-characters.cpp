class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        int low = 0;
        int res = 0;

        unordered_map<char, int> mp;

        for (int high = 0; high < n; high++) {

            mp[s[high]]++;

            while (mp[s[high]] > 1) {

                mp[s[low]]--;

                if (mp[s[low]] == 0) {
                    mp.erase(s[low]);
                }

                low++;
            }

            int len = high - low + 1;

            res = max(res, len);
        }

        return res;
    }
};