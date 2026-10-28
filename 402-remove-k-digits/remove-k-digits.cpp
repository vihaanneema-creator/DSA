
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.back () > num[i]) {
                st.pop_back();
                k--;
            }

            st.push_back(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        if (st == "") {
            return "0";
        }

        return st;
    }
};
