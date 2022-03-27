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
 * @return ops* 
 */
ops *loadData(ops *list)    
{
    FILE *fp;
    char line[20];
    int opID, machine, time;
    fp = fopen("dados.txt", "r");

    while (!feof(fp))
    {
        fgets(line, 20, fp);
        sscanf(line, "%d,%d,%d", &opID, &machine, &time);
        list = head_insert(list, opID);
        list = insert(list, opID, machine, time);
    }

    fclose(fp);
    
    return list;
}


/**
 * @brief salva dados do ficheiro txt
 * 
 * @param list 
 * @return ops* 
 */
void saveData(ops *list)
{
    {

    FILE *fp;

    fp = fopen("dados_guardar.txt", "w+");

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
}