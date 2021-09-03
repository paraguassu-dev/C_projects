#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 200

//Definição da struct:

typedef struct
{
	int codigo;  
	int status;
	int ano;
	int dddTel;
	int tel;
	char cliente[100];
	char titulo[100]; 
	char descricao[100]; 
	char gerente[100];	
	float valorTotal;	
}proj;

//Declaração e inicialização das variáveis globais:

proj cad[MAX];
int posicao = 0;

void initArray()
{
	int i;
	
	for (i = 0; i < MAX; i++)
		{
			cad[i].codigo = 0;
			cad[i].status = 0;
			cad[i].ano = 0;
			cad[i].dddTel = 0;
			cad[i].tel = 0;
			cad[i].valorTotal = 0;
			strcpy(cad[i].titulo, "\0");
			strcpy(cad[i].descricao, "\0");
			strcpy(cad[i].gerente, "\0");
			strcpy(cad[i].cliente, "\0");
		}
}

//Declaração dos protótipos das funções:

void cadastro();
void menuRelat();
void listarTodos();
void buscaStatus();
void buscaCodigo();

//Início da função main:

int main()
{	
	int option;
	
	do
	{
		system("cls");
		printf("\t\t\t\t+=====================================================+\n");
		printf("\t\t\t\t|\t       *PARAGUA TECH ENTERPRISE*\t      |\n");
		printf("\t\t\t\t|\t\t\t\t\t\t      |\n");
		printf("\t\t\t\t|\tLucas Paraguassu \t RA: 21147172-5\t      |\n");
		printf("\t\t\t\t+=====================================================+\n");
		printf("\t\t\t\t|\t\t      ***MENU***\t\t      |\n");
		printf("\t\t\t\t+=====================================================+\n");
		printf("\n");
		printf("(1) - Cadastrar projeto;\n");
		printf("(2) - Acessar o menu de relatorios;\n");
		printf("(0) - Encerrar programa.\n");
		printf("\n");
		printf("Digite o numero corresponde a opcao desejada: ");
		fflush(stdin);
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				if (posicao < MAX - 1)
				{
					cadastro();
				}
				else
				printf("\n*ATENCAO*: Nao ha espaco em memoria disponivel para novo cadastro!\n\n");
				printf("Pressione qualquer tecla para continuar...");
				getch();
				main();
				break;
			case 2:
				menuRelat();
				break;
			case 0:
				printf("\n");
				printf("***Obrigado por utilizar os sevicos da PARAGUA TECH ENTERPRISE!***\n");
				printf("\n");
				printf("Encerrando programa, pressione qualquer tecla para continuar...");
				getch();
				printf("\n");
				exit(0);
				break;
			default:
				printf("\nOpcao invalida, tente novamente...");
				getch();
				break;
		}
	}
	while (option != 0);
	
	return 0;
}

//Declaração da função CADASTRO:

void cadastro()
{	
	bool repeat = true;
	char resp;
	
	while (repeat == true)
	{	
		system("cls");
		cad[posicao].codigo = posicao + 1;
		printf("\t\t\t+=================================================================+\n");
		printf("\t\t\t|\t\t   ***CADASTRO DE PROJETOS***\t\t\t  |\n");
		printf("\t\t\t+=================================================================+\n\n");
		printf("CODIGO VINCULADO AO PROJETO: %d\n\n", cad[posicao].codigo);
		printf("Insira o titulo do projeto: ");
		fflush(stdin);
		gets(cad[posicao].titulo);
		printf("\n");
		printf("Insira a descricao do projeto: ");
		fflush(stdin);
		gets(cad[posicao].descricao);
		printf("\n");
		printf("Insira o nome do gerente responsavel pelo projeto: ");
		fflush(stdin);
		gets(cad[posicao].gerente);
		printf("\n");
		printf("Insira o ano do projeto: ");
		fflush(stdin);
		scanf("%d", &cad[posicao].ano);
		printf("\n");
		
		do
		{
			printf("Insira o numero correspondente ao status do projeto: (1) - A fazer / (2) - Fazendo / (3) - Concluido: ");
			fflush(stdin);
			scanf("%d", &cad[posicao].status);
			
			if (cad[posicao].status < 1 || cad[posicao].status > 3)
			{
				printf("\n*ERRO*: Valor inserido para \"STATUS\" nao suportado, tente novamente...\n\n");
				
			}
		}
		while (cad[posicao].status < 1 || cad[posicao].status > 3);
			
		printf("\n");	
		printf("Insira o orcamento total do projeto: R$ ");
		fflush(stdin);
		scanf("%f", &cad[posicao].valorTotal);
		printf("\n");
		printf("Insira o nome do cliente: ");
		fflush(stdin);
		gets(cad[posicao].cliente);
		printf("\n");
		printf("Telefone para contato do cliente (DDD+TEL):\n\n");
		printf("Insira o DDD: ");
		fflush(stdin);
		scanf("%d", &cad[posicao].dddTel);
		printf("Insira o telefone: ");
		fflush(stdin);
		scanf("%d", &cad[posicao].tel);
		printf("\n");
		printf("===================================================================\n\n");
		printf("*PROJETO CADASTRADO COM SUCESSO!*\n\n");
		printf("===================================================================\n\n");
		
		posicao++;
		
		if (posicao <= MAX - 1)
		{		
			do
			{
				printf("Deseja cadastrar novo projeto? (s/n): ");
				fflush(stdin);
				scanf("%c", &resp);
				
				if (resp != 's' && resp != 'n')
				{
					printf("\nOpcao invalida, tente novamente...\n\n");
				}
				
				else if (resp == 'n')
				{
					printf("\nRetornando ao menu principal, pressione qualquer tecla para continuar...");
					repeat = false;
					getch();
					main();
				}
			}
			while (resp != 's' && resp != 'n');
		}
		else
		{
			printf("*ATENCAO*: Nao ha mais espaco em memoria disponivel para novo cadastro!\n\n");
			printf("Retornando ao menu principal, pressione qualquer tecla para continuar...");
			repeat = false;
			getch();
			main();
		}
	}
}

