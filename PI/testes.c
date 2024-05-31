#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


typedef struct LInt_nodo
{
    int valor;
    struct LInt_nodo *prox;
} *LInt;

LInt acrescentaNoFim(LInt l, int valor) {
    LInt novo = malloc(sizeof(struct LInt_nodo));
    novo->valor = valor;
    novo->prox = NULL;

    if (l == NULL) {
        return novo;
    }

    LInt aux = l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    return l;
}

typedef struct ABin_nodo
{
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;

// LInt createLinkedListExample() {
//     LInt l = NULL;
//     l = acrescentaNoFim(l, 1);
//     l = acrescentaNoFim(l, 2);
//     l = acrescentaNoFim(l, 3);
//     l = acrescentaNoFim(l, 4);
//     return l;
// }

// ABin createBinarySearchTreeExample() {
//     ABin root = NULL;
//     root = malloc(sizeof(struct ABin_nodo));
//     root->valor = 4;
//     root->esq = malloc(sizeof(struct ABin_nodo));
//     root->esq->valor = 2;
//     root->esq->esq = malloc(sizeof(struct ABin_nodo));
//     root->esq->esq->valor = 1;
//     root->esq->esq->esq = NULL;
//     root->esq->esq->dir = NULL;
//     root->esq->dir = malloc(sizeof(struct ABin_nodo));
//     root->esq->dir->valor = 3;
//     root->esq->dir->esq = NULL;
//     root->esq->dir->dir = NULL;
//     root->dir = malloc(sizeof(struct ABin_nodo));
//     root->dir->valor = 6;
//     root->dir->esq = malloc(sizeof(struct ABin_nodo));
//     root->dir->esq->valor = 5;
//     root->dir->esq->esq = NULL;
//     root->dir->esq->dir = NULL;
//     root->dir->dir = malloc(sizeof(struct ABin_nodo));
//     root->dir->dir->valor = 7;
//     root->dir->dir->esq = NULL;
//     root->dir->dir->dir = NULL;
//     return root;
// }

void merge(int e[], int d[], int final[], int tamanho){
    int i=0, j=0, k=0;
    int te = tamanho/2;
    int td = tamanho-te;
    while(i<te && j<td){
        if(e[i] <= d[j]){
            final[k++] = e[i++];
        }
        else{
            final[k++] = d[j++];
        }
    }
    while(i<te){
        final[k++] = e[i++];
    }
    while(j<td){
        final[k++] = d[j++];
    }
}

void mergeSort(int v[], int tamanho){
    if(tamanho<2) return;
    else {
        int meio = tamanho/2, i, j, r=0;
        int esq[meio];
        int dir[tamanho-meio];
        for(i=0; i<meio; i++){
            esq[i] = v[i];
        }
        for(j=meio; j<tamanho; j++, r++){
            dir[r] = v[j];
        }
        mergeSort(esq, meio);
        mergeSort(dir, tamanho-meio);
        merge(esq, dir, v, tamanho);
    }
}

//ta bom
int nesimo(int a[], int N, int i){
    mergeSort(a,N);
    return a[i-1];
}


LInt removeMaiores(LInt l, int x){
    LInt ant=NULL, original=l;
    if(l==NULL)return l;
    else{
        while(l!=NULL && l->valor<=x){
            ant=l;
            l=l->prox;
        }
        if(l==NULL)return original;
        else if(ant!=NULL){
            ant->prox=NULL;
            while(l->prox!=NULL){
                ant=l;
                l=l->prox;
                free(ant);
            }
            free(l);
            return original;
        }
    }
    printf("IM ON A WHOLE ANOTHER LEVEL IM GEEKIN\n");
    return NULL;
}

int existe(ABin a, int x){
    if(a==NULL)return 0;
    else{
        while(a!=NULL && a->valor!=x){
            if(x>a->valor)a=a->dir;
            else a=a->esq;
        }
        if(a==NULL)return 0;
        else return 1;
    }
}

LInt newLInt(int x){
    LInt new=malloc(sizeof(struct LInt_nodo));
    new->prox=NULL;
    new->valor=x;
    return new;
}

// LInt acrescentaNoFim(LInt a,int x){
//     LInt aux=a;
//     if(aux==NULL)return newLInt(x);
//     else{
//         while(aux->prox!=NULL){
//         aux=aux->prox;
//         }
//         aux->prox=newLInt(x);
//     }
//     return a;
// }

LInt caminho(ABin a, int x){
    if(existe(a,x)== 0)return NULL;
    LInt r=NULL;
    while(a!=NULL){
        if(a->valor<x){
            r=acrescentaNoFim(r,a->valor);
            a=a->dir;
        }
        else if(a->valor==x){
            r=acrescentaNoFim(r,x);
            break;
        }
        else{
            r=acrescentaNoFim(r,a->valor);
            a=a->esq;
        }
    }
    return r;
}
void freeABin(ABin a) {
    if (a == NULL) return;
    freeABin(a->esq);
    freeABin(a->dir);
    free(a);
}

// Freeing the linked list
void freeLInt(LInt l) {
    LInt aux;
    while (l != NULL) {
        aux = l;
        l = l->prox;
        free(aux);
    }
}

void printTree(ABin root){
    if (root == NULL) return;
    printf("%d ", root->valor);
    printTree(root->esq);
    printTree(root->dir);
}

void printLInt(LInt lista){
    while(lista!=NULL){
        printf("%d ",lista->valor);
        lista=lista->prox;
    }
    printf("\n");
}

int incAux(char s[]){
    int i=strlen(s)-1;
    int r=0;
    while(i>=0){
        if(s[i]=='9'){
            r++;
            i--;
        }
        else break;
    }
    return r;
}

void inc(char s[]){
    int l = strlen(s);
    int h = incAux(s);
    if(h==0)
        s[l-1]++;
    else{
        if(l>h){
            s[l-h-1]++;
            for(int i=l-h;i<l;i++){
                s[i]='0';
            }
        }
        else{
            for(int j = l; j >= 0; j--){
                s[j+1] = '0';
            }
            s[l+2]='\0';
            s[0] = '1';
        }
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int sacos(int pesos[], int N, int C) {
    int dp[1001][1001];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (pesos[i-1] <= j)
                dp[i][j] = max(pesos[i-1] + dp[i-1][j-pesos[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return (N * C - dp[N][C] + C - 1) / (2 * C);
}

//EXAME 2022
int pesquisa(int a[], int N, int x) {
    int inicio = 0;
    int fim = N - 1;
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        
        if (a[meio] == x) {
            return meio;
        }
        else if (a[meio] < x) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    
    return -1;
}

void roda(LInt *l){
    if (*l == NULL || (*l)->prox == NULL) return;

    LInt aux = *l;
    LInt pen = NULL;
    while (aux->prox != NULL) {
        pen = aux;
        aux = aux->prox;
    }
    pen->prox = NULL;
    aux->prox = *l;
    *l = aux;
}

    // ABin tree = malloc(sizeof(struct ABin_nodo));
    // tree->valor = 4;
    // tree->dir = malloc(sizeof(struct ABin_nodo));
    // tree->dir->valor = 5;
    // tree->dir->dir = malloc(sizeof(struct ABin_nodo));
    // tree->dir->dir->valor = 12;
    // tree->dir->dir->dir = NULL;
    // tree->dir->dir->esq = NULL;
    // tree->dir->esq = NULL;
    // tree->esq = malloc(sizeof(struct ABin_nodo));
    // tree->esq->valor = 3;
    // tree->esq->esq = malloc(sizeof(struct ABin_nodo));
    // tree->esq->dir = malloc(sizeof(struct ABin_nodo));
    // tree->esq->esq->valor = 7;
    // tree->esq->dir->valor = 1;
    // tree->esq->esq->esq = NULL;
    // tree->esq->esq->dir = NULL;
    // tree->esq->dir->esq = NULL;
    // tree->esq->dir->dir = NULL;

int apaga(ABin a, int n){
    if(a==NULL) return 0;
    int apagaesq= apaga(a->esq,n);
    int apagadir= apaga(a->dir,n-apagaesq);
    if(apagaesq+apagadir+1<=n){
        free(a);
        a=NULL;
        return apagaesq+apagadir+1;
    }
    return apagaesq+apagadir;
}

int apagafinal(ABin a, int n){
    return n-apaga(a,n);
}

int caraterToInt(char s){
    return s -'0';
}

char intToChar(int x){
    return x+'0';
}

void stringToArray(char s[],int array[]){
    for(int i=0;s[i]!='\0';i++){
        array[i]=caraterToInt(s[i]);
    }
}

int casosPares(int x){
    if(x<5)return x*2;
    else{
        int r= 1+((x*2)%10);
        return r;
    }
    return 0;
}

int valorTotal(int a[], int N){
    int count=0;
    for(int i=0; i<N;i++){
        if(i%2!=0)count+=casosPares(a[i]);
        else count+=a[i];
    }
    return count;
}

void checksum(char s[]){
    int size=strlen(s);
    int array[size];
    stringToArray(s,array);
    int r=valorTotal(array,size);
    int n;
    if(r%10==0)return;
    else{
        n=10-(r%10);
    }
    char c = intToChar(n);
    s[size]=c;
    s[size+1]='\0';
}

//TESTE 2023

void divisores(int x, int a[]){
    int r=0;
    for(int i=1;i<=x/2;i++){
        if((x%i)==0){
            a[r]=i;
            r++;
        }
    }
}

int perfeito(int x){
    int soma=0;
    int a[x];
    divisores(x,a);
    for(int i=0;a[i]!=0;i++){
        soma+=a[i];
    }
    if(soma==x)return 1;
    else return 0;
}

int perfeito2(int x){
    int soma=0;
    for(int i=1;i<=x/2;i++){
        if(x%i==0)soma+=i;
    }
    if(soma==x)return 1;
    else return 0;
}

typedef struct {
    int x, y;
} Ponto;

int distancia(Ponto ponto) {
    return ponto.x * ponto.x + ponto.y * ponto.y;
}

void mergePontos(Ponto esq[], Ponto dir[], Ponto final[], int te, int td) {
    int i = 0, j = 0, k = 0;

    while (i < te && j < td) {
        if (distancia(esq[i]) > distancia(dir[j])) {
            final[k++] = dir[j++];
        } else {
            final[k++] = esq[i++];
        }
    }

    while (i < te) {
        final[k++] = esq[i++];
    }

    while (j < td) {
        final[k++] = dir[j++];
    }
}

void mergeSortPontos(Ponto pos[], int N) {
    if (N < 2) return;
    else {
        int meio = N / 2;
        Ponto *esq = (Ponto *)malloc(meio * sizeof(Ponto));
        Ponto *dir = (Ponto *)malloc((N - meio) * sizeof(Ponto));

        for (int i = 0; i < meio; i++) {
            esq[i] = pos[i];
        }
        
        for (int j = meio; j < N; j++) {
            dir[j - meio] = pos[j];
        }

        mergeSortPontos(esq, meio);
        mergeSortPontos(dir, N - meio);
        mergePontos(esq, dir, pos, meio, N - meio);

        free(esq);
        free(dir);
    }
}

void ordena(Ponto pos[], int N) {
    mergeSortPontos(pos, N);
}

int depth(ABin a, int x) {
    if (a == NULL) {
        return -1; // Árvore vazia, x não está presente
    } else if (a->valor == x) {
        return 0; // x está na raiz (nível 0)
    } else {
        int left_depth = depth(a->esq, x);
        int right_depth = depth(a->dir, x);

        if (left_depth == -1 && right_depth == -1) {
            return -1; // x não está na subárvore esquerda nem na direita
        } else if (left_depth != -1) {
            return left_depth + 1; // x está na subárvore esquerda
        } else {
            return right_depth + 1; // x está na subárvore direita
        }
    }
}

LInt periodica(char s[]) {
    int i = 0;
    LInt lista = NULL;
    LInt head = lista;
    if(s[i]=='('){
        LInt inicioPeriodo = newLInt(caraterToInt(s[i+1]));
        lista=inicioPeriodo;
        head=lista;
        i++;
        while (s[i] != ')') {
        int c = caraterToInt(s[i]);
        lista->prox = newLInt(c);
        lista = lista->prox;
        i++;
        }
        lista->prox=inicioPeriodo;
        return head;
    }
    // Criação da lista inicial (fora dos parênteses)
    while (s[i] != '(') {
        int c = caraterToInt(s[i]);
        if (lista == NULL) {
            lista = newLInt(c);
            head = lista;
        } else {
            lista->prox = newLInt(c);
            lista = lista->prox;
        }
        i++;
    }

    // Criação da parte periódica da lista
    i++;
    lista->prox=newLInt(caraterToInt(s[i]));
    lista=lista->prox;
    LInt inicioPeriodo = lista; // Guarda a posição do início do período
    i++;
    while (s[i] != ')') {
        int c = caraterToInt(s[i]);
        lista->prox = newLInt(c);
        lista = lista->prox;
        i++;
    }

    // Conecta o último nó da parte periódica ao início do período
    lista->prox = inicioPeriodo;

    return head;
}

int indiceLetra(char letra){
    return letra - 'a';
}

char minToMai(char x){
    return (indiceLetra(x))+'A';
}

void wordleAux(char secreta[],char nova[], char final[]){
    int t=strlen(nova);
    strcpy(final,secreta);
    for(int i=0;final[i]!='\0';i++){
        for(int j=0;nova[j]!='\0';j++){
            if(final[i]==nova[j]){
                nova[j]='*';
                break;
            }
            if(j==(t-1)){
                final[i]='*';
            }
        }
    }

}

int wordle(char secreta[], char tentativa[]){
    int t=strlen(secreta);
    char nova[t];
    char final[t];
    int count=0;
    for(int i=0;secreta[i]!='\0';i++){
        if(secreta[i]==tentativa[i]){
            nova[i]='*';
            tentativa[i]=minToMai(secreta[i]);
        }
        else{
            nova[i]=tentativa[i];
            tentativa[i]='*';
        }
    }
    wordleAux(secreta,nova,final);
    for(int j=0;tentativa[j]!='\0';j++){
        if((tentativa[j]=='*')&&(final[j]=='*'));
        else{
            if(tentativa[j]!='*')count++;
            else{
                tentativa[j]=final[j];
                count++;
            }
        }
    }
    return count;
}

// int isFib(long int x){
//     long int sFib[1001];
//     sFib[0]=0;
//     sFib[1]=1;
//     for(int i=2;i<101;i++){
//         sFib[i]=sFib[i-1]+sFib[i-2];
//     }
//     for(int j=0;j<101;j++){
//         if(x==sFib[j])return j;
//     }
//     return 0;
// }

// long int fib(int x){
//     long int r= 10000;
//     long int sFib[r];
//     sFib[0]=0;
//     sFib[1]=1;
//     for(int i=2;i<r;i++){
//         sFib[i]=sFib[i-1]+sFib[i-2];
//     }
//     return sFib[x];
// }

typedef struct {
    float teste, minis;
} Aluno;

int floattoint(float x){
    return roundf(x);
}

int calculaNota(Aluno a){
    float r=(a.teste*0.8)+(a.minis*0.2);
    if(r<9.5)return 0;
    else return floattoint(r);
}

int veMaior(int a[],int N){
    int M=a[0],nota=10;
    for(int i=1;i<N;i++){
        if(a[i]>M){
            M=a[i];
            if(i<10)nota=10+i;
            else if(i==10)nota=20;
            else nota = 0;
        }
    }
    return nota;
}

int moda(Aluno turma[], int N){
    int notas[12]={0};
    for(int i=0;i<N;i++){
        int r=calculaNota(turma[i]);
        if(r==0)notas[11]++;
        else if(r==20)notas[10]++;
        else notas[r%10]++;
    }
    int m=veMaior(notas,12);
    return m;
}

int take(int n, LInt *l){
    LInt lsize=*l;
    int size=0;
    int count=0;
    while(lsize!=NULL){
        size++;
        lsize=lsize->prox;
    }
    if(size<n)return 0;
    int n2=n;
    while(n2>1){
        LInt penultimo=*l;
        *l=(*l)->prox;
        penultimo->prox=NULL;
        free(penultimo);
        n2--;
        count++;
    }
    LInt limpa=(*l)->prox;
    while(limpa!=NULL){
        LInt penultimo=limpa;
        limpa=limpa->prox;
        penultimo->prox=NULL;
        free(penultimo);
        count++;
    }
    return count;
}

// void insertionSort(LInt *head_ref) {
//     // Lista ordenada inicializada
//     LInt sorted = NULL;

//     // Percorre a lista dada e insere cada nó na lista ordenada
//     LInt current = *head_ref;
//     while (current != NULL) {
//         // Armazena o próximo para o próximo passo
//         LInt next = current->prox;

//         // insere o nó atual na lista ordenada
//         sortedInsert(&sorted, current);

//         // Atualiza o nó atual
//         current = next;
//     }

//     // Atualiza head_ref para a lista ordenada
//     *head_ref = sorted;
// }

// /* função para inserir um novo nó na lista ordenada correta */
// void sortedInsert(LInt* head_ref, LInt new_node) {
//     LInt current;
//     /* caso especial para o cabeçalho da lista ligada */
//     if (*head_ref == NULL || (*head_ref)->valor >= new_node->valor) {
//         new_node->prox = *head_ref;
//         *head_ref = new_node;
//     } else {
//         /* localiza o nó antes do ponto de inserção */
//         current = *head_ref;
//         while (current->prox != NULL && current->prox->valor < new_node->valor) {
//             current = current->prox;
//         }
//         new_node->prox = current->prox;
//         current->prox = new_node;
//     }
// }

int verifica(char frase[], int k){
    int i,j;
    for(i=0;frase[i]!='\0';i++){
        if(frase[i]==' ' || frase[i]==',' || frase[i]=='.')continue;
        else{
            for(j=i;frase[j]!=' ' && frase[j]!=',' && frase[j]!='.';j++);
            if(j-i>=k){i=j;continue;}
            else return 0;
        }
    }
    return 1;
}

ABin novoNo(int valor){
    ABin noNovo=malloc(sizeof(struct ABin_nodo));
    noNovo->valor=valor;
    noNovo->esq=noNovo->dir=NULL;
    return noNovo;
}

ABin reconstroi(char s[]){
    static int pos=0;
    if(s[pos]=='\0' || s[pos]=='*'){
        pos++;
        return NULL;
    }
    ABin a=novoNo(s[pos]-'0');
    pos++;
    a->esq=reconstroi(s);
    a->dir=reconstroi(s);

    return a;
}

int main() {
    char frase[]="Esta frase tem palavras suficientemente longas.";
    int r=verifica(frase,3);
    printf("%d\n",r);
    return 0;
}