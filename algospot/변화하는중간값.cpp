#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 200005;
int N,a,b;
ll A[LM];

struct RNG {
  int seed, a, b;
  RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}

  int next() {
    int ret = seed;
    seed = ((seed * (ll) a) + b) % 20090711;
    return ret;
  }
};

int solve(RNG rng) {
  priority_queue<int> maxpq;
  priority_queue<int, vector<int>, greater<int>> minpq;
  int ret = 0;

  for (int i = 1; i <= N; i++) {
    if (maxpq.size() == minpq.size())
      maxpq.push(rng.next());
    else
      minpq.push(rng.next());

    if (!minpq.empty() && !maxpq.empty() && minpq.top() < maxpq.top()) {
      int a = maxpq.top(), b = minpq.top();
      maxpq.pop();
      minpq.pop();
      maxpq.push(b);
      minpq.push(a);
    }
    ret = (ret + maxpq.top()) % 20090711;
  }
  return ret;
}

int main(int argc, char **argv){
  int C; scanf("%d",&C);
  while(C--) {
    scanf("%d%d%d", &N,&a,&b);

    RNG rng(a,b);
    int ans = solve(rng);
    printf("%d\n", ans); 
  }  
}