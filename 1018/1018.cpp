
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	double s;
	cin >> n;
	for(int i = 0;i < n;i++) {
		s = 0;
		int a;
		cin >> a;
		for(int j = 1;j <= a;j++) {
			s += log10(j);
		}
		cout << ((int)s + 1) << endl;
	}
}
