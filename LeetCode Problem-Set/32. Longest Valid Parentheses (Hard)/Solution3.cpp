// Problem: https://leetcode.com/problems/longest-valid-parentheses/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && st.top() != -1 && s[st.top()] == '(') {
                st.pop();
                ans = max(ans, i - st.top());
            } else st.push(i);
        }
        return ans;
    }
};
