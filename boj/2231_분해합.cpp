#include <bits/stdc++.h>

using namespace std;


int GetResult(int num){
	string s = to_string(num);

	int sum=num;
	for(int i=0; i<s.size(); i++){
		int a = s[i] - '0';

		sum += a;
	}

	return sum;
}

int main() {
	int n;
	cin >> n;

	for(int i=1; i<=n; i++){
		int res = GetResult(i);

		if(res == n){
			cout << i << endl;
			return 0;
		}
	}

	cout << "0" << endl;

	return 0;
}