class Solution {
private:
    void backtrack(int open, int close, int n, string current, vector<string>& result) {
        
        // Base case
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            backtrack(open + 1, close, n, current + "(", result);
        }

        // Add closing bracket
        if (close < open) {
            backtrack(open, close + 1, n, current + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(0, 0, n, "", result);

        return result;
    }
};