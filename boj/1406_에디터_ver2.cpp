#include <bits/stdc++.h>
using namespace std;

const int LM = 1000005;
char dat[LM];
int pre[LM], nxt[LM];
int unused = 1;

void insert(int addr, char num) {
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if(nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traversal() {
	int cur = nxt[0];
	while(cur != -1) {
		printf("%c", dat[cur]);
		cur = nxt[cur];
	}
}

int main(int argc, char **argv){
	string init;
	cin >> init;

	fill(pre, pre+LM, -1);
	fill(nxt, nxt+LM, -1);
	
	int cursor=0;
	for(auto c : init) {
		insert(cursor, c); cursor++;
	}

	int q;
	scanf("%d", &q);
	while(q--) {
		char op;
		scanf(" %c", &op);
		
		if(op == 'P') {
			char add;
			scanf(" %c", &add);
			insert(cursor, add);
			cursor = nxt[cursor];
		}
		else if(op == 'L') {
			if(pre[cursor] != -1) 
				cursor = pre[cursor];
		}
		else if(op == 'D') {
			if(nxt[cursor] != -1)
				cursor = nxt[cursor];
		}
		else {
			if(pre[cursor] != -1) {
				erase(cursor);
				cursor = pre[cursor];
			}
		}
	}

	traversal();
}
