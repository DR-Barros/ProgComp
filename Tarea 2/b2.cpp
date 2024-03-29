#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }

    // Mapa para almacenar todas las combinaciones posibles de sumas de la primera mitad y sus índices.
    unordered_map<int, pair<int, int>> sums;

    // Generar todas las sumas posibles para la primera mitad
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            sums[v[i] + v[j]] = {i, j};
        }
    }

    // Buscar en la segunda mitad
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            int complement = b - (v[i] + v[j]);
            if (sums.count(complement)) {
                auto& p = sums[complement];
                // Asegurarse de que no se reutilizan índices
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
