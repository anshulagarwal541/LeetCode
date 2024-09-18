class Solution {
public:
    static bool cmp(string a, string b)
    {
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        for(int x=0;x<nums.size();x++)
        {
            numbers.push_back(to_string(nums[x]));
        }
        sort(numbers.begin(), numbers.end(), cmp);
        if(numbers[0]=="0")
        {
            return "0";
        }
        string ans="";
        for(int x=0;x<numbers.size();x++)
        {
            ans+=numbers[x];
        }
        return ans;
    }
};