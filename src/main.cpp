#include <bits/stdc++.h>
using namespace std;

#define all(X) begin(X), end(X)
#define ll long long int

#define bonus first
#define time second
#define countBits __builtin_popcount
#define debug(x) cout<<#x <<"= "<<x<<endl

typedef vector<pair<ll,ll>> Sections;
typedef vector<pair<ll,ll>> Tricks;

struct Chip {
    int action; // manobra
    ll record;  // bonificação relacionada
};

Sections s;   // seções da pista
Tricks t;     // manobras possíveis
int N, K;     // Número de seções e manobras
vector<vector<Chip>> MEM; // Matriz de memória para DP

void updateScore(int id, int action, int points, int lastAction, ll r, ll nextR){
    ll currentScore = s[id].bonus * countBits(action) * points + nextR;
    if(currentScore > r ){
        MEM[id][lastAction] = {action,currentScore};
    }
}

Chip dp(int id, int lastAction) {

    auto &[a, r] = MEM[id][lastAction]; // referência ao estado atual da DP
    if (a != -1) return {a, r};   // se já foi calculado, retorna o resultado


    // testa todas as manobras possíveis
    for (int action = 0; action < (1<<K); action++) {
        // verifica se é possivel fazer essas manobras no tempo da seção
        int actionsTimes =0;
        for(int b=0;b<K;b++){
            if(action&(1<<b)) actionsTimes+= t[b].time;
        }

        if(s[id].time < actionsTimes) continue;

        ll points = 0;
        for(int b=0;b<K;b++){
            if(action&(1<<b)) //olhar se a manobra foi feita
            {
                points += (lastAction&(1<<b)) ? t[b].bonus / 2 : t[b].bonus; // define a pontuação baseado no lastAction
            }
        }

        if(id < N-1){
            auto [nextA, nextR] = dp(id + 1, action); // calcula o próximo estado
            updateScore(id, action, points, lastAction, r, nextR);
        }
        else updateScore(id, action, points, lastAction, r, 0);
    }
    debug(id);
    debug(lastAction);
    debug(r);
    debug(a);
    cout<<"----------------------------------"<<endl;
    return {a, r}; // retorna o melhor resultado para o estado atual
}

void printAction(int a){
    int len = countBits(a);
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
    MEM.resize(N, vector<Chip>(1<<K, {-1, 0})); // inicializa a matriz de memória

    // guarda os dados das seções e das manobras
    for (int i = 0; i < N; i++) cin >> s[i].bonus >> s[i].time;
    for (int i = 0; i < K; i++) cin >> t[i].bonus >> t[i].time;

    // executa a PD e calcula a pontuação máxima
    auto [action, record] = dp(0, 0);

    // imprime a pontuação total máxima
    cout << record << endl;

    //imprime quantidade e quais manobras foram utilizadas em cada seção
    for(int i=0;i<N;i++) printAction(action-i);

    return 0;
}
