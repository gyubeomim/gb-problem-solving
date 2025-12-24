#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
#define X first
#define Y second

using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 10005;
int N;

struct Node{
	int l;
	int r;
};

map<int, Node> tree;
bool root_node[LM];

vector<pii> len;
vector<int> loc[LM];
int col = 0;

void inOrder(int node, int lv){
	if(node==-1) return;

	inOrder(tree[node].l, lv+1);
	loc[lv].push_back(++col);
	inOrder(tree[node].r, lv+1);
}

int main(int argc, char **argv){
	scanf("%d",&N);

	fill_n(root_node, N+1, true);

	for(int i=0;i<N;i++){
		int n,l,r;
		scanf("%d %d %d", &n,&l,&r);

		tree[n].l = l;
		tree[n].r = r;
		
		if(l!=-1) root_node[l]=false;
		if(r!=-1) root_node[r]=false;
	}

	int root = 0;
	for(int node=1;node<=N;node++){  
		if(root_node[node]) {
			root = node;
			break;
		}
	}

	inOrder(root, 1);

	int lv=1;
	while(loc[lv].size()) {
		int min = loc[lv][0];
		int max = loc[lv][loc[lv].size()-1];
		len.push_back({lv, max-min+1});
		lv++;
	}

	sort(len.begin(), len.end(), [](const pii&a, const pii&b) {
			if(a.Y==b.Y) return a.X < b.X;
			else return a.Y > b.Y;
			});

	printf("%d %d\n", len[0].X, len[0].Y);
}
