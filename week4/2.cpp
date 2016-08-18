#include <iostream>
using namespace std;

int H[101][101];
int L[101][101];

int fun(int R, int C)
{
	// sort and record points according to height
	int idx[101*101],idy[101*101];
	int m[101][101];

	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			m[i][j] = 0;
		}
	}


	for(int t=1;t<=R*C;t++){
		int minH = 10001;
		int _idx,_idy;
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				if(m[i][j] == 0 && H[i][j] < minH){
					minH = H[i][j];
					_idx = i;
					_idy = j;
				}
			}
		}
		idx[t] = _idx;
		idy[t] = _idy;
		m[_idx][_idy] = 1;
	}

	int maxL = 0;
	for(int t=1;t<=R*C;t++){
		int _idx = idx[t];
		int _idy = idy[t];

		int _tmp = 0;
		if((_idx-1)>=1 && H[_idx-1][_idy] < H[_idx][_idy]){
			_tmp = (_tmp<L[_idx-1][_idy])?L[_idx-1][_idy]:_tmp;
		}
		if((_idx+1)<=R && H[_idx+1][_idy] < H[_idx][_idy]){
			_tmp = (_tmp<L[_idx+1][_idy])?L[_idx+1][_idy]:_tmp;
		} 
		if((_idy-1)>=1 && H[_idx][_idy-1] < H[_idx][_idy]){
			_tmp = (_tmp<L[_idx][_idy-1])?L[_idx][_idy-1]:_tmp;
		}
		if((_idy+1)<=C && H[_idx][_idy+1] < H[_idx][_idy]){
			_tmp = (_tmp<L[_idx][_idy+1])?L[_idx][_idy+1]:_tmp;
		}
		L[_idx][_idy] = _tmp + 1;
		maxL = (maxL<L[_idx][_idy])?L[_idx][_idy]:maxL;
	}
	return maxL;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int R,C;
	cin >> R >> C;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin >> H[i][j];
			L[i][j] = 1;
		}
	}
	cout << fun(R,C) << endl;
	return 0;
}