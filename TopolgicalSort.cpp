vector<int>graph[n+1];
vector<int>sol;
int push[n+1];
void f(int idx){
	if(push[idx]==0){
		int siz=graph[idx].siz;
		for(int i=0;i<siz;i++)
			if(push(graph[idx][i])==0)
				f(graph[idx][i]);
		push[i]=1;
		sol.push(i);
	}
}
void TopSort(int n){
	memset(push,0,sizeof(push));
	f(1);
}
