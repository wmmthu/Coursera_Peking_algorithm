#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char maze[200][200];
int visited[200][200];
int R,C,T;
struct Point
{
	int x,y,step;
	Point(int _x, int _y, int _s):x(_x),y(_y),step(_s){}
	Point():x(0),y(0),step(0){}

};

vector<Point> v;
int qHead,qEnd;
int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> T;
	while(T--){
		v.clear();
		cin >> R >> C;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin >> maze[i][j];
				visited[i][j] = 0;
				if(maze[i][j] == 'S') v.push_back(Point(i,j,0));
			}
		}
		
		qHead = 0;
		qEnd = 1;
		Point cur;
		while(qHead < qEnd){
			cur = v[qHead];
			if(maze[cur.x][cur.y] == 'E') break;
			for(int i=0;i<4;i++){
				int _x = cur.x + dir[i][0];
				int _y = cur.y + dir[i][1];

				if(_x < 0 || _x >= R || _y < 0 || _y >=C ||
					visited[_x][_y] || maze[_x][_y] == '#') continue;

				v.push_back(Point(_x,_y,cur.step+1));
				visited[_x][_y] = 1;
				qEnd ++;
			}
			qHead ++;
		}
		if(qHead < qEnd) cout << cur.step << endl;
		else cout << "oop!" << endl;
	}
	return 0;
}