class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }

            else if (c == ')') {
                low--;
                high--;
            }

            else { // c == '*'
                low--;   // '*' acts as ')'
                high++;  // '*' acts as '('
            }

            // We can never have fewer than 0 unmatched '('
            if (low < 0) {
                low = 0;
            }

            // Even the maximum possibility is negative
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};