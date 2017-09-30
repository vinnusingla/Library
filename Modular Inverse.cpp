///////////////////////////modular inverse///////////////////////////
#include<bits/stdc++.h>
using namespace std;
int inv(int a, int m){
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)	return 0;
    // Apply extended Euclid Algorithm
    while (a > 1){
        // q is quotient , m is remainder now, process same as euclid's algo
        q = a / m;
        t = m;
        m = a % m, a = t;
 		// now ext. part
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
        cout<<x0<<"	"<<x1<<endl;
    }
    if (x1 < 0)	x1 += m0;
    return x1;
}

int main(){
	cout<<inv(5000,1e9+7)%(1000000007);
}
