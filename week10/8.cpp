#include <iostream>
using namespace std;

int room[6][20][20];
int visited[6][20][20];
int dirs[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int roomNum,roomArea,maxRoomArea;

struct Point
{
	int m,i,j;
	Point(int _m,int _i,int _j):m(_m),i(_i),j(_j){}
	Point():m(-1),i(-1),j(-1){}
};



Point move(Point cur, int d, int k)
{
	Point r(cur.m,cur.i,cur.j);
	r.i += dirs[d][0];
	r.j += dirs[d][1];
	if(r.i>=0 && r.i<k && r.j>=0 && r.j<k) return r;

	if(cur.m == 0){
		if(r.i<0)  return Point(4,k-1,r.j);
		if(r.i>=k) return Point(5,k-1,r.j);
		if(r.j<0)  return Point(3,r.i,k-1);
		if(r.j>=k) return Point(1,r.i,0); 
	}
	if(cur.m == 1){
		if(r.i<0)  return Point(4,k-1-r.j,k-1);
		if(r.i>=k) return Point(5,k-1-r.j,k-1);
		if(r.j<0)  return Point(0,r.i,k-1);
		if(r.j>=k) return Point(2,r.i,0);
	}
	if(cur.m == 2){
		if(r.i<0)  return Point(4,0,k-1-r.j);
		if(r.i>=k) return Point(5,0,k-1-r.j);
		if(r.j<0)  return Point(1,r.i,k-1);
		if(r.j>=k) return Point(3,r.i,0);
	}
	if(cur.m == 3){
		if(r.i<0)  return Point(4,r.j,0);
		if(r.i>=k) return Point(5,r.j,0);
		if(r.j<0)  return Point(2,r.i,k-1);
		if(r.j>=k) return Point(0,r.i,0);
	}
	if(cur.m == 4){
		if(r.i<0)  return Point(2,0,k-1-r.j);
		if(r.i>=k) return Point(0,0,r.j);
		if(r.j<0)  return Point(3,0,r.i);
		if(r.j>=k) return Point(1,0,k-1-r.i);
	}
	if(cur.m == 5){
		if(r.i<0)  return Point(2,k-1,k-1-r.j);
		if(r.i>=k) return Point(0,k-1,r.j);
		if(r.j<0)  return Point(3,k-1,r.i);
		if(r.j>=k) return Point(1,k-1,k-1-r.i);
	}

}

void dfs(Point cur,int k)
{
	if(visited[cur.m][cur.i][cur.j] || room[cur.m][cur.i][cur.j]) return;
	visited[cur.m][cur.i][cur.j] = 1;
	roomArea ++;
	for(int i=0;i<4;i++){
		Point p = move(cur,i,k);
		dfs(p,k);
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	int T,k;
	cin >> T;
	while(T--){
		roomNum = 0;
		roomArea = 0;
		maxRoomArea = 0;
		cin >> k;
		for(int m=0;m<6;m++){
			for(int i=0;i<k;i++){
				for(int j=0;j<k;j++){
					cin >> room[m][i][j];
					visited[m][i][j] = 0;
				}
			}
		}

		for(int m=0;m<6;m++){
			for(int i=0;i<k;i++){
				for(int j=0;j<k;j++){
					if(!visited[m][i][j] && !room[m][i][j]){
						roomNum ++;
						roomArea = 0;
						dfs(Point(m,i,j),k);
						if(roomArea > maxRoomArea) maxRoomArea = roomArea;
					}
				}
			}
		}
		cout << roomNum << " " << maxRoomArea << endl;
	}
	return 0;
}