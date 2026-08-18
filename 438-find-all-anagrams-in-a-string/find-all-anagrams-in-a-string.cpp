class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> ans;

        if (m > n) {
            return ans;
        }

        vector<int> p_freq(26, 0);
        vector<int> s_freq(26, 0);

        int low = 0;
        int high = 0;

        for (char &ch : p) {
            p_freq[ch - 'a']++;
        }

        while (high < n) {

            s_freq[s[high] - 'a']++;

            if (high - low + 1 > m) {
                s_freq[s[low] - 'a']--;
                low++;
            }

            if (p_freq == s_freq) {
                ans.push_back(low);
            }

            high++;
        }

        return ans;
    }
};