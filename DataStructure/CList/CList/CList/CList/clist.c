//
//  clist.c
//  CList
//
//  Copyright © 2017年 koogong. All rights reserved.
//

#include "clist.h"

#include <stdlib.h>
#include <string.h>


/* clist_init */
void clist_init(CList *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->head = NULL;
    list->destroy = destroy;
    return;
}

/* clist_destroy */
void clist_destroy(CList *list)
{
    void *data;
    while( clist_size(list) > 0 )
    {
        if( clist_rem_next(list, list->head, (void **)&data) == 0
           && list->destroy != NULL )
        {
            //destroy the memory where the data point to.
            list->destroy(data);
        }
    }
    
    memset(list, 0, sizeof(CList));
    return;
}

/* clist_ins_next */
int clist_ins_next(CList *list, CListElmt *element, const void *data)
{
    CListElmt *new_element;
    
    /* allocate the memory */
    new_element = (CListElmt *)malloc(sizeof(CListElmt));
    if( new_element == NULL )
        return -1;
    
    /* insert the new element into the list */
    new_element->data = (void *)data;
    if( clist_size(list) == 0 )
    {
        //when the list is empty.  be care!
        new_element->next = new_element; //here, new_element is the head and the tail element;
        list->head = new_element;
    }
    else
    {
        //when the list is not empty.
        new_element->next = element->next;
        element->next = new_element;
    }
    
    /* Adjust the size */
    list->size++;
    
    return 0;
}


/* clist_rem_next */
int clist_rem_next(CList *list, CListElmt *element, void **data)
{
    CListElmt *old_element; //keep the element which to be removed.
    
    /* Do not remove from an empty list */
    if( clist_size(list) == 0 )
        return -1;
    
    /* Remove the element from the list */
    *data = (void *)element->next->data;
    if( element->next == element ) //be care the condition.
    {
        /* when the element is the last element */
        old_element = element;
        list->head = NULL;
    }
    else
    {
        /* remove the other element */
        old_element = element->next;
        element->next = element->next->next;
        if( old_element == clist_head(list) ) //if the head element will be removed.
            list->head = old_element->next;
    }
    
    free(old_element);
    list->size--;
    
    return 0;
}





















