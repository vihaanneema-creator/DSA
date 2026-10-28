

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string s;

        while (getline(ss, s, '/')) {
            if (s == "" || s == ".") {
                continue;
            }

            if (s == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(s);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans == "") {
            return "/";
        }

        return ans;
    }
};
