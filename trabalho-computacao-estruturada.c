/*Nomes: joão Vitor de lima Gonçalves */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
int id[1000], nUsuarios;
float altura[1000];
char nome[1000][100], email[1000][100], sexo[1000][100], endereco[1000][1000];
bool vacina[1000];

int idBkp[1000], usuarioBkp;
float alturaBkp[1000];
char nomeBkP[1000][100], emailbkp[1000][100], sexobkp[1000][100], enderecobkp[1000][100];
bool vacinabkp[1000];



void validarNome(int numerX);      
void validarVacina(int numerX);      
void validarSexo(int numerX);     
void validarEmail(int numerX);  
void validarAltura(int numerX);      
void validarId(int numerX);    
void mostrarPerfil(int posicao); 
void validarEndereco(int numerX);  
   


void editaCadastro();            
void excluirCadastro();  

int buscarId();                  
int buscarEmail();  

void bkp();                   
void validarbkp();               
void recuperabkp();    

void imprimirTodos();            
bool voltar();      
             


int main()
{
    do
    {
        switch (menuopcao())
        {
        case 1:
            cadastro();
            break;
        case 2:
            editaCadastro();
            break;
        case 3:
            excluirCadastro();
            break;
        case 4:
            buscarId();
            break;
        case 5:
            buscarEmail();
            break;
        case 6:
            imprimirTodos();
            break;
        case 7:
            bkp();
            break;
        case 8:
            return 0;
        }
    } while (1);
}
bool voltar()
{
    char input;
    while (1)
    {
        printf("Deseja voltar?\n");
        printf("S / N: ");
        scanf("%c", &input);
        fflush(stdin);

        if (tolower(input) == 's')
        {
            return true;
        }
        else if (tolower(input) == 'n')
        {
            return false;
        }
    }
}

void validarId(int numerX)
{
    srand(time(NULL));
    id[numerX] = (rand() % (2000 - 1 + 1)) + 1;
    for (int x = 0; x < numerX; x++)
    {
        if (id[numerX] == id[x])
        {
            id[numerX] = (rand() % (2000 - 1 + 1)) + 1;
            x = 0;
        }
    }
}

void validarNome(int numerX)
{
    do
    {
        printf("\n_______________________________________________________________");
		printf("\n|                                                              |");
		printf("\n|                INFORME NOME COMPLETO                         |");
		printf("\n|______________________________________________________________|\n");
        fflush(stdin);
        fgets(nome[numerX], 100, stdin);
        fflush(stdin);
        if ((strlen(nome[numerX]) < 1))
        {
            printf("\n_______________________________________________________________");
			printf("\n|                             ERRO!                            |");
			printf("\n|    CERTIFIQUE-SE  QUE ESTÁ ESCRITO DE MANEIRA CORRETA        |");
			printf("\n|______________________________________________________________|\n");
        }
        

    } while (strlen(nome[numerX]) < 1);
}

void validarEmail(int numerX)
{
    do
    {
        printf("\n_______________________________________________________________");
		printf("\n|                  Informe o seu e-mail                        |");
		printf("\n|______________________________________________________________|\n");
        fgets(email[numerX], 100, stdin);
        fflush(stdin);
        if ((strchr(email[numerX], '@') == NULL))
        {
            printf("\n_______________________________________________________________");
			printf("\n|                             ERRO!                            |");
			printf("\n|    CERTIFIQUE-SE  QUE ESTÁ ESCRITO DE MANEIRA CORRETA        |");
			printf("\n|______________________________________________________________|\n");
        }
        
    } while (strchr(email[numerX], '@') == NULL);
}

void validarSexo(int numerX)
{
    int opcao = 1;
    do
    {
        printf("\n_______________________________________________________________");
		printf("\n|                      Informe sexo:                           |");
		printf("\n|                      * Masculino                             |");
		printf("\n|                      * Feminino                              |");
		printf("\n|                      * Nao-declarado                         |");
		printf("\n|______________________________________________________________|\n");
        fflush(stdin);
        fgets(sexo[numerX], 100, stdin);
        if (stricmp(sexo[numerX], "masculino\n") == 0 || stricmp(sexo[numerX], "feminino\n") == 0 || stricmp(sexo[numerX], "nao declarar\n") == 0)
        {
            return;
        }
      
        
        if (stricmp(sexo[numerX], "masculino\n") == 0 || stricmp(sexo[numerX], "feminino\n") == 0 || stricmp(sexo[numerX], "nao declarar\n") == 0)
		{
			printf("\n_______________________________________________________________");
			printf("\n|                           ERRO!                              |");
			printf("\n|     CERTIFIQUE-SE  QUE ESTÁ ESCRITO DE MANEIRA CORRETA       |");
			printf("\n|______________________________________________________________|\n");
		}
        
        
    } while (opcao == 1);
}

