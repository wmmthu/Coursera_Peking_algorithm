#include <iostream>
#include <cstring>
using namespace std;

long long N[250][250];
long long sumN[250];

int main()
{
	//freopen("test.txt","r",stdin);
	memset(N,0,sizeof(N));
	for(int i=0;i<250;i++) N[0][i] = 1;
	for(int i=1;i<250;i++){
		N[i][i] = 1;
		N[i][0] = 1;
		sumN[i] = 1;
		for(int j=1;j<=i/2;j++){
			if((i-2*j)>0){
				for(int t=j;t<250;t++){
					N[i][j] += N[i-2*j][t];
				}
			}else{
				N[i][j] += 1;
			}
			sumN[i] += N[i][j];
		}
	}
	
	int n;
	while(cin >>n){
		if(n==0) break;
		cout << n << " " << sumN[n] << endl;
	}

	return 0;
}