#include <bits/stdc++.h>
using	namespace std;

typedef int KeyType;

struct Node {
  KeyType key;
  int priority, size;

  Node *left, *right;

  Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
  void setLeft(Node* newL) {
    left = newL;
    calcSize();
  }
  void setRight(Node* newR) {
    right = newR;
    calcSize();
  }
  void calcSize() {
    size = 1;
    if (left) size += left->size;
    if (right) size += right->size;
  }
};

typedef pair<Node*, Node*> NodePair;

// root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는 두 개의 트립으로 분리한다
NodePair split(Node* root, KeyType key){
  if(root==NULL) return NodePair(NULL,NULL);
  if(root->key < key){
    NodePair rs = split(root->right, key);
    root->setRight(rs.first);
    return NodePair(root, rs.second);
  }
  NodePair ls = split(root->left, key);
  root->setLeft(ls.second);
  return NodePair(ls.first, root);
}

// root를 루트로 하는 트립에 새 노드 node를 삽인한 뒤 결과 트립의 루트를 반환한다
Node* insert(Node* root, Node* node) {
  if (root == NULL) return node;
  // node가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라 각각 자손으로 한다
  if (root->priority < node->priority) {
    NodePair splitted = split(root, node->key);
    node->setLeft(splitted.first);
    node->setRight(splitted.second);
    return node;
  } 
  else if (node->key < root->key) root->setLeft(insert(root->left, node));
  else                            root->setRight(insert(root->right, node));

  return root;
}

// a,b가 두 개의 트립이고 max(a) < min(b) 일 때 이 둘을 합친다
Node* merge(Node*a, Node*b){ 
  if(a==NULL) return b; 
  if(b==NULL) return a;

  if(a->priority < b->priority) {
    b->setLeft(merge(a,b->left));
    return b;
  }
  a->setRight(merge(a->right, b));
  return a;
}

// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다
Node* erase(Node*root, KeyType key){
  // root를 지우고 양 서브트리를 합친 뒤 반환한다
  if(root==NULL) return root;
  if(root->key == key){
    Node* ret = merge(root->left, root->right);
    delete root;
    return ret;
  }
  if(key < root->key) root->setLeft(erase(root->left, key));
  else                root->setRight(erase(root->right, key));

  return root;
}

Node* kth(Node* root, int k) {
  // 왼쪽 서브트리를 우선 계산한다
  int ls = 0;  
  if (root->left != NULL) ls = root->left->size;
  if (k <= ls) return kth(root->left, k);
  if (k == ls + 1) return root;
  return kth(root->right, k - ls - 1);
}

int countLessThan(Node* root, KeyType key) {
  if (root == NULL) return 0;
  if (root->key >= key) return countLessThan(root->left, key);
  int ls = (root->left ? root->left->size : 0);
  return ls + 1 + countLessThan(root->right, key);
}