#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    vector<int> v(a);
    for (int i = 0; i < a; i++){
        cin >> v[i];
    }

    for (int i = 0; i < a-3; i++){
        for (int j = i + 1; j < a-2; j++){
            for (int k = j + 1; k < a-1; k++){
                for (int l = k + 1; l < a; l++){
                    if (v[i] + v[j] + v[k] + v[l] == b){
                        cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
