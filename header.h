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

#define DADOS
#endif 