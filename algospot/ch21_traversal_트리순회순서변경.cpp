#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> pre,in;
vector<int> Slice(const vector<int> &v, int a, int b) {
  return vector<int>(v.begin()+a, v.begin()+b);
}

void printPostOrder(const vector<int>& preorder, 
                    const vector<int>& inorder){

  const int N = preorder.size();
  if(preorder.empty()) return;

  const int root = preorder[0];

  const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
  const int R = N - 1 - L;

  printPostOrder(Slice(preorder, 1, L + 1), Slice(inorder, 0, L));
  printPostOrder(Slice(preorder, L + 1, N), Slice(inorder, L + 1, N));

  printf("%d ", root);
}

int main(int argc, char **argv){
  int C; scanf("%d",&C);
  while(C--) {
    pre.clear(), in.clear();

    scanf("%d",&N);

    for(int i=0;i<N;i++){
      int a;
      scanf("%d ", &a);
      pre.push_back(a);
    }   
    for(int i=0;i<N;i++){
      int a;
      scanf("%d ", &a);
      in.push_back(a);
    }   

    printPostOrder(pre, in);
    puts("");
  }
}
