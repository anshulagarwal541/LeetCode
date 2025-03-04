class Solution {
public:
    bool getAns(int& n, int start, int sum)
    {
        if(sum==n)
        {
            return true;
        }
        for(int x=start;x<=n;x*=3)
        {
            bool result = getAns(n, x*3, sum+x);
            if(result)
            {
                return true;
            }
        }
        return false;
    }
    bool checkPowersOfThree(int n) {
        return getAns(n, 1, 0);
    }
};