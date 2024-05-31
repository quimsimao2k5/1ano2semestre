#include <stdio.h>
#include <stdlib.h>


typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

int length (LInt a){
    int result=0;
    while(a!=NULL){
        result += 1;
        a=a->prox;
    }
    return result;
}

void freeL (LInt l){
    LInt anterior;
    while(l!=NULL){
        anterior=l;
        l=l->prox;
        free(anterior);
    }
}

void imprimeL (LInt l){
    while(l!=NULL){
        printf("%d",l->valor);
        l=l->prox;
    }
}

LInt reverseL(LInt l) {
    LInt prev = NULL;
    LInt atual = l;
    LInt next;

    while (atual != NULL) {
        next = atual->prox; // Salva o próximo nó
        atual->prox = prev; // Inverte o ponteiro para o nó anterior
        prev = atual;       // Move prev para o nó atual
        atual = next;       // Move atual para o próximo nó
    }
    // prev agora é o novo primeiro nó da lista invertida
    return prev;
}

// Função auxiliar para criar um nó da lista ligada

void insertOrd(LInt *lista, int valor) {
    LInt novo = malloc(sizeof(struct lligada));
    if (novo == NULL) {
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (*lista == NULL || (*lista)->valor >= valor) {
        novo->prox = *lista;
        *lista = novo;
    } else {
        LInt atual = *lista;
        while (atual->prox != NULL && atual->prox->valor < valor) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

int removeOneOrd(LInt *lista, int coiso) {
    if (*lista == NULL || (*lista)->valor > coiso) return 1;
    else {
        LInt temp = *lista;
        LInt anterior = NULL;
        while (temp != NULL) {
            if (temp->valor == coiso) {
                if (anterior == NULL) {
                    *lista = temp->prox;
                } else {
                    anterior->prox = temp->prox;
                }
                free(temp);
                return 0;
            }
            anterior = temp;
            temp = temp->prox;
        }
    }
    return 1;
}

void merge(LInt *r, LInt a, LInt b) {
    if (a == NULL) {
        *r = b;
        return;
    }
    if (b == NULL) {
        *r = a;
        return;
    }

    LInt resultado = malloc(sizeof(struct lligada));
    LInt temp = resultado;

    while (a != NULL && b != NULL) {
        if (a->valor <= b->valor) {
            temp->valor = a->valor;
            a = a->prox;
        } else {
            temp->valor = b->valor;
            b = b->prox;
        }
        temp->prox = malloc(sizeof(struct lligada));
        temp = temp->prox;
    }

    while (a != NULL) {
        temp->valor = a->valor;
        a = a->prox;
        if (a != NULL) {
            temp->prox = malloc(sizeof(struct lligada));
            temp = temp->prox;
        }
    }

    while (b != NULL) {
        temp->valor = b->valor;
        b = b->prox;
        if (b != NULL) {
            temp->prox = malloc(sizeof(struct lligada));
            temp = temp->prox;
        }
    }
    temp->prox = NULL;

    *r = resultado;
}


int main() {
    // Criando uma lista ligada para teste
    LInt lista = NULL;
    insertOrd(&lista, 2);
    insertOrd(&lista, 4);
    insertOrd(&lista, 1);
    insertOrd(&lista, 3);

    printf("Lista antes da remoção: ");
    imprimeL(lista);
    printf("\n");

    // Removendo o elemento 2 da lista
    int resultado = removeOneOrd(&lista, 5);
    if (resultado == 0) {
        printf("Elemento removido com sucesso.\n");
    } else {
        printf("Elemento não encontrado na lista.\n");
    }

    printf("Lista após a remoção: ");
    imprimeL(lista);

    // Liberando memória alocada para a lista
    while (lista != NULL) {
        LInt temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}