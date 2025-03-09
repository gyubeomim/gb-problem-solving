#include <bits/stdc++.h>
using namespace std;

const int LM = 1000005;
int dat[2*LM + 1];
int head = LM, tail = LM;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() { return dat[head]; }
int back() { return dat[tail-1]; }

int main(int argc, char **argv){
	int N;
	scanf("%d", &N);
	while(N--){
		string q;
		cin >> q;

		if(q == "push_back") {
			int val; cin >> val;
			push_back(val);
		}
		else if(q == "push_front") {
			int val; cin >> val;
			push_front(val);
		}
		else if(q == "pop_front") {
			if(tail==head) printf("-1\n");
			else {
				printf("%d\n", front());
				pop_front();
			}
		}
		else if(q == "pop_back") {
			if(tail==head) printf("-1\n");
			else {
				printf("%d\n", back());
				pop_back();
			}
		}
		else if (q == "size") {
			printf("%d\n", tail-head);
		}
		else if (q == "empty") {
			printf("%d\n", (tail==head));
		}
		else if (q == "front") {
			if(tail == head) printf("-1\n");
			else printf("%d\n", front());
		}
		else {  // back
			if(tail == head) printf("-1\n");
			else printf("%d\n", back());
		}
	}
	 
}
