# Trabalho de Projeto de Arquivos

Trabalho feito por Eliton Machado da Silva e Joao Vitor Fröhlich

Nesse trabalho, foram analisadas as complexidades de tempo das estruturas AVL-Tree e B-Tree.

## AVL-Tree

A AVL-Tree foi implementada utilizando uma abordagem iterativa, e foram analisadas as seguintes funções:

* Criação da árvore
* Inserção na Árvore
* Balanceamento

Na estrutura da AVL-Tree está presente apenas uma varíavel, que guardava o ponteiro para a raíz da árvore.
Quanto à estrutura dos nós, ela possue as seguintes varíaveis:

* Três ponteiros para nós, que indicam o pai, o filho a esquerda e o filho a direita do nó.
* Dois números inteiros, que representam o valor guardado no nó e a altura do nó.

A altura dos nós foram armazenados dentros dos nós para diminuir o esforço computacional para a função de balanceamento, pois se percebeu que haveria um aumento na complexidade se fosse necessário computar a altura de cada log (n) nós a cada chamada de balanceamento, que ocorre a cada nó inserido.

## B-Tree



## Análise

Foram analisados dois casos para cada estrutura, sendo eles o pior caso e o caso aleatório.

Os dados das análises foram inseridos num gráfico de linha.

### Pior Caso

Para análise do pior caso, foi passado para cada estrutura um arquivo com números de 1 a n ordenados, sendo n o tamanho da árvore informado no arquivo. Os casos foram analisados com árvores de tamanhos de 1 a 100.

![Pior Caso](GraficosEntrega/Worst%20Case.png)

### Caso Aleatorio

Para análise do caso aleatório, foram gerados casos para árvores de tamanho variando entre 1 e 100. Para cada tamanho, foram gerados 10 arquivos, para prover uma certa variabilidade estatistica, com n números escolhidos aleatoriamente no intervalo entre 1 e 100, com limites inclusos.

![Caso Aleatorio](GraficosEntrega/Random%20Case.png)
