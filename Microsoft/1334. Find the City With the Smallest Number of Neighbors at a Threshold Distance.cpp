// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


class Solution {
    private:
     void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size(); 
        for (int i = 0 ; i< n ; i++ ){
        for (int j = 0 ; j <n ; j++ ) {
               if ( mat [i] [j] == -1) {
                    mat[i][j]=1e9;
                }
                 if ( i == j ) {
                    mat[i][i]= 0;
                }
                
            }
        }
        for (int k = 0 ;k < n ; k++ ) {
            for (int i = 0; i < n ; i++ ) {
                for (int j = 0 ; j <n ; j++ ) {
                   mat[i][j] = min ( mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
         
    } 
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n ,vector<int>(n , -1));
        for ( auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v]=wt;
            mat[v][u]=wt;
        }
     
        shortestDistance(mat);
        
        map<int,int>mp;
        for ( int i =0 ;i < n ; i++ ) {
            bool chk = 1;
            int cnt = 0;
            for( int j = 0; j < n ;j++ ) {
                if ( mat[i][j] != 0 && mat[i][j] <=distanceThreshold ) {
                    cnt ++;
                }
            }
            mp[i] = cnt;
        }
 
        int mini = 1e9;
    for ( auto it : mp ){
         if ( it.second < mini){
            mini = it.second;
         }
    }
    int ans = -1;
    for ( auto it : mp ){
        if( it.second == mini){
         ans = it.first;
        }
    }
    return ans;

    }
};
// Time: O(N^3)