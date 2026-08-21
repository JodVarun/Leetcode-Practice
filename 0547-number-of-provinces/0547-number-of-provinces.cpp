class Solution {
public:
    int provinces = 0;
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(), 0);
        for(int i =0; i<isConnected.size(); i++){
            if(!vis[i]){
                provinces++;
                dfs(i, isConnected, vis);
            }
        }
        return provinces;

    }
    void dfs(int node,vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node] = 1;
        for(int i =0; i<isConnected.size(); i++){

            if (isConnected[node][i] == 1 && !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }
};