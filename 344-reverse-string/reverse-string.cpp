class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            st.push(s[i]);
        }

        int i = 0;
        while (!st.empty()) {
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
};