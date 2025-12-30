#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 60005;
int k;
char S[LM];
unordered_map<string, int> hmap;    // [ string, cnt ]

int main(int argc, char **argv) {
  // freopen("d.txt","r",stdin);
  scanf("%d %s", &k, S);
  string str = S;
  int ans = 0;

  for (int i = 0; i < str.size() - k; i++) {   // n-k : 59000
    string sub = str.substr(i, k);             // k : 1000
    sort(sub.begin(), sub.end());              // k*log(k) : 10000
    ans = max(ans, ++hmap[sub]);
  }

  printf("%d\n", ans);
}