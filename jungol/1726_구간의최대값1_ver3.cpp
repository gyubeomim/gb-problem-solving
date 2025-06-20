// 세그먼트 트리 : 업데이트 및 쿼리 (구조체 버전)
#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using pii = std::pair<int,int>;
using namespace std;

const int LM = 50005;
const int TLM = 1<<17; // 131072

int N, Q;

struct SegTree{
  int n;                 // 배열의 길이
  vector<int> tree;      // 각 구간의 최소치
  
  SegTree(const vector<int>& arr) {
    n = arr.size();
    tree.resize(n*4);
    init(arr, 0, n-1, 1);
  }
  // node가 arr[l ... r] 배열을 표현할 때 node를 루트로 하는 서브트리를 초기화하고 이 구간의 최소치를 반환한다
  int init(const vector<int>& arr, int s, int e, int node){
    if(s==e) return tree[node] = arr[s];
    
    int m = (s+e)/2;
    int smin = init(arr, s, m, node*2);
    int emin = init(arr, m+1, e, node*2+1);
    return tree[node] = max(smin, emin);
  }
  
  int query(int s, int e, int node, int qs, int qe) {
    if(e < qs || qe < s) return INT_MIN;
    if(qs >= s && qe <= e) return tree[node];
    
    int m = (qs+qe)/2;
    return max( query(s, e, node*2, qs, m), 
                query(s, e, node*2+1, m+1, qe) );
  }
  
  int query(int s, int e) { return query(s, e, 1, 0, n-1); }
  
  int update(int idx, int nval, int node, int qs, int qe) {
    // idx가 노드가 표현하는 구간과 상관없는 경우엔 무시한다
    if(idx < qs || qe < idx) return tree[node];
    if(qs == qe) return tree[node] = nval;
    
    int m = (qs+qe)/2;
    return tree[node] = max(update(idx, nval, node*2, qs, m),
                            update(idx, nval, node*2+1, m+1, qe) );
  }
  
  int update(int idx, int nval) { return update(idx, nval, 1, 0, n-1); }
};   

int main(int argc, char **argv){
  //freopen("s_in_1123.txt", "r", stdin);
  FASTIO;
  cin >> N >> Q;

  vector<int> arr(N);
  for(int i = 0; i < N; i++) {
      cin >> arr[i];
  }

  SegTree seg(arr);

  while (Q--) {
      int s, e; cin >> s >> e;
      int ans = seg.query(s - 1, e - 1);
      cout << ans << '\n';
  }
}