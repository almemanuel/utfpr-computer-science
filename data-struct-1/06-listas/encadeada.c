#include <stdio.h>
#include<stdlib.h>

/* DEFINIÇÃO DAS STRUCTS */
typedef struct {
    int valor;
} Dado;


typedef struct No {
    Dado chave;
    struct No *prox;
} No;

typedef struct No *Lista;


/* PROTÓTIPOS */
int lista_vazia(Lista *lista);
Lista *cria_lista();
void libera_lista(Lista *lista);
int tamanho_lista(Lista *lista);
void insere_lista_inicio(Lista *lista, Dado dado);
void insere_lista_final(Lista *lista, Dado dado);
void insere_lista_pos(Lista *lista, Dado dados, int pos);
int ordem_lista(Lista *lista);
void ordena_crescente(Lista *lista); // fazer
void ordena_decrescente(); // fazer
void remove_lista_inicio(Lista *lista);
void remove_lista_final(Lista *lista);
void remove_chave(Lista *lista, int chave); /* checar */
void remove_pos(); // fazer
void exclui_repeticoes(); // fazer
int consulta_lista_pos(Lista *lista, int pos);
int consulta_lista_chave(Lista *lista, int chave);
void imprime_lista(Lista *lista); // fazer
Lista *copia_lista(); // fazer
void inverte_lista(); // fazer


/* PROGRAMA PRINCIPAL */
int main() {
    Lista *lista = cria_lista();
    Dado teste;
    teste.valor = 0;
    insere_lista_inicio(lista, teste);
    teste.valor = 1;
    insere_lista_inicio(lista, teste);
    teste.valor = 2;
    insere_lista_inicio(lista, teste);
    teste.valor = 3;
    insere_lista_inicio(lista, teste);
    imprime_lista(lista);
    printf("%i\n", ordem_lista(lista));

    teste.valor = 4;
    insere_lista_pos(lista, teste, 1);
    imprime_lista(lista);
    printf("%i", consulta_lista_pos(lista, 1));
    printf("\n");
    printf("%i\n", ordem_lista(lista));

    libera_lista(lista);

    return 0;
}


/* FUNÇÕES */
int lista_vazia(Lista *lista) {
    if(lista == NULL || *lista == NULL) return 1; /* lista vazia */
    return 0; /* lista preenchida */
}


Lista *cria_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista)); /* endereço para o primeiro nó */
    if(lista != NULL)
        *lista = NULL; /* quando criada, a lista é vazia, e, portanto, aponta para NULL */
    return lista;
}


void libera_lista(Lista *lista) {
    if(lista == NULL) return;

    No *no;
    while((*lista) != NULL) {
        no = *lista; /* nó será auxiliar que recerá o inicio da lista */
        *lista = (*lista)->prox; /* o inicio da lista receberá o seu proximo elemento */
        free(no); /* no, que guarda o antigo primeiro elemento, é descartado */
        no = NULL;
    }
    free(lista); /* por fim, descarta a lista */
    lista = NULL;
}


int tamanho_lista(Lista *lista) {
    if(lista == NULL) return 0; /* Lista vazia */
    int tam = 0;
    No *no = *lista; /* nó será um ponteiro auxiliar que percorrerá toda lista */
    while(no != NULL) {
        tam++;
        no = no->prox;
    }
    return tam;
}


void insere_lista_inicio(Lista *lista, Dado dado) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* lista nao existe */
    }
    No *no = (No *) malloc(sizeof(No)); /* cria o nó */
    if(no == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* significa que não foi possível alocar memória */
    }
    no->chave = dado; /* ele recebe como chave o dado informado */
    no->prox = *lista; /* o próximo do nó é o endereço armazenado na lista */
    *lista = no; /* a cabeça passa a apontar para o nó */
}


void insere_lista_final(Lista *lista, Dado dado) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* lista nao existe */
    }
    No *no = (No *) malloc(sizeof(No)); /* cria o nó */
    if(no == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* significa que não foi possível alocar memória */
    }
    no->chave = dado;
    no->prox = NULL; /* aponta para NULL, marcando o fim da lista */
    if((*lista) == NULL)
        *lista = no; /* lista vazia -> nó torna-se primeiro elemento */
    else {
        No *aux = *lista; /* ponteiro auxiliar equivalendo o inicio da lista */
        while(aux->prox != NULL)
            aux = aux->prox; /* o auxiliar recebera sempre o seguinte até que o proximo seja NULL */
        aux->prox = no;
    }
}


