class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        int max_freq = 0;
        for(int i=0;i<26;i++){
            if(freq[i]> max_freq) max_freq = freq[i];
        }

        int last_frame = 0;
        for(int i=0;i<26;i++){
            if(freq[i] == max_freq) last_frame ++;
        }

        int formula = (max_freq-1)*(n+1) + last_frame;
        int total = tasks.size();

        return max(formula,total);
    }
};
