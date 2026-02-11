#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;
 
stack<char> st;
 
int main(int argc, char **argv){
        int C; scanf("%d", &C);
        while(C--) {
            int N; scanf("%d", &N);
 
            st = {};
 
            for(int i=0; i<N; i++){
                char c; scanf(" %1c", &c);
                st.push(c);
 
								while(st.size() >= 3) {
										char x = st.top(); st.pop();
										char o = st.top(); st.pop();
										char f = st.top(); st.pop();
		
										if(x == 'x' && o == 'o' && f == 'f') {}
										else {
												st.push(f);
												st.push(o);
												st.push(x);
												break; 
										}
             
                }
            }
 
            printf("%d\n", (int)st.size());
        }
     
}