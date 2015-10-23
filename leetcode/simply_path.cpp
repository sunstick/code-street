/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        path += "/";
        bool inword = false;
        int start = 0;
        int length = 0;

        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/') {
                if (inword) {
                    string str = path.substr(start, length);
                    if (str == "..") {
                        if (!st.empty())
                            st.pop_back();
                    } else if (str != ".")
                        st.push_back(str);
                }
                inword = false;
            } else {
                if (!inword) {
                    start = i;
                    length = 1;
                } else {
                    length++;
                }
                inword = true;
            }
            i++;
        }
        if (st.empty()) return "/";
        string res = "";
        for (i = 0; i < st.size(); i++)
            res += "/" + st[i];
        return res;
    }
};