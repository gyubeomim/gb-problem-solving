#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

struct Rect{
	int sr,sc,er,ec;

};

char getStatus(const Rect& a, const Rect& b) {
	char status = 'f';
	// a : 겹침
	// b : 선분 맞닿음
	// c : 점 맞닿음
	// d : 공통부분 없음

	int rr=0, cc=0;
	// 1: 직선
	// 2: 점
	// 3: 만나지 않음

	if(b.sr < a.er && a.sr < b.er)   rr = 1; 
	if(a.er == b.sr || b.er == a.sr) rr = 2;
	if(a.er < b.sr || b.er < a.sr)   rr = 3; 

	if(b.sc < a.ec && a.sc < b.ec)   cc = 1; 
	if(a.ec == b.sc || b.ec == a.sc) cc = 2; 
	if(a.ec < b.sc || b.ec < a.sc)   cc = 3; 

	if(rr==1 && cc==1) { status = 'a'; }
	if((rr==1 && cc==2) || (rr==2 && cc==1)) { status = 'b'; }
	if(rr==2 && cc==2) { status = 'c'; }
	if(rr==3 || cc==3) { status = 'd'; }



	return status;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d3333.txt", "r", stdin);
	#endif

	for(int i=0; i<4; i++){
		Rect A, B;

		scanf("%d%d%d%d", &A.sr,&A.sc,&A.er,&A.ec); 
		scanf("%d%d%d%d", &B.sr,&B.sc,&B.er,&B.ec); 

		char ret = getStatus(A, B);
		printf("%c\n", ret);
	}
}