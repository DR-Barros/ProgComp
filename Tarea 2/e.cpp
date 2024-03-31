#include <bits/stdc++.h>
using namespace std;


/* int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        //set <pair<int, int>> s;
        set <pair<int, int>> s;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            s.insert({x, i});
        }
        int res = 0;
        // (max1 + max2 + max3) - (j - i)
        while (s.size() > 2){
            auto it = s.end();
            it--;
            int max1 = it->first;
            int idx1 = it->second;
            it--;
            int max2 = it->first;
            int idx2 = it->second;
            it--;
            int max3 = it->first;
            int idx3 = it->second;
            if (idx1 < idx2){
                swap(max1, max2);
                swap(idx1, idx2);
            }
            if (idx2 < idx3){
                swap(max2, max3);
                swap(idx2, idx3);
            }
            if (idx1 < idx2){
                swap(max1, max2);
                swap(idx1, idx2);
            }
            res = max(res, max1 + max2 + max3 - idx1);
            s.erase({max1, idx1});
        }

        cout << res << endl;
    }   
    
}
 */

/* int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
        int res = 0;
        // calcular el maximo del subarreglo de tamaño arbitrario con los 3 elementos mas grandes - tamaño del subarreglo
        for (int j = 0; j < n; j++){
            int max1 = 0;
            int max2 = 0;
            int max3 = 0;
            for (int k = j; k < n; k++){
                if (a[k] > max1){
                    max3 = max2;
                    max2 = max1;
                    max1 = a[k];
                } else if (a[k] > max2){
                    max3 = max2;
                    max2 = a[k];
                } else if (a[k] > max3){
                    max3 = a[k];
                }
                res = max(res, max1 + max2 + max3 - (k - j));
            }
        }

        cout << res << endl;
    }   
    
}
 */

/* int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
        int res = 0;
        int max1 = 0;
        int max2 = 0;
        int max3 = 0;
        int first = 0;
        // calcular el maximo del subarreglo de tamaño arbitrario con los 3 elementos mas grandes - tamaño del subarreglo
        for (int j = 0; j < n; j++){
            if (a[j] > max1){
                max3 = max2;
                max2 = max1;
                max1 = a[j];
            } else if (a[j] > max2){
                max3 = max2;
                max2 = a[j];
            } else if (a[j] > max3){
                max3 = a[j];
            }
            res = max(res, (max1 + max2 + max3) - (j - first));
            if (j - first > max1 + max2 + max3){
                first++;
            }
        }

        cout << res << endl;
    }   
    
} */