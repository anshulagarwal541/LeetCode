class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> strings;
        for(int x=1;x<=n;x++)
        {
            strings.push_back(to_string(x));
        }
        sort(strings.begin(), strings.end());
        vector<int> answer;
        for(string s:strings)
        {
            answer.push_back(stoi(s));
        }
        return answer;
    }
};