#include <iostream>
#include <cstring>
using namespace std;

int R,C,N;
int data[51][51];

int findMax()
{
	int _v=0,_i,_j,_s,_t;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			if(data[i][j]<=0) continue;
			for(int s=i;s<=R;s++){
				for(int t=1;t<=C;t++){
					if(data[s][t]<=0) continue;
					if(i==s && t<=j) continue;
					int dx = s - i;
					int dy = t - j;
					int v = 2;
					for(int l=1;l<=50;l++){
						int newx = s + dx * l;
						int newy = t + dy * l;
						if(newx<1 || newx>R || newy<1 || newy>C) continue;

						if(data[newx][newy] <= 0){
							v=0; break;
						}
						v ++;
					}
					if(v>_v){
						_v = v;
						_i = i; _j = j;
						_s = s; _t = t;
					}

				}
			}
		}
	}
	if(_v > 0){
		data[_i][_j] --;
		data[_s][_t] --;
		int dx = _s - _i;
		int dy = _t - _j;
		for(int l=1;l<=50;l++){
			int newx = _s + dx * l;
			int newy = _t + dy * l;
			if(newx<1||newx>R||newy<1||newy>C) break;
			data[newx][newy] --;
			//cout << newx << " " << newy << " " << data[newx][newy] << endl;
		}
		//cout << _v << " " << _i << " " << _j << " " << _s << " " << _t << endl;
		return _v;
	}else{
		return 0;
	}
}

int sumN()
{
	int r = 0;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			r += data[i][j];
		}
	}
	return r;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n,x,y,t;
	cin >> n;
	while(n--){
		int N2 = 0;
		cin >> R >> C >> N;
		memset(data,0,sizeof(data));
		for(int i=0;i<N;i++){
			cin >> x >> y >> t;
			data[x][y] = t;
			N2 += t;
		}
		int num = 0;
		
		while(N2 > 0){
			int temp = findMax();
			//cout << temp << " " << N2 <<" " << sumN()  << endl;
			if(temp){
				N2 -= temp;
				num ++;
			}
		}
		cout << num << endl;

	}
	return 0;
}