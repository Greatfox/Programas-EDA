#ifndef RTRIE_H_
#define RTRIE_H_
#include "Trie.h"

using namespace std;

/*
 * Es la estructura que guarda los bloques al revez para buscar sufijos.
 * La mayoria de metodos son iguales a los metodos de Trie
 * 
 */
class RTrie
{
public:
	
	vector <Node *> Rank;	
	vector <Node *> All;	
		
	Node * raiz;
	
	RTrie();
	/*
	 * A diferencia de Trie no todos los nodos que pertenecen al RTrie
	 * ni cada camino de la raiz a las hojas es una palabra, por lo que 
	 * hay que saber el id del nodo que agregamos en el Trie
	 */
	void add1(string a,int id);
	/*
	 * Ingresa un vector de string que vendriana ser los boques de la trie
	 * recive el vector que se obtiene en el print2 de la trie
	 */
	void add2(vector<string> &a);
	virtual ~RTrie();
	void print1(Node*tmp);
	void print2();
	void subAssign(Node *tmp,vector<Node*> &V);		
	void Assign();
	Node* Lrank(int i);
	Node* Rrank(int i);
};

#endif /*RTRIE_H_*/
