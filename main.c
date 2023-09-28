#include <stdio.h>
#include <time.h>
#define m 6
#define n 1000
#define max 255

void leArquivo(char T[n]) {
  FILE *arq;
  arq = fopen("banco.txt", "r");

  int i = 0;
  while (i < n) {
    while (fscanf(arq, "%c", &T[i]) == 1) {
      i++;
    }
  }
  fclose(arq);
}

int BuscaBMH(char* T, char* P, int* comparacoes){
    int tabela[max];
    int i, j, k;
    for(j=0; j<max; j++)
        tabela[j]=m;
    for(j=1; j<m; j++)
        tabela[P[j-1]]=m-j;
    i=m;
    while(i<=n){
        k=i;
        j=m;
        (*comparacoes)++;
        while(T[k-1] == P[j-1] && j>0){
            k--;
            j--;
        }
        if(j==0){
            return k+1;
        }
        i=i+tabela[T[i-1]];
    }
    return -1;
}


void main(){

    clock_t inicio, fim;
    double tempo_decorrido;

    inicio = clock();

    char p[m]= "cacbac";
    char t[n];
    int Comp= 0;

    leArquivo(t);

    printf("%d\n", BuscaBMH(t, p, &Comp));
    printf("Foram necessarias: %d comparações\n", Comp);

    fim = clock();

    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo decorrido: %f segundos\n", tempo_decorrido);

}