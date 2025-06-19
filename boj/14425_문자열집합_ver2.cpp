#include <bits/stdc++.h>
using namespace std;

const int LM = 500*10000+5;
int N,M;

int c2i(char c) { return c-'a'; }

struct TrieNode {
	TrieNode* child[26];
	bool terminal;

	TrieNode() :terminal(false){
		memset(child, 0, sizeof(child));
	}
	~TrieNode(){
		for(int i=0; i<26; i++){
			if(child[i]) delete child[i];
		}
	}

	void insert(const char* key){
		if(*key==0) terminal = true;
		else {
			int next = c2i(*key);
			if(child[next] == NULL) child[next] = new TrieNode();
			child[next]->insert(key+1);
		}
	}

	TrieNode* find(const char* key){
		if(*key==0) return this;
		int next = c2i(*key);
		if(child[next] == NULL) return NULL;
		return child[next]->find(key+1);
	}
};


int main(int argc, char **argv){
	freopen("s_in_1345.txt", "r", stdin);

	scanf("%d%d",&N,&M);

	TrieNode trie;

	while(N--){
		string s; cin >> s;
		trie.insert(s.c_str());
	}

	int ans = 0;

	while(M--) {
		string s; cin >> s;
		TrieNode* t = trie.find(s.c_str());
		if(t != nullptr && t->terminal) ans++;
	}

	printf("%d\n", ans);
}