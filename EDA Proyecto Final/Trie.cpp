#include "Trie.h"

/*
 * Inicializa la trie,dando a la raiz valores null
 */
Trie::Trie()
{
	raiz=new Node('=',0,NULL);

}
/*
 * Adiciona los subloques mientras lee el texto
 * Cada vez que encuentra un nuevo bloque anade un un nodo
 * Cada fin de linea termina con un identificador '$'
 */
void Trie::add(string text){

	int cont=1;
			
	int tam=text.length();	
	int i=0;
	int f;
	Node *tmp=raiz;
		
		while(i<tam){
			char actual=text[i];
			if(tmp->hijos.count(actual)==0){
			
				Node *nuevo=new Node(actual,cont,tmp);
				(*tmp).hijos[actual]=nuevo;
				tmp=raiz;
				cont++;
				All.push_back(nuevo);
				f=i+1;
			}
			else{
				
				tmp=(*tmp).hijos[actual];
			}				
			i++;
		}

	if(f<tam){
		Node *nuevo=new Node('$',cont,tmp);
		(*tmp).hijos['$']=nuevo;
		All.push_back(nuevo);

	}
}
/*
 * Regresa el rank del mayor de sus hijos
 */
Node* Trie::Rrank(int i){
	
	Node*tmp=Rank[i];
	map<char,Node*>::reverse_iterator it;
	
	while(tmp->hijos.size()){
			it=tmp->hijos.rbegin();
			tmp=(*it).second;			
	}
	return tmp;
}
Node *Trie::Lrank(int i){
	return Rank[i];
}
void Trie::print1(){
	
	int tam=All.size();
	for (int i = 0; i < tam; ++i) {
		cout<<All[i]->id<<' '<<All[i]->data<<endl;

	}
}
void Trie::print2(vector<string> &r){
	int tam=All.size();
	for (int i = 0; i < tam; ++i) {
		string c="";			
		Node*tmp=All[i];
		//cout<<tmp->id;
		while(tmp!=raiz){
			c=tmp->data+c;
			tmp=tmp->padre;
		}
		cout<<c<<'/';
		r.push_back(c);
	}
	cout<<endl;

}
void Trie::subAssign(Node *tmp,vector<Node*> &V){
	
			map<char,Node * >::iterator it;
			V.push_back(tmp);
			
			for ( it=tmp->hijos.begin() ; it != tmp->hijos.end(); it++ ){
				
				subAssign((*it).second,V);
			
			}
			
		}
		
void Trie::Assign(){
		
		Node *tmp= raiz;		
		
		vector<Node*>V;
		subAssign(tmp,V);
		Rank=V;
		int tam=V.size();
		for(int i=1;i<tam;i++){
			(*Rank[i]).rank=i;
		}
}
Trie::~Trie()
{
}
