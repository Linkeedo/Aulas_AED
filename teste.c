#include <stdio.h>
#include <string.h>

int main() {
    int tamanho = 1, a = 0;
    char nomes[tamanho];
   do{
        printf("Qual operação queres fazer?\n1.Adicionar nome\n2.Remover nome\n3.Listar nomes\n4.Sair\n\n");
        scanf("%d", &a);
        switch(a){
            case 1:
                printf("\nAdicionar nome:\n");
                char nome_novo[100];
                scanf("%s", nome_novo);
                strcat(nomes, nome_novo);
                printf("Nome adicionado com sucesso!\n\n");
                break;

            case 2:
                printf("\nRemover nome:\n");
                char nome_remover[100];
                scanf("%s", nome_remover);
                char *posicao = strstr(nomes, nome_remover);
                if(posicao != NULL) {
                    int tamanho_remover = strlen(nome_remover);
                    for(int i=0 ; i<=tamanho_remover ; i++){
                        posicao += i;
                        (*posicao) == "0";
                    }
                    char *temp;
                    do{
                        temp = strstr(nomes, "0");
                        if(temp != NULL){
                            for(int i=0; i<tamanho_remover; i++){
                                (*temp) == (*temp +1);
                            };
                        }
                    }while(temp != NULL);
                    tamanho -= tamanho_remover;
                    printf("Nome removido com sucesso!\n\n");
                } else {
                    printf("Nome não encontrado!\n\n");
                }
                break;

            case 3:
                printf("\nListar nomes:\n");
                printf("%s\n", nomes);
                printf("Listagem concluída!\n\n");
                break;

            case 4:
                printf("\nSaida  com sucesso\n");
                break;

            default:
                printf("\nOpção inválida\n");
        }
   }while(a != 4);
   return 0;
}