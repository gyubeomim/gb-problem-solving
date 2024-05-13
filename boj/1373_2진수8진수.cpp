#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

string str2, str8;

int main(int argc, char **argv){
	cin >> str2;
		
	reverse(str2.begin(), str2.end());

	int threebit=0;

	for(int i=0; i<str2.size(); i++){
		threebit += (str2[i]-'0') * pow(2, i%3);

		if((i+1)%3 == 0 || i+1 == str2.size()) {
			str8 += threebit+'0';
			threebit = 0;
		}
	}

	reverse(str8.begin(), str8.end());
	printf("%s", str8.c_str());

}

