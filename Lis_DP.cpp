//dynamic solution to longest increasing sub sequence
// O(n^2)
// a is the actual array


int a[1000000];
int d[1000000];
int m ;

int longest_inc_sub_sequence(int n){
    m=0;
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        if(a[i]<a[j] && d[j]<d[i]+1){
	            d[j]=d[i]+1;
	            m=max(m,d[j]);
	        }
	    }
	}
	return m+1;
}


