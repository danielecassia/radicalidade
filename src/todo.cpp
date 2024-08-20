#include <bits/stdc++.h>
using namespace std;

#define all(X) begin(X), end(X)
#define ll long long int

#define bonus first
#define time second

// typedef vector<std::hash<ll>> Sections;
typedef vector<pair<ll,ll>> Sections;
typedef vector<pair<ll,ll>> Tricks;

struct Chip{
    int action;
    ll record;
};

Sections s;
Tricks t;
int N, K;
vector<vector<Chip>> MEM;


Chip dp(int id, int last){
    // if(id >N || last> 1<<K) return {0,-1};
    auto &[a, r] = MEM[id][last];

    if(a != -1) return {r,a};

    for(int action=0;action<1<<K;action++){
        if(id < N-1){
            auto [nextA, nextR] = dp(id+1, action);
            int acaoAGORA = t[action].bonus;
            r = max(acaoAGORA+nextR, r);
        }
    }
    // MEM[id][last] = {a,r};
    return {a,r};
}

int main() {

    // ler quantidade de sessões e manobra (N e K);
    cin>>N>>K;

    // aloca memoria para os vetores de sessoes e manobras
    s.resize(N);
    t.resize(K);

    MEM.resize(N, vector<Chip>(1<<K,{-1,0}));

    cout<< MEM[0][0].action << ", "<< MEM[0][0].record<<endl;

    // guarda os dados de N e K
    for(int i=0;i<N;i++) cin>> s[i].bonus >>s[i].time;
    for(int i=0;i<K;i++) cin>> s[i].bonus >>s[i].time;

    auto [a,r] = dp(0,0);

    // imprime a pontuação total máxima
    cout << r<<endl;

    //imprime a quantidade de manobras feitas em casa sessão e quai foram

    return 0;
}