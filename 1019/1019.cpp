
#include<iostream>
using namespace std;

int gcd(int n, int m)
{
	int t;
	if(n < m) swap(n, m);
	while(n % m) {
		t = n % m;
		n = m;
		m = t;
	}
	return m;
}

int main()
{
	int t, n, m;
	int sum;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0;i < n;i ++) {
			cin >> m;
			if(i == 0) sum = m;
			else {
				sum = sum / gcd(sum, m) * m;
			}
		}
		printf("%1d\n", sum);
	}
	return 0;
}
