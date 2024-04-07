#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> moscas(n); // vector con las especies de moscas
    for (int i = 0; i < n; i++){
        cin >> moscas[i];
    }
    map<int, int> mapa; // mapa para almacenar las posiciones previas de las moscas
    int lastPos = 0;
    int maximaHilera=0;
    for (int i = 0; i < n; i++){
        if (mapa.count(moscas[i])){
            lastPos = max(lastPos, mapa[moscas[i]]+1);
        }
        mapa[moscas[i]] = i;
        maximaHilera = max(maximaHilera, i-lastPos+1);
    }
    //devolvemos la hilera más larga
    cout << maximaHilera << endl;
}