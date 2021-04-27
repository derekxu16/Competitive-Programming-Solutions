#include <vector>

using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        // Elements in the stack mean that p.second is the smallest height
        // between p.first and i.
        vector<pair<int, int>> stack;
        for (int i = 0; i < n; i++) {
            int l = i;
            while (!stack.empty() && heights[i] < stack.back().second) {
                pair<int, int> back = stack.back();
                stack.pop_back();
                l = back.first;
                ans = max(ans, (i - back.first) * back.second);
            }
            stack.emplace_back(l, heights[i]);
        }
        while (!stack.empty()) {
            pair<int, int> back = stack.back();
            stack.pop_back();
            ans = max(ans, (n - back.first) * back.second);
        }
        return ans;
    }
};
