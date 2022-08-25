#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
  if (argc != 3) 
  {
    printf("Uso indevido do programa. Passar os três parâmetros (programa, "
           "fonte, destino) .\n");
    exit(1);
  }
  char *caminho_inicial = argv[1];
  char *caminho_destino = argv[2];

  FILE *arquivo_inicial = fopen(caminho_inicial, "r");
  if (arquivo_inicial == NULL)
  {
    printf("Erro tentando abrir o arquivo inicial");
    exit(1);
  }
    
  FILE *arquivo_final = fopen(caminho_destino, "w+");
  if (arquivo_inicial == NULL)
  {
    printf("Erro tentando abrir o arquivo final");
    exit(1);
  }
  
  char caractere = fgetc(arquivo_inicial);
  while (caractere != EOF) 
  {
    fputc(caractere, arquivo_final);
    caractere = fgetc(arquivo_inicial);
  }
  fclose(arquivo_inicial);
  fclose(arquivo_final);
}
