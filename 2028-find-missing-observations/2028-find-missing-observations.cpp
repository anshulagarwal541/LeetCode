class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumM = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int remainingSum = mean * (m + n) - sumM;
        vector<int> answer(n, 1);
        if (remainingSum < n || remainingSum > 6 * n) {
            return {};
        }
        remainingSum-=n;
        for(int x=0;x<answer.size() && remainingSum>0;x++)
        {
            int add=min(5, remainingSum);
            answer[x]+=add;
            remainingSum-=add;
        }
        return answer;
    }
};