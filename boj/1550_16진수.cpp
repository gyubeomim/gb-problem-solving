#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>

#define pii pair<int,int>
#define ll long long

using namespace std;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	char S[10];

	scanf("%s",S);
	
	int ret=0;
	for(int i=0;S[i];i++){
		if(S[i] < 'A') ret = ret*16 + S[i]-'0';
		else ret = ret*16 + S[i]-'A'+10;
	}

	printf("%d",ret);

	return 0;
}
