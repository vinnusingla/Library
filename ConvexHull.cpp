struct Point {
	double x, y;
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

// crossproduct return negative for clockwise
coord2_t cross(const Point &O, const Point &A, const Point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

//calculate perimeter of convex hull
double calcPerimeter(vector<Point> &a){
	int siz=a.size();
	double ans=0;
	for(int i=1;i<siz;i++){
		ans+=sqrt((a[i].x-a[i-1].x)*(a[i].x-a[i-1].x) + (a[i].y-a[i-1].y)*(a[i].y-a[i-1].y));
	}
	ans+=sqrt((a[0].x-a[siz-1].x)*(a[0].x-a[siz-1].x) + (a[0].y-a[siz-1].y)*(a[0].y-a[siz-1].y));
	return ans;
}

// Returns a list of points on the convex hull in counter-clockwise order.
//You might want to give only unique points in convex hull
vector<Point> convex_hull(vector<Point> P){
	int n = P.size(), k = 0;
	if (n == 1) return P;
	vector<Point> H(2*n);
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k-1);
	return H;
}
