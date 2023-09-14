#include <stdio.h> 	//biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocação de texto por regiao
#include <string.h>	//biblioteca responsavel por cuidar das strings

int registro() // Função responsavel por cadastrar os usuarios no sistema
{
	// inicio ciração de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// inicio ciração de variaveis/string

	printf("Digite o CPF a ser cadastrado: "); // coletando informção do usuario
	scanf("%s", cpf); // %s refere-se a strings
	
	strcpy(arquivo,cpf); 	// Responsavel por copiar os valores das strings
	
	FILE *file;						// criar o arquivo 
	file = fopen(arquivo, "w"); 	// cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); 			// salvo o valor da variavel
	fclose(file); 					// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s,",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}
int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); 		// definindo a linguagem

	char cpf[40];
	char conteudo [200];


	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("Não foi possivel abrir, arquivo não foi localizado!. \n");
	}
	
	while(fgets(conteudo,200, file) != NULL )
	{
	printf("\nEssas são as informações do usuáiro: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
	
}
int deletar()
{
	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	system("pause");
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("Nenhum CPF foi identificado no banco de dados!.\n");
	printf("Pressione Enter para voltar ao menu prinicpal\n");
	system("pause");
	}

}



int main()
{	
 	int opcao=0;  // Definindo variaveis 
	int laco=1;
	
 
 	for(laco==1;laco==1;)
	{
	
		system("cls"); // limpar a tela
	
    	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
    
		printf("\t Cartório do Mateus \t\n\n"); // inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Qual sua opção: ");    // final do menu

		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls");
		
		
		switch(opcao)
	{
		case 1:
			registro(); // chamada de funções
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
		
		
		default: // SE NÃO FOR SELECIONADO O NUMERO DO "CASO", "DEFAULT" SERÁ ACIONADO  
			printf("Pressione Enter para voltar ao menu prinicpal\n");
			system("pause");
			break;			
 		}
	}
}
	


