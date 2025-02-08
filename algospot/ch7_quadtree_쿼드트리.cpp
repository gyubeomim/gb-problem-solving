#include <bits/stdc++.h>
using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;

	if(head == 'b' || head == 'w') return string(1, head);

	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	// 각각 위와 아래 조각들의 위치를 바꾼다
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(int argc, char **argv){
	int T;
	scanf("%d", &T);

	while(T--){
		string quadtree;
		cin >> quadtree;
		string::iterator it = quadtree.begin();
		string ans = reverse(it);
		printf("%s\n", ans.c_str());
	}
}
