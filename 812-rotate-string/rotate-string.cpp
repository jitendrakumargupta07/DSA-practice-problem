class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.size();
        int i = n;
        while (i > 0) {
            // Rotate the goal string
            rotate(goal.begin(), goal.begin() + 1, goal.end());
            if (goal == s) return true;
            i--;
        }
        return false;
    }
};