//main.cpp

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int K, int mId[], int sCity[], int eCity[], int mToll[]);
extern void add(int mId, int sCity, int eCity, int mToll);
extern void remove(int mId);
extern int cost(int M, int sCity, int eCity);

/////////////////////////////////////////////////////////////////////////

#define MAX_K 2000
#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_COST 400

static bool run() {
	int q;
	scanf("%d", &q);

	int n, k, m;
	int mIdArr[MAX_K], sCityArr[MAX_K], eCityArr[MAX_K], mTollArr[MAX_K];
	int mId, sCity, eCity, mToll;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				okay = true;
				scanf("%d %d", &n, &k);
				for (int j = 0; j < k; ++j) {
					scanf("%d %d %d %d", &mIdArr[j], &sCityArr[j], &eCityArr[j], &mTollArr[j]);
				}
				init(n, k, mIdArr, sCityArr, eCityArr, mTollArr);
				break;
			case CMD_ADD:
				scanf("%d %d %d %d", &mId, &sCity, &eCity, &mToll);
				add(mId, sCity, eCity, mToll);
				break;
			case CMD_REMOVE:
				scanf("%d", &mId);
				remove(mId);
				break;
			case CMD_COST:
				scanf("%d %d %d %d", &m, &sCity, &eCity, &ans);
				ret = cost(m, sCity, eCity);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("data/d1923.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}