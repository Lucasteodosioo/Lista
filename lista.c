#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *prox;
}No;

int ler_num(){
    int num;
    printf("Digite o numero que deseja inserir: \n");
    scanf("%d", &num);
    return num;
}

void inserir_comeco(No **lista){
    No *novo = malloc(sizeof(No));

    if (novo){
        novo->num = ler_num();
        novo->prox = *lista;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria.\n");
}

void inserir_fim(No **lista){
    No *novo = malloc(sizeof(No));
    No *aux;

    if (novo){
        novo->num = ler_num();
        novo->prox = NULL;
        if(*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria.\n");
}

void inserir_meio(No **lista, int ant){
    No *novo = malloc(sizeof(No));
    No *aux;

    if (novo){
        novo->num = ler_num();

        if (*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->num != ant && aux->prox){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria.\n");
}

void inserir_ordenado(No **lista){
    No *novo = malloc(sizeof(No));
    No *aux;

    if (novo){
        novo->num = ler_num();
        if (*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        }
        else if (novo->num < (*lista)->num){
            novo->prox = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->prox && novo->num > aux->prox->num)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }   
    }
    else
        printf("Erro ao alocar memoria.\n");
}

No* pop(No **lista, int num){
    No *remover = NULL;
    No *aux;

    if (*lista){
        if ((*lista)->num == num){
            remover = *lista;
            *lista = remover->prox;
        }
        else{
            aux = *lista;
            while (aux->prox && aux->prox->num != num){
                aux = aux->prox;
            }
            if (aux->prox){
                remover = aux->prox;
                aux->prox = remover->prox;

            }
        }
    }

    return remover;
}

void imprimir(No *no){
    printf("Lista: \n");
    while (no){
        printf("%d ", no->num);
        no = no->prox;
    }
    printf("\n");
}

int main(){
    int opcao;
    int ref;
    int remover;
    No *l = NULL;
    No *remove;

    while(1){
        printf("1 inserir no comeco - 2 inserir no fim - 3 inserir no meio - 4 inserir ordenado - 5 remover - 6 imprimir - 0 sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserir_comeco(&l);
            break;
        case 2: 
            inserir_fim(&l);
            break;
        case 3:
            printf("Digite o valor de referencia: \n");
            scanf("%d", &ref);
            inserir_meio(&l, ref);
            break;
        case 4:
            inserir_ordenado(&l);
            break;
        case 5: 
            printf("Digite o numero que voce deseja remover: \n");
            scanf("%d", &remover);
            remove = pop(&l, remover);
            break;
        case 6:
            imprimir(l);
            break;
        case 0:
            return 0;
        }
    }
    
    return 0;
}
