A “troca” de informações é realizada através da comunicação inter processos (IPC). Para introduzir o conceito analisamos um dos problemas mais famosos na área de Sistemas Operacionais: o jantar dos filósofos.
Cada filósofo possui um prato cheio de spaghetti à sua frente. 
Além disso, um garfo é posicionado entre cada par adjacente de filósofos (portanto, cada filósofo tem exatamente um garfo à sua esquerda e exatamente um garfo à sua direita).

Cada filósofo pode estar ou pensando ou comendo. Para comer são necessários dois garfos: direito e esquerdo. 
Se ele pega um dos garfos e o outro não está disponível, devolve-o à mesa e continua pensando até que consiga pegar os dois garfos de uma só vez. 
Quando conseguir pegar os dois garfos o filósofo come e logo depois devolve ambos os garfos à mesa.

Levando em consideração o problema computacional proposto, responda á seguinte questão:

Implemente uma possível solução para o problema do jantar dos filósofos?
Explique, em cada trecho do seu programa, como é resolvido o problema da comunicação inter processos (IPC)?


######################--------------------------------######################


MATERIAL DE ESTUDO UTILIZADO PARA RESOLUÇÃO

Livro "Sistema Operacionais Modernos" 3°Edição:

Página 50, capítulo de thread;

Página 99 até 102 solução para o problema dos filósofos.


http://www.di.ubi.pt/~operativos/praticos/html/13-sinc.html

Material de apoio para entedimento das bibliotecas de semaphore e mutex.


######################--------------------------------######################


Ao implementar uma solução onde o filósofo pega um garfo e aguarda até o próximo garfo estar disponível NÂO FUNCIONA. Se todos os filosófos resolverem pegar os garfos simultanemante o programa terá um deadlock, onde nenhum deles terá dois garfos e nenhum irá libera um garfo para o próximo, o problema apresenta condições de impasses:


POSSE E ESPERA:

  Filosófo toma o garfo da esquerda e fica aguardando o da direita;
  
ESPERA CIRCULAR:

  Cadeia circular de filosófos aguardando simultanemante um garfo;
  
NÃO PREEMPÇÃO:

  Filósofo não pode tomar um garfo do outro;

CONTÉUDO DO VIDEO: https://www.youtube.com/watch?v=LhkDV3cECNY


######################--------------------------------######################


*Ao implementar uma solução utilizando sleep() e/ou timeout para os filosófos decidirem se podem ou não pegar um garfo, ou se devem devolver ele a mesa caimos em um 
problema de inanição, onde mesmo utilizando números aleatórios para os filosófos iniciarem a função pegaGarfo(), caso eles iniciem simultanemalmente e todos peguem um garfo o programa iria executar que todos devolvessem os garfos e assim ficariamos neste loop, onde o programa continua executando indevinidamente, mas sem progressão   real (starvation).*

Existe a possibilidade do programa não cair nesta situação, mas para a solução ideal do problema é necessário a utilização de mutex(), onde durante a execução da função pensando() se faz necessário um DOWN  MUTEX e após o filosófo trocar os garfos um UP MUTEX;
Está solução funciona sem erros, mas ainda não é a versão mais otimizada, pois implementando desta com forma, com a utilização de um semáforo binário, somente um filosófo poderá comer por vez.
A versão mais otimizada possível é utilizando um arranjo de semafóros, onde controlamos o estado de cada filosófo de forma idenpendente, só o liberando para comer caso seus vizinhos estejam pensando(), sem garfos adjacentes ocupados.

Detalhes da implementação do código estarão comentados no código, explicando a execução e o racional por trás das soluções

Códigos finalizados:

Filosofos2.c - VERSÃO DO CÓDIGO EM C, UTLIZANDO MULTITHREAD, SEMAPHORE E MUTEX
jantar4.cpp  - VERSÃO DO CÓDIGO EM C++, UTILIZANDO THREAD E MUTEX

######################--------------------------------######################

COMPILAR UTILIZANDO:
g++ -std=c++11 -pthread nome.cpp -o nome
