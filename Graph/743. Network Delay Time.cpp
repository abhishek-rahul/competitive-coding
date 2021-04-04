class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< pair < int , int > > graph[n+5];
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        int source = k ;
        int u,v,w;
        int dist[n+5];
        
        for(int i=0;i<=n;i++)
        {
            dist[i]=INT_MAX;
        }
        dist[source]=0;
        priority_queue< pair<int,int> , vector < pair<int,int> > , greater< pair<int,int> > > pq;
        pq.push(make_pair(0,source));
        while(!pq.empty())
        {
            u = pq.top().second;
            pq.pop();
            for(int i=0;i<graph[u].size();i++)
            {
                v = graph[u][i].first;
                w = graph[u][i].second;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans = max(ans,dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    };
};
