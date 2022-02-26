class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
      
    int n = graph.size(),res = 0;
    queue<tuple<int,int,int>> q;
    vector<vector<int>> seen(n,vector<int>(1<<n));
    for(int i=0;i<n;i++){
        q.push(tuple<int,int,int>(i,1<<i,0));
        seen[i][1<<i] = true;
    }
    while (!q.empty())
    {
        auto [idx,mask,dist] = q.front();
        q.pop();
        if(mask==(1<<n)-1){
            res = dist;
            break;
        }
        for(auto v:graph[idx]){
            int mask_v = mask|1<<v;
            if(!seen[v][mask_v]){
                q.push(tuple<int,int,int>(v,mask_v,dist+1));
                seen[v][mask_v] = true;
            }
        }
    }
    return res;
}
};