/*void insere_lista_ordenada(Lista *lista, Dado dado) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    no->chave = dado;
    if(lista_vazia(lista)) {
        no->prox = *lista;
        return;
    } else {
        No *ant, *atual = *lista;
        while(atual != NULL && atual->chave.valor < dado.valor) {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *lista) {
            no->prox = *lista;
            *lista = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
}*/


void insere_lista_pos(Lista *lista, Dado dados, int pos) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    No *novo = (No *) malloc(sizeof(No));
    if(novo == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    novo->chave = dados;
    if(lista_vazia(lista)) {
        novo->prox = *lista;
        return;
    } else {
        No *atual = *lista;
        int i = 0;
        while(atual != NULL) {
            atual = atual->prox;
            i++;
        }
        if(pos < i) {
            No *ant = *lista;
            for(i = 0; i < pos - 1; i++) {
                ant = ant->prox;
            }
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
}


void remove_lista_inicio(Lista *lista) {
    if(lista_vazia(lista)) {
        printf("nao foi possivel remover o no\n");
        return;
    }

    No *no = *lista; /* no que armazena o inicio da lista */
    *lista = no->prox; /* inicio da lista recebe o valor do segundo no */
    free(no); /* remove o no, que armazena o antigo primeiro elemento */
    no = NULL;
}


void remove_lista_final(Lista *lista) {
    if(lista_vazia(lista)) {
        printf("nao foi possivel remover o no\n");
        return;
    }
    No *ant, *no = *lista;
    while(no->prox != NULL) {
        ant = no; /* no anterior recebe o no */
        no = no->prox; /* no recebe o valor do seu proximo */
    }
    if(no == *lista)
        *lista = no->prox; /* siginifica que a lista continha só um elemento, que será removido nessa linha */
    else
        ant->prox = no->prox; /* caso contrário, o valor anterior ao no apontará para o proximo de nó */
    free(no);
    no = NULL;
}


void remove_chave(Lista *lista, int chave) {
    if(lista == NULL) {
        printf("nao foi possivel remover o no\n");
        return;
    }
    No *ant, *no = *lista;
    while(no != NULL && no->chave.valor != chave) {
        ant = no; /* valor anterior recebe o no atual */
        no = no->prox; /* no se tornara no seu proximo */
    }
    if(no == NULL) {
        printf("nao foi possivel remover o no\n");
        return; /* elemento não encontrado */
    }

    if(no == *lista) /* lista com apenas um elemento */
        *lista = no->prox; /* isso levará a apontar NULL */
    else
        ant->prox = no->prox; /* o proximo do anterior se tornara no proximo do atual */
    free(no);
    no = NULL;
}


int consulta_lista_pos(Lista *lista, int pos) {
    if(lista == NULL || pos <= 0) return -1;
    No *no = *lista; /* auxiliar apontando para o inicio */
    int i = 1;
    while(no != NULL && i <= pos) {
        no = no->prox; /* auxiliar torna-se no seu proximo valor */
        i++;
    }
    if(no == NULL) /* não existe a posição */
        return -1;
    return no->chave.valor; /* retorna o valor */
}


int consulta_lista_chave(Lista *lista, int chave) {
    if(lista == NULL) return 0;
    No *no = *lista;
    int i = 1;
    while(no != NULL && no->chave.valor != chave)
        no = no->prox; /* no torna-se no proximo */
        i++;
    if(no == NULL)
        return 0; /* chave nao existe */
    return i; /* retorna a posição da chave */
}


void imprime_lista(Lista *lista) {
    if(lista == NULL) return;

    No *aux;
    for(aux = *lista; aux != NULL; aux = aux->prox) {
        printf("%i ", aux->chave.valor);
    }
    printf("\n");
}


int ordem_lista(Lista *lista) {
    if(lista == NULL) return 0;
    No *aux = *lista;

    while(aux->prox != NULL && aux->chave.valor < aux->prox->chave.valor)
        aux = aux->prox;
    if(aux->prox == NULL) return 1; // crescente

    aux = *lista;
    while(aux->prox != NULL && aux->chave.valor > aux->prox->chave.valor)
        aux = aux->prox;
    if(aux->prox == NULL) return -1; // decrescente

    return 0;
}

