class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        int low = 0;
        int res = 0;
        int maxFreq = 0;

        unordered_map<char, int> mp;

        for (int high = 0; high < n; high++) {

            mp[s[high]]++;

            maxFreq = max(maxFreq, mp[s[high]]);

            while ((high - low + 1) - maxFreq > k) {

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