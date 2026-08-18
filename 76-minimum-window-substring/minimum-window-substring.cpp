class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for (char c : t) {
            mp[c]++;
        }

        int low = 0;
        int count = t.size();

        int start = 0;
        int minLen = INT_MAX;

        for (int high = 0; high < s.size(); high++) {

            if (mp[s[high]] > 0) {
                count--;
            }

            mp[s[high]]--;

            while (count == 0) {

                int len = high - low + 1;

                if (len < minLen) {
                    minLen = len;
                    start = low;
                }

                mp[s[low]]++;

                if (mp[s[low]] > 0) {
                    count++;
                }

                low++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};