# Caminhamentos com Restrições

### Objetivo
Desenvolver um programa em C++ para resolver o problema de caminhamentos com restrições na comuna de Radlândia. O objetivo é calcular a sequência de manobras que maximize a pontuação total ao atravessar uma pista com seções específicas, levando em consideração as regras de bonificação e penalização.

### Definições e Conceitos Importantes:

- **Seção da Pista**: Cada seção tem um fator de bonificação \(c_i\) e um tempo de travessia \(l_i\).
- **Manobras**: Existem \(K\) manobras permitidas, cada uma com uma pontuação base \(p_j\) e duração \(t_j\). A pontuação de uma manobra pode ser reduzida pela metade se for repetida em seções consecutivas.
- **Pontuação Total**: Calculada com base nas manobras realizadas em cada seção e nos fatores de bonificação.

### Entrada:
- **N**: Número de seções da pista.
- **K**: Número de manobras permitidas.
- **Fatores de Bonificação e Tempos**: Para cada uma das \(N\) seções, são fornecidos dois inteiros \(c_i\) (fator de bonificação) e \(l_i\) (tempo de travessia).
- **Pontuação e Duração das Manobras**: Para cada uma das \(K\) manobras, são fornecidos dois inteiros \(p_j\) (pontuação base) e \(t_j\) (tempo necessário para executar a manobra).

### Saída:
1. A pontuação total máxima que Diná pode alcançar.
2. A sequência de manobras em cada seção da pista que resulta nessa pontuação.

### Exemplo de Entrada e Saída:

**Entrada**:
```
3 2
10 20
1 1
100 50
50 10
100 60
1000 50
100 60
```

**Saída**:
```
210050
1 1
0
2 1 2
```

## Passos para Implementação

### 1. Leitura dos Dados:
- Ler **N** (número de seções) e **K** (número de manobras).
- Para cada seção da pista, ler os valores \(c_i\) (fator de bonificação) e \(l_i\) (tempo de travessia).
- Para cada manobra, ler os valores \(p_j\) (pontuação base) e \(t_j\) (tempo necessário para a manobra).

### 2. Escolha do Algoritmo: Programação Dinâmica (PD)
Para resolver o problema de maximização da pontuação com restrições, utilizamos o algoritmo de **Programação Dinâmica (PD)**. Este método é adequado porque:
- **Subproblemas sobrepostos**: A pontuação máxima para uma seção depende das seções anteriores, criando subproblemas que podem ser resolvidos individualmente.
- **Estrutura de solução ótima**: A solução ótima do problema total pode ser construída a partir das soluções ótimas dos subproblemas.

### 3. Definição do Estado:
- Defina `dp[i][j]` como a pontuação máxima que pode ser alcançada até a seção `i`, realizando a manobra `j` nessa seção.
- Inicialize `dp[0][j]` para cada manobra `j` na primeira seção.

### 4. Recorrência:
- Para cada seção `i` e manobra `j`, calcule:
  \[
  dp[i][j] = \max(dp[i-1][k] + c_i \times p_j - \text{{penalidade}}, \quad \text{para todo } k)
  \]
  Onde `k` é qualquer manobra realizada na seção anterior. A penalidade é aplicada se a manobra `j` foi a mesma que `k` na seção anterior.

### 5. Construção da Solução:
- Preencha a tabela `dp` para todas as seções e manobras, maximizando a pontuação a cada passo.
- A pontuação máxima será o valor máximo encontrado na última linha da tabela `dp`.

### 6. Reconstrução da Solução:
- Acompanhe o caminho que levou ao valor máximo na tabela `dp` para reconstruir a sequência de manobras que resulta na pontuação máxima.

### 7. Geração da Saída:
- Após calcular a pontuação máxima, gere a saída conforme o formato especificado, indicando a quantidade e quais manobras devem ser realizadas em cada seção.

### 8. Validação e Testes:
- Teste o programa com os casos de teste fornecidos e crie casos adicionais para validar a corretude e eficiência do algoritmo.
- Certifique-se de que o programa atenda aos limites de tempo (3 segundos por caso de teste) e memória (100MB).

## Estruturas e Funções Úteis:

- **Estruturas de Dados**:
  - Utilize vetores para armazenar os fatores de bonificação, tempos de travessia, e detalhes das manobras.

- **Funções de Algoritmos**:
  - **Função para calcular a pontuação**: Implementar a lógica para calcular a pontuação total com base nas manobras e seções.
  - **Função de otimização**: Considerar todas as combinações possíveis de manobras para maximizar a pontuação.

## Considerações
- Comente seu código para facilitar a leitura e a manutenção.
- Certifique-se de que o código esteja dentro das restrições de tempo e memória especificadas.
- Realize testes exaustivos para garantir que o programa funcione corretamente em todos os cenários possíveis.
