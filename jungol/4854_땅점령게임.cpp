#include <bits/stdc++.h>
#define X first
#define Y second
using ll = long long;
using namespace std;

int N,Q;
int cnt[4];
unordered_map<ll, int> hmap;   // [r*N+c, user]

int main(int argc, char **argv){
	scanf("%d%d",&N,&Q);

	for (int i = 0; i < Q; i++) {
		int user = i%4;
		int r, c;
		scanf("%d%d", &r, &c);

		ll key = (ll)r*N + c;
		auto it = hmap.find(key);
		if(it == hmap.end()) {
			hmap[key] = user;
			cnt[user]++;
		}
		else {
			if(it->Y == user) {
				cnt[user]--;
				hmap.erase(it);
			}
			else {
				if(cnt[user] < cnt[it->Y]){
					cnt[user]++;
					cnt[it->Y]--;
					it->Y = user;
				}
			}
		}
	}
	for (int c : cnt) 
		printf("%d\n", c);
}
