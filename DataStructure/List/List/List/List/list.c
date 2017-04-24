//
//  list.c
//  List

#include "list.h"

#include <stdlib.h>
#include <string.h>



//list_init
void list_init(List *list,void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    
    return;
}

//list_destroy

void list_destroy(List *list)
{
    void *data;//keep the data in the element of the list
    
    //Remove the element
    while (list_size(list) > 0) {
        if(list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy !=NULL)
        {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(list));
    
    return;
}

//list_ins_next
int list_ins_next(List *list,ListElmt *element,const void *data)
{
    //Allocate storage
    ListElmt *new_element = NULL;//插入链表用
    new_element = (ListElmt *)malloc(sizeof(ListElmt));//申请内存
    
    if(new_element == NULL)//判断申请内存是否成功
        return -1;
    
    new_element->data = (void *)data;//赋值
    //Insert the element into the list
    if(element == NULL)//from head position to insert
    {
        //考虑当链表数为0时，将新结点插入到链表尾处
        if(list_size(list) == 0)//be care to tail
            list->tail = new_element;
        
        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        if(element->next == NULL)//be care to tail
            list->tail = new_element;
        
        new_element->next = element->next;
        element->next = new_element;
    }
    
    //Adjust size
    list->size++;
    
    return 0;
}


//list_rem_next
int list_rem_next(List *list, ListElmt *element, void **data)
{
    ListElmt *old_element;
    
    //if the list is empty
    if( list_size(list) == 0 )
        return -1;
    
    /* Remove the element from the list */
    if( element == NULL ) //from head to remove
    {
        *data = list->head->data; //keep the data.
        old_element = list->head;
        list->head = list->head->next;
        
        if( list_size(list) == 1 )  //be care to the tail
            list->tail = NULL;
    }
    else
    {
        //if the element to be removed is NULL
        if( element->next == NULL )
            return -1;
        
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        
        if( element->next == NULL ) //be care to the tail
            list->tail = element;
    }
    
    //free the memory
    free(old_element);
    
    list->size--;
    
    return 0;
}













