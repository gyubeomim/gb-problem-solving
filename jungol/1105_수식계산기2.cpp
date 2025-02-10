#include <cstdio>

using ll = long long;
const int LM = 210;
char exp[LM], opStk[LM];
int opTop, numTop;
ll numStk[LM];

void calc() {
	char op = opStk[opTop];
	if (op == '+') numStk[numTop - 1] += numStk[numTop];
	else if (op == '-') numStk[numTop - 1] -= numStk[numTop];
	else if (op == '*') numStk[numTop - 1] *= numStk[numTop];
	else if (op == '/') numStk[numTop - 1] /= numStk[numTop];
	else return;  // 연산자가 유효하지 않은 경우 무시 (예: '(')
	opTop--, numTop--;
}

int main() {
	scanf("%s", exp);
	for (int i = 0; exp[i];) {
		if (exp[i] > 47) {  // 숫자인 경우
			ll d = 0;
			for (; exp[i] > 47; ++i)   // 숫자 변환
				d = d * 10 + exp[i] - '0';

			numStk[++numTop] = d;
			if (opStk[opTop] == '*' || opStk[opTop] == '/')
				calc();
		}
		else {              // 연산자인 경우
			if (exp[i] == '+' || exp[i] == '-') {
				calc();
				opStk[++opTop] = exp[i];  // 연산자 스택에 저장
			}
			else if (exp[i] == ')') {
				calc();
				opTop--;  // '(' 제거
				if (opStk[opTop] == '*' || opStk[opTop] == '/')
					calc();
			}
			else {   // '(', '*', '/' 등의 연산자를 스택에 저장
				opStk[++opTop] = exp[i];
			}
			i++;
		}
	}
	calc();  // 남은 연산 수행

	printf("%lld\n", numStk[numTop]);
}
