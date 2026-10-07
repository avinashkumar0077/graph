class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int i, int leftRemove, int rightRemove,
               int balance, string current) {

        if (i == s.length()) {
            if (leftRemove == 0 &&
                rightRemove == 0 &&
                balance == 0) {
                ans.insert(current);
            }
            return;
        }

        char c = s[i];

        // '('
        if (c == '(') {

            // Remove '('
            if (leftRemove > 0) {
                solve(s, i + 1,
                      leftRemove - 1,
                      rightRemove,
                      balance,
                      current);
            }

            // Keep '('
            solve(s, i + 1,
                  leftRemove,
                  rightRemove,
                  balance + 1,
                  current + c);
        }

        // ')'
        else if (c == ')') {

            // Remove ')'
            if (rightRemove > 0) {
                solve(s, i + 1,
                      leftRemove,
                      rightRemove - 1,
                      balance,
                      current);
            }

            // Keep ')' only if there is an opening '('
            if (balance > 0) {
                solve(s, i + 1,
                      leftRemove,
                      rightRemove,
                      balance - 1,
                      current + c);
            }
        }

        // Letter
        else {
            solve(s, i + 1,
                  leftRemove,
                  rightRemove,
                  balance,
                  current + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for (char c : s) {

            if (c == '(') {
                balance++;
            }
            else if (c == ')') {

                if (balance > 0)
                    balance--;
                else
                    rightRemove++;
            }
        }

        leftRemove = balance;

        solve(s, 0,
              leftRemove,
              rightRemove,
              0,
              "");

        return vector<string>(ans.begin(), ans.end());
    }
};