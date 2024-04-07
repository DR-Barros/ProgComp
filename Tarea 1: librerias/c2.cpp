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
    double ans = 0;
    while (fp.size() > 0 && fn.size() > 0){
        if (!fp.size()){
            double s = (double)t / fn.size();
            double need = DBL_MAX;
            for (auto const &i : fn)
            {
                double curr = i / s;
                need = min(need, curr);
            }
            ans += need;
            vector<double> nfn;
            for (auto &i : fn)
            {
                i -= (need * s);
                if (i > 1e-6)
                nfn.push_back(i);
            }
            swap(nfn, fn);
            continue;
        }
        if (!fn.size()){
            double s = (double)t / fp.size();
            double need = DBL_MAX;
            for (auto const &i : fp)
            {
                double curr = i / s;
                need = min(need, curr);
            }
            ans += need;
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
        double sp = (double)(t * 0.75) / fp.size();
        double sn = (double)(t * 0.25) / fn.size();
        double need = DBL_MAX;
        for (auto const &i : fp){
            double curr = i / sp;
            need = min(need, curr);
        }
        for (auto const &i : fn){
            double curr = i / sn;
            need = min(need, curr);
        }
        ans += need;
        vector<double> nfp, nfn;
        for (auto &i : fp){
            i -= (need * sp);
            if (i > 1e-6)
            nfp.push_back(i);
        }
        for (auto &i : fn){
            i -= (need * sn);
            if (i > 1e-6)
            nfn.push_back(i);
        }
        swap(nfp, fp);
        swap(nfn, fn);
    }
    cout << fixed << setprecision(10) << ans << endl;
}