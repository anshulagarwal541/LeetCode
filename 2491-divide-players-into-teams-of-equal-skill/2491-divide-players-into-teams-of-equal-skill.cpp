class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<int> array = skill;
        sort(array.begin(), array.end());
        long long chemistry = 0;
        int first = 0;
        int rear = array.size() - 1;
        int sum = array[first] + array[rear];
        while (first < rear) {
            if ((array[first] + array[rear]) == sum) {
                chemistry += (array[first] * array[rear]);
                first++;
                rear--;
            } else {
                return -1;
            }
        }
        return chemistry;
    }
};