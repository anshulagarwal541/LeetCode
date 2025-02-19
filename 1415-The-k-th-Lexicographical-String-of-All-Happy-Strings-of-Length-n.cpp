class Solution {
public:
    void getStrings(vector<string>& allStrings, string currentString, int& n, int& k, unordered_map<string, int>& mp)
    {
        if(allStrings.size() >= k)
        {
            return;
        }
        if(currentString.length()>n)
        {
            return;
        }
        if(currentString.length() == n)
        {
            if(mp.find(currentString) == mp.end())
            {
                allStrings.push_back(currentString);
                mp[currentString]=1;
            }
            
        }
        for(char ch = 'a'; ch<='c'; ch++)
        {
            if(allStrings.size() == k)
            {
                return;
            }
            if(currentString=="")
            {
                currentString+=ch;
                getStrings(allStrings, currentString, n, k, mp);
                currentString=currentString.substr(0, currentString.length()-1);
            }
            else
            {
                if(currentString[currentString.length()-1]!=ch)
                {
                    currentString+=ch;
                    getStrings(allStrings, currentString, n, k, mp);
                    currentString=currentString.substr(0, currentString.length()-1);
                }
            }
        }
        return;
    }

    string getHappyString(int n, int k) {
        vector<string> allStrings;
        unordered_map<string, int> mp;
        getStrings(allStrings, "", n, k, mp);
        if(allStrings.size() != k)
        {
            return "";
        }
        return allStrings[k-1];
    }
};