class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for (int x = 0; x < nums.size(); x++) {
            minValue = min(minValue, nums[x]);
            maxValue = max(maxValue, nums[x]);
        }
        int l = minValue;
        int r = maxValue;
        while (l < r) {
            int stole = 0;
            int m = (l + r) / 2;
            for (int x = 0; x < nums.size();) {
                if (nums[x] <= m) {
                    stole++;
                    x += 2;
                } else {
                    x++;
                }
            }
            if (stole >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};