void validarEndereco(int numerX)
{
    do
    {
        printf("\n_______________________________________________________________");
		printf("\n|                                                              |");
		printf("\n|                INFORME ENDEREÇO DO USUARIO                   |");
		printf("\n|______________________________________________________________|\n");
        fgets(endereco[numerX], 100, stdin);
        fflush(stdin);
        if ((strlen(endereco[numerX]) < 1))
        {
          	printf("\n_______________________________________________________________");
			printf("\n|                             ERRO!                            |");
			printf("\n|    CERTIFIQUE-SE  QUE ESTÁ ESCRITO DE MANEIRA CORRETA        |");
			printf("\n|______________________________________________________________|\n");
        }
        
    } while (strlen(endereco[numerX]) < 1);
}

void validarAltura(int numerX)
{
    do
    {
        printf("\n_______________________________________________________________");
		printf("\n|                                                              |");
		printf("\n|                   INFORME ALTURA DO USUÁRIO                  |");
		printf("\n|______________________________________________________________|\n");
        scanf("%f", &altura[numerX]);
        fflush(stdin);
        if ((altura[numerX] < 1 || altura[numerX] > 2))
        {
		printf("\n_______________________________________________________________");
		printf("\n|                           ERRO!                              |");
		printf("\n|                       ALTURA INVÁLIDA                        |");
		printf("\n|______________________________________________________________|\n");
        }
        
    } while (altura[numerX] < 1 || altura[numerX] > 2);
}

void validarVacina(int numerX)
{
    int opcao;
    do
    {
		printf("\n_______________________________________________________________");
		printf("\n|                     usuario vacinado?                        |");
		printf("\n|                    digite [1]  para SIM                      |");
		printf("\n|                    digite [2]  para NAO                      |");
		printf("\n|______________________________________________________________|\n");
        scanf("%d", &opcao);
        fflush(stdin);
        vacina[numerX] = opcao;
        if ((opcao < 0 || opcao > 2))
        {
		printf("\n_______________________________________________________________");
		printf("\n|                           ERRO!                              |");
		printf("\n|______________________________________________________________|\n");
        }
        
    } while (opcao < 0 || opcao > 2);
}
int menuopcao()
{
    system("cls");

    int opcao = 0;
    	            printf("\n_______________________________________________________________");
	                printf("\n|                    1-validar usuario                         |");
	                printf("\n|                    2-editar                                  |");
	                printf("\n|                    3-Excluir                                 |");
	                printf("\n|                    4-Buscar id                               |");
                    printf("\n|                    5-buscar gmail                            |");
	                printf("\n|                    6-Imprimir                                |");
	                printf("\n|                    7-beckup                                  |");
	                printf("\n|                    8-sair                                    |");
	                printf("\n|______________________________________________________________|\n");

    do
    {
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 8);

    return opcao;
}
void imprimirTodos()
{
    for (int i = 0; i < nUsuarios; i++)
    {
        mostrarPerfil(i);
    }
}
void cadastro()
{
    int opcao;
    do
    {
        system("cls");
		printf("\n_______________________________________________________________");
		printf("\n|                         cadastro                             |");
		printf("\n|______________________________________________________________|\n");
        validarId(nUsuarios);
        validarNome(nUsuarios);
        validarEmail(nUsuarios);
        validarSexo(nUsuarios);
        validarEndereco(nUsuarios);
        validarAltura(nUsuarios);
        validarVacina(nUsuarios);
        mostrarPerfil(nUsuarios);
        nUsuarios++;
        do
        {
            system("cls");
            printf("Deseja cadastra outro usuario(1-sim 2-nao): ");
            scanf("%d", &opcao);
        } while (opcao < 1 || opcao > 2);
    } while (opcao == 1);
    return;
}

