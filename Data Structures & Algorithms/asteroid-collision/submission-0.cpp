class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        
        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if (abs(asteroids[i]) > abs(st.top())) {
                    st.pop();
                    continue;
                } 
                else if (abs(asteroids[i]) == abs(st.top())) {
                    st.pop();
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true;
                    break;
                }
            }
            
            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};