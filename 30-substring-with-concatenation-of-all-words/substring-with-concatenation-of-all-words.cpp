class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();

        unordered_map<string, int> mp;

        // Required frequency
        for (string word : words) {
            mp[word]++;
        }

        // Try every possible alignment
        for (int i = 0; i < wordLen; i++) {

            int left = i;
            int count = 0;

            unordered_map<string, int> seen;

            for (int right = i;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not present in words
                if (mp.find(word) == mp.end()) {

                    seen.clear();
                    count = 0;
                    left = right + wordLen;

                }
                else {

                    seen[word]++;
                    count++;

                    // Too many copies of this word
                    while (seen[word] > mp[word]) {

                        string leftWord =
                            s.substr(left, wordLen);

                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Complete concatenation found
                    if (count == wordCount) {
                        ans.push_back(left);
                    }
                }
            }
        }

        return ans;
    }
};