//Declaração da função MENURELAT:

void menuRelat()
{
	int option, i = 0;
	
	do
	{
		system("cls");
		printf("\t\t\t+=================================================================+\n");
		printf("\t\t\t|\t\t      ***MENU RELATORIO***\t\t\t  |\n");
		printf("\t\t\t+=================================================================+\n");
		printf("\n");
		printf("(1) - Listar todos os projetos;\n");
		printf("(2) - Buscar projetos por status;\n");
		printf("(3) - Buscar projeto por codigo;\n");
		printf("(0) - Retornar ao menu principal.\n");
		printf("\n");
		printf("Digite o numero corresponde a opcao desejada: ");
		fflush(stdin);
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				if(cad[i].codigo == 1)
				{
					listarTodos();
				}
				else
				{
					printf("\n=================================================================\n");
					printf("\nNao ha projetos cadastrados!\n");
					printf("\n=================================================================\n\n");
					printf("Pressione qualquer tecla para continuar...");
					getch();
				}
					break;
			case 2:
				if(cad[i].codigo == 1)
				{
					buscaStatus();
				}
				else
				{
					printf("\n=================================================================\n");
					printf("\nNao ha projetos cadastrados!\n");
					printf("\n=================================================================\n\n");
					printf("Pressione qualquer tecla para continuar...");
					getch();
				}
					break;
			case 3:
				if(cad[i].codigo == 1)
				{
					buscaCodigo();
				}
				else
				{
					printf("\n=================================================================\n");
					printf("\nNao ha projetos cadastrados!\n");
					printf("\n=================================================================\n\n");
					printf("Pressione qualquer tecla para continuar...");
					getch();
				}
					break;
						
			case 0:
				printf("\nRetornando ao menu principal, pressione qualquer tecla para continuar...");
				getch();
				main();
				break;
			default:
				printf("\nOpcao invalida, tente novamente...");
				getch();
				break;
		}
	}
	while (option != 0);
}

//Declaração da função LISTARTODOS:

void listarTodos()
{
	int i = 0;
	
	system("cls");
	printf("\t\t\t+=================================================================+\n");
	printf("\t\t\t|\t\t ***TODOS OS PROJETOS CADASTRADOS***\t\t  |\n");
	printf("\t\t\t+=================================================================+\n");
	printf("\n");
	
	for (i = 0; i <= posicao-1; i++)
	{
		printf("\n=================================================================\n\n");
		printf("Codigo do projeto: %d;\n\n", cad[i].codigo);
		printf("Titulo do projeto: %s;\n\n", cad[i].titulo);
		printf("Descricao do projeto: %s;\n\n", cad[i].descricao);
		printf("Gerente responsavel pelo projeto: %s;\n\n", cad[i].gerente);
		printf("Ano do projeto: %d;\n\n", cad[i].ano);
		printf("Status do projeto: %d;\n\n", cad[i].status);
		printf("Orcamento total do projeto: R$ %.2f;\n\n", cad[i].valorTotal);
		printf("Telefone do cliente: (%d) %d.\n\n", cad[i].dddTel, cad[i].tel);
	}
	
	printf("=================================================================\n\n");
	printf("Retornando ao menu de relatorios, pressione qualquer tecla para continuar...");
	getch();
	
}

//Declaração da função BUSCASTATUS:

