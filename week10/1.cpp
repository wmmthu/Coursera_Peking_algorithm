#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int dir[][2] = {{0,0},{1,0},{-1,0},{0,1},{1,1},{-1,1},{0,-1},{1,-1},{-1,-1}};

inline int min(int a, int b){return a<b?a:b;}
inline int max(int a, int b){return a>b?a:b;}

int main()
{
	//freopen("test.txt","r",stdin);
	int T,d,n,x,y,w,tmp;
	cin >> T;
	while(T--){
		map<int,int> trash;
		cin >> d >> n;
		for(int i=0;i<n;i++){
			cin >> x >> y >> w;
			for(int _x=max(0,x-d);_x<=min(1024,x+d);_x++){
				for(int _y = max(0,y-d); _y <= min(1024,y+d); _y ++){

					tmp = _x*1025 + _y;
					if(trash.find(tmp) == trash.end()){
						trash[tmp] = 0;
					}
					trash[tmp] += w;
				}
			}
		}

		
		int _max = 0;
		int _num = 1;
		for(map<int,int>::iterator it=trash.begin();it!=trash.end();it++){
			if(it->second > _max){
				_max = it->second;
				_num = 0;
			}
			if(it->second == _max) _num++;
		}
		cout << _num << " " << _max << endl;
 	}
	return 0;
}