#include<iostream>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n) != EOF) {
		if(n < 2) cout << "no" << endl;
		else {
			if((n - 2) % 4 == 0) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}
