#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int gid = 0;

struct Data {
	int id,score;
};

unordered_map<string, Data> hmap;

int main(int argc, char **argv){
	FASTIO;

	#ifndef ONLINE_JUDGE
		freopen("data/d4444.txt", "r", stdin);
	#endif

	// 200'000
	int Q; cin >> Q;
	while(Q--){
		string s; 
		int score;
		
		cin >> s >> score;

		for(int i=0; i<s.size(); i++){
			char c = s[i];
			if(c >= 'A' && c <= 'Z') {
				s[i] = c - 'A' + 'a';
			}
		}

		auto it = hmap.find(s);
		if(it == hmap.end()){
			hmap[s] = {++gid, score};
		}else{
			hmap[s] = {hmap[s].id, score > hmap[s].score ? score : hmap[s].score};
		}
		
		cout << hmap[s].id << " " << hmap[s].score << '\n';

	}
}