#include <iostream>
#include <string>
#include <vector>
using namespace std;

int D[26][26];
int n,p,q;
string str;
int dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

int dfs(int depth, int i, int j, string& str)
{
	D[i][j] = 1;
	depth ++;
	str.append(1,'A'+i);
	str.append(1,'1'+j);
	if(depth == p*q){
		return 1;
	}
	for(int _i=0;_i<8;_i++){
		int s = i + dir[_i][0];
		int t = j + dir[_i][1];
		if(s<0 || s>= q || t < 0 || t>=p || D[s][t] == 1) continue;
		if(dfs(depth,s,t,str)) return 1;
	}
	D[i][j] = 0;
	str = str.substr(0,str.size()-2);
	return 0;
}

int main()
{
	//freopen("test.txt","r",stdin);
	str = "";
	cin >> n;
	int c = 0;
	while(n--){
		str = "";
		c ++;
		cout << "Scenario #" << c << ":" << endl;
		cin >> p >> q;
		for(int i=0;i<q;i++){
			for(int j=0;j<p;j++){
				D[i][j] = 0;
			}
		}
		int flag = 1;
		for(int i=0;i<q;i++){
			for(int j=0;j<p;j++){
				if(dfs(0,i,j,str) && flag){
					cout << str << endl << endl;
					flag = 0;
					break;
				}
			}
		}
		
		if(flag){
			cout << "impossible" << endl << endl;
		}

	}
	return 0;
}