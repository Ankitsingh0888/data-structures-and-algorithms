class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            string current = q.front();
            q.pop();

            // If this string is valid,
            // add it to answer.
            if (isValid(current)) {
                ans.push_back(current);
                found = true;
            }

            // We already found valid strings at
            // minimum removal level.
            if (found)
                continue;

            // Try removing each parenthesis once.
            for (int i = 0; i < current.length(); i++) {

                // We only remove parentheses.
                if (current[i] != '(' && current[i] != ')')
                    continue;

                string next = current.substr(0, i)
                            + current.substr(i + 1);

                // Avoid duplicate strings.
                if (visited.find(next) == visited.end()) {

                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};