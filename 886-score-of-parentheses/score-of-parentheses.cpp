class Solution {
public:
    int scoreOfParentheses(string s) {
        int open = 0;
        int score = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                open++;
            }
            else {
                open--;

                if(s[i-1] == '(') {
                    score += (1 << open);
                }
            }
        }

        return score;
    }
};