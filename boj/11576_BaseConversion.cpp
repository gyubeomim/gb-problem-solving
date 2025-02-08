#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int A,B;
int N;
string As;
int decimal;
string Bs;

char letter[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
//                                                        10  11  12  13  14 15  16  17   18  19 20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35   

int stringToDecimal(char ch){
	if(ch >= 'A' && ch <= 'Z') 
		return ch - 'A' + 10;
	else
		return ch - '0';
}

void convertAToDecimal(){
	decimal = 0;
	for(int j=0; j<As.size(); j++) {
		int n = stringToDecimal(As[j]);
		// printf("n %d\n", n);
		decimal = decimal*A + n;
	}
}

void convertDecimalToB(){
	Bs.clear();
	
	while(decimal>1){
		int piece= decimal % B;
		decimal /= B;
		Bs += letter[piece];
	}
	if(decimal != 0) Bs += letter[decimal];

	reverse(Bs.begin(), Bs.end());
}

int main(int argc, char **argv){
	scanf("%d %d", &A, &B);
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int n;
		scanf("%d", &n);
		As += letter[n];
	}

	convertAToDecimal();
	convertDecimalToB();
	for(int i=0; i<Bs.size(); i++){
		printf("%d ", stringToDecimal(Bs[i]));
	}
}
