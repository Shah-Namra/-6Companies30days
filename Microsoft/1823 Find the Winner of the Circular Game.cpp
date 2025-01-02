// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }
        
        while(q.size() > 1) {  
            for(int i = 1; i <= k-1; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

// TC = O(n*k) = O(n^2)