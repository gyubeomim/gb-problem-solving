#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N, Q;

struct myHash{
  ll operator() (const pii& t) const {
    return (ll)t.first*N + t.second;
  }
};

int cnt[4];
unordered_map<pii, int, myHash> hmap;  // [r*N+c, user]

int main(int argc, char **argv) {
  // freopen("d.txt", "r", stdin);
  scanf("%d%d", &N, &Q);
  int r, c, i, user;
  for (int i = 0; i < Q; i++) {
    user = i % 4;
    scanf("%d%d", &r, &c);

    pii key = { r, c };
    auto it = hmap.find(key);
    
    if (it == hmap.end()) {
      hmap[key] = user;
      cnt[user]++;
    } else {
      if (it->second == user) {
        cnt[user]--;
        hmap.erase(it);
      } else {
        if (cnt[user] < cnt[it->second]) {
          cnt[user]++;
          cnt[it->second]--;
          it->second = user;
        }
      }
    }
  }
  for (int c : cnt) printf("%d\n", c);
}