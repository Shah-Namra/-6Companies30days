//497. Random Point in Non-overlapping Rectangles

// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

class Solution {
public:
    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
    }
    
    vector<int> pick() {
        int sum_area = 0;
        vector<int> selected;
        for(auto r: rects){
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;
            if(rand() % sum_area < area) selected = r;
        }
        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
        return {x, y};
    }
};
//TC: O(n) for pick() and O(1) for another  