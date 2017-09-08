#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	int t;
	int a[100000], b[100000];
	scanf("%d", &t);
	int k = 0;
	while(t--) {
		int sum = 0;
		int n, begin, end;
		int max1 = -10000;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[i] = max(b[i - 1] + a[i], a[i]);
			if(max1 < b[i]) {
				max1 = b[i];
				end = i;
			}
		}
		for(int i = end; i > 0; i--) {
			sum += a[i];
			if(sum == max1) begin = i;
		}
		printf("Case %d:\n", ++k);
		printf("%d %d %d", max1, begin, end);
		if(t != 0) printf("\n");
	}
	
}
