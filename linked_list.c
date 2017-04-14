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
 * @file linked_list.c
 * @author Hsien Wen, Hu
 * @date 14 April 2017
 * @brief Containing functions source code
 */
#include "linked_list.h"

/**
 * This function can initial and create a new list to use
 * @param list The list descriptor.
 * @return No return.
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListNew(List *list)
{
  list->head = NULL;
}

/**
 * This function can add node to list
 * @param list The list descriptor.
 * @param input_node Whatever kinds of struct which you want to discribe your information.
 * @return No return.
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListAdd(List *list, void *input_node) {
  if (input_node == NULL){ return; }
  ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
  new_node->obj = input_node;
  new_node->next = list->head;
  list->head = new_node;
}

/**
 * This function can free the whole list
 * @param list The list descriptor.
 * @return No return.
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListFree(List *list){
  while(list->head != NULL){
    ListNode *tmp_next = list->head->next;
    free(list->head);
    list->head = tmp_next;
  }
}

/**
 * This function can search a specific node in the list
 * @param list The list descriptor.
 * @param key The struct which you want.
 * @param key_size The size of key in byte.
 * @return The node you want
 * @note To becontinue...
 * @warning To becontinue...
 */
void *ListSearch(List *list, void *key, size_t key_size){
  ListNode *tmp = list->head;
  while(tmp != NULL){
    ListNode *tmp_next = tmp->next;
    if(memcmp(tmp->obj, key, key_size) == 0){
      return tmp->obj;
    }else{
      tmp = tmp_next;
    }
  }

  return NULL;
}

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
LIST_FEED_BACK ListDelete(List *list, void *key, size_t key_size){
  if(memcmp(list->head->obj, key, key_size) == 0){
    ListNode *tmp = list->head;
    list->head = list->head->next;
    free(tmp);
    return DELETED;
  }

  ListNode *tmpCurrent = list->head->next;
  ListNode *tmpPrevious = list->head;

  while(tmpCurrent != NULL && tmpPrevious != NULL){
    if(memcmp(tmpCurrent->obj, key, key_size) == 0){
      ListNode *tmp = tmpCurrent;
      tmpPrevious->next = tmpCurrent->next;
      free(tmp);
      return DELETED;
    }
    tmpPrevious = tmpCurrent;
    tmpCurrent = tmpCurrent->next;

  } 
  return NO_MATCH;
}

/**
 * This function can print the whole list.
 * @param list The list descriptor.
 * @param f print function
 * @return No return
 * @note To becontinue...
 * @warning To becontinue...
 */
void ListPrint(List *list, PRINT_FUNC f) {
  ListNode *p;
  for (p = list->head; p != NULL; p=p->next)
    f(p->obj);
}