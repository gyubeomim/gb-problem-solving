#include <bits/stdc++.h>

using namespace std;


int main() {
	map<string, int> m;

	string s;
	int cnt;
	while(std::getline(cin, s)){
		m[s]++;
		cnt++;

		//cout << "input: " << s << ", " << m[s] << endl;
	}

	cout << fixed;
	cout.precision(4);

	for(auto it : m) {
		double portion = it.second * 100 / (double)cnt;
		cout << it.first << " " << portion << '\n';
	}



	return 0;
}
