#include <cstdio>
int A[11][11];
int total = 0;
int sr = 0, sc = 0;
int mr = 0, mc = 0;
int er = 0, ec = 0;

bool isValid(int r, int c) {
	return r > 0 && r < 11 && c>0 && c < 11 && A[r][c];
}

void output() {
	printf("%d %d\n%d %d\n%d %d\n", sr, sc, mr, mc, er, ec);
}

bool check1(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;
	int sum = 0;
	int len = (er - sr);

	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= i; j++) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}
	return total == sum;
}

bool check2(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;
	int sum = 0;
	int len = (er - sr);

	for (int i = 0; i <= len; i++) {
		for (int j = i; j <= len; j++) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}
	return total == sum;
}

bool check3(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;
	int sum = 0;
	int len = (er - sr);

	for (int i = 0; i <= len; i++) {
		for (int j = -i; j <= i; j++) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}
	return total == sum;
}

bool check4(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;
	int sum = 0;
	int len = (er - sr);

	for (int i = 0; i <=len; i++) {
		for (int j = i; j <= 2*len-i; j++) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}
	return total == sum;
}

bool check5(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;
	int sum = 0;
	int len = (er - sr);

	for (int i = 0; i <= len; i++) {
		for (int j = 0; j >= -i; j--) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}
	return total == sum;
}

bool check6(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;
	int sum = 0;
	int len = (er - sr);

	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= (len-i); j++) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}
	return total == sum;
}


bool check7(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;

	int sum = 0;
	int len = (er - sr);
	if ((len & 1) == 1) return false;

	for (int j = 0; j >= mc-sc; j--) {
		for (int i = -j; i <= len+j; i++) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}

	return total == sum;
}

bool check8(int r, int c) {
	if (isValid(r, c) == 0) return 0;

	mr = r; mc = c;
	int sum = 0;
	int len = (er - sr);

	if ((len & 1) == 1) return false;

	for (int j = 0; j <= mc-sc; j++) {
		for (int i = j; i <= (len - j); i++) {
			if (A[sr + i][sc + j] == 0) return 0;
			sum++;
		}
	}

	//printf("%d %d", total, sum);

	return total == sum;
}



int main() {
	for (int r = 1; r <= 10; r++) {
		for (int c = 1; c <= 10; c++) {
			scanf("%1d", &A[r][c]);
			if (A[r][c] == 1) total++;
			if (A[r][c] == 1 && sr == 0) {
				sr = r;
				sc = c;
			}

			if (A[r][c] == 1) {
				er = r;
				ec = c;
			}
		}
	}

	if (sr == er && sc == ec) {
		puts("0");
		return 0;
	}
	if (check1(er, sc)) output();
	else if (check2(sr, ec)) output();
	else if (check3(er, ec - (ec-sc)*2)) output();
	else if (check4(sr, sc + (ec-sc)*2)) output();

	else if (check5(er, ec - (er-sr))) output();
	else if (check6(sr, sc + (er-sr))) output();
	else if (check7((sr+er)/2, sc - ((sr+er)/2-sr))) output();
	else if (check8((sr+er)/2, sc + ((sr+er)/2-sr))) output();
	else printf("0");


	return 0;
}
