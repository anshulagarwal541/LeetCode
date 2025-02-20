class Solution {
public:
    string getAns(string s, int n, unordered_map<string, int>& mp)
    {
        if(s.length()>n)
        {
            return "";
        }
        if(s.length()==n)
        {
            if(mp.find(s)==mp.end())
            {
                return s;
            }
            return "";
        }
        for(char ch='0'; ch<='1'; ch++)
        {
            s+=ch;
            string ans = getAns(s, n, mp);
            if(ans!="")
            {
                return ans;
            }
            s=s.substr(0, s.length()-1);
        }
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> mp;
        for(int x=0;x<nums.size();x++)
        {
            mp[nums[x]]=1;
        }
        return getAns("", nums[0].length(), mp);
    }
};