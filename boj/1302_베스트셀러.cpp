#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, int> book;



	for(int i=0; i<N; i++) {
		string b;
		cin >> b;


		book[b]++;
	}



	vector<pair<string,int>> v(book.begin(), book.end());


	sort(v.begin(), v.end(), [](const pair<string,int> &a, const pair<string,int> &b) {
		if(a.second != b.second) {
			return a.second > b.second;
		}
		else {
			return a.first < b.first;
		}

	});

	cout << v.front().first << '\n';


	

	return 0;
}