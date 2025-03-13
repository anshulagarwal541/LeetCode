class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Apply range increments
        for (auto &q : queries) {
            prefix[q[0]]++;
            if (q[1] + 1 < n) prefix[q[1] + 1]--;
        }

        // Compute prefix sum
        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        // Check if prefix array satisfies condition
        for (int i = 0; i < n; i++) {
            if (prefix[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};
