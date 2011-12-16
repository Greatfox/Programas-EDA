#ifndef TRIE_H_
#define TRIE_H_

#include "Node.h"

#include <vector>


using namespace std;
/*
 * La estructura que guarda todos los bloques resultado de
 * la compresion LZ
 */
class Trie 
{
	
	public:
		/*
		 * Guarda a los nodos por el recorrido in-order
		 */
		vector <Node *> Rank;
		
		/*
		 * Guarda a los nodos , una vez creados se libera
		 */
		vector <Node *> All;
		
		/*
		 * el nodo raiz de valor "" es la cabeza de la trie		
		 */
		Node * raiz;
		
		/*
		 * COnstructor por defecto
		 */
		Trie();
		
		/*
		 * Imprime  atodos los nodos con sus id,datos
		 */
		void print1();
		
		/*
		 * Imprime los bloques del texto
		 */
		void print2(vector<string> &r);
		
		/*
		 * Hace es sub recorrido in order de un nodo y lo guarda en V
		 */
		void subAssign(Node *tmp,vector<Node*> &V);		
		
		/*
		 * Inicializa a subAssign con la raiz
		 */
		void Assign();
		
		/*
		 * Crea la Trie desde una linea de texto
		 */
		void add(string word);
		
		/*
		 * Me da el menor rango de los hijos del nodo de rank(i)
		 */
		Node* Lrank(int i);
		
		/*
		 * Me da el menor rango de los hijos del nodo de rank(i)
		 */				
		Node* Rrank(int i);				
		virtual ~Trie();

};

#endif /*TRIE_H_*/
