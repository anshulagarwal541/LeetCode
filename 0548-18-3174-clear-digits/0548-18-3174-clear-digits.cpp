class Solution {
public:
    string clearDigits(string s) {
        deque<char> characters;
        deque<int> numbers;
        for(int x=0;x<s.length();x++)
        {
            if(s[x]>='a' && s[x]<='z')
            {
                characters.push_back(s[x]);
            }
            else if(s[x]>='0' && s[x]<='9')
            {
                characters.pop_back();
            }
        }
        string ans="";
        while(!characters.empty())
        {
            ans+=characters.front();
            characters.pop_front();
        }
        return ans;
    }
};