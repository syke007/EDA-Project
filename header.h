/**
 * @file header.h
 * @author Iuri Rodrigues (a21159@alunos.ipca.cpt)
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * https://github.com/syke007/EDA-Project
 */
#ifndef funcoes
#define funcoes

#include <stdbool.h>
#pragma warning ( disable : 4996) 

typedef struct prod
{
    int machine;
    int time;
    struct prod *next, *prev;
}prod;

typedef struct ops
{
    int opID;
    struct ops *next, *prev;
    struct prod *first, *last;
}ops;

ops *loadData(ops *list);
void saveData(ops *list);
void Show(ops *list);
prod *headprod_insert(prod *list, int machine, int time);
ops *headops_insert(ops *list, int opID);
ops *insert(ops *list, int opID, int machine, int time);
ops * changeMachine(ops *list, int opID,int machine, int time);
ops * removeOP(ops *list, int opID);
ops *minimumTime(ops *list);
ops *maximumTime(ops *list);
ops *avg(ops *list);


#endif 