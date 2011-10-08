//Integrantes: Alvaro Zúñiga Quiroz
//             Antony Orlando Ramirez

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int limi = 200; // limite maximo de vertices q puede tener el grafo

int grafo[200][200];
bool visitados[200];
int color[200];

bool fun(int ini, int tama){
    for(int i = 0;i<tama;i++){
        if(grafo[ini][i] == 1 && visitados[i] == false){
            visitados[ini] = true;
            if(color[ini]==1){
                if(color[i] == 0) color[i] = 2;
                else if(color[i] == 1) return false;
            }
            else{
                if(color[i] == 0) color[i] = 1;
                else if(color[i] == 2) return false;
            }
            fun(i,tama);
        }
    }
    return true;

}

int main()
{
    // n = numero de vertices o nodos q el grafo tendra
    // num = numero de datos q se va a ingresar
    // los colores q considerare son el 0 1 2 el 0 no ta pintado

    int n,num;
    while(cin>>n){
        if(n == 0) return 0;
        for(int i = 0;i<n;i++){
            visitados[i] = false;
            color[i]=0;
            for(int j = 0;j<n;j++)
                grafo[i][j] = 0;
        }
        cin >> num;
        int v_x,v_y;
        for(int i = 0;i<num;i++){
            cin>>v_x>>v_y;
            grafo[v_x][v_y] = 1;
            grafo[v_y][v_x] = 1;
        }
        color[0] = 1;
        if(fun(0,n) == true) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
}
