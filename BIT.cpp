lli getSum( lli index){
    lli sum = 0;
	while (index > 0){
        sum += BITree[index];
		index -= ( index & (-index) );
    }
    return sum;
}
 
void update(lli n, lli index, lli val){
    while (index <= n){
       BITree[index] += val;
	   index += ( index & (-index) );
    }
}
