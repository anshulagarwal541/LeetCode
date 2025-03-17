class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int  x=0;x<nums.size();x++)
        {
            mp[nums[x]]++;
        }
        int count=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2!=0)
            {
                return false;
            }
            else
            {
                count+=it->second/2;
            }
        }
        return count==(nums.size()/2);
    }
};