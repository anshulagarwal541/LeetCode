class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char> st;
        for(int x=0;x<s.length();x++)
        {
            char ch=s[x];
            if(ch=='(')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                }
                else if(!st.empty() && st.top()!='(')
                {
                    count++;
                }
                else
                {
                    count++;
                }
            }
        }
        count+=st.size();
        return count;
    }
};