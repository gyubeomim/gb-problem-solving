#include <bits/stdc++.h>

using namespace std;










int bfs(vector<string> init, vector<string> dest) {
	set<vector<string>> discover;
	map<vector<string>, int> depth;
	queue<vector<string>> Q;


	discover.insert(init);
	depth.insert(make_pair(init, 0));
	Q.push(init);









	while(!Q.empty()) {
		vector<string> here = Q.front();
		Q.pop();


		if(here == dest) {
			return depth[here];
		}




		for(int i=0;i<3;i++) {
			for(int j=0; j<3; j++) {
					if(i == j) continue;
					if(here[i].size() == 0) continue;




					vector<string> there = here;
					string from = there[i];
					string to   = there[j];


					char from_top = there[i].back();
					from.pop_back();
					to += from_top;



					there[i] = from;
					there[j] = to;


					if(discover.count(there) == 0) {

						discover.insert(there);
						depth.insert(make_pair(there, depth[here]+1));
						Q.push(there);

					}


			}
		}

	}

	return -1;
}












int main() {

	vector<string> init(3);
	vector<string> dest(3);

		int An=0, Bn=0, Cn=0;






	for(int i=0; i<3; i++) {

		int N;
		string tmp;

		cin >> N;



		if(N !=0)
			cin >> tmp;
		else 
			tmp = "";





		for(int j=0; j<N; j++) {
				if(tmp[j] == 'A') An++;
				else if(tmp[j] == 'B') Bn++;
				else if(tmp[j] == 'C') Cn++;
		}

		init[i] = tmp;

	}





	for(int i=0; i<An; i++) {
		dest[0] += 'A';
	}

	for(int i=0; i<Bn; i++) {
		dest[1] += 'B';
	}

	for(int i=0; i<Cn; i++) {
		dest[2] += 'C';
	}







	cout << bfs(init, dest);

	



	return 0;

}


