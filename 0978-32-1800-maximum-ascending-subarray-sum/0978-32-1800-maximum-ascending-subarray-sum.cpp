class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=nums[0];
        int sum=nums[0];
        int prevValue=nums[0];
        for(int x=0;x<nums.size();x++)
        {
            if(nums[x]>prevValue)
            {
                prevValue=nums[x];
                sum+=nums[x];
            }
            else
            {
                prevValue=nums[x];
                sum=nums[x];
            }
            maxSum=max(maxSum, sum);
        }
        maxSum=max(maxSum, sum);
        return maxSum;
    }
};