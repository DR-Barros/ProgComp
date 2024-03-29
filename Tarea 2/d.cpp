#include <bits/stdc++.h>
using namespace std;


int main(){
    int a;
    cin >> a;

    vector<int> v(a); //obtenemos fila de moscas
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    vector<int> v2(a); // vector con las especies de moscas
    int pos = 0;
    int maximaHilera=0;
    for (int i = 0; i < a; i++){
        for (int j = pos; j < i; j++){
            if (v[i] == v[j]){
                maximaHilera =  max(maximaHilera, i - pos);
                pos = j+1;

            } 
        }
    }
    maximaHilera = max(maximaHilera, a - pos);
    //devolvemos la hilera más larga
    cout << maximaHilera << endl;
}