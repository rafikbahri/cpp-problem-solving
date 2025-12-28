#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
    public:
        vector<pair<long long,long long>> adj[50001]; 
        vector<vector<int>> edges;
        long long n, k;
        vector<bool> onlines;
        bool visited[500001];
        vector<long long> nodes;
    

        bool dfs(long long curr, long long target){
            if(curr == target)
                return true;

            visited[curr] = true;
            
            for(auto child : adj[curr]){
                if(!visited[child.first] && dfs(child.first, target))
                    return true;
            }

            return false;
        }

        vector<long long> topologicalSort() {
            // build the dag with its degrees
            vector<long long> degres(n, 0);
            for(auto edge : edges){
                long long from = edge[0], to = edge[1], weight = edge[2];
                if(!onlines[from] || !onlines[to])
                    continue;
                adj[from].push_back({to, weight});
                degres[to]++;
            }
            // topo
            queue<long long> q;
            for(long long i = 0; i < degres.size(); i++){
                if(degres[i] == 0)
                    q.push(i);
            }
            vector<long long> res;
            while(!q.empty()){
                long long u = q.front();
                q.pop();
                res.push_back(u);
                for(auto out : adj[u]){
                    degres[out.first]--;
                    if(degres[out.first] == 0)
                        q.push(out.first);
                }
            }
            // cout<<"topological sort"<<endl;
            // for(long long i = 0; i < res.size(); i++){
            //     cout<<" "<<res[i]<<endl;
            // }

            return res;
        }

        bool check(long long minimumThreshold){
            vector<long long> dist(n, LONG_LONG_MAX);
            dist[0] = 0;
            for(auto node : nodes){
                long long distToReachMe = dist[node];
                if(distToReachMe == LONG_LONG_MAX){
                    continue;
                }
                for(auto child : adj[node]){
                    if(child.second < minimumThreshold){
                        continue;
                    }
                    long long candidatePath = distToReachMe + child.second;
                    if(dist[child.first] > candidatePath)
                        dist[child.first] = candidatePath;
                }
            }

            // for(long long d : dist)
            //     cout<<"dist "<<d<<endl;

            return dist[n - 1] <= k;
        }
        

        long long findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
            this->n = online.size();
            this->onlines = online;
            this->k = k;
            this->edges = edges;
            this->nodes = topologicalSort();
            if(edges.size() == 0)
                return -1;
            if(!dfs(0, n - 1))
                return -1;
            if(edges.size() == 1){
                if(edges[0][2] <= k){
                    return edges[0][2];
                }
                else{
                    return -1;
                }
            }

            std::sort(edges.begin(), edges.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[2] < b[2]; });

            // auto last = std::unique(edges.begin(), edges.end());
            // edges.erase(last, edges.end());
            // for(auto edge : edges){
            //     cout<<"check("<<edge[2]<<"):    "<<check(edge[2])<<endl;
            // }

            if(check(edges[0][2]) == 0){
                return -1;
            }

            if(check(edges.back()[2]))
                return edges.back()[2];


            // for(long long i = 1; i < edges.size(); i++){
            //     bool curr = check(edges[i][2]);
            //     if(!curr)
            //         return edges[i-1][2];
            // }
            long long left = 0, right = edges.size() - 1;
            while(left < right){
                long long mid = (left + right) / 2;
                if(check(edges[mid][2])){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

            if(check(edges[left][2]))
                return edges[left][2];
            
            if(check(edges[left - 1][2]))
                return edges[left - 1][2];
            
            return -1;  
        }
};


int main() {
    Solution sol;

    vector<vector<int>> in1 = {{0,1,5},
                            {0,2,4},
                            {1,3,6},
                            {1,4,3},
                            {2, 3, 12},
                            {2, 4, 5},
                            {3, 5, 1},
                            {4, 5, 14}
                        };
    
    vector<bool> online(6, true);
    int res = sol.findMaxPathScore(in1, online, 25);

    cout<<res<<endl;

    // for(long long i = 0; i < 6; i++){
    //     cout<<i<<": ";
    //     for(auto child : sol.adj[i])
    //         cout<<" ("<<child.first<<", "<<child.second<<")";
    //     cout<<endl;
    // }
    // for(auto v : res){
    //     cout<<"node "<<v<<" ";
    // }
    

    return 0;
}