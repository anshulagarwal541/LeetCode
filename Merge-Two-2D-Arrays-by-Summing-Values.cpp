class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for(int x=0;x<nums1.size();x++)
        {
            mp1[nums1[x][0]]=nums1[x][1];
        }
        for(int x=0;x<nums2.size();x++)
        {
            mp2[nums2[x][0]]=nums2[x][1];
        }
        vector<vector<int>> ans;
        for(auto it = mp1.begin(); it!= mp1.end(); it++)
        {
            if(mp2.find(it->first)!=mp2.end())
            {
                ans.push_back({it->first, it->second+mp2[it->first]});
            }
            else
            {
                ans.push_back({it->first, it->second});
            }
        }
        for(auto it = mp2.begin(); it!= mp2.end(); it++)
        {
            if(mp1.find(it->first)==mp1.end())
            {
                ans.push_back({it->first, it->second});
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};