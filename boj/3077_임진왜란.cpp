#include <bits/stdc++.h>

using namespace std;





int main() {
	int N;

	cin >> N;





	int total=0;
	vector<string> ans;
	for(int i=0; i<N; i++) {
		string s;
		cin >> s;
		ans.push_back(s);
		total += i;
	}



	map<string, int> m;
	vector<string> res;
	for(int i=0; i<N; i++) {
		string s;
		cin >> s;

		res.push_back(s);
	}



	for(auto it : res) {
		for(int i=0; i<N; i++) {
			if(ans[i] == it) {
				// cout <<"s,i: " << it << ", " << i << endl;
				m[it] = i;
			}
		}
	}





	int count=0;

	for(int i=0; i<N; i++) {
		for(int j=i+1; j<N; j++) {
				// cout << "OUTij: " << i << ", " << j << endl;
			if(m[res[i]] < m[res[j]]) {
				// cout << "ij: " << i << ", " << j << ", " <<  endl;
				// cout << "res: " << res[i] << ", " << res[j] << ", " << m[res[i]] << ", " << m[res[j]] << endl;
				count++;
			}
		}
	}


	cout << count << "/"<< total << '\n';
	





	return 0;
}