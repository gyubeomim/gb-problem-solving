#include <cstdio>

using ll = long long;

int main() {
	int w, h;
	scanf("%d %d", &w, &h);

	int ax, ay;
	scanf("%d %d", &ax, &ay);

	int t;
	scanf("%d", &t);

	int x, y;
	x = (ax + t) % (2 * w);
	y = (ay + t) % (2 * h);

	if (x > w) x = 2 * w - x;
	if (y > h) y = 2 * h - y;

	printf("%d %d", x, y);

	return 0;
}
