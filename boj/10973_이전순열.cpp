#include <bits/stdc++.h>
using namespace std;

constexpr int LM=10005;
int num[LM]={0};
int N;

int main(int argc, char **argv){
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d",&num[i]);

	bool first_perm=true;        // 마지막 순열인지 확인을 위한 변수

	for(int i=N-1;i>0;i--){    // 입력된 순열의 마지막 원소부터 검사
		if(num[i-1] > num[i]){   // 왼쪽 원소(기준) > 오른쪽 원소
			int idx=i;             // 교환할 원소의 인덱스
			for(int j=N-1; j>=i; j--)
				if(num[i-1] > num[j] && num[j] > num[idx])  
					idx=j;

			int tmp = num[idx];   // 교환
			num[idx] = num[i-1];
			num[i-1] = tmp;

			sort(num+i, num+N, greater<int>());   // 기준 원소 우측 오름차순 정렬

			first_perm=false;      // 마지막 순열이 아님 

			break;
		}
	}

	if(first_perm) printf("-1\n");
	else {
		for(int i=0;i<N;i++)
			printf("%d ", num[i]);
		printf("\n");
	}

	return 0;
}
