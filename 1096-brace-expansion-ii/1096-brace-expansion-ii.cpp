class Solution {
public:
    set<string> combine(set<string> a, set<string> b) {
        set<string> result;
        for(string x : a) {
            for(string y : b) {
                result.insert(x + y);
            }
        }
        return result;
    }
    set<string> solve(string &s, int &i) {
        set<string> result;
        set<string> current;
        current.insert("");
        while(i < s.size() && s[i] != '}') {
            if(s[i] == ',') {
                for(string x : current)
                    result.insert(x);
                current.clear();
                current.insert("");
                i++;
            }
            else {
                set<string> next;
                if(s[i] == '{') {
                    i++;
                    next = solve(s, i);
                    i++;
                }
                else {
                    string temp = "";
                    temp += s[i];
                    next.insert(temp);
                    i++;
                }
                current = combine(current, next);
            }
        }

        for(string x : current)
            result.insert(x);
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = solve(expression, i);
        return vector<string>(result.begin(), result.end());
    }
};