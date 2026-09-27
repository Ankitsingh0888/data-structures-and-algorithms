class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<string> st;
        st.push("");   // starting string
        
        for (char ch : s) {
            
            if (ch == '(') {
                // Start a new string inside parentheses
                st.push("");
            }
            
            else if (ch == ')') {
                // Get the string inside parentheses
                string temp = st.top();
                st.pop();
                
                // Reverse it
                reverse(temp.begin(), temp.end());
                
                // Add it to the previous string
                st.top() += temp;
            }
            
            else {
                // Normal character
                st.top() += ch;
            }
        }
        
        return st.top();
    }
};