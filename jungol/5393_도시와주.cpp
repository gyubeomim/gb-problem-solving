#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

unordered_map<string, vector<string>> hmap;  // state, vector(city)

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d5555.txt", "r", stdin);
	#endif

	int N; scanf("%d", &N);
	int ans = 0;
	while(N--){
		string c,s; 
		cin >> c >>s;

		c = c.substr(0,2);

		auto it = hmap.find(c);
		if(it != hmap.end()){   // city == old state
			if(s != it->X){       // state != old state
				for(auto oldcity : it->Y){
					if(s == oldcity){
						ans++;
					}
				}
			}
		}
		hmap[s].push_back(c);
	}
	printf("%d\n", ans);
}