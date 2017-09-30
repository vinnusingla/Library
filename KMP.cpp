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

string text,query;		//size of text is n and query is m
int lps[2000005];
void KMP(string text,string query){
	string pat=query+"#"+text;
	int len=0,i=1,siz=text.size()+1+query.size();
	lps[0]=0;
	while(i<siz){
		if(pat[i]==pat[len]){
			lps[i]=len+1;
			i++;
			len++;
			if(len==m)len=lps[len-1];
		}
		else{
			if(len==0){
				lps[i]=0;
				i++;
			}
			else len=lps[len-1];
		}
	}
}

int main(){
	string t,q;
	cin>>t>>q;
	KMP(t,q);
	int n=t.size(),m=q.size();
	for(int i=0;i<n;i++)cout<<lps[i+m+1]<<" ";
	return 0;
}
