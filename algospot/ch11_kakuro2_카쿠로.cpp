#include <bits/stdc++.h>
using namespace std;

const int LM = 55;
const int WHITE=1;
const int BLACK=0;

const int dx[] = {0,1};
const int dy[] = {1,0};

// cand[len][sum][known] = getCandidates(len, sum, known)
int cand[10][46][1024]; 

// color: 각 칸의 색깔 (0=검은칸 혹은 힌트칸, 1=흰 칸)
// value: 각 흰칸에 쓴 숫자(아직 쓰지 않은 칸은 0)
// hint: 각 칸에 해당하는 두 힌트의 번호
int N;
int color[LM][LM], value[LM][LM], hint[LM][LM][2];

// sum: 힌트 칸에 쓰인 숫자
// len: 힌트 칸에 해당하는 흰 칸의 수
// known: 힌트 칸에 해당하는 흰 칸에 쓰인 숫자들의 집합
int Q;
int sum[LM*LM], len[LM*LM], known[LM*LM];

int maskSum[1024], maskLen[1024];

// mask에 속한 원소들의 개수를 반환한다
int getSize(int mask) { return maskLen[mask]; }
// mask에 속한 원소들의 합을 반환한다
int getSum(int mask) { return maskSum[mask]; }

void calcMasks(){
	memset(maskSum,0,sizeof(maskSum));
	memset(maskLen,0,sizeof(maskLen));
	for(int mask=0; mask<1024; mask++){
		for(int i=0; i<10; i++){
			if(mask & (1<<i)){
				maskSum[mask] += i;
				maskLen[mask]++;
			}
		}
	}
}

#if 0
// len칸의 합이 sum이고 이 칸들에 이미 쓰인 수의 집합이 known일 때 
// 나머지 칸에 들어갈 수 있는 숫자의 집합을 반환한다
int getCandidates(int len, int sum, int known){
	// 조건에 부합하는 집합들의 교집합
	int allSets=0;

	// 1~9의 부분집합(즉 모든 짝수)를 모두 생성하고 그 중
	for(int set=0; set<1024; set+=2){
		// known을 포함시키고 크기가 len이며 합이 sum인 집합을 모두 찾는다
		if((set & known) == known && getSize(set) == len 
				&& getSum(set) == sum) 
				allSets |= set;
	}

	// known에 이미 속한 숫자들은 답에서 제외한다
	return allSets & ~known;
}
#endif

// cand[][][]를 미리 계산해둔다
void generateCandidates(){
	memset(cand, 0, sizeof(cand));
	// 1~9의 부분집합을 전부 생성한다
	for(int set=0; set<1024; set+=2){
		int l = getSize(set), s = getSum(set);
		// set의 모든 부분집합에 대해 cand[][][]를 갱신한다
		int subset = set;
		while(1){
			// 전체 숫지의 집합이 set이 되도록 나머지 숫자들을 채워넣을 수 있다
			cand[l][s][subset] |= (set & ~subset);
			if(subset == 0) break;
			subset = (subset-1) & set;
		}
	}
}

// (x,y)에 val을 쓴다
void put(int x, int y, int val){
	for(int h=0; h<2; h++)
		known[hint[x][y][h]] += (1<<val);
	value[x][y] = val;
}

// (x,y)에 쓴 val을 지운다
void remove(int x, int y, int val){
	for(int h=0; h<2; h++)
		known[hint[x][y][h]] -= (1<<val);
	value[x][y] = 0;
}

// 힌트 번호가 주어질 때 후보의 집합을 반환한다
int getCandHint(int hint){
	return cand[len[hint]][sum[hint]][known[hint]];
}

// 좌표가 주어질 때 해당 칸에 들어갈 수 있는 후보의 집합을 반환한다
int getCandCoord(int x, int y){
	return getCandHint(hint[x][y][0]) & getCandHint(hint[x][y][1]);
}

// value[][]에 적힌 값을 출력한다
void printSolution() {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(j==0) printf("%d", value[i][j]);
			else printf(" %d", value[i][j]);
		}
		puts("");
	}
}

bool search(){
	// 아직 숫자를 쓰지 않은 흰 칸 중 후보의 수가 최소인 칸을 찾는다
	int y=-1, x=-1, minCands=1023;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(color[i][j] == WHITE && value[i][j] == 0) {
				int cands = getCandCoord(i,j);
				if(getSize(minCands) > getSize(cands)) {
					minCands = cands;
					x=i,y=j;
				}
			}
		}
	}
	// 이 칸에 들어갈 숫자가 없으면 실패
	if(minCands==0) return false;
	// 모든 칸이 채워졌으면 출력하고 종료한다
	if(x==-1) {
		printSolution();
		return true;
	}

	// 숫자를 하나씩 채워보자
	for(int val=1; val<=9; val++){
		if(minCands & (1<<val)){
			put(x,y,val);
			if(search()) return true;
			remove(x,y,val);
		}
	}
	return false;
}

int main(int argc, char **argv){
	// freopen("data/d13331.txt", "r", stdin);

	calcMasks();
	generateCandidates();

	int C; scanf("%d", &C);
	while(C--) {
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%d", &color[i][j]);
			}
		}

		scanf("%d", &Q);
		memset(hint, -1, sizeof(hint));
		for(int i=0; i<Q; i++){
			int x,y,d;
			scanf("%d%d%d%d", &x,&y,&d,&sum[i]);
			x--;y--;
			len[i]=0;
			while(1){
				x += dx[d];
				y += dy[d];
				if(x>=N || y>=N || color[x][y]==BLACK) break;
				hint[x][y][d] = i;
				len[i]++;
			}
		}

		memset(known, 0, sizeof(known));
		memset(value, 0, sizeof(value));
		search();
	}
}