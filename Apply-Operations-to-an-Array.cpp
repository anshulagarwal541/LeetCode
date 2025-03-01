class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> num;
        vector<int> zeros;
        for(int x=0;x<nums.size()-1;x++)
        {
            if(nums[x]==nums[x+1])
            {
                nums[x]*=2;
                nums[x+1]=0;
            }
            if(nums[x]!=0)
            {
                num.push_back(nums[x]);
            }
            else
            {
                zeros.push_back(nums[x]);
            }
        }
        if(nums[nums.size()-1]!=0)
        {
            num.push_back(nums[nums.size()-1]);
        }
        else
        {
            zeros.push_back(nums[nums.size()-1]);
        }
        for(int x=0;x<num.size();x++)
        {
            nums[x]=num[x];
        }
        for(int x=0;x<zeros.size();x++)
        {
            nums[num.size()+x]=zeros[x];
        }
        return nums;
    }
};