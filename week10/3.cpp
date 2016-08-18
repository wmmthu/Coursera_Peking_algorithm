#include <iostream>
using namespace std;

int data[51][51];


int main()
{
	for(int i=0;i<=50;i++){ 
		data[i][1] = 1;
		data[0][i] = 1;
	} 
	for(int i=2;i<=50;i++){
		for(int j=2;j<=i;j++){
			if(j>(i-j)) data[i][j] = data[i-j][i-j] + data[i][j-1];
			else data[i][j] = data[i-j][j] + data[i][j-1];
		}
	}

	int N;
	while(cin >>N){
		cout << data[N][N]<< endl;;
	}
	return 0;
}