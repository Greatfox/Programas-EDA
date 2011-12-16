#include "Range.h"

Range::Range()
{
}

Range::~Range()
{
}

Range::Range(int x,int y){

	Node *tN=new Node(' ',-1,0);
	for(int i=0;i<x;i++){
		
		vector <Node* > *tmp=new vector<Node *>(y,tN);
		matriz[i]=*tmp;
	}

}
void Range::get(int x,int x1,int y,int y1,vector<Node *> &r){

for(int i=x;i<=x1;i++){
	for(int j=y;j<y1;j++)
		if(matriz[i][j]>0){
			r.push_back(matriz[i][j]);
		}
}

}