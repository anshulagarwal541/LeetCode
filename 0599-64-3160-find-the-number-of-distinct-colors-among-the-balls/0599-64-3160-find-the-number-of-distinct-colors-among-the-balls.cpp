class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> answer(queries.size());
        unordered_map<int, int> mp;
        unordered_map<int, int> currentColors;
        for(int x=0;x<queries.size();x++)
        {
            if(mp.find(queries[x][0])!=mp.end())
            {
                int color=mp[queries[x][0]];
                currentColors[color]--;
                if(currentColors[color]<=0)
                {
                    currentColors.erase(color);
                }
            }
            mp[queries[x][0]]=queries[x][1];
            currentColors[queries[x][1]]++;
            answer[x]=currentColors.size();
        }
        return answer;
    }
};