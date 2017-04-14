/****************************************************************************
 * Copyright (C) 2017 by Hsien Wen, Hu                                      *
 *                                                                          *
 *                                                                          *
 *   This is a free software: you can redistribute it and/or modify it      *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/


/**
 * @file sample_linked_list.c
 * @author Hsien Wen, Hu
 * @date 14 April 2017
 * @brief Containing the sample usage of linked_list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

/**
 * @brief User customized information struct
 *
 */
typedef struct{
    char *name;/**< just a sample */
    int age;/**< just a sample */
}Person;

/**
 * This function is to be used as printing function
 * @param p User customized information struct
 * @return No return.
 */
void PersonPrint(Person *p) {
  printf("%s is %d years old\n", p->name, p->age);  
}
 
int main(int argc, char *argv[]) {
    Person john = {
      .name = "John",
      .age = 40
    };
    Person mary = {
      .name = "Mary",
      .age = 32
    };
    Person george = {
      .name = "George",
      .age = 26
    };
    Person kate = {
    	.name = "Kate",
    	.age = 22
    };

    Person key = {
      .name = "John",
      .age = 40
    };
    

    List listHead;
    printf("Initial new list\n");
    ListNew(&listHead);
    printf("Add John\n");
    ListAdd(&listHead, &john);
    printf("Add Mary\n");
    ListAdd(&listHead, &mary);
    printf("Add George\n");
    ListAdd(&listHead, &george);
    printf("Print list : \n");
    ListPrint(&listHead, (PRINT_FUNC) PersonPrint);
    printf("\n\nSeach for John\n");
    Person *searched = ListSearch(&listHead, &key, sizeof(Person));
    printf("\tSearch resualt : \n");
    printf("\t\tname = %s\n", searched->name);
    printf("\t\tage = %d\n", searched->age);
    printf("Delete John\n");
    ListDelete(&listHead, &key, sizeof(Person));
    printf("\nPrint list : \n");
    ListPrint(&listHead, (PRINT_FUNC) PersonPrint);
    printf("Add Kate\n");
    ListAdd(&listHead, &kate);
    printf("\nPrint list : \n");
    ListPrint(&listHead, (PRINT_FUNC) PersonPrint);
    ListFree(&listHead);
    return 0;
}