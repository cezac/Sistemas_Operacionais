----------------------------------------------------------

## Códigos finalizados:

**JantarFilosofosFinal.c - VERSÃO DO CÓDIGO EM C, UTLIZANDO MULTITHREAD, SEMAPHORE E MUTEX**

COMPILAR NORMAL, SEM NECESSIDADE DE ARGUMENTOS EXTERNOS

----------------------------------------------------------

**jantar_dos_filosofos_final.cpp  - VERSÃO DO CÓDIGO EM C++, UTILIZANDO THREAD E MUTEX**

COMPILAR UTILIZANDO COMPILADOR G++ E EXECUTAR O SEGUINTE COMANDO NO TERMINAL:
g++ -std=c++11 -pthread jantar_dos_filosofos_final.cpp

----------------------------------------------------------

*Detalhes da implementação do código estarão comentados no código, explicando a execução e o racional por trás das soluções*

----------------------------------------------------------

### MATERIAL DE ESTUDO UTILIZADO PARA RESOLUÇÃO:

Livro "Sistema Operacionais Modernos" 3°Edição:

Página 50, capítulo de thread;

Página 99 até 102 solução para o problema dos filósofos.

Material de apoio para entedimento das bibliotecas de semaphore e mutex.

http://www.di.ubi.pt/~operativos/praticos/html/13-sinc.html

https://cplusplus.com/reference/thread/thread/

https://cplusplus.com/reference/mutex/mutex/unlock/

https://cplusplus.com/reference/mutex/lock/

https://en.cppreference.com/w/cpp/thread/thread

https://www.geeksforgeeks.org/multithreading-in-cpp/

https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html


----------------------------------------------------------


POSSE E ESPERA:
Filosófo toma o garfo da esquerda e fica aguardando o da direita;
  
  
ESPERA CIRCULAR:
Cadeia circular de filosófos aguardando simultanemante um garfo;
  
  
NÃO PREEMPÇÃO:
Filósofo não pode tomar um garfo do outro;


CONTÉUDO DO VIDEO: https://www.youtube.com/watch?v=LhkDV3cECNY

----------------------------------------------------------


A “troca” de informações é realizada através da comunicação inter processos (IPC). Para introduzir o conceito analisamos um dos problemas mais famosos na área de Sistemas Operacionais: o jantar dos filósofos.
Cada filósofo possui um prato cheio de spaghetti à sua frente. 
Além disso, um garfo é posicionado entre cada par adjacente de filósofos (portanto, cada filósofo tem exatamente um garfo à sua esquerda e exatamente um garfo à sua direita).

Cada filósofo pode estar ou pensando ou comendo. Para comer são necessários dois garfos: direito e esquerdo. 
Se ele pega um dos garfos e o outro não está disponível, devolve-o à mesa e continua pensando até que consiga pegar os dois garfos de uma só vez. 
Quando conseguir pegar os dois garfos o filósofo come e logo depois devolve ambos os garfos à mesa.

Levando em consideração o problema computacional proposto, responda á seguinte questão:

Implemente uma possível solução para o problema do jantar dos filósofos?
Explique, em cada trecho do seu programa, como é resolvido o problema da comunicação inter processos (IPC)?


RESPOSTA:

**Ao implementar uma solução onde o filósofo pega um garfo e aguarda até o próximo garfo estar disponível NÂO FUNCIONA. Se todos os filosófos resolverem pegar os garfos simultanemante o programa terá um deadlock, onde nenhum deles terá dois garfos e nenhum irá libera um garfo para o próximo, o problema apresenta condições de impasses.**

**Ao implementar uma solução utilizando sleep() e/ou timeout() como método para vencer o problema de deadlock podemos cair em outro problema, onde mesmo utilizando um tempo aleatório para os filosófos iniciarem a pegar os garfos e comer, caso eles iniciem simultanemalmente, o programa iria executar uma parte do código, mas depois   iria parar sem que ninguêm comesse. 
Assim ficariamos neste loop, onde o programa continua executando indevinidamente, mas sem progressão real (starvation).**

**Existe a possibilidade do programa não cair nesta situação, mas para a solução ideal do problema é necessário a utilização de mutex(), onde durante a execução das funções pegarGarfo e devolverGarfo() iriamos utilizar os semáforos binários para controlar o estado de cada garfo.
Além do mutex() pode-se se utilizar da biblioteca semaphore() para implementação de semáforos binários.**

**Existe ainda a possibilidade de fazer o controle de cada filosófo individualmente, utilizando multithread, fazemos o controle de estado de cada integrande da mesa e a manutenção do status de cada semáforo individualmente, está seria a forma mais otimizada.**

**Com estás implementações somos capazes de vencer as condições declaradas acima e propor a melhor solução possível para o projeto.**
