class Solution {
public:
    string decodeString(string s) {
        stack<int > numStack;
        stack <string> strStack;

        string currString = "";
        int currNum = 0;

        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                currNum = currNum*10 +(s[i] - '0');
            }
            else if (s[i] == '['){
                numStack.push(currNum);
                strStack.push(currString);

                currNum = 0;
                currString = "";
            }
            else if(s[i] == ']'){
                int repeat = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                string temp = "";

                for(int j=0;j<repeat;j++){
                    temp += currString;
                }

                currString = prev + temp;
            }
            else{
                currString += s[i];
            }
        }
        return currString;
    }
};