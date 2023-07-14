#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

//printf("A locale utilizada � %s \n",setlocale(LC_ALL,"")); para localizar o setlocale

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//In�cio cria��o de vari�veis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string

	printf("Digite o CPF que ser� cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e "w" significa escrever
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"CPF: ");
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome que ser� cadastrado: "); //colentando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string

	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"\nNome: ");
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo

	printf("Digite o sobrenome que ser� cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"\nSobrenome: ");
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo que ser� cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e "a" significa atualizar
	fprintf(file,"\nCargo: ");
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis/string

	printf("Digite o CPF que ser� consultado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e "r" significa ler
	
	printf("\nInforma��es localizadas para este CPF:\n");
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel localizar o CPF!\n\n");
		printf("Deseja cadastrar este novo CPF?\n\n");
		
		//vari�veis
		int opcao=0;
		int laco=1;
	
		//in�cio das op��es
		for(laco=1;laco=1;)
		{
			printf("\t1 - Sim\n");
			printf("\t2 - N�o\n");
			printf("\nOp��o: ");
	
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				main();
				break;
			}	
			//fim das op��es
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
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF que gostaria de deletar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		printf("\nTem certeza que deseja deletar o usu�rio?\n");
		
		int opcao=0;
		int laco=1;
	
		for(laco=1;laco=1;)
		{
			printf("\t1 - Sim\n");
			printf("\t2 - N�o\n");
			printf("\nOp��o: ");
	
			scanf("%d", &opcao); //armazenando a escolha
			system("cls"); //limpar tela
			
			if(opcao==1)
			{
				fclose(file);
				printf("Usu�rio deletado com sucesso!\n");
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				main();
				break;
			}
		}
	}
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	
	printf("### Cart�rio do Jo�o Pedro ###\n\n"); //in�cio do menu
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		for(laco=1;laco=1;)
		{
			system("cls"); //limpar a tela
	
			setlocale(LC_ALL, "Portuguese_Brazil.1252"); //definindo a linguagem
			printf("### Cart�rio do Jo�o Pedro ###\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
	
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha
	
			system("cls"); //limpar a tela
		
			switch(opcao) //inicio op��es
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;	
			} //fim op��es
		}
	}
	
	else
		printf("\nSenha incorreta!\n\n");
		system("pause");
		system("cls");
		main();
}
