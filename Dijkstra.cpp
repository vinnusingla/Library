int n;
vector<pii >graph[n+1];		//first is node and second is edge 
int dist [n+1];
void Dijkstra(int n,int src,vector<pii >graph[n+1] ){
	priority_queue< pii, vector <pii> , greater<pii> > pq;
	bool vis [n+1];
	for(int i=0;i<=n;i++)dist[i]=INT_MAX;
	for(int i=0;i<=n;i++)vis[i]=0;
	pq.push({0,src});		//first one is distance and second is node 
	dist[src]=0;
	int u,siz;
	while(!pq.empty()){
		u=pq.top().ss;
		if(vis[u]==0){
			siz=graph[u].size();
			for(int i=0;i<siz;i++){
				if(dist[graph[u][i].ff]>dist[u]+graph[u][i].ss){
					dist[graph[u][i].ff]=dist[u]+graph[u][i].ss;
					if(vis[graph[u][i].ff]==0)pq.push({dist[graph[u][i].ff],graph[u][i].ff});
				}
			}
		}
		pq.pop();
		vis[u]=1;
	}
}
