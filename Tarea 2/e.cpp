#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a(n); 
        for (int i = 0; i < n; i++){
            int num1;
            cin >> num1;
            a[i] = num1;
        }
        // b corresponde al máximo valor de a[i] + i desde la izquierda (bi1 - l)
        // c corresponde al máximo valor de a[i] - i desde la derecha (bi3 -r)
        vector<int> b(n), c(n);
        for (int i = 0; i < n; i++){
            b[i] = a[i]+i;
            c[i] = a[i]-i;
        }
        for (int i = 1; i < n; i++){
            b[i] = max(b[i], b[i-1]);
        }
        for (int i = n-2; i >= 0; i--){
            c[i] = max(c[i], c[i+1]);
        }

        int ans = 0;
        for (int i = 1; i < n-1; i++){
            ans = max(ans, a[i]+b[i-1]+c[i+1]); // a[i] = bi2, luego ans = bi2 + bi1 + bi3 - (r-l)
        }
        cout << ans << endl;
    }
}