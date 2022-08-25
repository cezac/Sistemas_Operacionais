# Lab1

Caio Cezar Oliveira Filardi do Carmo - TIA: 31891365
Mayara Meneghetti - TIA: 32152280

-----------------------------------------------------------------------------------------------
Ex 1 (1a): O comando cat é usado no sistema operacional Linux para exibir o conteúdo de um arquivo na tela do computador. Escreva um programa (na linguagem C) faça exatamente o que o cat faz, o programa deverá ler um arquivo texto (entrada) informado por linha de comando no interpretador de comando (Como se faz isso ?) e depois imprimir o conteúdo do arquivo na tela. Faça todos os testes necessários para abertura, leitura e ao final não se esqueça de fechar o arquivo.
Identifique no seu programa as linhas de comando onde ocorrem chamadas de sistemas ao SO.
Quantas chamadas de sistemas foram realizadas?

RESPOSTA: 
Caso ocorra uso indevido, o programa realiza o printf("") e o exit(1), totalizando duas chamadas no sistema. Caso ocorra erro ao abrir o arquivo, o programa chama fopen(argv[1], "r"), printf("") e exit(1), totalizando três chamadas. Por sua vez, se o programa for executado com sucesso, realizará as chamadas fopen(argv[1], "r"), putchar(caractere), fgetc(arquivo) e fclose(arquivo), realizando 4 chamadas somadas a outras N, onde N corresponde ao número de vezes que o programa percorreu o condição WHILE.

-----------------------------------------------------------------------------------------------
EX 2 (1b):  Escreva um programa (na linguagem C) que leia um arquivo texto (entrada) e copie para um outro arquivo (saída), ou seja, faz o que o comando cp faz no Linux. O seu programa deve solicitar o nome do arquivo de entrada e de saída (por linha de comando), uma vez obtido os dois nomes, o programa deve abrir o arquivo de entrada e criar o arquivo de saída. Caso por alguma razão não possa abrir o arquivo de entrada seu programa deve imprimir uma mensagem de aviso e finalizar, caso aconteça um erro de criação do arquivo saída o programa imprime uma mensagem e finaliza. Caso o programa tenha sucesso na abertura e criação, o programa lê a partir do arquivo de entrada e grava no arquivo de saída.
Finalmente, depois que o arquivo de entrada for inteiramente copiado o programa pode fechar os dois arquivos.
Identifique no seu programa as linhas de comando onde ocorrem chamadas de sistemas ao SO.
Quantas chamadas de sistemas foram realizadas?

REPOSTA: Caso ocorra uso indevido, o programa realiza o printf("") e o exit(1), totalizando duas chamadas no sistema. Caso ocorra erro ao abrir o arquivo, o programa chama fopen(caminho_inical, "r"), printf("") e exit(1), totalizando três chamadas. Por sua vez, se o programa for executado com sucesso, realizará as chamadas fopen(caminho_inical, "r"), fopen(caminho_destino, "w+"), fgetc(arquivo_inicial), fputc(caractere, arquivo_final), fgetc(arquivo_inicial), fclose(arquivo_incial) e fclose(arquivo_final) realizando 7 chamadas somadas a outras N, onde N corresponde ao número de vezes que o programa percorreu o condição WHILE.

-----------------------------------------------------------------------------------------------

