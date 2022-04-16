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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/**
 * @brief LÊ os dados do ficheiro txt
 * 
 * @param list 
 * @return list
 */
ops *loadData(ops *list)    
{
    FILE *fp;
    char line[20];
    int opID, machine, time;
    fp = fopen("data.txt", "r");

    while (!feof(fp))
    {
        fgets(line, 20, fp);
        sscanf(line, "%d,%d,%d", &opID, &machine, &time);
        list = headops_insert(list, opID);
        list = insert(list, opID, machine, time);
    }

    fclose(fp);
    return list;
}


/**
 * @brief salva dados do ficheiro txt
 * 
 * @param list 
 * @return  
 */
void saveData(ops *list)
{
    FILE *fp;
    fp = fopen("saveddata.txt", "w+");

    for (; list; list = list->next)
    {
        prod *ptr = list->first;
        for (; ptr;)
        {
            fprintf(fp, "%d,%d,%d\n", list->opID, ptr->machine, ptr->time);
            ptr = ptr->next;
        }
    }
    fclose(fp);
}


/**
 * @brief aux
 * 
 * @param list 
 */
void Show(ops *list)
{
    for (; list; list = list->next)
    {

        prod *ptr = list->first;

        for (; ptr;)
        {
            printf("ops -> %d | machine -> %d | time-> %d\n", list->opID, ptr->machine, ptr->time);
            ptr = ptr->next;
        }
    }
}


/**
 * @brief  inserçao á cabeça de produçoes. máquinas
 * 
 * @param list 
 * @param machine 
 * @param time 
 * @return new 
 */
prod *headprod_insert(prod *list, int machine, int time)
{
    prod *new = (prod *)malloc(sizeof(prod));
    new->machine = machine;
    new->time = time;
    new->next = list;

    return new;
}


/**
 * @brief inserção á cabeça de operaçoes
 * 
 * @param list 
 * @param opID 
 * @return new 
 */
ops *headops_insert(ops *list, int opID)
{
    ops *new = (ops *)malloc(sizeof(ops));
    new->opID = opID;
    new->first = new->last = NULL;
    new->next = list;

    return new;
}


/**
 * @brief inserir lista de maquinas dentro das operaçoes
 * 
 * @param list 
 * @param opID 
 * @param machine 
 * @param time 
 * @return list 
 */
ops *insert(ops *list, int opID, int machine, int time)
{
    ops *aux = list;
    while (aux)
    {
        if (aux->opID == opID)
        {
            break;
        }
        aux = aux->next;
    }

    if (!aux->last)
    {
        aux->first = aux->last = headprod_insert(aux->last,machine,time);
    }
    else
    {
        aux->last = headprod_insert(aux->last,machine,time);
    }
    return list;
}


/**
 * @brief Função que remove uma operaçao
 * 
 * @param list 
 * @param opID 
 * @return list 
 */
ops * removeOP(ops *list, int opID)
{
    if (list != NULL)
    {
    for (; list; list = list->next)
    {
        if(list->opID == opID)
        {
            prod *ptr = list->first;

            for (; ptr;)
            {
                if(list->first->next)
                {
                    list->first = list->first->next;
                    list->next->prev = NULL;
                }
                else
                {
                    list->first = NULL;
                    list->last = NULL;
                }
                free(ptr);
                ptr = ptr->next;
            }
        }
    }
    }
    return list;
}


/**
 * @brief Funçao que altera atributos de uma maquina
 * 
 * @param list 
 * @param opID 
 * @param machine 
 * @param time 
 * @return list 
 */
ops * changeMachine(ops *list, int opID,int machine, int time)
{
    if (list != NULL)
    {
    for (; list; list = list->next)
    {
        if(list->opID == opID)
        {
            prod *ptr = list->first;

            for (; ptr;)
            {
                if(ptr->machine == machine)
                {
                    ptr->time = time;
                }
                ptr = ptr->next;
            }
        }
    }
    }
    return list;
}


/**
 * @brief Funcao que determina o tempo máximo necessário para completar uma operação,
 * 
 * @param list 
 * @return list 
 */
ops *maximumTime(ops *list)
{
if (list != NULL)
{
    int max[100];
    for (int i = 0; i < 100; i++)
    {

        max[i] = 0;
    }
    for (; list; list = list->next)
    {
        prod *prod = list->first;
        for (; prod;)
        {
            if (max[list->opID] < prod->time)
            {

                max[list->opID] = prod->time;
            }

            prod = prod->next;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (max[i] != 0)
        {
            printf("%d -> %d \n", i, max[i]);
        }
    }
    return list;
}
}


/**
 * @brief Funcao que determina o tempo minimo necessário para completar uma operação,
 * 
 * @param list 
 * @return list 
 */
ops *minimumTime(ops *list)
{
if (list != NULL)
{

    int min[100];
    for (int i = 0; i < 100; i++)
    {
        min[i] = 9999;
    }
    for (; list; list = list->next)
    {
        prod *prod = list->first;
        for (; prod;)
        {
            if (min[list->opID] > prod->time)
            {
                min[list->opID] = prod->time;
            }

            prod = prod->next;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (min[i] != 9999)
        {
            printf("%d -> %d \n", i, min[i]);
        }
    }
    return list;
}
}


/**
 * @brief funcao que determina a média de unidades de tempo necessárias para completar uma operação,
 * 
 * @param list 
 * @return list 
 */
ops *avg(ops *list)
{
    if (list != NULL)
{
    int avg[100], cont[100];

    for (int i = 0; i < 100; i++)
    {
        cont[i] = 0;
        avg[i] = 0;
    }

    for (; list; list = list->next)
    {
        prod *prod = list->first;
        for (; prod;)
        {

            avg[list->opID] += prod->time;
            cont[list->opID]++;

            prod = prod->next;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (cont[i] != 0)
        {
            float average = avg[i] / (float)cont[i];
            printf("%d -> %.2f \n", i, average);
        }
    }
    return list;
}
}