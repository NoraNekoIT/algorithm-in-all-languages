# Implementing Dikstra's Algorithm
- question link: https://bit.ly/3KeZZ7j
- Solution

- vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<int>dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edgeWeight=it[1];
                if(edgeWeight+dis<dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
