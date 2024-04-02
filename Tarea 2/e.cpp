#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
        // maximo entre (a[j] + a[k] + a[l] - (l -r)) donde r y l son los indices extremos
        int max1 = 0;
        int max2 = 0;
        int max3 = 0;
        int pos1 = 0;
        int pos2 = 0;
        int pos3 = 0;
        // encontramos el maximo de mas a la izquierda
        for (int j = 0; j < n; j++){
            if (a[j] > max1){
                max3 = max2;
                pos3 = pos2;
                max2 = max1;
                pos2 = pos1;
                max1 = a[j];
                pos1 = j;
            } else if (a[j] > max2){
                max3 = max2;
                pos3 = pos2;
                max2 = a[j];
                pos2 = j;
            } else if (a[j] > max3){
                max3 = a[j];
                pos3 = j;
            }
        }
        int l = max(pos1, max(pos2, pos3));
        int value = a[l];
        //recorremos hacia la izquierda buscando el maximo
        int max4 = 0;
        int pos4 = l;
        int max5 = 0;
        int pos5 = l;
        int res = value;
        for (int j = l-1; j >= 0; j--){ 
            if (a[j] > max4){
                max5 = max4;
                pos5 = pos4;
                max4 = a[j];
                pos4 = j;
            } else if (a[j] > max5){
                max5 = a[j];
                pos5 = j;
            }
            res = max(res, value + max4 + max5 - (l - j));
        }
        cout << res << endl;
    }
}