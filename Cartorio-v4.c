#include <stdio.h>     //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>    // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>    //biblioteca de aloca��o de texto por regi�o
#include <string.h>    //biblioteca respons�vel por cuidar das string

int registro()                   //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio de cria��o da vari�veis / string (string � um conjunto de vari�veis sempre vai estar em [ ] )
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�ruio
	scanf("%s", cpf);           // %s --> reference a string, saval dentro de uma string, da vari�vel cpf
	
	strcpy(arquivo, cpf);       //respons�vel por copiar os valores das string
	
	FILE *file;                  // FILE --> acessa o arquivo; *file cria um arquivo
	file = fopen(arquivo, "w");  //fopen --> vai abrir o arquivo e cria um arquivo novo "w"
	fprintf(file, cpf);          //salvando no arquivo a vari�vel cpf
	fclose(file);                //fecha o arquivo
	
	file = fopen(arquivo, "a");     // abre o arquivo e "a" --> atualiza o arquivo
	fprintf(file, ",");             // salva essa "," para separar as informa��es dentro do arquivo
	fclose(file);                   // fecha oarquivo
	
	printf("Digite o nome a ser cadastrado: ");     
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a se consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");     // "r" --> � ler
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel encontrar o CPF! \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)                     // while � um la�o de repeti��o (enquanto); fgets --> vai buscar no arquivo
	{
		printf("\nEssas s�o as informa��es do CPF consultado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	

	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}

int main ()
{
	int opcao=0;                                                     //definindo as vari�veis
	int repeticao=1;                                                //vari�vel para fazer a repeti��o das op��es
	
	for(repeticao=1;repeticao=1;)                                   // For (faz a repeti��o da execu��o); se colocar x=1; x=10; x++ -> esse ++ faz repitir 10x e depois encerra o programa.
	{
		
		system("cls");                                             //limpa as op��es para o usu�rio
		
		setlocale(LC_ALL, "Portuguese");                           //definindo a linguagem
	
		printf("### Cart�rio do ANDR� TAVARES ###\n\n");           //inicio do menu  
		printf("Escolha a op��o desejada do menu:\n\n");                 //  \n: pula linha
		printf("\t1 - Registrar nomes:\n");                             // \t: � respons�vel por dar espa�o
		printf("\t2 - Consultar os nomes:\n");
		printf("\t3 - Deletar os nomes:\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");                                      //final do menu

		scanf("%d", &opcao);                                      //armazenando a escolha do usu�rio
	
		system("cls");                                            //deleta todas as mensagem anteriores
	 
	
		switch(opcao)                                            //inicio da sele��o do menu. Fizemos com o "if", mas mudamos para "switch"
		{
			
			case 1:
			registro();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");            //no inicio foi usado if(opcao>=4 || opcao<=0), o caracter | chama-se pipe. Usado como operador l�gico (ou)
			system("pause");
			break;
							
		}                                                          //fim da sele��o do menu
		
	}
	
}
