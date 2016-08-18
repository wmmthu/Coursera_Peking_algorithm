#include <iostream>
#include <cstring>
using namespace std;

char D[10][10];
int usedR[10],usedC[10];
int N,K;

// n : number of points placed
// k : total number required
// i,j : points to be tested
int dfs(int n, int i, int j)
{
	int r = 0;
	usedR[i] ++;
	usedC[j] ++;
	n ++; 
	if(n==K){
		r = 1;
	}else{
		for(int s=i;s<N;s++){
			for(int t=0;t<N;t++){
				if(s == i && t <= j) continue;
				if(D[s][t] == '.') continue;
				if(usedR[s] > 0 || usedC[t] > 0) continue;

				r += dfs(n,s,t);
			}
		}
	}
	usedR[i] -- ;
	usedC[j] -- ;
	return r;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int nSolution;
	cin >> N >> K;
	while(N>0 && K > 0){
		nSolution = 0;
		memset(usedR,0,sizeof(usedR));
		memset(usedC,0,sizeof(usedC));

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> D[i][j];
			}
		}

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(D[i][j]=='.') continue;
				nSolution += dfs(0,i,j);
			}
		}

		cout << nSolution << endl;
		cin  >> N >> K;
	}
	return 0;
}