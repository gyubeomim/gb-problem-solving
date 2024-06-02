#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

char N[100];
int B;

int charToInt(char c) {
	if(isdigit(c)) {
		return c - '0';
	}
	else if(isalpha(c)) {
		return toupper(c) - 'A' + 10;
	}
	return 0;
}

void convertToDecimal(const string &N, int B) {
	int decimal=0;

	for(char digit : N) {
		decimal = decimal * B + charToInt(digit);
	}

	printf("%d", decimal);
}

int main(int argc, char **argv){
	scanf("%s", N);
	scanf("%d", &B);
	
	convertToDecimal(string(N), B);
}
