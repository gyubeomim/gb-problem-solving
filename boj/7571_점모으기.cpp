#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char **argv){
	int N,M;
	scanf("%d %d",&N,&M);

	vector<int> xs,ys;
	for(int i=0;i<M;i++){
		int x,y;
		scanf("%d %d", &x, &y);

		xs.push_back(x);
		ys.push_back(y);
	}

	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	int medx, medy;
	medx = *(xs.begin() + xs.size()/2);
	medy = *(ys.begin() + ys.size()/2);

	int cost=0;
	for(int x : xs) cost += abs(medx - x);
	for(int y : ys) cost += abs(medy - y);

		
	printf("%d", cost);
	 

	return 0;
}

