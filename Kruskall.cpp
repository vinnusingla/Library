#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ff first
#define asc(a) ((int)a)
#define ss second
#define pii pair<int,int>
#define pll pair<lli,lli>
#define pii3 pair< int,pair<int,int> >
#define pb(a) push_back(a)
const lli MOD=1e9+7;
vector<pii >graph[3005];
vector<pair<int,pii > >edges;
int n,m;
/////////////////////////////////////////////////////////////////////////////////////
class inf{
	public :
		int rank;
		int parent;
	inf(int r=0,int p=(-1)){
		rank=r;
		parent=p;
	}
};
inf subsets[3005];

int Find(int x){
	if(subsets[x].parent==-1 || subsets[x].parent==x)return x;
	else{
		subsets[x].parent=Find(subsets[x].parent);
	}
	return subsets[x].parent;
}

void Union(int x,int y){
	int xroot=Find(x);
	int yroot=Find(y);
	if(subsets[xroot].rank>subsets[yroot].rank){
		subsets[yroot].parent=xroot;
	}
	else if(subsets[xroot].rank<subsets[yroot].rank){
		subsets[xroot].parent=yroot;
	}
	else{
		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
	}
}
//////////////////////////////////////////////////////////////////////////////////////
int main(){
	cout.sync_with_stdio(false);
	cin.sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back({w,{u,v}});
	}
	sort(edges.begin(),edges.end());
	lli ans=0;
	for(int i=0;i<m;i++){
		if(Find(edges[i].ss.ff)!=Find(edges[i].ss.ss)){
			ans=ans+((lli)edges[i].ff);
			Union(edges[i].ss.ff,edges[i].ss.ss);
		}
	}
	cout<<ans;
	return 0;
}
