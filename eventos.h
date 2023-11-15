struct Evento{
    char nome[50];
    char descricao[200];
    unsigned short int dia;
    unsigned short int mes;
    unsigned short int ano;
    char hora[10];
};

void adicionarEvento(struct Evento eventos[], unsigned int *numEventos){

short int adicionar = 1;

    struct Evento novoEvento;

    // Limpar o buffer de entrada antes de cada leitura
    while (getchar() != '\n');

    //Adicionando as informacoes do evento

    printf("\nNome do evento: ");
    fgets(novoEvento.nome, sizeof(novoEvento.nome), stdin);
    novoEvento.nome[strcspn(novoEvento.nome, "\n")] = '\0'; // Remova a quebra de linha, se houver

    printf("Descricao do evento: ");
    fgets(novoEvento.descricao, sizeof(novoEvento.descricao), stdin);
    novoEvento.descricao[strcspn(novoEvento.descricao, "\n")] = '\0'; // Remova a quebra de linha, se houver

    printf("Dia do evento: ");
    scanf("%hu", &novoEvento.dia);

    printf("Mes do evento: ");
    scanf("%hu", &novoEvento.mes);

    printf("Ano do evento: ");
    scanf("%hu", &novoEvento.ano);

    // Consumir o caractere de nova linha após a leitura da data
    getchar();

    printf("Hora do evento: ");
    fgets(novoEvento.hora, sizeof(novoEvento.hora), stdin);
    novoEvento.hora[strcspn(novoEvento.hora, "\n")] = '\0'; // Remova a quebra de linha, se houver

    //Verificando se ja existem eventos no mesmo dia

    unsigned short int eventosNoMesmoDia = 0; //Declarando variavel

    // Laco for para verificar qtd de eventos no dia, se houver.
    if(*numEventos > 0){
    for (unsigned short int i = 0; i < *numEventos; i++) {
        if (eventos[i].dia == novoEvento.dia && eventos[i].mes == novoEvento.mes && eventos[i].ano == novoEvento.ano){
            eventosNoMesmoDia = 1;
            break;
        }
    }}


    // Se existir eventos no dia, mostrará quais sao os eventos.
    if (eventosNoMesmoDia) {
        printf("\nJa existem eventos no mesmo dia:\n");
        for (unsigned short int i = 0; i < *numEventos; i++) {
            if (eventos[i].dia == novoEvento.dia && eventos[i].mes == novoEvento.mes && novoEvento.ano)
                printf("%s as %s\n", eventos[i].nome, eventos[i].hora);
        }
        //Questiona se deseja adicionar o evento mesmo assim
        printf("\nDeseja adicionar mesmo assim? (1 para Sim, 0 para Nao)\n>>> ");
        scanf("%hi", &adicionar);
    }

    // Se sim, adiciona o evento.
    if (adicionar){
        eventos[*numEventos] = novoEvento;
        (*numEventos)++;
        printf("Evento adicionado com sucesso!\n");
    }
    // Se nao, nao adiciona.
    else {
        printf("Evento nao adicionado!\n");
    }

}

void localizarEventos(struct Evento eventos[], unsigned int numEventos){

    unsigned short int dia, mes, ano;

    printf("\nInforme a data que voce deseja ver os eventos:\nDD MM AAAA\n");
    scanf("%hu %hu %hu", &dia, &mes, &ano);

    short int encontrouEventos = 0;
    for(short int i = 0;i < numEventos; i++){

        if (eventos[i].dia == dia && eventos[i].mes == mes && eventos[i].ano == ano){
            printf("\nID %hi: %s as %s.\n%s.\n", i+1, eventos[i].nome, eventos[i].hora, eventos[i].descricao);
            encontrouEventos = 1;
        }
    if (!encontrouEventos){
        printf("Sem eventos encontrados!");
    }

    }

}

void editaEventos(struct Evento eventos[], unsigned int numEventos){

    unsigned short int escolhaID, escolhaEdicao;

    localizarEventos(eventos, numEventos);

    printf("Informe o ID do evento que voce deseja editar: ");
    scanf("%hu", &escolhaID);

    printf("O que voce deseja editar?\n\n1 - Nome\n2 - Descricao\n3 - Hora\n4 - Cancelar\n\n>>> ");
    scanf("%hu", &escolhaEdicao);

    // Consumir o caractere de nova linha após a leitura da escolha
    getchar();

    switch(escolhaEdicao){

        case 1:
        printf("Novo nome: ");
        fgets(eventos[escolhaID - 1].nome, sizeof(eventos[escolhaID - 1].nome), stdin);
        eventos[escolhaID - 1].nome[strcspn(eventos[escolhaID - 1].nome, "\n")] = '\0'; // Remova a quebra de linha, se houver
        printf("Nome alterado com sucesso!\n");
        break;

        case 2:
        printf("Nova descricao: ");
        fgets(eventos[escolhaID - 1].descricao, sizeof(eventos[escolhaID - 1].descricao), stdin);
        eventos[escolhaID - 1].descricao[strcspn(eventos[escolhaID - 1].descricao, "\n")] = '\0'; // Remova a quebra de linha, se houver
        printf("Descricao alterada com sucesso!\n");
        break;

        case 3:
        printf("Novo horario: ");
        fgets(eventos[escolhaID - 1].hora, sizeof(eventos[escolhaID - 1].hora), stdin);
        eventos[escolhaID - 1].hora[strcspn(eventos[escolhaID - 1].hora, "\n")] = '\0'; // Remova a quebra de linha, se houver
        printf("Horario alterado com sucesso!\n");
        break;

        case 4: printf("Acao cancelada!\n");
        break;

        default: printf("Escolha inválida!");
        break;}

}

void excluiEvento(struct Evento eventos[], unsigned int *numEventos) {
    unsigned short int escolhaID;

    localizarEventos(eventos, *numEventos);

    printf("Informe o ID do evento que voce deseja excluir: ");
    scanf("%hu", &escolhaID);

    if (escolhaID >= 1 && escolhaID <= *numEventos) {
        // Desloca os eventos para preencher a posição do evento excluído
        for (unsigned int i = escolhaID - 1; i < *numEventos - 1; i++) {
            eventos[i] = eventos[i + 1];
        }

        (*numEventos)--;
        printf("Evento excluido com sucesso!\n");
    } else {
        printf("ID de evento invalido!\n");
    }
}
