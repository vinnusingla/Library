class inf{
	public :
		int rank;
		int parent;
	inf(int r=0,int p=(-1)){
		rank=r;
		parent=p;
	}
};
inf subsets[200000];

int Find(int x){
	if(subsets[x].parent==-1)return x;
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
