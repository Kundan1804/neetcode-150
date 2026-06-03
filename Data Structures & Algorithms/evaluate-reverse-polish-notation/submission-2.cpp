class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        for(string s:tokens){
            if(s=="+" || s == "-" || s== "*" || s== "/"){
                int num1=s1.top();
                s1.pop();
                int num2=s1.top();
                s1.pop();
                if (s=="+"){
                    s1.push(num1+num2);
                } else if (s=="-"){
                    s1.push(num2-num1);
                } else if (s=="*"){
                    s1.push(num2*num1);
                } else if (s=="/"){
                    s1.push(num2/num1);
                }
            } else {
                s1.push(stoi(s));
            }
        }
        return s1.top();
    }
};
