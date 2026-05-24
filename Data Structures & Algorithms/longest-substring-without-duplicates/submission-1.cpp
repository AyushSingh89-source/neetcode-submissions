class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool> check(128,0);

        int maxLength = 0;
        int l = 0;

        for(int i= 0;i < n;i++){
            while(check[s[i]] == 1){
                check[s[l]] = 0;
                l++;
            }

            check[s[i]] = 1;

            maxLength = max(maxLength,i - l + 1 );
        }
        return maxLength;
    }
};
