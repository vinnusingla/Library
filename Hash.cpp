#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>


#define N 1050

using namespace std;

void compare_two_string() {
	//Imagine that you've already made hashes to two strings.
	if (hash1[s.size()] == hash2[ss.size()])
		printf("They are same");
	else
		printf("They are not same");
}

void find_max_palindrom() {
	//Imagine that you've already made hashe to your string.
	//Below shown a program, which searching max palindromfor each i's position with binary search.
	//I use two binary searches to find max_palindrom for even positions and for odd positions.
	for (i = 1; i <= n; i++) {
		l = 1;
		r = max(n - i, i - 1);
		while (l <= r) {
			m = (l + r) / 2;
			if ((hash1[i + m] - hash1[i - m - 1]) * st[n - (i + m)] == (hash2[i - m] - hash2[i + m + 1]) * st[i - m - 1]){			
				l = m + 1;
				if ((2 * m + 1) > ans) {
					ans = 2 * m + 1;
					l1 = min(i + m, i - m);
					r1 = max(i + m, i - m);
				}
			}
			else
				r = m - 1;
		}
		l = 1;
		r = max(n - i, i - 1);
		while (l <= r) {
			m = (l + r) / 2;
			if (((hash1[i + m] - hash1[i - m]) * st[n - (i + m)]) == ((hash2[i - m + 1] - hash2[i + m + 1]) * st[i - m])) {
				l = m + 1;     //2*m
				if ((2 * m) > ans) {
					ans = 2 * m;
	                l1 = min(i + m, i - m + 1);
					r1 = max(i + m, i - m + 1);
    			}
			}
			else
				r = m - 1;
		}
	}

	if (ans == 0)
		cout << s[0];
	else
		for (i = l1; i <= r1; i++) {
			cout << s[i - 1];
		}
}

int main () {

	cin >> s;

	//Making hash of string s
	for (int i = 0; i < s.size(); i++) {
		hash[i] = (hash[i - 1] + s[i - 1]) * _prime   //The best formula for making hash that I've ever met.
		//Instead of _prime you can use any prime number, better to use big ones. In some cases you can get WA
		//choose prime between 2000-10000.
		//And the important part of code is that you must to use hash array as long long, not int. Because in some ways you can get WA.
	}
	//Making hash of string s

	/*
		Now you can use your hash in many problems.
		You can compare strings for O(1).
		But in some problems, there can antihashs, that can make your solution WA.
	*/

	// Some intersting features, look below.

	compare_two_string(); //Compares two strings for O(1)
	
	find_max_palindrom(); //Find palindrom in your string for O(N log N)

	//and e.t.c.

	//So there are many ways, as I said before, where you can use HASH, so good luck. And to fasten your knowledge solve more problems.

	//P.S. it's not compiling, because I wrote it to help you understand basic steps. But algorithms are right. And building hash array is also right. I hope i helped you ;-).

	return 0;

}
