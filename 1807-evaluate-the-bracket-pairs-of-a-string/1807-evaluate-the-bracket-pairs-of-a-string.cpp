class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        map<string, string> mp;

        // Store key -> value
        for (auto x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        int i = 0;

        while (i < s.length()) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
                i++;
            }

            // Bracket starts
            else {
                i++;  // skip '('

                string key = "";

                // Get the key
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Check key in map
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }

                i++;  // skip ')'
            }
        }

        return ans;
    }
};