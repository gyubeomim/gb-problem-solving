#include <cstdio>

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//                  1   2   3   4    5   6  7   8   9   10  11  12
// one-indexing

char date[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
//                   0      1      2      3      4      5      6

int main(int argc, char **argv){
	int M, D;
	scanf("%d %d", &M, &D);
	

	int total_days = 0;

	for(int m=0; m<M; m++) {
		total_days += days[m];
	}
	total_days += D;

	printf("%s", date[total_days % 7]);

	return 0;
}
