#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main(int argc, char **argv) {
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;

	str1 += str2;
	str3 += str4;

	ll num1 = stoll(str1);
	ll num2 = stoll(str3);

	printf("%lld", num1+num2);
}
