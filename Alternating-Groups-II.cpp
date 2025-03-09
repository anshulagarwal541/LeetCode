class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> c=colors;
        for(int x=0;x<k-1;x++)
        {
            c.push_back(c[x]);
        }
        int count=1;
        int answer=0;
        for(int x=1;x<c.size();x++)
        {
            if(c[x]!=c[x-1])
            {
                count++;
            }
            else
            {
                count=1;
            }
            if(count>=k)
            {
                answer++;
            }
        }
        return answer;
    }
};