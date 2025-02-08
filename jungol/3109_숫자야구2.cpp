struct Data {
	int strike;
	int ball;
};

extern Data query(int supose[]);

int n;
struct Info {
	int A[4], s, b;
} info[20];

int A[4];
bool used[10];

bool isPossible() {
	for (int i = 0; i < n; i++) {
		int s = 0, b = 0;
		for (int j = 0; j < 4; j++) {
			//strike
			if (A[j] == info[i].A[j]) s++;

			//ball
			for (int k = 0; k < 4; k++) {
				if (j != k && A[j] == info[i].A[k]) b++;
			}
		}
		if (info[i].s != s || info[i].b != b) return 0;
	}
	return 1;
}

bool recur(int c) {
	if (c == 4) {                              // base condition
		if (isPossible()) {
			Data ret = query(A);

			if (ret.strike == 4) return 1;

			for (int i = 0; i < 4; i++) 
				info[n].A[i] = A[i];

			info[n].s = ret.strike;
			info[n].b = ret.ball;
			n++;
		}
		return 0;
	}

	for (int i = 0; i <= 9; i++) {             
		if (used[i])continue;

		A[c] = i;
		used[i] = 1;
		bool ret = recur(c + 1);              // back tracking
		used[i] = 0;

		if (ret) return 1;
	}
	return 0;
}


void tryBest(int suppose[]) {
	n = 0;
	recur(0);
	for (int i = 0; i < 4; i++) {
		suppose[i] = A[i];
	}
}
