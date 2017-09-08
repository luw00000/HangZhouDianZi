
#include<iostream>
using namespace std;

int main()
{
	int t, n, m, num;
	cin >> t;
	while(t--) {
		num = 0;
		while(cin >> n >> m && n != 0) {
			num++;
			int count = 0;
			for(int i = 1;i < n;i++) {
				for(int j = i + 1;j < n;j++) {
					int tmp = (i * i + j * j + m) % (i * j);
					if(tmp == 0) count++;
				}
			}
			cout << "Case " << num << ": " << count << endl;
		}
		if(t) cout << endl;
	}
}
