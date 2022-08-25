#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
  if (argc != 2) 
  {
    printf("Uso incorreto, por favor especificar o arquivo desejado na linha "
           "de comando\n");
    exit(1);
  }
  FILE* arquivo = fopen(argv[1], "r");
  if (arquivo == NULL)
  {
    printf("ERRO ao tentar abrir o arquivo solicitado\n");
    exit(1);
  }
  char caractere = fgetc(arquivo);
  while (caractere != EOF)
    {
      putchar(caractere);
      caractere = fgetc(arquivo);
    }
  fclose(arquivo);
}
