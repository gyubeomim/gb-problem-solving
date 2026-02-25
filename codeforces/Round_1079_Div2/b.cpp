#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    freopen("data/1079b.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n; scanf("%d", &n);

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        vector<int> blocks;
        blocks.reserve(n);
        for (int i = 1; i <= n; i++) {
            if (blocks.empty() || blocks.back() != a[i]) blocks.push_back(a[i]);
        }

        vector<char> seen(n + 1, 0);
        bool ok = true;
        for (int v : blocks) {
            if (seen[v]) { ok = false; break; }
            seen[v] = 1;
        }

        if (ok) {
            int j = 0;
            for (int i = 1; i <= n && j < (int)blocks.size(); i++) {
                if (p[i] == blocks[j]) j++;
            }
            if (j != (int)blocks.size()) ok = false;
        }
				if(ok) printf("YES\n");
				else printf("NO\n");
    }
}