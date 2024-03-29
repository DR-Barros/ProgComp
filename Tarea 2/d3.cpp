#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }

    unordered_map<int, int> lastIndex;
    int left = 0, maxLength = 0;

    for (int right = 0; right < a; ++right) {
        // Si el elemento actual ya ha sido visto, actualizamos left si es necesario
        if (lastIndex.find(v[right]) != lastIndex.end()) {
            left = max(left, lastIndex[v[right]] + 1);
        }

        // Actualizamos el último índice del elemento actual
        lastIndex[v[right]] = right;

        // Calculamos la nueva longitud máxima
        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;
}
