#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_PESSOA ( ( 10 * sizeof ( char ) ) + sizeof ( int ) + ( 10 * sizeof ( char ) ) )
#define QNT_PESSOAS *( ( int * )pBuffer + 1 )
#define INT_REMOVER ( *( (int *)( (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) + ( sizeof ( char ) * 10 ) ) ) )
#define INT_LISTA ( *( (int *)( (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) ) ) )
// DESENHO BUFFER ATUAL [MENU|NDEPESSOAS|PESSOA1]
int main() {
    void *pBuffer = malloc ( sizeof ( int ) * 2 );
    *(int *)pBuffer = 0, QNT_PESSOAS = 0;

    do {

        printf("Agenda\n1-Adicionar pessoa\n2-Remover pessoa\n3-Buscar pessoa\n4-Listar todos\n5-Sair\nEscolha uma opção: ");
        scanf("%d", ( int * )pBuffer );

        switch ( *(int *)pBuffer ) {
            
            case 1:

                printf( "\n");

                pBuffer = realloc ( pBuffer, TAM_PESSOA + (  ( 2 * sizeof ( int )  + TAM_PESSOA * ( QNT_PESSOAS ) ) ) );

                printf ( "Digite o nome da pessoa: " );
                scanf ( "%9s", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) );
                printf ( "Digite a idade da pessoa: " );
                scanf ( "%d", (int *)( (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) + ( sizeof ( char ) * 10 ) ) );
                printf ( "Digite o email da pessoa: " );
                scanf ( "%9s", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) + ( ( sizeof ( char ) * 10 ) + sizeof ( int ) ) );

                QNT_PESSOAS += 1; // adciona mais uma pessoa no contador de pessoas

                printf( "\n");

                break;

            case 2:

                printf( "\n");

                if ( QNT_PESSOAS == 0 ) {
                    printf ( "Não há pessoas cadastradas.\n" );
                    break;
                }
                else {
                    pBuffer = realloc ( pBuffer, TAM_PESSOA + sizeof(int) + (  ( 2 * sizeof ( int )  + TAM_PESSOA * ( QNT_PESSOAS ) ) ) );
                    printf ( "Digite o nome da pessoa a ser removida: " );
                    scanf ( "%9s", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) );

                    for ( INT_REMOVER = 0; INT_REMOVER < QNT_PESSOAS; INT_REMOVER++ ) {
                        if ( strcmp ( ( (char *)pBuffer + ( 2 * sizeof ( int ) ) + ( TAM_PESSOA * INT_REMOVER ) ) , ( (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) ) ) == 0 ){
                            printf( "\n");
                            memmove ( ( (char *)pBuffer + ( 2 * sizeof ( int ) ) + ( TAM_PESSOA * INT_REMOVER ) ) , ( (char *)pBuffer + ( 2 * sizeof ( int ) ) + ( TAM_PESSOA * ( INT_REMOVER + 1 ) ) ), ( TAM_PESSOA * ( QNT_PESSOAS - INT_REMOVER - 1 ) ) );
                            INT_REMOVER = QNT_PESSOAS;
                            QNT_PESSOAS -= 1;
                            printf(  "Pessoa removida com sucesso!\n" );
                            break;
                        }
                    }
                    if ( INT_REMOVER == QNT_PESSOAS ){
                            printf( "Pessoa não encontrada!\n" );
                    }

                    printf( "\n");

                    pBuffer = realloc( pBuffer, ( ( 2 * sizeof ( int ) ) + ( TAM_PESSOA * QNT_PESSOAS ) ) );
                }


                break;
            
            case 3:

                printf( "\n");

                if ( QNT_PESSOAS == 0 ) {
                    printf ( "Não há pessoas cadastradas.\n" );
                    break;
                }
                else{
                    //Igualzinho o case 2, utilizo até o mesmo sistema de INT, mas troque o que é feito dentro do if
                    pBuffer = realloc ( pBuffer, TAM_PESSOA + sizeof(int) + (  ( 2 * sizeof ( int )  + TAM_PESSOA * ( QNT_PESSOAS ) ) ) );
                    printf ( "Digite o nome da pessoa: " );
                    scanf ( "%9s", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) );

                    for ( INT_REMOVER = 0; INT_REMOVER < QNT_PESSOAS; INT_REMOVER++ ) {
                        if ( strcmp ( ( (char *)pBuffer + ( 2 * sizeof ( int ) ) + ( TAM_PESSOA * INT_REMOVER ) ) , ( (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( QNT_PESSOAS ) ) ) ) == 0 ){
                            printf ( "Nome: %s\n", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( INT_REMOVER ) ) );
                            printf ( "Idade: %d\n", *(int *)( (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( INT_REMOVER ) ) + ( sizeof ( char ) * 10 ) ) );
                            printf ( "Email: %s\n", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( INT_REMOVER ) ) + ( ( sizeof ( char ) * 10 ) + sizeof ( int ) ) );
                            break;
                        }
                    }
                    if ( INT_REMOVER == QNT_PESSOAS ){
                            printf( "Pessoa não encontrada!\n" );
                    }

                    printf( "\n");

                    pBuffer = realloc( pBuffer, ( ( 2 * sizeof ( int ) ) + ( TAM_PESSOA * QNT_PESSOAS ) ) );
                }

                break;
            
            case 4:

                printf( "\n");

                if ( QNT_PESSOAS == 0 ) {
                    printf ( "Não há pessoas cadastradas.\n" );
                    break;
                }
                else{

                    pBuffer = realloc ( pBuffer, sizeof(int) + (  ( 2 * sizeof ( int )  + TAM_PESSOA * ( QNT_PESSOAS ) ) ) );
                    for ( INT_LISTA = 0; INT_LISTA < QNT_PESSOAS; INT_LISTA++ ){
                        printf ( "Nome: %s\n", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( INT_LISTA ) ) );
                        printf ( "Idade: %d\n", *(int *)( (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( INT_LISTA ) ) + ( sizeof ( char ) * 10 ) ) );
                        printf ( "Email: %s\n", (char *)pBuffer + ( 2 * sizeof ( int ) + TAM_PESSOA * ( INT_LISTA ) ) + ( ( sizeof ( char ) * 10 ) + sizeof ( int ) ) );
                        printf( "\n");
                    }
                    printf( "Impressão concluída com sucesso!\n");

                }
                break;
            
            case 5:

                printf( "\n");

                printf ("Saida concluída com sucesso.\n");

                break;
            
            default:

                printf ( "Opção inválida.\n" );

        }

    }while( *(int *)pBuffer != 5 );

    free(pBuffer);
    return 0;
}