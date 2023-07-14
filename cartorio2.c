#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

//printf("A locale utilizada é %s \n",setlocale(LC_ALL,"")); para localizar o setlocale

int registro() //Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//Início criação de variáveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string

	printf("Digite o CPF que será cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" significa escrever
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"CPF: ");
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome que será cadastrado: "); //colentando informação do usuário
	scanf("%s", nome); //%s refere-se a string

	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"\nNome: ");
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo

	printf("Digite o sobrenome que será cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"\nSobrenome: ");
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo que será cadastrado: "); //coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"\nCargo: ");
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//Início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Final da criação de variáveis/string

	printf("Digite o CPF que será consultado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e "r" significa ler
	
	printf("\nInformações localizadas para este CPF:\n");
	
	if(file == NULL)
	{
		printf("\nNão foi possível localizar o CPF!\n\n");
		printf("Deseja cadastrar este novo CPF?\n\n");
		
		//variáveis
		int opcao=0;
		int laco=1;
	
		//início das opções
		for(laco=1;laco=1;)
		{
			printf("\t1 - Sim\n");
			printf("\t2 - Não\n");
			printf("\nOpção: ");
	
			scanf("%d", &opcao);
			system("cls");
			
			if(opcao==1)
			{
				fclose(file);
				registro();
				main();
				break;
			}
			if(opcao==2)
			{
				switch(opcao)
				{
				case 1:
				consulta();
				break;
				
				case 2:
				printf("Voltando ao menu!\n");
				system("pause");
				return 0;
				main();
				break;
				}
			}
			if(opcao>=3 || opcao<=0)
			{
				fclose(file);
				printf("Essa opção não está disponível!\n");
				system("pause");
				main();
				break;
			}	
			//fim das opções
		}
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n"); //pular linha
	system("pause");
	fclose(file); // fecha o arquivo
}

int deletar()
{
	//Início criação de variáveis/string
	char cpf[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF que gostaria de deletar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		printf("\nTem certeza que deseja deletar o usuário?\n");
		
		int opcao=0;
		int laco=1;
	
		for(laco=1;laco=1;)
		{
			printf("\t1 - Sim\n");
			printf("\t2 - Não\n");
			printf("\nOpção: ");
	
			scanf("%d", &opcao); //armazenando a escolha
			system("cls"); //limpar tela
			
			if(opcao==1)
			{
				fclose(file);
				printf("Usuário deletado com sucesso!\n");
				system("pause");
				remove(cpf);
				break;
			}
			if(opcao==2)
			{
				fclose(file);
				printf("Voltando ao menu!\n");
				system("pause");
				main();
				break;
			}
			if(opcao>=3 || opcao<=0)
			{
				fclose(file);
				printf("Essa opção não está disponível!\n");
				system("pause");
				main();
				break;
			}
		}
	}
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	
	printf("### Cartório do João Pedro ###\n\n"); //início do menu
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		for(laco=1;laco=1;)
		{
			system("cls"); //limpar a tela
	
			setlocale(LC_ALL, "Portuguese_Brazil.1252"); //definindo a linguagem
			printf("### Cartório do João Pedro ###\n\n"); //início do menu
			printf("Escolha a opção desejada do menu:\n\n");
	
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha
	
			system("cls"); //limpar a tela
		
			switch(opcao) //inicio opções
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;	
			} //fim opções
		}
	}
	
	else
		printf("\nSenha incorreta!\n\n");
		system("pause");
		system("cls");
		main();
}