void editaCadastro()
{
    int opcao, xnumero;
    do
    {
        system("cls");		
        printf("\n_______________________________________________________________");
		printf("\n|                         Editar                               |");
		printf("\n|______________________________________________________________|\n");
        do
        {
            printf("buscar usuario:\n");
            printf("1-por ID\n");
            printf("2-por Email\n");
            printf("3-volta\n");
            printf("Digite uma opcao valida:");
            scanf("%d", &opcao);
        } while (opcao < 1 || opcao > 3);
        if (opcao == 1)
        {
            xnumero = buscarId();
        }
        else if (opcao == 2)
        {
            xnumero = buscarEmail();
        }
        else
        {
            return;
        }

        if (xnumero == -1)
        {
            return;
        }

        do
        {
            do
            {
                system("cls");
                   	printf("\n_______________________________________________________________");
	                printf("\n|                    1-nome                                    |");
	                printf("\n|                    2-Email                                   |");
	                printf("\n|                    3-sexo                                    |");
	                printf("\n|                    4-endereco                                |");
	                printf("\n|                    5-altura                                  |");
	                printf("\n|                    6-vacina                                  |");
	                printf("\n|                    7-voltar                                  |");
	                printf("\n|           Digite a opcao que deseja alterar:                 |");
	                printf("\n|______________________________________________________________|\n");
                scanf("%d", &opcao);
            } while (opcao < 1 || opcao > 7);
            if (opcao == 1)
            {
                validarNome(xnumero);
            }
            else if (opcao == 2)
            {
                validarEmail(xnumero);
            }
            else if (opcao == 3)
            {
                validarSexo(xnumero);
            }
            else if (opcao == 4)
            {
                validarEndereco(xnumero);
            }
            else if (opcao == 5)
            {
                validarAltura(xnumero);
            }
            else if (opcao == 6)
            {
                validarVacina(xnumero);
            }
            else
            {
                return;
            }
            do
            {
                system("cls");
                printf("deseja edita mais alguma informacao(1-sim 2-nao):");
                scanf("%d", &opcao);
            } while (opcao < 1 || opcao > 2);
        } while (opcao == 1);
        system("cls");
        mostrarPerfil(xnumero);
        do
        {
            system("cls");
            printf("deseja edita outro usuario(1-sim 2-nao):");
            scanf("%d", &opcao);
        } while (opcao < 1 || opcao > 2);
    } while (opcao == 1);
}

void excluirCadastro()
{
    int opcao, xnumero;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________");
		printf("\n|                         excluir                              |");
		printf("\n|______________________________________________________________|\n");

        do
        {
            printf("buscar usuario:\n");
            printf("1-por ID\n");
            printf("2-por Email\n");
            printf("3-volta\n");
            printf("Digite uma opcao valida: ");
            scanf("%d", &opcao);
            fflush(stdin);
        } while (opcao < 1 || opcao > 3);

        if (opcao == 1)
        {
            xnumero = buscarId();
        }

        else if (opcao == 2)
        {
            xnumero = buscarEmail();
        }

        else
        {
            return;
        }

        if (xnumero == -1)
        {
            return;
        }
        printf("Deletando usuario . . .");

        for (int i = xnumero; i < nUsuarios; i++)
        {
            id[i] = id[i + 1];
            vacina[i] = vacina[i + 1];
            altura[i] = altura[i + 1];

            for (int k = 0; k < strlen(nome[i]); k++)
            {
                nome[i][k] = nome[i + 1][k];
            }

            for (int k = 0; k < strlen(email[i]); k++)
            {
                email[i][k] = email[i + 1][k];
            }

            for (int k = 0; k < strlen(endereco[i]); k++)
            {
                endereco[i][k] = endereco[i + 1][k];
            }

            for (int k = 0; k < strlen(sexo[i]); k++)
            {
                sexo[i][k] = sexo[i + 1][k];
            }
        }

        nUsuarios--;

        do
        {
            system("cls");
            printf("Usuario selecionado deletado\n");
            printf("deseja excluir mais algum usuario? (1-sim / 2-nao): ");
            printf("\n_______________________________________________________________");
		    printf("\n|                                                              |");
            printf("\n|                 Usuario selecionado deletado                 |");
            printf("\n|                 deseja excluir mais algum usuario?           |");
            printf("\n|                         1-sim                                |");
            printf("\n|                         2-nao                                |");
		    printf("\n|______________________________________________________________|\n");
            
            scanf("%d", &opcao);
            fflush(stdin);
        } while (opcao < 1 || opcao > 2);

    } while (opcao == 1);
}
int buscarId()
{
    int idx, i, x = -1;
    do
    {
        printf("\n_______________________________________________________________");
		printf("\n|                 digite ID do usuario                         |");
		printf("\n|______________________________________________________________|\n");
        scanf("%d", &idx);
        fflush(stdin);

        for (int i = 0; i < nUsuarios; i++)
        {
            if (id[i] == idx)
            {
                x = i;
                mostrarPerfil(x);
                return x;
            }
        }
          printf("\n_______________________________________________________________");
		printf("\n|                        ID cadastrado                           |");
		printf("\n|________________________________________________________________|\n");
        if (voltar())
        {
            return -1;
        }
    } while (x == -1);
}
int buscarEmail()
{
    system("cls");

    int i, k;
    char userEmail[105], x[105];
    do
    {
        printf("Digite o email do usuario: ");
        fgets(userEmail, 105, stdin);
        fflush(stdin);

        for (int i = 0; i < nUsuarios; i++)
        {
            if (stricmp(userEmail, email[i]) == 0)
            {
                mostrarPerfil(i);
                return i;
            }
        }
        printf("Email solicitado nao encontrado\n");
        if (voltar())
        {
            return -1;
        }

    } while (x[0] == '\0');
}

