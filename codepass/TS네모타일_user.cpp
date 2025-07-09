#include <bits/stdc++.h>
using namespace std;
#define MAX_N 999

enum { LM=999, TLM=20005, HLM=100000, INF=(int)2e9 };
int N;
int used[LM][LM];
int tiles[LM];
vector<int> htab[HLM];

int dr[] = {0,2,1,0,2};
int dc[] = {2,2,1,0,0};

void init(int N, int mInfo[MAX_N][MAX_N])
{
	memset(used, 0, sizeof(used));
	for(int i=0;i<HLM;i++) htab[i].clear();

	::N = N;

	for(int i=0;i<N;i++){
		for(int j=i%2; j<N; j+=2) {
			int &val = --mInfo[i][j];  // 1,2,3,4,5,11,12,13,14,15 --> 0~9
			if(val > 4) val -= 5;
		}
	}

	for(int i=0;i<=N-3;i++){
		for(int j=i%2; j<=N-3; j+=2) {
			int key=0, nutCnt = 0;
			for(int k=0; k<5; k++) {
				int r = i+dr[k];
				int c = j+dc[k];
				if(mInfo[r][c] > 4) nutCnt++;  // 너트인 경우 카운트 증가
				key = key*10 + mInfo[r][c];
			}
			if(nutCnt < 4) continue;
			htab[key].push_back(i*10000 + j);
		}
	}
}

int Find(int key){
	for(int rc : htab[key]) {
		int r = rc/10000;
		int c = rc%10000;
		int i= 0;
		for(;i<5;i++){
			int nr = r+dr[i];
			int nc = c+dc[i];
			if(used[nr][nc]) break;
		}
		if(i == 5) return rc;
	}
	return INF;
}

int w[] = { 10000, 1000, 100, 10, 1 };

int addRectTile(int mID, int mTile[3][3])
{
	tiles[mID] = -1;
	
	int needKey=0, boltNum=-1, nutPos=-1;
	for(int i=0; i<5; i++){
		int r = dr[i];
		int c = dc[i];
		int val=0;

		if(mTile[r][c] > 5) {
			boltNum = mTile[r][c] - 11;
			nutPos = i;
			needKey = needKey*10;
		}
		else {
			int nutNum = mTile[r][c] + 4;
			needKey = needKey*10 + nutNum;
		}
	}

	int ret = INF;
	if(boltNum == -1) {
		ret = Find(needKey);
	}
	else {
		ret = Find(needKey + boltNum*w[nutPos]);
		for(int i=5; i<10; i++){
			int rv = Find(needKey + i*w[nutPos]);
			ret = min(ret, rv);
		}
	}

	if(ret == INF) return -1;
	tiles[mID] = ret;

	
	int r = ret/10000;

	return 0;
}

void removeRectTile(int mID)
{
}

