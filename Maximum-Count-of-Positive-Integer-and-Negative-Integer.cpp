class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countPos =0;
        int countNeg =0;
        for(int x=0;x<nums.size();x++)
        {
            if(nums[x]<0)
            {
                countNeg++;
            }
            if(nums[x]>0)
            {
                countPos++;
            }
        }
        return max(countPos, countNeg);
    }
};