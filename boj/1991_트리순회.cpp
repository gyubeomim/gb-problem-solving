#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

struct Node{
	char left;
	char right;
};

int N;
map<char, Node> tree;

// 전위순회
void preOrder(char node){
	if(node=='.') return;
	printf("%c", node);
	preOrder(tree[node].left);
	preOrder(tree[node].right);
}

// 중위순회
void inOrder(char node){
	if(node=='.') return;
	inOrder(tree[node].left);
	printf("%c", node);
	inOrder(tree[node].right);
}

// 후위순회
void postOrder(char node){
	if(node=='.') return;
	postOrder(tree[node].left);
	postOrder(tree[node].right);
	printf("%c", node);
}

int main(int argc, char **argv){
	scanf("%d", &N); 

	for(int i=0;i<N;i++){
		char node, left, right;
		cin >> node >> left >> right;
		tree[node].left = left;
		tree[node].right = right;
	}

	preOrder('A'); printf("\n");
	inOrder('A'); printf("\n");
	postOrder('A'); printf("\n");
}
