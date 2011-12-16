#ifndef RANGE_H_
#define RANGE_H_


#include <vector>
#include "Node.cpp"

using namespace std;

class Range{
public:
	/*
	 * Una matriz que guarda Nodos cuya posicion del nodo
	 * es (Trie::Rank(x),RTrie.Rank)
	 */
	vector< vector <Node * > > matriz;

	Range();
	Range(int i,int j);
	void get(int x,int x1,int y,int y1,vector<Node * >&);
	virtual ~Range();
};
#endif /*RANGE_H_*/
