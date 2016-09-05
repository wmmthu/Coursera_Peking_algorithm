#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct State
{
	int x,y;
	int diamond;
	int step;
	int parent;
	State(int _x,int _y):x(_x),y(_y),step(0),diamond(0),parent(0){}
};

char map[201][201];
int visited[201][201][1<<5];
int door[10][2];
int doornum;

int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};

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
		queue<State> q;
		cin >> R >> C >> K;
		doornum = 0;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin >> map[i][j];
				
				if(map[i][j] == 'S'){
					q.push(State(i,j));
					visited[i][j][0] = 1;
					map[i][j] = '.';
				}
				if(map[i][j] == '$'){
					door[doornum][0] = i;
					door[doornum][1] = j;
					doornum ++;
				}
			}
		}
		State cur(0,0);
		while(!q.empty()){
			cur = q.front();
			q.pop();
			if(map[cur.x][cur.y] == 'E' && diamondnum(cur.diamond) >= K) break;
			for(int i=0;i<4;i++){
				int x = cur.x + dir[i][0];
				int y = cur.y + dir[i][1];

				if(x<0 || x>= R || y<0 || y>=C) continue;
				if(visited[x][y][cur.diamond] || map[x][y] == '#') continue;
				
				State s(x,y);
				s.diamond = cur.diamond;
				s.step = cur.step + 1;

				//cout << s.x << " " << s.y << " " << s.step << " " << s.diamond << endl;
				visited[s.x][s.y][s.diamond] = 1;
				
				if(map[x][y] >= '0' && map[x][y] <= '9'){
					s.diamond |= (1 << (map[x][y] - '0'));
				}
				
				q.push(s);

				if(map[x][y] == '$'){
					for(int d=0;d<doornum;d++){
						int x = door[d][0];
						int y = door[d][1];
						if(!visited[x][y][s.diamond]){
							visited[x][y][s.diamond] = 1;
							s.x = x; s.y = y;
							q.push(s);
						}
					}
				}
			}
		}

		if(!q.empty()){
			cout << cur.step << endl;
		}else{
			cout << "oop!" << endl;
		}
	}
	return 0;
}