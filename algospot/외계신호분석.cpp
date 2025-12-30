#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N, K;

int simple(const vector<int>& signals, int k) {
  int ret = 0;
  for(int head=0; head<signals.size(); head++) {
    int sum = 0;
    for(int tail=head; tail<signals.size();tail++){
      sum += signals[tail];
      if(sum == k) ret++;
      if(sum >= k) break;
    }
  }
  return ret;
}

int optimized(const vector<int>& signals, int k) {
  int ret=0, tail=0, rangeSum=signals[0];

  for(int head=0; head<signals.size(); head++){
    // rangeSum이 k 이상인 최초의 구간을 만날때까지 tail을 옮긴다
    while(rangeSum<k && tail+1<signals.size()) 
      rangeSum += signals[++tail];

    if(rangeSum == k) ret++;

    rangeSum -= signals[head];
  }
  return ret;
}

struct RNG{
  unsigned seed;
  RNG() : seed(1983) {}
  unsigned next(){
    unsigned ret = seed;
    seed = ((seed*214013u) + 2531011u);
    return ret % 10000 + 1;
  }
};

int countRanges(){
  RNG rng;
  queue<int> Q;
  int ret = 0, rangeSum = 0;

  for(int i=0; i<N; i++){
    int newSignal = rng.next();
    rangeSum += newSignal;
    Q.push(newSignal);

    while(rangeSum > K) {
      rangeSum -= Q.front(); 
      Q.pop();
    }

    if(rangeSum == K) ret++;
  }
  return ret;
}

int main(int argc, char **argv){
  int C; scanf("%d",&C);
  while(C--) {
    scanf("%d%d", &K, &N);
    printf("%d\n", countRanges());
  }
}