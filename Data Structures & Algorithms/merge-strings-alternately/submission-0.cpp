class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i= 1;
        int j =0;
        ans.push_back(word1[0]);
        while(i+j<word1.size()+word2.size()){
            if (i >= word1.size()) {
                ans.push_back(word2[j]);
                j++;
            }
            else if (j >= word2.size()) {
                ans.push_back(word1[i]);
                i++;
            }
            else if(i>j){
                ans.push_back(word2[j]);
                j++;
            }
            else if(i<=j){
                ans.push_back(word1[i]);
                i++;
            }
        }
        return ans;
    }
};