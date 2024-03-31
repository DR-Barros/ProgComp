#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // creamos un vector de k * 2 elementos
    vector<int> dp(k * 2, 0);
    // recorremos el vector a y contamos cuantos 1 y 2 hay en cada grupo de k elementos
    for (int i = 0; i < n; i ++) {
        if (a[i] == 1) {
            dp[(i % k) * 2]++;
        } else {
            dp[(i % k) * 2 + 1]++;
        }
    }

    int cant = 0;
    // recorremos el vector dp y vemos si conviene cambiar el valor de 1 por 2 o viceversa
    for (int i = 0; i < 2*k; i+=2) {
        cant += min(dp[i], dp[i + 1]);
    }

    cout << cant << endl;
}