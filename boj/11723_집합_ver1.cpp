#include <bits/stdc++.h>
#define rnt register int
using namespace std;


int main(int argc, char **argv){
	cin.tie(0)->sync_with_stdio(false);

	int M;
	cin>>M;

	vector<int> S;

	while(M--){
		string cmd;
		cin>>cmd;

		if(cmd == "add") {
			int x; 
			cin>>x;

			bool found=false;
			for(int &s : S) {
				if(s == x) found = true;
			} 
			if(!found) S.push_back(x);
		}
		else if (cmd == "check") {
			int x; 
			cin>>x;

			bool found=false;
			for(int &s : S) {
				if(s == x) found = true;
			} 
			if(!found) printf("0\n");
			else printf("1\n");
		}
		else if (cmd == "remove") {
			int x; 
			cin>>x;

			for(auto it=S.begin(); it!=S.end(); ){
				if(*it == x) { 
					it = S.erase(it); 
				} else it++;
			}
		}
		else if (cmd == "toggle") {
			int x; 
			cin>>x;

			bool found=false;
			for(auto it=S.begin(); it!=S.end(); ){
				if(*it == x) {
					found=true;
					it = S.erase(it); 
				} else it++;
			}
			if(!found) S.push_back(x);
		}
		else if (cmd == "all") {
			S.clear();
			for(int i=1; i<=20;i++){
				S.push_back(i);
			}
		}
		else if (cmd == "empty") {
			S.clear();
		}

	}


	return 0;
}

