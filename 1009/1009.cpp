
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int m, n, label = 0;
	while(cin >> m >> n) {
		if(m == -1 && n == -1) break;
		double a[1000], b[1000], sum = 0;
		for(int i = 0;i < n;i++) {
			cin >> a[i] >> b[i];
		}
		for(int i = 0;i < n;i++) {
			for(int j = i;j < n;j++) {
				label = 0;
				if(b[j] == 0) label = 1;
				if((a[j] / b[j]) > (a[i] / b[i])) label = 1;
				if(label == 1) {
					double tmp;
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
					tmp = b[j];
					b[j] = b[i];
					b[i] = tmp;
				}
			}
		}
		
		for(int i = 0;i < n;i++) {
			if(m == 0) break;
			if(m >= b[i]) {
				sum += a[i];
				m = m - b[i];
			}else {
				sum += (a[i] / b[i]) * m;
				m = 0;
			}
		}
		printf("%.3f\n", sum);
	}
}
