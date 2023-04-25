#include <stdio.h> // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das strings 

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema 
{ 
    // in�cio cria��o de vari�veis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40]; 
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio 
    scanf("%s", cpf); // %s Refere-se as string 
    
    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings 
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever 
    fprintf(file, cpf); //salva o valor da vari�vel 
    fclose(file); // fecha arquivo 
    
    file = fopen(arquivo, "a"); 
    fprintf(file, ","); // V�rgula para separar as informa��es do usu�rio
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: "); // Coletando informa��o do usu�rio 
    scanf("%s", nome); // Salvar a string 
    
    file = fopen(arquivo, "a"); // cria o arquivo 
    fprintf(file, nome); //salva o valor da vari�vel 
    fclose(file); //fecha o arquivo 
    
    file = fopen(arquivo, "a"); 
    fprintf(file, ","); // V�rgula para separar as informa��es do usu�rio
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //Coletanto informa��o do usu�rio 
    scanf("%s", sobrenome); //Salvar a string 
    
    file = fopen(arquivo, "a"); // cria o arquivo 
    fprintf(file, sobrenome); //salva o valor da vari�vel 
    fclose(file); //fecha o arquivo 
    
    file = fopen(arquivo, "a"); 
    fprintf(file, ","); // v�rgula para separar as informa��es do usu�rio 
    fclose(file); 
    
    printf("Digite o cargo a ser cadastrado: "); //Coletando inform��o do usu�rio 
    scanf("%s", cargo); //Salvar a string 
    
    file = fopen(arquivo, "a"); // cria o arquivo 
    fprintf(file, cargo); //salva o valor da vari�vel 
    fclose(file); // fecha o arquivo 
    
    system("pause"); // pausar tela 
}

int consulta() 
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); 
	scanf("%s", cpf); 
	
	FILE *file; 
	file = fopen(cpf,"r"); 
	
	if(file == NULL) 
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	} 
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); 
		printf("\n\n"); 
	}
	
	system("pause"); 
	fclose(file);
}

int deletar() 
{
    char cpf[40]; 
    
	printf("Digite o CPF do usu�rio a ser deletado: "); 
	scanf("%s", cpf); 
	
	remove(cpf); 
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL); 
	{ 
	   printf("O usu�rio n�o se encontra no sistema!.\n"); 
	   system("pause"); 
	}
	
	
	
	
    
}



int main() 
{

	int opcao=0; // Definindo vari�veis 
	int x=1; 
    
	for(x=1;x=1;) 
   {    
     
	 system("cls"); 
	 
	 setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	 printf ("### Cart�rio da EBAC ###\n\n"); //inicio do menu 
	 printf ("Escolha a op��o desejada do menu: \n\n");
	 printf ("\t1 - Registrar nomes\n"); 
	 printf ("\t2 - Consultar nomes\n"); 
	 printf ("\t3 - Deletar nomes\n\n"); 
	 printf("\t4 - Sair do sistema\n\n");
	 printf ("Op��o:  "); // fim do menu 
	
	 scanf("%d", &opcao); //armazenamento da escolha do usu�rio 

     system("cls");	// respons�vel por limpar a tela 
	
      switch(opcao) // in�cio da sele��o do menu 
      {
      	case 1: 
      	registro(); //chamada de fun��es 
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
		//fim da sele��o 
	  }	
	  
	}

}

