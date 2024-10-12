class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> start(n);
        vector<int> last(n);
        for(int x=0;x<n;x++)
        {
            start[x]=intervals[x][0];
            last[x]=intervals[x][1];
        }
        sort(start.begin(), start.end());
        sort(last.begin(), last.end());
        int minValue=1;
        int temp=1;
        int i=1;
        int j=0;
        while(i<n && j<n)
        {
            if(start[i]<=last[j])
            {
                temp++;
                i++;
            }
            else
            {
                temp--;
                j++;
            }
            minValue=max(minValue, temp);
        }
        return minValue;
    }
};