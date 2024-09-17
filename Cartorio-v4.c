#include <stdio.h>     //biblioteca de comunicação com o usuário
#include <stdlib.h>    // biblioteca de alocação de espaço em memória
#include <locale.h>    //biblioteca de alocação de texto por região
#include <string.h>    //biblioteca responsável por cuidar das string

int registro()                   //função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio de criação da variáveis / string (string é um conjunto de variáveis sempre vai estar em [ ] )
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuáruio
	scanf("%s", cpf);           // %s --> reference a string, saval dentro de uma string, da variável cpf
	
	strcpy(arquivo, cpf);       //responsável por copiar os valores das string
	
	FILE *file;                  // FILE --> acessa o arquivo; *file cria um arquivo
	file = fopen(arquivo, "w");  //fopen --> vai abrir o arquivo e cria um arquivo novo "w"
	fprintf(file, cpf);          //salvando no arquivo a variável cpf
	fclose(file);                //fecha o arquivo
	
	file = fopen(arquivo, "a");     // abre o arquivo e "a" --> atualiza o arquivo
	fprintf(file, ",");             // salva essa "," para separar as informações dentro do arquivo
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
	file = fopen(cpf, "r");     // "r" --> é ler
	
	if(file == NULL)
	{
		printf("Não foi possível encontrar o CPF! \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)                     // while é um laço de repetição (enquanto); fgets --> vai buscar no arquivo
	{
		printf("\nEssas são as informações do CPF consultado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
		
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	

	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}

int main ()
{
	int opcao=0;                                                     //definindo as variáveis
	int repeticao=1;                                                //variável para fazer a repetição das opções
	
	for(repeticao=1;repeticao=1;)                                   // For (faz a repetição da execução); se colocar x=1; x=10; x++ -> esse ++ faz repitir 10x e depois encerra o programa.
	{
		
		system("cls");                                             //limpa as opções para o usuário
		
		setlocale(LC_ALL, "Portuguese");                           //definindo a linguagem
	
		printf("### Cartório do ANDRÉ TAVARES ###\n\n");           //inicio do menu  
		printf("Escolha a opção desejada do menu:\n\n");                 //  \n: pula linha
		printf("\t1 - Registrar nomes:\n");                             // \t: é responsável por dar espaço
		printf("\t2 - Consultar os nomes:\n");
		printf("\t3 - Deletar os nomes:\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");                                      //final do menu

		scanf("%d", &opcao);                                      //armazenando a escolha do usuário
	
		system("cls");                                            //deleta todas as mensagem anteriores
	 
	
		switch(opcao)                                            //inicio da seleção do menu. Fizemos com o "if", mas mudamos para "switch"
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
			printf("Essa opção não está disponível!\n");            //no inicio foi usado if(opcao>=4 || opcao<=0), o caracter | chama-se pipe. Usado como operador lógico (ou)
			system("pause");
			break;
							
		}                                                          //fim da seleção do menu
		
	}
	
}
