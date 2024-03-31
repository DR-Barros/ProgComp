#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T;
    cin >> N >> T;

    map<char, priority_queue<double>> m;
    for (int i = 0; i < N; i++) {
        char c;
        double x;
        cin >> c >> x;
        m[c].push(-1*x);
    }

    double count = 0;
    int p, n;
    double vp, vn;
    double dp, dn = 0;
    while (m['P'].empty() == false || m['N'].empty() == false) {
        //chequeamos cuantos elementos hay en cada vector
        p = m['P'].size();
        n = m['N'].size();
        if (p > 0 && n > 0) {
            //si hay elementos en ambos vectores, los eliminamos
            vp = T*0.75/p;
            vn = T*0.25/n;
            // el minimo cantidad de tiempo para que algun vector pierda un elemento aplicando vp a P y vn a N
            double t;
            if ((m['P'].top()*-1 - dp)/vp > (m['N'].top()*-1 - dn)/vn){
                t = (m['N'].top()*-1 - dn)/vn;
                m['N'].pop();
            } else {
                t = (m['P'].top()*-1 - dp)/vp;
                m['P'].pop();
            }
            dp += vp*t;
            dn += vn*t;
            count += t;
        } else if (p > 0) {
            //si solo hay elementos en el vector P
            vp = T/p;
            double t = (m['P'].top()*-1 - dp)/vp;
            m['P'].pop();
            dp += vp*t;
            count += t;
        } else {
            //si solo hay elementos en el vector N
            vn = T/n;
            double t = (m['N'].top()*-1 - dn)/vn;
            m['N'].pop();
            dn += vn*t;
            count += t;
        }
    }
    cout << count << endl;
}