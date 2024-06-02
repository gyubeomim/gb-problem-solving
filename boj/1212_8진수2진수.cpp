#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

string str2, str8;

int main(int argc, char **argv){
	cin >> str8;
		
	reverse(str8.begin(), str8.end());

	for(int i=0; i<str8.size(); i++){
		int one = ((str8[i]-'0') >> 0)%2;
		int two = ((str8[i]-'0') >> 1)%2;
		int three = ((str8[i]-'0') >> 2)%2;
		
		str2 += one +'0';
		str2 += two +'0';
		str2 += three +'0';
	}

	reverse(str2.begin(), str2.end());
	while(str2[0]=='0' && str2.size() != 1){
		str2.erase(str2.begin());
	}
	printf("%s", str2.c_str());
}

