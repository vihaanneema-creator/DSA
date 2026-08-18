class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (totalLen > n) {
            return ans;
        }

        unordered_map<string, int> mp;

        for (string &word : words) {
            mp[word]++;
        }

        for (int start = 0; start < wordLen; start++) {

            int low = start;
            int count = 0;

            unordered_map<string, int> window;

            for (int high = start; high + wordLen <= n; high += wordLen) {

                string word = s.substr(high, wordLen);

                if (mp.find(word) == mp.end()) {
                    window.clear();
                    count = 0;
                    low = high + wordLen;
                    continue;
                }

                window[word]++;
                count++;

                while (window[word] > mp[word]) {
                    string leftWord = s.substr(low, wordLen);

                    window[leftWord]--;
                    low += wordLen;
                    count--;
                }

                if (count == wordCount) {
                    ans.push_back(low);
                }
            }
        }

        return ans;
    }
};