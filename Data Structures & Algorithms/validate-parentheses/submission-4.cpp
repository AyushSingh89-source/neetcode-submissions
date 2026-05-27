class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        
        for (int i = 0; i < s.size(); i++) {
            // 1. Corrected the multi-comparison syntax
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } 
            // 2. Added !st.empty() to prevent runtime crashes on empty stacks
            else if (!st.empty() && (
                (s[i] == ')' && st.top() == '(') || 
                (s[i] == ']' && st.top() == '[') || 
                (s[i] == '}' && st.top() == '{')
            )) {
                st.pop(); 
            } 
            // If it's a closing bracket that doesn't match the top, it's invalid
            else {
                return false; 
            }
        }
        
        // 3. Changed 'return true;' to check if any unmatched brackets remain
        return st.empty(); 
    }
};