class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        int p=1;
        for(int x=0;x<n;x++)
        {
            pre[x]=p;
            p*=nums[x];
        }
        p=1;
        for(int x=n-1;x>=0;x--)
        {
            post[x]=p;
            p*=nums[x];
        }
        vector<int> ans(n);
        for(int x=0;x<n;x++)
        {
            ans[x]=pre[x]*post[x];
        }
        return ans;
    }
};