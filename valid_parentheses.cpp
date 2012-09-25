class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty()) return false;
                char x = st.top();
                st.pop();
                if (s[i] == ')' && x != '(') return false;
                if (s[i] == ']' && x != '[') return false;
                if (s[i] == '}' && x != '{') return false;
            }
        }

        return st.empty();
    }
};