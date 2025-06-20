#include <bits/stdc++.h>
using namespace std;

const int ALPHA=26;

int N, M;

int toNumber(char ch) { return ch-'A'; }

struct TrieNode {
	TrieNode* children[ALPHA];
	int terminal; // 이 노드에서 종료하는 문자열의 번호, 없으면 -1
	int first;

	TrieNode():terminal(-1), first(-1) {
		memset(children, 0, sizeof(children));
	}

	~TrieNode(){
		for(int i=0; i<ALPHA; i++){
			if(children[i]) delete children[i];
		}
	}

	// 이 노드를 루트로 하는 트라이에 문자열 key를 추가한다
	void insert(const char* key, int id){
		if(first==-1) first = id;

		// 문자열이 끝나면 terminal만 참으로 바꾸고 종료
		if(*key == 0) terminal = id;
		else {
			int next = toNumber(*key);
			if(children[next] == NULL) 
				children[next] = new TrieNode();
			children[next]->insert(key+1, id);  // 해당 자식의 노드로 재귀 호출
		}
	}

	// 이 노드를 루트로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다
	// 없으면 NULL을 반환한다
	TrieNode* find(const char* key){
		if(*key == 0) return this;
		int next = toNumber(*key);
		if(children[next] == NULL) return NULL;
		return children[next]->find(key+1);
	}

	// 이 노드까지 타이핑해 왔을 때 번호 id인 key를 타이핑하기 위해 최소 몇 번의 키를 더 눌러야 하는가?
	int type(const char* key, int id){
		if(*key==0) return 0;         // 문자열 종료시
		if(first == id) return 1;     // 이 노드에서 추천되는 문자열이 이 문자열이면 탭 누르고 종료
		int next = toNumber(*key);    // 아니면 다음 문자 타이핑
		return 1 + children[next]->type(key+1, id);
	}
};

// 사전을 나타내는 트라이가 주어질 때 단어 word를 타이핑하는데 몇 번이나 키를 눌러야 하는가?
int countKeys(TrieNode* trie, const char* word){
	TrieNode* node = trie->find(word);            // 이 문자열에 사전에 있는지 확인하고 있다면 번호를 구한다
	if(node == NULL || node->terminal == -1) return int(strlen(word));  // 사전에 없으면 직접 타이핑
	return trie->type(word, node->terminal);      // 탐색하면서 타이핑할 방법을 찾는다
}

// 입력에 주어지는 단어들을 정렬해서 트라이로 변환한다
TrieNode* readInput() {
	// 단어들을 출현 빈도의 내림차순, 단어의 오름차순으로 정렬한다
	vector<pair<int, string>> input;
	for(int i=0; i<N; i++){
		string s;
		int freq;
		cin >> s >> freq;
		input.push_back( {-freq, s});
	}

	sort(input.begin(), input.end());

	// 이 때 앞에 있는 단어일수록 우선순위가 높다
	// 배열의 인덱스를 각 단어의 번호로 쓰자
	TrieNode* trie = new TrieNode();
	for(int i=0; i<N; i++)
		trie->insert(input[i].second.c_str(), i);
	trie->first = -1;

	return trie;
}


int main(int argc, char **argv){
	//freopen("s_in_2256.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--){
		scanf("%d%d", &N, &M);

		TrieNode* trie = readInput();

		int ans = M-1;
		for(int i=0; i<M; i++){
			string s; cin>>s;
			ans += countKeys(trie, s.c_str());
		}
		printf("%d\n", ans);
	}
}
