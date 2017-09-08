#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	char a[100], b[100];
	int flag[200];
	while(cin >> n) {
		cin >> a;
		cin >> b;
		stack<char> s;
		int j = 0, i = 0;
		for(;i <= n;) {
			if(s.empty() && i == n) break;
			if(s.empty()) {
				s.push(a[i]);
				flag[i + j] = 0;
				i++;
			}else {
				if(s.top() != b[j]) {
					s.push(a[i]);
					flag[i + j] = 0;
					i++;
				}else {
					s.pop();
					flag[i + j] = 1;
					j++;
				}
			}
		}
		
		if(s.empty()) {
			cout << "Yes." << endl;
			for(int i = 0;i < 2 * n;i++) {
				if(flag[i] == 1) cout << "out" << endl;
				else cout << "in" << endl;
			}
		}else {
			cout << "No." << endl;
		}
		cout << "FINISH" << endl;
	}
	
}
