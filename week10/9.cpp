#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

struct State
{
	int x,y;
	int diamond;
	int step;
	State(int _x,int _y):x(_x),y(_y),step(0),diamond(0){}
};

char map[200][200];
int visited[200][200][1<<5];
vector<State> door;
vector<State> q;
long long qHead=0,qEnd=0;
int dir[][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int diamondnum(int diamond)
{
	int cnt = 0;
	for(int i=0;i<5;i++){
		if( ((diamond >> i) & 1) == 1 ) cnt++;
	}
	return cnt;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T,R,C,K;
	cin >> T;
	while(T--){
		q.clear();
		door.clear();
		cin >> R >> C >> K;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin >> map[i][j];
				
				if(map[i][j] == 'S'){
					q.push_back(State(i,j));
					qHead = 0; qEnd = 1;
					visited[i][j][0] = 1;
				}
				if(map[i][j] == '$'){
					door.push_back(State(i,j));
				}
			}
		}
		State cur(0,0);
		while(qHead < qEnd){
			cur = q[qHead];
			if(map[cur.x][cur.y] == 'E' && diamondnum(cur.diamond) >= K) break;
			for(int i=0;i<4;i++){
				int x = cur.x + dir[i][0];
				int y = cur.y + dir[i][1];

				State s(x,y);
				s.diamond = cur.diamond;
				s.step = cur.step + 1;

				if(x<0 || x>= R || y<0 || y>=C || map[x][y] == '#') continue;
				if(map[x][y] >= '0' && map[x][y] <= '9'){
					s.diamond |= (1 << (map[x][y] - '0'));
				}
				if(visited[x][y][cur.diamond]) continue;

				visited[s.x][s.y][s.diamond] = 1;
				q.push_back(s);
				qEnd ++;

				if(map[x][y] == '$'){
					for(int d=0;d<door.size();d++){
						if(!visited[door[d].x][door[d].y][s.diamond]){
							s.x = door[d].x;
							s.y = door[d].y;
							q.push_back(s);
							qEnd++;
							visited[s.x][s.y][s.diamond] = 1;
						}
					}
				}
			}

			qHead++;
		}

		if(qHead < qEnd){
			cout << q[qHead].step << endl;
		}else{
			cout << "oop!" << endl;
		}
	}
	return 0;
}