class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0;
        int maxValue = 0;
        vector<int> visited(32, -1);
        for (int x = 0; x < s.length(); x++) {
            char ch = s[x];
            switch (ch) {
            case 'a':
                mask ^= 1;
                break;
            case 'e':
                mask ^= 2;
                break;
            case 'i':
                mask ^= 4;
                break;
            case 'o':
                mask ^= 8;
                break;
            case 'u':
                mask ^= 16;
                break;
            default:
                mask ^= 0;
            }
            if (visited[mask] == -1 && mask != 0) {
                visited[mask] = x;
            }
            maxValue = max(maxValue, x - visited[mask]);
        }
        return maxValue;
    }
};