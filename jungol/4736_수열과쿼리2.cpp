#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

set<int> S;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d4736.txt", "r", stdin);
	#endif

		int T; scanf("%d",&T);
		while(T--) {

			int Q; scanf("%d", &Q);
			S.clear();
			while(Q--){
				string cmd; cin >> cmd;
				if(cmd == "insert")	{
					int x; scanf("%d", &x);
					S.insert(x);
				}
				if(cmd == "erase")	{
					int x; scanf("%d", &x);
					auto sit = S.find(x);
					if(sit != S.end()) {
						S.erase(sit);
					}
				}
				if(cmd == "update")	{
					int x, y; scanf("%d%d", &x, &y);
					auto sit = S.find(x);
					auto sit2 = S.find(y);
					if(sit2 == S.end() && sit != S.end()) {
						S.erase(sit);
						S.insert(y);
					}
				}
				if(cmd == "front")	{
					int c; scanf("%d", &c);

					if(S.empty()){ printf("empty\n"); }
					else{
						if(S.size() < c) {
							auto sit = prev(S.end(), 1);
							printf("%d\n", *sit);
						}else{
							auto sit = next(S.begin(), c-1);
							printf("%d\n", *sit);
						}
					}
				}
				if(cmd == "back")	{
					int c; scanf("%d", &c);

					if(S.empty()){ printf("empty\n"); }
					else{
						if(S.size() < c) {
							auto sit = S.begin();
							printf("%d\n", *sit);
						}else{
							auto sit = prev(S.end(), c);
							printf("%d\n", *sit);
						}
					}
				}
			}

		}
}