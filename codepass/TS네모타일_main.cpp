#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N 999

extern void init(int N, int mInfo[MAX_N][MAX_N]);
extern int addRectTile(int mID, int mTile[3][3]);
extern void removeRectTile(int mID);

#define CMD_INIT 0
#define CMD_ADD 1
#define CMD_REMOVE 2

static int dy[5] = { 0, 0, 1, 2, 2 };
static int dx[5] = { 0, 2, 1, 0, 2 };

static int mSeed;
static int pseudo_rand()
{
	mSeed = mSeed * 214013 + 2531011;
	return (mSeed >> 16) & 0x7fff;
}

#define MAX_SHAPE	10
static int Shape[MAX_SHAPE] = { 1, 2, 3, 4, 5, 11, 12, 13, 14, 15 };

static int Info[MAX_N][MAX_N];
static int Data[3][3];

static int N, mID;

static void info_init()
{
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			Data[i][k] = 0;
		}
	}

	for (int i = 0; i < MAX_N; i++) {
		for (int k = 0; k < MAX_N; k++) {
			Info[i][k] = 0;
		}
	}
}

static void make_info()
{
	for (int y = 0; y < N; y += 2) {
		for (int x = 0; x < N; x += 2) {
			Info[y][x] = Shape[pseudo_rand() % MAX_SHAPE];
			if (y + 1 < N && x + 1 < N) Info[y + 1][x + 1] = Shape[pseudo_rand() % MAX_SHAPE];
		}
	}
}

static void make_info_1()
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &Info[y][x]);
		}
	}
}

static bool run()
{
	int query_num, sample_1;
	scanf("%d %d", &query_num, &sample_1);

	int ans;
	bool ok = false;

	for (int q = 0; q < query_num; q++)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == CMD_INIT)
		{
			scanf("%d %d", &N, &mSeed);
			if (sample_1 == 1) make_info_1();
			else make_info();

			mID = 0;
			init(N, Info);
			ok = true;
		}
		else if (cmd == CMD_ADD)
		{
			mID++;
			for (int i = 0; i < 5; i++) scanf("%d", &Data[dy[i]][dx[i]]);
			int ret = addRectTile(mID, Data);
			scanf("%d", &ans);
			if (ans != ret) {
				ok = false;
			}
		}
		else if (cmd == CMD_REMOVE)
		{
			int id;
			scanf("%d", &id);
			removeRectTile(id);
		}
		else ok = false;
	}
	return ok;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("s_in.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	info_init();
	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}
