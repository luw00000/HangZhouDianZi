#include<iostream>
using namespace std;

int prime[40] = {0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};

void dfs(int a[], int k, int t)
{
	if(k == t) {
		
	}else {
		for(int i = 1;i <= k;i++) {
			a[t] = i;
			if(prime[a[t] + a[t - 1]] == 1)
		}
	}
}

int main()
{
	int n;
	int a[20];
	a[0] = 1;
	cin >> n;
	if(n % 2 != 0) {
		dfs(a, n, 1);
	}
	
}
