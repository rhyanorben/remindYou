#include <stdio.h>
#include "eventos.h"

int main()
{
    //Declaração de Variaveis

    short int escolhaMenu = 0;
    unsigned int numEventos = 0;
    struct Evento eventos[100];

    //Menu inicial do programa

    printf("Remind You - Calendario de Eventos!\n");

    // Escolha de qual acao tomar

    do{
    printf("\n1 - Adicionar evento.\n2 - Editar evento.\n3 - Localizar.\n4 - Excluir evento\n5 - Sair.\n\n>>> "); // Menu de escolha principal
    scanf("%hi", &escolhaMenu);

    //Switch para verificar o que o usuário deseja fazer.

    switch(escolhaMenu){

    case 1: adicionarEvento(eventos, &numEventos);
        break;

    case 2: editaEventos(eventos, numEventos);
        break;

    case 3: localizarEventos(eventos, numEventos);
        break;

    case 4: excluiEvento(eventos, &numEventos);
        break;

    case 5: printf("Fim do programa!\n\n");
        break;
    default: printf("Opcao incorreta! Informe uma opcao valida!\n\n");
    }}while(escolhaMenu != 5); //Do-While para continuar no programa ate o usuario informar a opcao 4.

    return 0;
}
