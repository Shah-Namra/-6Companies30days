// 354. Russian Doll Envelopes

// https://leetcode.com/problems/russian-doll-envelopes/description/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>a, vector<int>b){
            if(a[0] != b[0]) 
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        vector<int> x;
        for(auto& i : envelopes){
            auto index = lower_bound(x.begin(), x.end(), i[1]);
            
            if(index == x.end()) 
                x.push_back(i[1]);
            else 
                *index = i[1];
        }
        return x.size();
    }
};