void buscaStatus()
{
	int i = 0, busca = 0, option;
	bool acha = false;
	char statusName[15];
	
	system("cls");
	printf("\t\t\t+=================================================================+\n");
	printf("\t\t\t|\t\t     ***MENU LISTAR POR STATUS***\t\t  |\n");
	printf("\t\t\t+=================================================================+\n");
	printf("\n");
	printf("Digite (1) para listar todos os projetos \"A fazer\";\n");
	printf("Digite (2) para listar todos os projetos \"Fazendo\";\n");
	printf("Digite (3) para listar todos os projetos \"Concluido\";\n\n");
	
	do
	{
		printf("Insira a opcao desejada: ");
		fflush(stdin);
		scanf("%d", &busca);
		
		if (busca < 1 || busca > 3)
		{
			printf("\n*ERRO*: Valor inserido para \"STATUS\" nao suportado, tente novamente...\n\n");
			
		}
	}
	while (busca < 1 || busca > 3);

	if (busca == 1)
	{
		strcpy(statusName, "A FAZER");
	}	
	else if (busca == 2)
	{
		strcpy(statusName, "FAZENDO");
	}
	else if (busca == 3)
	{
		strcpy(statusName, "CONCLUIDO");
	}
	
	system("cls");
	printf("\t\t\t+=================================================================+\n");
	printf("\t\t\t|\t\t***PROJETOS COM O STATUS: %s***\t\t  |\n", statusName);
	printf("\t\t\t+=================================================================+\n");
	printf("\n");
	
	for (i = 0; i <= posicao-1; i++)
	{	
		if (cad[i].status == busca)
		{
			printf("=================================================================\n\n");
			printf("Codigo do projeto: %d;\n\n", cad[i].codigo);
			printf("Titulo do projeto: %s;\n\n", cad[i].titulo);
			printf("Descricao do projeto: %s;\n\n", cad[i].descricao);
			printf("Gerente responsavel pelo projeto: %s;\n\n", cad[i].gerente);
			printf("Ano do projeto: %d;\n\n", cad[i].ano);
			printf("Status do projeto: %d;\n\n", cad[i].status);
			printf("Orcamento total do projeto: R$ %.2f;\n\n", cad[i].valorTotal);
			printf("Telefone do cliente: (%d) %d.\n\n", cad[i].dddTel, cad[i].tel);
			acha = true;
		}		
	}
	
	if (acha == false)
	{
		printf("\n===================================================================\n\n");
		printf("Nao ha projetos com o status %d: %s.\n\n", busca, statusName);
	}
	
	do
	{
		printf("===================================================================\n\n");
		printf("Digite (1) para retornar ao menu de busca por status;\n");
		printf("Digite (2) para retornar ao menu de relatorios;\n");
		printf("Digite (0) para retornar ao menu principal;\n\n");
		printf("Insira a opcao desejada: "); 
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				buscaStatus();
				break;
			case 2:
				menuRelat();
				break;
			case 0:
				main();
				break;
			default:
				printf("\nOpcao invalida, tente novamente...\n");
				getch();
				break;			
		}
	}
	while (option < 0 || option > 2);
}

//Declaração da função BUSCACODIGO:

void buscaCodigo()
{
	int i = 0, busca = 0, option;
	bool acha = false;
	
	system("cls");
	printf("\t\t\t+=================================================================+\n");
	printf("\t\t\t|\t\t***BUSCA DE PROJETO POR CODIGO***\t\t  |\n");
	printf("\t\t\t+=================================================================+\n");
	printf("\n");
	
	do
	{
		printf("Insira o codigo do projeto que deseja buscar: ");
		scanf("%d", &busca);
		
		if (busca < 1)
		{
			printf("\n*ERRO*: Valor inserido para \"CODIGO\" nao suportado.\n");
			printf("\"CODIGO\" aceita somente valores de 1 em diante. Tente novamente...\n\n");
		}	
	}
	while (busca < 1);
	
	for (i = 0; i <= posicao-1; i++)
	{
		if (cad[i].codigo == busca)
		{
			printf("\n=================================================================\n\n");
			printf("Codigo do projeto: %d;\n\n", cad[i].codigo);
			printf("Titulo do projeto: %s;\n\n", cad[i].titulo);
			printf("Descricao do projeto: %s;\n\n", cad[i].descricao);
			printf("Gerente responsavel pelo projeto: %s;\n\n", cad[i].gerente);
			printf("Ano do projeto: %d;\n\n", cad[i].ano);
			printf("Status do projeto: %d;\n\n", cad[i].status);
			printf("Orcamento total do projeto: R$ %.2f;\n\n", cad[i].valorTotal);
			printf("Telefone do cliente: (%d) %d.\n\n", cad[i].dddTel, cad[i].tel);
			acha = true;
		}	
	}
	
	if (acha == false)
	{
		printf("\n===================================================================\n\n");
		printf("Nao ha projetos com o codigo %d!\n\n", busca);
	}
	
	do
	{
		printf("===================================================================\n\n");
		printf("Digite (1) para buscar novo projeto por codigo;\n");
		printf("Digite (2) para retornar ao menu de relatorios;\n");
		printf("Digite (0) para retornar ao menu principal;\n\n");
		printf("Insira a opcao desejada: "); 
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				buscaCodigo();
				break;
			case 2:
				menuRelat();
				break;
			case 0:
				main();
				break;
			default:
				printf("\nOpcao invalida, tente novamente...\n");
				getch();
				break;			
		}
	}
	while (option < 0 || option > 2);
}
