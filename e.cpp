#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main() {
    int n, k, m2;
    cin >> n >> k >> m2;
    
    vector<string> palabras(n);
    vector<ll> costo(n);
    map<string, ll> map;

    for (int i = 0; i < n; ++i)
        cin >> palabras[i];

    for (int i = 0; i < n; ++i) {
        cin >> costo[i];
        map[palabras[i]] = costo[i];
    }
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        vector<int> p_mensajes(m);
        ll min_costo = 1e18;
        for (int j = 0; j < m; ++j) {
            cin >> p_mensajes[j];
            min_costo = min(min_costo, costo[p_mensajes[j] - 1]);
        }
        
        for (int j = 0; j < m; ++j)
        {
            map[palabras[p_mensajes[j] - 1]] = min_costo; 
        }
    }

    ll total = 0;
    for (int i = 0; i < m2; ++i) {
        string s;
        cin >> s;
        total += map[s];
    }

    cout << total << endl;

    return 0;
}
