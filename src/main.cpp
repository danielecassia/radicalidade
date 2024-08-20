#include <bits/stdc++.h>
using namespace std;

#define all(X) begin(X), end(X)
#define ll long long int

#define bonus first
#define time second

typedef vector<pair<ll,ll>> Sections;
typedef vector<pair<ll,ll>> Tricks;

struct Chip {
    int action; // Ação escolhida (manobra)
    ll record;  // Pontuação obtida
};

Sections s;   // Vetor que guarda as seções da pista
Tricks t;     // Vetor que guarda as manobras possíveis
int N, K;     // Número de seções e manobras
vector<vector<Chip>> MEM; // Matriz de memória para PD


Chip dp(int id, int last) {
    // caso base: se chegamos ao final da pista
    if (id == N) return {0, 0};

    auto &[a, r] = MEM[id][last]; // referência ao estado atual da DP
    if (a != -1) return {a, r};   // se já foi calculado, retorna o resultado


    // testa todas as manobras possíveis
    for (int action = 0; action < (1<<K); action++) {

        // TODO: iterar nos bits de action
        int penalidade;
        if (last == action) {
            penalidade = t[action].bonus / 2; // aplica a penalidade por repetir a mesma manobra
        } else {
            penalidade = t[action].bonus;     // nenhuma penalidade, usa o bônus original
        }

        if(id < N-1){
            auto [nextA, nextR] = dp(id + 1, action); // calcula o próximo estado
            ll currentScore = t[id].bonus * penalidade + nextR;
            r = max(currentScore, r);
            a = action;
        }
    }

    return {a, r}; // retorna o melhor resultado para o estado atual
}

void printAction(int a){
    int len = __builtin_popcount(a);
    cout<<len <<" ";
    int pow=1;
    while (a>0) {
        if(a&1) cout<<pow<<" ";
        a>>=1;
        pow=2;
    }
    cout<<endl;
}

int main() {
    // ler quantidade de seções e manobras (N e K);
    cin >> N >> K;

    // aloca memória para os vetores de seções e manobras
    s.resize(N);
    t.resize(K);
    MEM.resize(N, vector<Chip>(K, {-1, 0})); // inicializa a matriz de memória

    // guarda os dados das seções e das manobras
    for (int i = 0; i < N; i++) cin >> s[i].bonus >> s[i].time;
    for (int i = 0; i < K; i++) cin >> t[i].bonus >> t[i].time;

    // executa a PD e calcula a pontuação máxima
    auto [action, record] = dp(0, 0);

    // imprime a pontuação total máxima
    cout << record << endl;
    cout << action << endl;

    //imprime quantidade e quais manobras foram utilizadas em cada seção
    printAction(action);

    return 0;
}
