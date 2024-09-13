class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int pre=arr[0];
        vector<int> prefix;
        prefix.push_back(pre);
        for(int x=1;x<arr.size();x++)
        {
            pre^=arr[x];
            prefix.push_back(pre);
        }
        int n=queries.size();
        vector<int> ans(n);
        for(int x=0;x<n;x++)
        {
            int start=queries[x][0];
            int end=queries[x][1];
            int xored=0;
            if(start==0)
            {
                xored=prefix[end];
            }
            else
            {
                xored=prefix[end]^prefix[start-1];
            }
            ans[x]=xored;
        }
        return ans;
    }
};