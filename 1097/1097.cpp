#include<iostream>
using namespace std;

int main()
{
	int a, b, sum;
	while(scanf("%d %d", &a, &b) != EOF) {
		sum = a % 10;
		if(b % 4 == 1) cout << sum << endl;
		else if(b % 4 == 2) cout << (sum * sum) % 10 << endl;
		else if(b % 4 == 3) cout << (sum * sum * sum) % 10 << endl;
		else if(b % 4 == 0) cout << (sum * sum * sum * sum) % 10 << endl;
	}
}
