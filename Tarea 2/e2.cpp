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
        int p1 = 0;
        int p2 = 0;
        int pos1 = 0;
        int pos2 = 0;
        int maximo = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (a[i] + a[j] > maximo){
                    maximo = a[i] + a[j];
                    pos1 = i;
                    pos2 = j;
                }
            }
        }

        int p3 = 0;
        int pos3 = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            if (i != pos1 && i != pos2){
                if (i < min(pos1, pos2)){
                    if (a[i]+ a[pos1] + a[pos2] - (max(pos1, pos2) - i) > res){
                        res = a[i]+ a[pos1] + a[pos2] - (max(pos1, pos2) - i);
                    }
                } else if (i < max(pos1, pos2)){
                    if (a[i]+ a[pos1] + a[pos2] - (max(pos1, pos2) - min(pos1, pos2)) > res){
                        res = a[i]+ a[pos1] + a[pos2] - (max(pos1, pos2) - min(pos1, pos2));
                    }
                } else {
                    if (a[i]+ a[pos1] + a[pos2] - (i - min(pos1, pos2)) > res){
                        res = a[i]+ a[pos1] + a[pos2] - (i - min(pos1, pos2));
                    }
                }
            }
        }
        cout << res << endl;
    }
}