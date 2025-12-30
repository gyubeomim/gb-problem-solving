#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N;
deque<int> A;
vector<int> B;
stack<int> S;

int main(int argc, char **argv){
  int C; scanf("%d",&C);
  while(C--) {
    scanf("%d",&N);

    A.clear();
    B.clear();
    while(!S.empty()) S.pop();

    for(int i=0;i<N;i++){
      int a;
      scanf("%d",&a); 
      A.push_back(a);
    }

    for(int i=1;i<=N;i++){
      B.push_back(i);
    }

    while(!A.empty()){
      int a = A.back(); A.pop_back();
      auto it = B.end() - a - 1;
      int b = *it; B.erase(it);

      S.push(b);
    }

    while(!S.empty()){
      int q = S.top(); S.pop();
      printf("%d ", q);
    } puts("");

  }
}