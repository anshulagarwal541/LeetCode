class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int start=0;
        int currentNum=0;
        int end=0;
        int count=0;
        int ans=0;
        while(end<nums.size())
        {
            if((currentNum&nums[end])==0)
            {
                count++;
                currentNum|=nums[end];
            }
            else
            {
                while(start<=end && (currentNum&nums[end])!=0)
                {
                    count--;
                    currentNum=currentNum&(~(nums[start]));
                    start++;
                }
                if(start<=end)
                {
                   count++;
                   currentNum=currentNum|nums[end]; 
                }
                else
                {
                    currentNum=nums[end];
                    count++;
                }
            }
            end++;
            ans=max(ans, count);
        }
        ans=max(ans, count);
        return ans;
    }
};