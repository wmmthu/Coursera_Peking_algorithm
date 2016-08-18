#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char board[16];
int num[16];
int dir[5] = {0,-1,1,4,-4};
vector<int> q;
vector<int> qD;
vector<int> qN;
int qH, qE;
int used[1<<16];

void state2num(int state)
{
	for(int i=0;i<16;i++){
		num[i] = (state & (1 << i))>0?1:0;
	}
}

int flip(int state, int pos)
{
	state2num(state);
	
	num[pos] = 1 - num[pos];

	if((pos-4)>=0) num[pos-4] = 1 - num[pos-4];
	if((pos+4)<16) num[pos+4] = 1 - num[pos+4];
	if(pos%4 != 0) num[pos-1] = 1 - num[pos-1];
	if(pos%4 != 3) num[pos+1] = 1 - num[pos+1];

	int s = 0;
	for(int i=0;i<16;i++){
		s += (num[i] * (1 << i));
	}
	return s;
}

int main()
{
	//freopen("test.txt","r",stdin);
	memset(used,0,sizeof(used));
	int state = 0;
	for(int i=0;i<16;i++){
		cin >> board[i];
		if(board[i] == 'b') num[i] = 1;
		else num[i] = 0;
		state += (num[i] * (1 << i));
	}
	
	q.push_back(state);
	qD.push_back(0);
	qN.push_back(0);
	qH = 0;
	qE = 1;
	int s,d,n;
	while(qH < qE){
		s = q[qH];
		d = qD[qH];
		if(s == 0 || s == ((1<<16)-1)) break;
		for(int i=0;i<16;i++){
			int _s = flip(s,i);
			if(!used[_s]){
				q.push_back(_s);
				qD.push_back(d+1);
				used[_s] = 1;
				qE ++;
			}
		}
		qH ++;
	}

	if(qH<qE) cout << d << endl;
	else cout << "Impossible" << endl;

	return 0;
} 