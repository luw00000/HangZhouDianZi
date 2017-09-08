
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int n;
	char a[10001];
	cin >> n;
	while(n--) {
		int count = 1, i = 1;
		scanf("%s", &a);
		for(i = 1;i < strlen(a);i++) {
			if(a[i] == a[i - 1]) count++;
			else {
				if(count != 1) cout << count;
				cout << a[i - 1];
				count = 1;
			}
		}
		if(count != 1) cout << count << a[i - 1];
		else cout << a[i - 1];
		cout << endl;
	}
	return 0;
}
