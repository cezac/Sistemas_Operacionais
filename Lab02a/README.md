## LAB02a

### Exercicio 01 
Rode o programa anterior para valores grandes de n. As mensagens sempre estarão ordenadas pelo valor de i?

### Resposta
Sim, as mensagens sempre estarão ordenadas pelo valor de i, uma vez que stderr não é bufferizado e o print é realizado diretamente no console.

-----------------------------------------------------------------------------------------------

### Exercicio 02
O que acontece se no programa anterior escreve-se as mensagens para sys.stdout, usando print, ao invés de para sys.stderr?

### Resposta
Apesar dos testes realizados apresentarem sempre o valor de i em sequência (testes feitos entre n=15000), acreditamos que deveria ocorrer uma quebra da sequencia em algum momento devido ao buffer. Sobre isso, destacamos que stdout é a stream standard output (output padrão), é bufferizado, por isso é necessário chamar um flush para limpar o buffer e evitar o erro desta questão, e pode ter a mensagem de output redirecionada a um arquivo. Por outro lado, stderr é a stream standard error, o output para mensagens de erro, o qual não é bufferizado e a mensagem é printada diretamente no console, normalmente não podendo ser redicionada a um arquivo (mas há formas de contornar isto).
