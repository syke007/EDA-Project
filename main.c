/**
 * @file functions.c
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

int main()
{
    ops *list = NULL;

    list = loadData(list); 

    system("cls || clear");
    saveData(list);
    system("pause");
    system("cls || clear");
    Show(list);
    system("pause");

    system("cls || clear");
    removeMachine(list,1);
    printf("NOVA ->\n");
    Show(list);
    system("pause");

    system("cls || clear");
    changeMachine(list, 2,3, 500);
    printf("NOVA ->\n");
    Show(list);
    system("pause");

    system("cls || clear");
    printf("Maximo ->\n");
    maximumTime(list);
    system("pause");

    system("cls || clear");
    printf("Minimo ->\n");
    minimumTime(list);
    system("pause");

    system("cls || clear");
    printf("Media ->\n");
    avg(list);
    system("pause");
    return 0;
}