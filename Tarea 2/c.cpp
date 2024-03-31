#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T;
    cin >> N >> T;

    map<char, vector<int>> m;
    for (int i = 0; i < N; i++) {
        char c;
        int x;
        cin >> c >> x;
        m[c].push_back(x);
    }

    double count = 0;
    int p, n;
    double vp, vn;
    while (m['N'].size() > 0 || m['P'].size() > 0) {
        //chequeamos cuantos elementos hay en cada vector
        p = m['P'].size();
        n = m['N'].size();
        if (p > 0 && n > 0) {
            //si hay elementos en ambos vectores, los eliminamos
            vp = T*3/4/p;
            vn = T/4/n;
            // el minimo cantidad de tiempo para que algun vector pierda un elemento aplicando vp a P y vn a N
            double t = min(m['P'][0]/vp, m['N'][0]/vn);
            for (int i = 1; i < m['P'].size(); i++) {
                if (m['P'][i]/vp <= t) {
                    t = m['P'][i]/vp;
                }
            }
            for (int i = 1; i < m['N'].size(); i++) {
                if (m['N'][i]/vn <= t) {
                    t = m['N'][i]/vn;
                }
            }
            for (int i = 0; i < m['P'].size(); i++) {
                m['P'][i] -= vp*t;
                if (m['P'][i] <= 0) {
                    m['P'].erase(m['P'].begin() + i);
                    i--;
                }
            }
            for (int i = 0; i < m['N'].size(); i++) {
                m['N'][i] -= vn*t;
                if (m['N'][i] <= 0) {
                    m['N'].erase(m['N'].begin() + i);
                    i--;
                }
            }
            count += t;
        } else if (p > 0) {
            //si solo hay elementos en el vector P
            vp = T/p;
            double t = m['P'][0]/vp;
            for (int i = 1; i < m['P'].size(); i++) {
                if (m['P'][i]/vp <= t) {
                    t = m['P'][i]/vp;
                }
            }
            for (int i = 0; i < m['P'].size(); i++) {
                m['P'][i] -= vp*t;
                if (m['P'][i] <= 0) {
                    m['P'].erase(m['P'].begin() + i);
                    i--;
                }
            }
            count += t;
        } else {
            //si solo hay elementos en el vector N
            vn = T/n;
            double t = m['N'][0]/vn;
            for (int i = 1; i < m['N'].size(); i++) {
                if (m['N'][i]/vn <= t) {
                    t = m['N'][i]/vn;
                }
            }
            for (int i = 0; i < m['N'].size(); i++) {
                m['N'][i] -= vn*t;
                if (m['N'][i] <= 0) {
                    m['N'].erase(m['N'].begin() + i);
                    i--;
                }
            }
            count += t;
        }
    }
    cout << count << endl;
}