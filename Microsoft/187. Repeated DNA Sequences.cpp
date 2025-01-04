// 187. Repeated DNA Sequences

// https://leetcode.com/problems/repeated-dna-sequences/description/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>mp;
        int n = s.size();
        for(int i =0 ;i <n ; i++){
            mp[s.substr(i,10)]++;
        }
        vector<string>ans;

        for(auto a : mp){
            if(a.second > 1) 
                ans.push_back(a.first);
        }
        return ans;
    
    }
};

// TC: O(n) SC: O(n)