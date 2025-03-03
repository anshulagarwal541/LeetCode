class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> equal;
        vector<int> large;
        for(int x=0;x<nums.size();x++)
        {
            if(nums[x]<pivot)
            {
                small.push_back(nums[x]);
            }
            else if(nums[x]==pivot)
            {
                equal.push_back(nums[x]);
            }
            else{
                large.push_back(nums[x]);
            }
        }
        vector<int> ans;
        for(int x : small)
        {
            ans.push_back(x);
        }
        for(int x : equal)
        {
            ans.push_back(x);
        }
        for(int x : large)
        {
            ans.push_back(x);
        }
        return ans;
    }
};