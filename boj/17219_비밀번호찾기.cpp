#include <bits/stdc++.h>

using namespace std;








int main() {
	map<string, string> memo;


	int N,M;

	cin >> N >> M;





	for(int i=0; i<N; i++) {
		string id, pw;

		cin >> id >> pw;


		// cout << "ID: " << id << ", PW: " << pw << endl;

		memo[id] = pw;

	}



	for(int i=0; i<M; i++) {
		string id;
		cin >> id;


		cout << memo[id] << '\n';
	}


	

	return 0;
}