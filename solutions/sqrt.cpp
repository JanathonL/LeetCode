sqrt

int binary_search(int n){
	int lo = 0;
	int hi = n/2;
	while(lo < hi){
		int mid= lo + (hi-lo+1)/2;
		if(mid*mid == n){
			return mid;
		} else if (mid*mid < n){
			lo = mid;
		} else {
			hi = mid-1;
		}
	}
	return lo;
}


