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
 * @file linked_list.h
 * @author Hsien Wen, Hu
 * @date 14 April 2017
 * @brief Containing functions definition and usage of linked list
 */
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Node of list definition
 *
 */
typedef struct lnode { 
  struct lnode *next; /**< the pointer to discript next node */
  void *obj;/**< To store user's struct */
}ListNode;

/**
 * @brief list definition
 *
 */
typedef struct {
  ListNode *head;/**< Head of list */
}List;

/**
 * @brief Returnning value definition
 *
 */
typedef enum
{
  SUCCESS = 0,/**< Success to execute a function. */
  DELETED = -1,/**< Success to delete a node in the list. */
  NO_MATCH = -2/**< No math. */
}LIST_FEED_BACK;

/**
 * @brief Console print function definition
 *
 */
typedef void(*PRINT_FUNC)(void*);

/**
 * This function can initial and create a new list to use
 * @param list The list descriptor.
 * @return No return.
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListNew(List *list);

/**
 * This function can add node to list
 * @param list The list descriptor.
 * @param input_node Whatever kinds of struct which you want to discribe your information.
 * @return No return.
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListAdd(List *list, void *input_node);

/**
 * This function can free the whole list
 * @param list The list descriptor.
 * @return No return.
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListFree(List *list);

/**
 * This function can search a specific node in the list
 * @param list The list descriptor.
 * @param key The struct which you want.
 * @param key_size The size of key in byte.
 * @return The node you want
 * @note To becontinue...
 * @warning To becontinue...
 */
void *ListSearch(List *list, void *key, size_t key_size);

/**
 * This function can delete a specifi node in the list
 * @param list The list descriptor.
 * @param key The struct which you want.
 * @param key_size The size of key in byte.
 * @return The reault of the function
 * @see #LIST_FEED_BACK
 * @note To becontinue...
 * @warning To becontinue...
 */
LIST_FEED_BACK ListDelete(List *list, void *key, size_t key_size);

/**
 * This function can print the whole list.
 * @param list The list descriptor.
 * @param f print function
 * @return No return
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListPrint(List *list, PRINT_FUNC f);


#endif
