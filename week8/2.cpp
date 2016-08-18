#include <iostream>
#include <vector>
using namespace std;

int maze[5][5];
int used[5][5];
struct Point
{
	int x,y;
	int father;
	Point(int _x, int _y, int _f):x(_x),y(_y),father(_f){}
};

vector<Point> q;
int qHead, qEnd;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
	//freopen("test.txt","r",stdin);
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> maze[i][j];
			used[i][j] = 0;
		}
	}

	q.push_back(Point(0,0,-1));
	qHead = 0;
	qEnd  = 1; 
	used[0][0] = 1;
	while(qHead < qEnd){
		Point p = q[qHead];
		if(p.x == 4 && p.y == 4) break;
		for(int i=0;i<4;i++){
			int _x = p.x + dir[i][0];
			int _y = p.y + dir[i][1];

			if(maze[_x][_y] == 1  || used[_x][_y] == 1) continue;

			q.push_back(Point(_x,_y,qHead));
			qEnd ++;
		}
		qHead ++;
	}

	vector<int> path;
	while(qHead>=0){
		path.push_back(qHead);
		qHead = q[qHead].father;
	}

	for(int i=path.size()-1;i>=0;i--){
		cout << "(" << q[path[i]].x << ", " << q[path[i]].y << ")" << endl;
	}

	return 0;
}