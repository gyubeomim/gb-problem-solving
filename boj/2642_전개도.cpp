#include <cstdio>
#include <map>

int arr[6][7][7];
int (*A)[7] = arr[0];
int (*P1)[7] = arr[1];  //Attach
int (*Q1)[7];
int (*P2)[7] = arr[2];  //Flip
int (*Q2)[7];
int (*P3)[7] = arr[3];  // Rotate
int (*Q3)[7];

int B[11][6][6] = {
	1,0,0,0,0,0,
	2,3,5,4,0,0,
	6,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,3,5,4,0,0,
	0,6,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,3,5,4,0,0,
	0,0,6,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,3,5,4,0,0,
	0,0,0,6,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	0,1,0,0,0,0,
	2,3,5,4,0,0,
	0,6,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	0,1,0,0,0,0,
	2,3,5,4,0,0,
	0,0,6,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,3,0,0,0,0,
	0,6,5,0,0,0,
	0,0,4,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,0,0,0,0,0,
	6,3,0,0,0,0,
	0,5,0,0,0,0,
	0,4,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,3,0,0,0,0,
	0,6,5,0,0,0,
	0,4,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,3,5,0,0,0,
	0,6,0,0,0,0,
	0,4,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	1,0,0,0,0,0,
	2,3,0,0,0,0,
	0,6,0,0,0,0,
	0,4,5,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0
};


void Print(const char* s) {
	printf("Print A %s\n", s);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", A[i][j]);
		}
		puts("");
	}
	printf("---------------\n");
}



void AttachToWall() {
	int i = 0, j = 0;

	bool found = false;

	// If already aligned, return
	bool already_x = false;
	bool already_y = false;
	for (i = 0; i < 6; i++) {
		if (A[i][0]) already_x = true;
	}
	for (i = 0; i < 6; i++) {
		if (A[0][i]) already_y = true;
	}
	if (already_x&&already_y) return;


	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (A[i][j]) {
				found = true;
				break;
			}
		}
		if (found)break;
	}

	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 6; b++) {
			P1[a][b] = 0; // Reset
		}
	}

	//printf("Row %d %d\n", i, j);

	// Row attach
	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 6; b++) {
			//printf("a b %d %d, i, j %d %d, P %d <- A %d\n", a, b, i, j, P1[a][b], A[i + a][b]);
			if(i+a<6)
			P1[a][b] = A[i + a][b];
		}
	}

	Q1 = A;	A = P1;	P1 = Q1;

	//printf("After Row aligned\n");
	//for (int a = 0; a < 6; a++) {
	//	for (int b = 0; b < 6; b++) {
	//		printf("%d ", A[a][b]);
	//	}puts("");
	//}

	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 6; b++) {
			P1[a][b] = 0; // Reset
		}
	}


	found = false;
	for (j = 0; j < 6; j++) {
	for (i = 0; i < 6; i++) {
			//printf("i j: %d %d, A: %d\n", i, j, A[i][j]);
			if (A[i][j]) {
				found = true;
				break;
			}
		}
		if (found)break;
	}

	//printf("Col %d %d\n", i, j);

	// Col attach
	for (int a = 0; a < 6; a++) {
		for (int b = 0; b < 6; b++) {
			if(j+b<6)
			P1[a][b] = A[a][j+b];
		}
	}

	Q1 = A;	A = P1;	P1 = Q1;

	//printf("After Col aligned\n");
	//for (int a = 0; a < 6; a++) {
	//	for (int b = 0; b < 6; b++) {
	//		printf("%d ", A[a][b]);
	//	}puts("");
	//}
}

void Flip(int idx) {
	if (idx == 0) {
		AttachToWall();
		return;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			P2[i][j] = 0; // Reset
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			P2[i][j] = A[i][5 - j];  // Horizontal Flip
		}
	}

	Q2 = A;	A = P2;	P2 = Q2;

	//Print("After Flipped");

	AttachToWall();
}

void Rotate(int idx) {
	if (idx == 0) {
		AttachToWall();
		return;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			P3[i][j]=0; // Reset
		}
	}


	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			P3[i][j] = A[5 - j][i]; // Rotate 90deg
		}
	}

	Q3 = A;	A = P3;	P3 = Q3;

	//Print("After Rotated");

	AttachToWall();
}


void FindAnswer(int k) {
	bool found = false;
	
	int i, j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (A[i][j] == 1) {
				found = true;
				break;
			}
		}
		if (found) break;
	}

	int val = B[k][i][j];

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (B[k][i][j] == 7-val) {
				//printf("i,j %d %d\n", i, j);
				printf("%d\n", A[i][j]);
			}
		}
	}
}


int main() {
#ifdef _WIN32
	freopen("10.txt", "r", stdin);
#endif // _WIN32

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%d ", A[i] + j);
		}
	}
	
	bool found = false;

	for (int b = 0; b < 2; b++) {
		Flip(b);
		//Print("Flip");
		for (int a = 0; a < 4; a++) {
			Rotate(a);
			//Print("Rotation");
			bool success = false;

			for (int k = 0; k < 11; k++) {
				int count = 0;
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 6; j++) {
						if (B[k][i][j] && A[i][j]) {
							count++;
						}
					} // for j
				}// for i

				if(count==6) { // Found!
					//printf("found at k: %d", k);
					FindAnswer(k);
					return 0;
				}
			}//for k

		}// Rotate 

	}// Flip

	printf("0");


	return 0;
}
