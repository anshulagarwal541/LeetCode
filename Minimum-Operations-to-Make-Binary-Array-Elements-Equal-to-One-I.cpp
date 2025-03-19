class Solution {
public:
    void  getAns(vector<int>& nums, int  x, int& count)
    {
        if(x>(nums.size()-3))
        {
            return;
        }
        if(nums[x]==0)
        {
            nums[x]=1;
            if((x+1)<nums.size())
            {
                nums[x+1]=!nums[x+1];
            }
            if((x+2)<nums.size())
            {
                nums[x+2]=!nums[x+2];
            }
            count++;
        }
        getAns(nums, x+1, count);
    }
    int minOperations(vector<int>& nums) {
        int count=0;
        getAns(nums, 0,  count);
        for(int x: nums)
        {
            if(x==0)
            {
                return -1;
            }
        }
        return count;
    }
};