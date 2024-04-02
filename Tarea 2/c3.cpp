#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, t;
    cin >> n >> t;
    vector<double> fp, fn;
    for(int i = 0; i < n; i++){
        char c;
        int x;
        cin >> c >> x;
        if(c == 'P'){
            fp.push_back(x);
        } else {
            fn.push_back(x);
        }
    }
    double time = 0;
    while (fp.empty() == false || fn.empty() == false){
        if (fp.empty()){
            double v = (double)t / fn.size();
            double need = DBL_MAX;
            for (auto const &i : fn){
                double curr = i / v;
                need = min(need, curr);
            }
            time += need;
            vector<double> nfn;
            for (auto &i : fn){
                i -= (need * v);
                if (i > 1e-6)
                nfn.push_back(i);
            }
            swap(nfn, fn);
            continue;
        }
        if (fn.empty()){
            double s = (double)t / fp.size();
            double need = DBL_MAX;
            for (auto const &i : fp)
            {
                double curr = i / s;
                need = min(need, curr);
            }
            time += need;
            vector<double> nfp;
            for (auto &i : fp)
            {
                i -= (need * s);
                if (i > 1e-6)
                nfp.push_back(i);
            }
            swap(nfp, fp);
            continue;
        }
        double vp = (double)(t * 0.75) / fp.size();
        double vn = (double)(t * 0.25) / fn.size();
        double need = DBL_MAX;
        for (auto const &i : fp){
            double curr = i / vp;
            need = min(need, curr);
        }
        for (auto const &i : fn){
            double curr = i / vn;
            need = min(need, curr);
        }
        time += need;
        vector<double> nfp;
        for (auto &i : fp)
        {
        i -= (need * vp);
        if (i > 1e-6)
            nfp.push_back(i);
        }
        swap(nfp, fp);
        vector<double> nfn;
        for (auto &i : fn)
        {
        i -= (need * vn);
        if (i > 1e-6)
            nfn.push_back(i);
        }
        swap(nfn, fn);
    }
    cout << time << endl;
}