#include <bits/stdc++.h>
#define rnt register int
using namespace std;

constexpr int LM = 25;
int S[LM] = {0};
bool found = false;

int main(int argc, char **argv){
	cin.tie(0)->sync_with_stdio(false);

	int M, x;
	scanf("%d", &M);


	while(M--){
		char cmd[20];
		scanf("%s", cmd);

		if(strcmp(cmd,"add")==0) {
			scanf("%d", &x);

			found=false;
			for(int i=0; i<LM; i++){
				if(S[i] && i == x) found = true;
			} 
			if(!found) S[x] = 1;
		}
		else if (strcmp(cmd,"check")==0) {
			scanf("%d", &x);

			found=false;
			for(int i=0; i<LM; i++){
				if(S[i] && i == x) found = true;
			}
			if(!found) printf("0\n");
			else printf("1\n");
		}
		else if (strcmp(cmd,"remove")==0) {
			scanf("%d", &x);

			for(int i=0; i<LM; i++){
				if(S[i] && i == x) S[i] = 0;
			}
		}
		else if (strcmp(cmd,"toggle")==0) {
			scanf("%d", &x);

			found=false;
			for(int i=0; i<LM; i++){
				if(S[i] && i==x) found=true, S[i] = 0;
			}
			if(!found) S[x] = 1;

		}
		else if (strcmp(cmd,"all")==0) {
			for(int i=0; i<LM;i++){
				S[i] = 1;
			}
		}
		else if (strcmp(cmd,"empty")==0) {
			memset(S, 0, sizeof(S));
		}

	}


	return 0;
}

