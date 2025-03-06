class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        unordered_map<int, int> uniqueElements;
        vector<int> ans;
        for(int x=0;x<grid.size();x++)
        {
            for(int y=0;y<grid[0].size();y++)
            {
                mp[grid[x][y]]++;
                if(uniqueElements.find(grid[x][y])==uniqueElements.end())
                {
                    uniqueElements[grid[x][y]]=1;
                }
                if(mp[grid[x][y]]>1)
                {
                    ans.push_back(grid[x][y]);
                }
            }
        }
        
        int n= grid.size();
        for(int x=1;x<=(n*n);x++)
        {
            if(uniqueElements.find(x)==uniqueElements.end())
            {
                ans.push_back(x);
                break;
            }
        }
        return ans;
    }
};