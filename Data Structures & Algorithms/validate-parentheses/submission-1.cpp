class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char chr:s){
            if(chr=='(' || chr=='[' || chr=='{'){
                st.push(chr);
            } else if(st.empty()) return false;
            else if (chr==')' && st.top()=='('){
                st.pop();
            } else if (chr==']' && st.top()=='['){
                st.pop();
            } else if (chr=='}' && st.top()=='{'){
                st.pop();
            } else return false;
        }
        return st.empty();
    }
};
