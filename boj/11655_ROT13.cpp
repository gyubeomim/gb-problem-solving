#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using uchar = unsigned char;

int getCharMode(char ch) {
	if(ch >= 'a' && ch <= 'z') return 1;
	else if(ch >= 'A' && ch <= 'Z') return 2;
	return 0;
}

int main(int argc, char **argv){
	string input;

	getline(cin, input);
	
	int len = input.length();
	int cur = 0;

	while(cur < len) {
		uchar ch = input[cur++];
		
		int mode = getCharMode(ch);
		if(mode == 1) {  // non-capital
			uchar next_ch = ch + 13;
			if (next_ch > 'z') {
				next_ch = 'a' + (next_ch - 'z') - 1;
			}
			printf("%c", next_ch);
		}
		else if(mode == 2) {  // capital
			uchar next_ch = ch + 13;
			if (next_ch > 'Z') {
				next_ch = 'A' + (next_ch - 'Z') - 1;
			}
			printf("%c", next_ch);
		}
		else {  // others
			printf("%c", ch);
		}
	}

}
