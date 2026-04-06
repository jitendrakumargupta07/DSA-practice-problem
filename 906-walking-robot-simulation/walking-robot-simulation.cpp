class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string, string> turn_left({
            {"north", "west"},
            {"west", "south"},
            {"south", "east"},
            {"east", "north"}
        });
        
        unordered_map<string, string> turn_right({
            {"north", "east"},
            {"east", "south"},
            {"south", "west"},
            {"west", "north"}
        });
        
        auto cantorPair = [](int x, int y) -> long long {
            long long newX = static_cast<long long>(x) + 10000;
            long long newY = static_cast<long long>(y) + 10000;
            return ((newX + newY) * (newX + newY + 1)) / 2 + newY;
        };
        
        unordered_set<long long> obstacleSet;
        for (auto& obstacle : obstacles) {
            long long hashed = cantorPair(obstacle[0], obstacle[1]);
            obstacleSet.insert(hashed);
        }
        
        int x = 0, y = 0;
        string direction = "north";
        int maxDistance = 0;

        for (int command : commands) {
            if (command == -2) {
                direction = turn_left[direction];
            } else if (command == -1) {
                direction = turn_right[direction];
            } else {
                for (int step = 0; step < command; ++step) {
                    int nextX = x, nextY = y;
                    if (direction == "north") nextY++;
                    else if (direction == "south") nextY--;
                    else if (direction == "east") nextX++;
                    else if (direction == "west") nextX--;

                    long long hashedPosition = cantorPair(nextX, nextY);
                    
                    if (obstacleSet.count(hashedPosition) == 0) {
                        x = nextX;
                        y = nextY;
                        maxDistance = max(maxDistance, x * x + y * y);
                    } else {
                        break; 
                    }
                }
            }
        }
        return maxDistance;
    }
};