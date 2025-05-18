#include <bits/stdc++.h>
using namespace std;

const int LM = 105;
int N;
int x[LM], y[LM], radius[LM];

int longest;  // 지금까지 찾은 가장 긴 잎-잎 경로의 길이를 저장한다

struct Tree{
  vector<Tree*> children;
};

// 성벽 a가 성벽 b를 포함하는지 확인한다
bool enclose(int a, int b) {
  if(radius[a] > radius[b]) {
    double centerDist = pow(y[a] - y[b], 2) + pow(x[a] - x[b], 2);
    double radiusDist = pow(radius[a] - radius[b], 2);  // 두 성벽 반지름 차이의 제곱
    if(centerDist < radiusDist) return true;
  }
  return false;
}

// parent는 child를 꼭 직접 포함해야 한다
bool isChild(int parent, int child){
  if(!enclose(parent, child)) return false;

  for(int i=0;i<N;i++){
    if(i != parent && i != child && enclose(parent, i) && enclose(i, child)) 
      return false;
  }

  return true;
}

Tree* getTree(int root){
  Tree* ret = new Tree();
  for(int i=0; i<N; i++){
    // i 성벽이 root 성벽에 직접적으로 포함되어 있다면 
    // 트리를 만들고 자손 목록에 추가한다
    if(isChild(root, i)) 
      ret->children.push_back(getTree(i));
  }
  return ret;
}

// root를 루트로 하는 서브트리의 높이를 반환한다
int height(Tree* root) {
  vector<int> heights;
  for (int i = 0; i < root->children.size(); i++) {
    heights.push_back(height(root->children[i]));
  }

  if (heights.empty()) return 0;

  sort(heights.begin(), heights.end());

  if (heights.size() >= 2) 
    longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

  return heights.back() + 1;
}

// 두 노드 사이의 가장 긴 경로의 길이를 계산한다
int solve(Tree* root){
  longest = 0;
  int h = height(root);     
  return max(longest, h); // 트리의 높이와 최대 잎-잎 경로의 길이 중 큰 것을 선택한다
}

int main(int argc, char **argv){
  // freopen("d.txt", "r", stdin);
  int C; scanf("%d",&C);
  while(C--) {
    scanf("%d",&N);

    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(radius,0,sizeof(radius));

    for(int i=0;i<N;i++){
      scanf("%d%d%d",&x[i],&y[i],&radius[i]);
    }
    Tree* root = getTree(0);
    printf("%d\n", solve(root));
  }
}
