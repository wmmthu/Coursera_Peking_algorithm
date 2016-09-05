#include <iostream>
using namespace std;

int data[51][51][51];
int data2[51][51];

inline int min(int a, int b){
	return a<b?a:b;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int N,K;
	while(cin >> N >> K){
		for(int i=1;i<=N;i++){
			data[i][0][0] = 0;
			data[i][0][1] = 0;
			for(int j=1;j<=i;j++){
				data[i][j][1] = (i==j)?1:0;
			}
		}

		data[0][0][0] = 1;
		data[0][0][1] = 0;


		for(int k=2;k<=K;k++){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=i;j++){
					data[i][j][k] = data[i-j][min(j,i-j)][k-1] 
					+ data[i][j-1][k];
				}
			}
		}

		cout << data[N][N][K] << endl;

		data2[0][0] = 1;
		for(int i=1;i<=N;i++) data2[i][0] = 0;

		for(int i=1;i<=N;i++){
			for(int j=1;j<=i;j++){
				data2[i][j] = data2[i-j][min(j-1,i-j)] + data2[i][j-1];
			}
		}
		cout << data2[N][N] << endl;

		for(int i=1;i<=N;i++){
			for(int j=1;j<=i;j++){
				if(j%2) data2[i][j] = data2[i-j][min(j,i-j)] + data2[i][j-1];
				else data2[i][j] = data2[i][j-1];
			}
		}

		cout << data2[N][N] << endl;

	}
	return 0;
}