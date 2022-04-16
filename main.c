/**
 * @file main.c
 * @author Iuri Rodrigues (a21159@alunos.ipca.cpt)
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"


/**
 * @brief Main com o menu de interaçao com o utilizador
 * 
 * @return 
 */
int main()
{
    ops *list = NULL;
    int op = 0, opID = 0,machine = 0,time = 0;
    list = loadData(list); 


    system("pause");
    system("cls");
	 do
    	{
        printf("|-------------------------------------------|\n");
        printf("|   Escolha uma das seguintes opcoes:   	|\n");     
        printf("|-------------------------------------------|\n");
        printf("| 1- Mostrar dados                          |\n");          
        printf("| 2- Exportar para ficheiro             	|\n");  
        printf("|--                                     	|\n");		
        printf("| 3- Adicionar operaçao                 	|\n"); 
		printf("| 4- Remover operaçao                   	|\n"); 
		printf("| 5- Alterar operaçao                   	|\n");
		printf("|--                                     	|\n");
		printf("| 6- Tempo minimo para completar a operacao |\n");          
        printf("| 7- Tempo maximo para completar a operacao |\n");   
        printf("| 8- Tempo medio para completar a operacao |\n");  
		printf("|--                                     	|\n");
        printf("|        Selecione 0 para sair          	|\n");                     
        printf("|-------------------------------------------|\n");
	
	    printf("Indique qual a opcao:\n");
        scanf("%d", &op);
        system("cls");
        switch (op)
        {

        case 1:
            system("cls");
			Show(list); 
			system("pause"); 
			break;  

	    case 2:
            system("cls");
			saveData(list);
			system("pause");
		    break;

        case 3: 
            system("cls"); 
            printf("Id da operacao -> "); 
            scanf("%d",&opID);
            printf("Maquina -> "); 
            scanf("%d",&machine);
            printf("Unidade de tempo -> "); 
            scanf("%d",&time);

            list = headops_insert(list, opID);
            list = insert(list, opID, machine, time);
            system("pause");
            break;

        case 4: 
            system("cls"); 
            printf("Id da operacao -> "); 
            scanf("%d",&opID);
            removeOP(list,opID);
            system("pause");
            break;

        case 5: 
            system("cls"); 
            printf("Id da operacao -> "); 
            scanf("%d",&opID);
            printf("Maquina -> "); 
            scanf("%d",&machine);
            printf("---------------\n");
            printf("Unidade de tempo -> "); 
            scanf("%d",&time);
            
            changeMachine(list,opID,machine,time);
            system("pause");
            break;

        case 6: 
            system("cls"); 
            minimumTime(list);
            system("pause");
            break;

        case 7: 
            system("cls"); 
            maximumTime(list);
            system("pause");
            break;
            
        case 8:                     
            system("cls"); 
            avg(list);
            system("pause");
            break;
	    case 0:
            printf("Obrigado, Ate um Dia\n");
            system("pause");
            system("cls");
            system("exit");
			break;

        default:
            printf("Opcao Invalida!!!");
            system("cls");
            break;
        }
     } while (op != 0);
     system("cls");
     return 0;
}