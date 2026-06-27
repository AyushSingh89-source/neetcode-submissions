class Solution {
public:
    string getLetters(char digit){
        if(digit == '2') return "abc";
        if(digit == '3') return "def";
        if(digit == '4') return "ghi";
        if(digit == '5') return "jkl";
        if(digit == '6') return "mno";
        if(digit == '7') return "pqrs";
        if(digit == '8') return "tuv";
        if(digit == '9') return "wxyz";
        return "";
    }

    vector<string> result;

    void backTrack(string digits, string temp, int index){
        if(index == digits.size()){
            result.push_back(temp);
            return;
        }
        string letters = getLetters(digits[index]);
        for(int j=0; j<letters.size(); j++){
            temp += letters[j];
            backTrack(digits, temp, index+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        backTrack(digits, "", 0);
        return result;
    }
};