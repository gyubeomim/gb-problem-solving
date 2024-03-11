#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Rect {
	int sx, sy, ex, ey;
};

void MakeRect(Rect &r, int sx, int sy, int ex, int ey) {
	r.sx = sx;
	r.sy = sy;
	r.ex = ex;
	r.ey = ey;
}

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
	Rect a, b, c;
	int sx, sy, ex, ey;


	for (int i = 0; i < 4; i++) {
		scanf("%d%d%d%d", &a.sx, &a.sy, &a.ex, &a.ey);
		scanf("%d%d%d%d", &b.sx, &b.sy, &b.ex, &b.ey);
		c.sx = max(a.sx, b.sx);
		c.sy = max(a.sy, b.sy);
		c.ex = min(a.ex, b.ex);
		c.ey = min(a.ey, b.ey);

		if (c.sx > c.ex || c.sy > c.ey) puts("d");
		else if (c.sx < c.ex &&c.sy < c.ey) puts("a");
		else if (c.sx == c.ex &&c.sy == c.ey) puts("c");
		else puts("b");
	}

	return 0;
}
