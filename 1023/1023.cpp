#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//大整数乘法 
string big_mul(string bigint, int n)
{
	reverse(bigint.begin(), bigint.end());
	int temp = 0;
	
	for(int i = 0; i < bigint.size(); i++) {
		temp = (int)(bigint[i] - '0') * n + temp;
		bigint[i] = temp % 10 + '0';
		temp /= 10;
	}
	while(temp != 0) {
		bigint += (temp % 10 + '0');
		temp /= 10;
	}
	reverse(bigint.begin(), bigint.end());
	return bigint;
}
//大整数除法 
string big_div(string bigint, int divisor)
{
	string quotient;
	int temp = 0, quotient_index = 0;
	for (int i = 0; i < bigint.size(); i++) {
		temp = temp * 10 + (int)(bigint[i] - '0');
		if (temp < divisor) {
			if(!quotient.empty())
				quotient.push_back((char)(temp / divisor + '0'));
		}else {
			quotient.push_back((char)(temp / divisor + '0'));
			temp %= divisor;
		}
	}
	return quotient;
}


string catalan(int n)
{
	string num = "1";
	for (int i = 1; i <= n; i++) {
		num = big_mul(num, 2 * n - i + 1);
		num = big_div(num, i);
	}
	return big_div(num, n + 1);
}

int main()
{
	int n;
	while (cin >> n) {
		cout << catalan(n) << endl;
	}
	return 0;
}
