#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int printFile(vector<string> v, int start, int depth, char stop)
{
	string prefix = "";
	for(int i=0;i<depth;i++) prefix += "|     ";
	vector<string> files;
	int pos = start;
	for(int i=start;i<v.size();i++){

		if(v[i][0] == stop) {pos = i;break;}
		if(v[i][0] == 'f') files.push_back(v[i]);
		if(v[i][0] == 'd'){
			cout << prefix << "|     " << v[i] << endl;
			i = printFile(v,i+1,depth+1,']');
		}
		
	}

	sort(files.begin(),files.end());
	for(int i=0;i<files.size();i++) cout << prefix << files[i] << endl;

	return pos;
}

int main()
{
	//freopen("test.txt","r",stdin);
	vector<string> v;
	string s;
	int id = 1;
	while(cin>>s){
		if(s=="#") break;
		v.push_back(s);
		if(s=="*"){
			cout << "DATA SET " << id << ":" << endl;
			cout << "ROOT" << endl;
			printFile(v,0,0,'*');
			cout << endl;
			v.clear();
			id++;
		}
		
	}


	return 1;
}