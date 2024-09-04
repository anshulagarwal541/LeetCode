class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, vector<int>> mpx;
        unordered_map<int, vector<int>> mpy;
        for (int x = 0; x < obstacles.size(); x++) {
            mpx[obstacles[x][0]].push_back(obstacles[x][1]);
            mpy[obstacles[x][1]].push_back(obstacles[x][0]);
            sort(mpy[obstacles[x][1]].begin(), mpy[obstacles[x][1]].end());
            sort(mpx[obstacles[x][0]].begin(), mpx[obstacles[x][0]].end());
        }

        int x = 0;
        int y = 0;
        int direction = 0;
        int answer=0;

        for (int c = 0; c < commands.size(); c++) {
            if (commands[c] == -1) {
                if (direction == 0) {
                    direction = 2;
                } else if (direction == 1) {
                    direction = 3;
                } else if (direction == 2) {
                    direction = 1;
                } else {
                    direction = 0;
                }
                continue;
            } else if (commands[c] == -2) {
                if (direction == 0) {
                    direction = 3;
                } else if (direction == 1) {
                    direction = 2;
                } else if (direction == 2) {
                    direction = 0;
                } else {
                    direction = 1;
                }
                continue;
            } else {
                if (direction == 0 || direction == 1) {
                    int tempy =
                        y + (direction == 0 ? commands[c] : commands[c] * -1);
                    int k = 0;
                    while (k < mpx[x].size()) {
                        if ((mpx[x][k] <= tempy && mpx[x][k] > y &&
                             direction == 0) ||
                            (mpx[x][k] >= tempy && mpx[x][k] < y &&
                             direction == 1)) {
                            break;
                        }
                        k++;
                    }
                    if (k < mpx[x].size()) {
                        y = mpx[x][k] - (direction == 0 ? 1 : -1 * 1);
                    } else {
                        y =  tempy;
                    }
                    answer=max(answer, x*x+y*y);

                } else if(direction==2 || direction==3) {

                    int tempx =
                        x + (direction == 2 ? commands[c] : -1 * commands[c]);
                    int k = 0;
                    while (k < mpy[y].size()) {
                        if ((mpy[y][k] <= tempx && mpy[y][k] > x &&
                             direction == 2) ||
                            (mpy[y][k] >= tempx && mpy[y][k] < x &&
                             direction == 3)) {
                            break;
                        }
                        k++;
                    }
                    if (k < mpy[y].size()) {
                        x = mpy[y][k] - (direction == 2 ? 1 : -1 * 1);
                    } else {
                        x =  tempx;
                    }
                    answer=max(answer, x*x+y*y);

                }
            }
        }
        return answer;
    }
};