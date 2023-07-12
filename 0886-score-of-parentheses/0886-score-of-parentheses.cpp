class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int x=0;
        for(char c:s)
        {
            if(c=='(')
            {
                st.push(x);
                x=0;
            }
            else
            {
                if(x==0)
                x=1;
                else{
                   x*=2;
                }
               
                x+=st.top();
                st.pop();
            }
        }
        return x;
    }
};