#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
	string init;
	cin >> init;

	list<char> L;
	for(auto c : init) L.push_back(c);
	auto cursor = L.end();

	int q;
	scanf("%d ",&q);

	while(q--){
		char op;
		scanf(" %c",&op);

		if(op == 'P') {
			char add;
			scanf(" %c", &add);
			L.insert(cursor,add);
		}
		else if(op == 'L') {
			if(cursor != L.begin()) cursor--;
		}
		else if(op == 'D') {
			if(cursor != L.end()) cursor++;
		}
		else {
			if(cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}

	for(auto c : L) printf("%c", c);
}
