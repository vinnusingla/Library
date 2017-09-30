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
int n,sizz=0;												//sizz=euler array size
vector<int>graph[200005];
int vis[200005],ea[400005],da[200005],fo[200005];			//ea=euler array , da=depth array , fo=first occ. 
int st[400005][21];											//st is sparse table

/////////////////////////////////////////////////////////////////////////////////////

//dfs finds fo ea and da
void dfs(int a,int depth){
	int siz=graph[a].size();
	vis[a]=1;
	if(fo[a]==-1)fo[a]=sizz;
	da[a]=depth;
	ea[sizz++]=a;
	for(int i=0;i<siz;i++){
		if(vis[graph[a][i]])continue;
		dfs(graph[a][i],depth+1);
		ea[sizz++]=a;
	}
}

//creates the sparse table 
void sp(){
	for(int i=0;i<sizz;i++)st[i][0]=ea[i];
	int num=log2(sizz)+1,x;
	for(int j=1,a,b;j<num;j++){
		x=(1<<j)-1;
		for(int i=0;i+x<sizz;i++){
			a=i,b=i+(1<<(j-1));
			if(da[st[a][j-1]]<da[st[b][j-1]]) st[a][j]=st[a][j-1];
			else st[a][j]=st[b][j-1];
		}
	}
}

int lca(int l,int r){
	l=fo[l],r=fo[r];
	if(l>r)swap(l,r);
	int len=log2(r-l+1);
	int a=l,b=r-(1<<len)+1;
	if(da[st[a][len]]<da[st[b][len]]) return st[a][len];
	else return st[b][len];
}
//////////////////////////////////////////////////////////////////////////
int main(){
	//create graph
	memset(vis,0,sizeof(vis));
	memset(fo,-1,sizeof(fo));
	dfs(1,0);
	sp();
	//ask your queries
	return 0;
}
