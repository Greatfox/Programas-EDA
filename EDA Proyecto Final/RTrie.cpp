#include "RTrie.h"

RTrie::RTrie()
{
	raiz=new Node('=',0,NULL);
}

void RTrie::add1(string a,int id){

	int tam=a.length();
	int i=0;
	Node*tmp=raiz;
	int cont =1;
	while(i<tam){
		char actual=a[tam-i-1];
		if(tmp->hijos.count(actual)==0){
			
			Node *nuevo=new Node(actual,-1,tmp);
			(*tmp).hijos[actual]=nuevo;
			tmp=nuevo;
			cont++;
		}
		else{
			tmp=(*tmp).hijos.find(actual)->second;
		}	
		i++;
	}
	tmp->id=id;
	All.push_back(tmp);
	
}
void RTrie::add2(vector<string> &a){
	int tam=a.size();
	for (int i = 0; i < tam; ++i) {
		this->add1(a[i],i+1);
	}
}
RTrie::~RTrie()
{
}
void RTrie::print1(Node* tmp){
	if(tmp!=raiz)
	cout<<"PADRE "<<tmp->id<<' '<<tmp->data<<' '<<tmp->padre->id<<endl;	
}
void RTrie::print2(){
	int tam=All.size();
	for (int i = 0; i < tam; ++i) {
		string c="";			
		Node*tmp=All[i];
		//cout<<tmp->id;
		while(tmp!=raiz){
			c+=tmp->data;
			tmp=tmp->padre;
		}
		cout<<c<<'/';		
	}
	cout<<endl;
}
void RTrie::subAssign(Node *tmp,vector<Node*> &V){
	
			map<char,Node * >::iterator it;
			V.push_back(tmp);
			
			for ( it=tmp->hijos.begin() ; it != tmp->hijos.end(); it++ ){
				
				subAssign((*it).second,V);
			
			}
			
		}
		
void RTrie::Assign(){
		
		Node *tmp= raiz;		
		int cont=0;
		vector<Node*>V;
		subAssign(tmp,V);
		int tam=V.size();
		for(int i=1;i<tam;i++){
			if((*V[i]).id>0){
				cont++;
				(*V[i]).rank=cont;
				Rank.push_back(V[i]);
			}				
			cout<<i<<"\t"<<(*V[i]).id<<"\t"<<(*V[i]).data<<"\t"<<(*V[i]).padre->id<<endl;
		
		}
}
Node* RTrie::Rrank(int i){
	
	Node*tmp=Rank[i];
	//cout<<"Id :"<<tmp->id<<' '<<tmp->rank<<" "<<tmp->hijos.size()<<endl;
	map<char,Node*>::reverse_iterator it;
	
	while(tmp->hijos.size()){
			it=tmp->hijos.rbegin();
			tmp=(*it).second;			
	}
	return tmp;
}
Node *RTrie::Lrank(int i){
	return Rank[i];
}