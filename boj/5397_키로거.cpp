#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

string str;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d2222.txt", "r", stdin);
	#endif
	
	int T; scanf("%d", &T);
	while(T--){
		str.clear();
		cin >> str;

		list<char> s;
		auto sit = s.begin();

		for(int i=0; i<str.size(); i++){
			char c = str[i];
			if(c == '<'){
				if(sit != s.begin()) sit--;
			}
			else if(c == '>'){
				if(sit != s.end()) sit++;
			}
			else if(c == '-'){
				if(sit != s.begin()) {
					sit--;
					sit = s.erase(sit);
				}
			}
			else {
				s.insert(sit, c);
			}
		}

		list<char>::iterator lit;
		for(lit = s.begin(); lit != s.end(); lit++){
			printf("%c", *lit);
		}puts("");
	}
}