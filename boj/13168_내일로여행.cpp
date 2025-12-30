#include <bits/stdc++.h>

using namespace std;

int n,m,k,t;
map<string, int> m1;
string tourcities[201];
double dist[101][101];
double railo[101][101];
const int INF=987654321;
string Free[3] = {"Mugunghwa", "ITX-Saemaeul", "ITX-CheongChun"};
string Half[2] = {"S-Train", "V-Train"};

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string name;
		cin>>name;
		m1[name]=i;
	}

	cin>>k;
	for(int i=0;i<k;i++){
		cin>>tourcities[i];
	}

	cin>>t;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				dist[i][j]=INF;
				railo[i][j]=INF;
			}
		}
	}	

	for(int i=0;i<t;i++){
		bool free=false;
		bool half=false;
		string trans,n1,n2;
		double cost;
		cin>>trans>>n1>>n2>>cost;

		int from=m1[n1];
		int to=m1[n2];

		dist[from][to] = dist[to][from] = min(dist[from][to], cost);
		for(int j=0;j<3;j++){
			if(trans == Free[j]) free=true;
		}
		for(int j=0;j<2;j++){
			if(trans == Half[j]) half=true;
		}

		if(free) cost = 0;
		else if(half) cost /= 2;
		
		railo[from][to] = railo[to][from] = min(railo[from][to], cost);
	}


		for (int l = 0; l < n; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][l]+dist[l][j]);
					railo[i][j] = min(railo[i][j], railo[i][l] + railo[l][j]);
			}
		}
	}

	double Dis=0, Railo=m;
	for(int i=0;i<k-1;i++){
		int from = m1[tourcities[i]];
		int to = m1[tourcities[i+1]];
		Dis += dist[from][to];
		Railo += railo[from][to];
	}

	int from = m1[tourcities[k-1]];
	int to = m1[tourcities[0]];
	Dis += dist[from][to];
	Railo += railo[from][to];


	cout << (Dis > Railo ?  "Yes" : "No");


	return 0;
}