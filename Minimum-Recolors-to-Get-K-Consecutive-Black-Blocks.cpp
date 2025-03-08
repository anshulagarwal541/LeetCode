class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int start=0;
        int end=0;
        int currentWhites=0;
        int ans=INT_MAX;
        int n=blocks.size();
        while(end<n)
        {
            if(blocks[end]=='W')
            {
                currentWhites++;
            }
            if((end-start+1)==k)
            {
                ans=min(ans, currentWhites);
                if(blocks[start]=='W')
                {
                    currentWhites--;
                }
                start++;
            }
            end++;
        }
        return ans;
    }
};