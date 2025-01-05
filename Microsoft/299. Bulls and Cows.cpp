// 299. Bulls and Cows

// https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls =0;
        int cows = 0;
        
        vector<bool> used_secret(secret.length(), false);
        vector<bool> used_guess(guess.length(), false);
        int l= secret.length();

        for (int i = 0; i < l; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                used_secret[i] = true;
                used_guess[i] = true;
            }
        }
        
        for (int i = 0; i <l; i++) {
            if (used_guess[i]) 
                continue;
            
            for (int j = 0; j < l; j++) {
                if (used_secret[j]) 
                    continue;
                
                if (guess[i] == secret[j]) {
                    cows++;
                    used_secret[j] = true;
                    break;
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
// TC: O(n^2) SC: O(n)