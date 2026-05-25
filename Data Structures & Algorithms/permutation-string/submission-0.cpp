class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if(m>n) return false;

        vector<int> s1_counts(26,0);
        vector<int> window_counts(26,0);

        for(int i=0;i<m;i++){
            s1_counts[s1[i]-'a']++;
            window_counts[s2[i]-'a']++;
        }

        if(s1_counts == window_counts) return true;

        for(int i=m;i<n;i++){
            window_counts[s2[i]-'a']++;

            window_counts[s2[i-m]-'a']--;

            if(s1_counts == window_counts) return true;
        }

        return false;
    }
};