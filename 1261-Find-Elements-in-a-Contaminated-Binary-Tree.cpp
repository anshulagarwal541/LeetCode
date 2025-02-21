class Solution {
public:
    int maxRepOpt1(string text) {
        int maxValue = 0;
        int n = text.length();
        int count = 0;
        int times = 0;
        int start=0;
        for (int x = 0; x < n; x++) {
            if (text[x] == text[start]) {
                count++;
            } else {
                int index = text.substr(x + 1).find(text[start]);
                if (index == string::npos) {
                    maxValue = max(maxValue, count);
                    count = 1;
                    times = 0;
                    while(text[start]!=text[x])
                    {
                        start++;
                    }
                } else {
                    if (times == 0) {
                        count++;
                        times++;
                    } else {
                        maxValue = max(maxValue, count);
                        count = 1;
                        times = 0;
                        while(text[start]!=text[x])
                        {
                            start++;
                        }
                    }
                }
            }
        }
        maxValue=max(maxValue, count);
        return maxValue;
    }
};