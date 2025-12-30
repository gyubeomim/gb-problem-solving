#include <bits/stdc++.h>

using namespace std;




  unordered_set<string> comb;
	int depth = 0;
	int N;



int card[100] = {0};
bool visit[100] = { false };











void dfs(string sum, int d) {


	if(d == depth) {
		comb.insert(sum);

		return;
	} 



	for(int i=0; i<N; i++) {
		if(visit[i]) continue;



		visit[i] = true;
		dfs(sum + to_string(card[i]), d+1);
		visit[i] = false;

	}




}











int main() {
	
	cin >> N;
 
	cin >> depth;





	for(int i=0; i<N; i++) {
		int num;
		cin >> num;


		card[i] = num;
	}







	dfs("", 0);




	cout << comb.size() << '\n';


	// for(auto it : comb) {
	// 	cout << it << endl;
	// }




	return 0;
}