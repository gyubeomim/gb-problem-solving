#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

deque<int> D;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1011.txt", "r", stdin);
	#endif

	int Q; scanf("%d", &Q);

	while(Q--){
		int cmd; scanf("%d", &cmd);
		if(cmd == 1){
			int pos, value; scanf("%d%d", &pos, &value);
			if(pos == 0){
				D.push_front(value);
			}else{
				D.push_back(value);
			}
		}
		if(cmd == 2){
			int pos, value; scanf("%d%d", &pos, &value);

			int cnt=0;
			if(pos == 0) {
				for(auto it=D.begin(); it!=D.end(); ){
					if(*it >= value) {
						it = D.erase(it);
						cnt++;
						if(cnt >= 3) break;
					}else{
						it++;
					}
				}
			} else{
				for(auto it=D.end(); it!=D.begin(); ){
					--it;
					if(*it >= value) {
						it = D.erase(it);
						cnt++;
						if(cnt >= 3) break;
					}				
				}
			}
		}
		if(cmd == 3){
			int value; scanf("%d", &value);
			sort(D.begin(), D.end(), [&](const int& a, const int &b){
				int reta = abs(a-value);
				int retb = abs(b-value);
				if(reta == retb) return a < b;
				return reta < retb;
			});
		}
		if(cmd == 4){
			int pos; scanf("%d", &pos);
			if(pos == 0){
				for(int i=0; i<D.size(); i++){
					printf("%d ", D[i]);
				}puts("");
			}
			else{
				for(int i=D.size()-1; i>=0; i--){
					printf("%d ", D[i]);
				}puts("");
			}
		}
	}
}