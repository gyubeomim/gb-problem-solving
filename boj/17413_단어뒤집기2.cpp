#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

void printReverseWord(string &rword) {
	reverse(rword.begin(), rword.end());
	printf("%s", rword.c_str());
	rword.clear();
}

int main(int argc, char **argv){
	string input;
	getline(cin, input);

	int len = input.length();
	int cur=0;
	string rword;

	while(cur < len) {
		char ch = input[cur];

		if(ch == '<') {
			if(!rword.empty()) 
				printReverseWord(rword);
			
			while(true) {
				char ch_end = input[cur++];
				printf("%c", ch_end);
				if(ch_end == '>') break;
			}
			cur--;
		}
		else if(ch == ' ') {
			rword.insert(rword.begin(), ch);
			printReverseWord(rword);
		}
		else {
			rword += ch;
		}
		cur++;
	}

	if(!rword.empty()){
		reverse(rword.begin(), rword.end());
		printf("%s", rword.c_str());
	}
}
