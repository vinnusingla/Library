//This code finds the sum of max continuous sub array
// # Kande's Algorithm

int max_contiguous_sub_array_sum(int n){
	int i=0;
	int curr_sum=0,max_sum=0;
	while(i<n){
		curr_sum=curr_sum+a[i];
		if(curr_sum<0){
			curr_sum=0;
		}
		else max_sum=max(curr_sum,max_sum);
		i++;
	}
	return max_sum;
}



