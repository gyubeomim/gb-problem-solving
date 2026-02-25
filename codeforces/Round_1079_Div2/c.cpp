#include <bits/stdc++.h>
using ll = long long;
using i128 = __int128;
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data/1079c.txt", "r", stdin);
	#endif
    int t; scanf("%d", &t);
    while (t--) {
        ll p, q;
        scanf("%lld%lld", &p,&q);

        i128 s = (i128)3 * p - (i128)2 * q; 

        if (s == 0) {
            cout << "Bob\n";
            continue;
        }
        if (s < 0) {
            cout << "Alice\n";
            continue;
        }

        ll m = min(p, q - 1);
        if (s <= (i128)m) cout << "Bob\n";
        else cout << "Alice\n";
    }
}