#include <iostream>
#include <cstring>
using namespace std;

void sort2(int*W, int*D, int N)
{
	for(int i=1;i<=N;i++){
		for(int j=1;j<=(N-i);j++){
			if(W[j]>W[j+1]){
				int tmp = W[j];
				W[j] = W[j+1];
				W[j+1] = tmp;

				tmp = D[j];
				D[j] = D[j+1];
				D[j+1] = tmp;
			}
		}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int N,M;
	int *D, *W;
	cin >> N >> M;
	D = new int[N+1];
	W = new int[N+1];

	for(int i=1;i<=N;i++) cin >> W[i] >> D[i];

	sort2(W,D,N);

	int **maxD = new int*[2];
	maxD[0] = new int[M+1];
	maxD[1] = new int[M+1];
	memset(maxD[0],0,sizeof(int)*(M+1));
	memset(maxD[1],0,sizeof(int)*(M+1));

	int j;
	for(j=1;j<=N;j++){
		for(int i=1;i<=M;i++){
			if(i-W[j]>=0){
				maxD[j%2][i] = max(D[j] + maxD[(j+1)%2][i-W[j]], maxD[(j+1)%2][i]);
			}else{
				maxD[j%2][i] = maxD[(j+1)%2][i];
			}
		}
	}

	cout << maxD[(j+1)%2][M] << endl;	
	delete[] D;
	delete[] W;
	delete[] maxD[0];
	delete[] maxD[1];
	delete[] maxD;
	return 0;
}