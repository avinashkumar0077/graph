class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int open = 0;
        int needed = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    needed++;
                }
            }

            i++;
        }

        return needed + open;
    }
};