void mostrarPerfil(int posicao)
{
    system("cls");
    printf("Usuario de id: %d\n", id[posicao]);
    printf("Nome: %s", nome[posicao]);
    printf("Sexo: %s", sexo[posicao]);
    printf("Altura: %lf\n", altura[posicao]);
    if (vacina[posicao])
    {
        printf("Vacina: SIM\n");
    }
    else
    {
        printf("Vacina: NAO\n");
    }
    printf("Endereco: %s", endereco[posicao]);
    printf("Email: %s", email[posicao]);
    system("pause");
}

void bkp()
{
    int opcao, xnumero;
    do
    {
        system("cls");
       	printf("\n_______________________________________________________________");
		printf("\n|                         backup                               |");
		printf("\n|______________________________________________________________|\n");

        do
        {
              	printf("\n___________________________________________________________________");
		        printf("\n|        1- validarr bkp a partir da memoria atual                 |");
                printf("\n|        2- Recuperar memoria guardada em backup                   |");
                printf("\n|        3- volta                                                  |");
                printf("\n|                Digite uma opcao valida:                          |");
		        printf("\n|__________________________________________________________________|\n");
            scanf("%d", &opcao);
            fflush(stdin);
        } while (opcao < 1 || opcao > 3);

        if (opcao == 1)
        {
            validarbkp();
        }

        else if (opcao == 2)
        {
            recuperabkp();
        }

        else
        {
            return;
        }

    } while (opcao == 1);
}

void validarbkp()
{
    int input;
       	printf("\n_______________________________________________________________");
		printf("\n|                     valiadr backup                           |");
		printf("\n|______________________________________________________________|\n");
    for (int i = 0; i < nUsuarios; i++)
    {

        idBkp[i] = id[i];
        vacinabkp[i] = vacina[i];
        alturaBkp[i] = altura[i];

        for (int k = 0; k < strlen(nome[i]); k++)
        {
            nomeBkP[i][k] = nome[i][k];
        }

        for (int k = 0; k < strlen(email[i]); k++)
        {
            emailbkp[i][k] = email[i][k];
        }

        for (int k = 0; k < strlen(sexo[i]); k++)
        {
            sexobkp[i][k] = sexo[i][k];
        }

        for (int k = 0; k < strlen(endereco[i]); k++)
        {
            enderecobkp[i][k] = endereco[i][k];
        }
    }
    usuarioBkp = nUsuarios;

    printf("bkp validardo com sucesso\n");
    system("pause");
}

void recuperabkp()
{
    int opcao;
        printf("\n____________________________________________________________________________________________________");
		printf("\n|                                                ATENCAO                                            |");
        printf("\n|Recuperar os dados significa substituir TODOS os dados atuais pelos em bkp (QUE PODEM ESTAR VAZIOS)|");
        printf("\n|                         Tem certeza que deseja continuar?                                         |");
        printf("\n|                       Digite 2 para voltar e qualquer coisa para continuar:                       |");
		printf("\n|___________________________________________________________________________________________________|\n");
    scanf("%d", &opcao);
    fflush(stdin);

    if (opcao == 2)
    {
        return;
    }

    printf("Recuperando dados . . . \n");
    for (int i = 0; i < usuarioBkp; i++)
    {

        id[i] = idBkp[i];
        vacina[i] = vacinabkp[i];
        altura[i] = alturaBkp[i];

        for (int k = 0; k < strlen(nomeBkP[i]); k++)
        {
            nome[i][k] = nomeBkP[i][k];
        }

        for (int k = 0; k < strlen(emailbkp[i]); k++)
        {
            email[i][k] = emailbkp[i][k];
        }

        for (int k = 0; k < strlen(sexobkp[i]); k++)
        {
            sexo[i][k] = sexobkp[i][k];
        }

        for (int k = 0; k < strlen(enderecobkp[i]); k++)
        {
            endereco[i][k] = enderecobkp[i][k];
        }
    }
    nUsuarios = usuarioBkp;

    printf("Dados recuperados com sucesso\n");
    system("pause");
}



