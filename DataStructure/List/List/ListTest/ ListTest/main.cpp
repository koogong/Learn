//
//  main.cpp
//  ListTest


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.c"


/* destroy */
void destroy(void *data)
{
    printf("in destroy\n");
    free(data);
    return;
}


/* main */
int main(int argc, char **argv)
{
    ListElmt *elem_ptr = NULL;
    int i;
    int ret;
    int *data = NULL;
    
    /* Create a linked list */
    List list_exp;
    
    /* init the list */
    printf("\ninit the list:\n");
    list_init(&list_exp, destroy);
    
    /* insert the element */
    printf("\ncreate a list:\n");
    for(i = 0; i < 10; i++ )
    {
        data = (int *)malloc(sizeof(int));
        if( data == NULL )
            return -1;
        
        *data = i;
        list_ins_next(&list_exp, NULL, (void *)data);
    }
    
    /* now the list has 10 element, then traverse and print every element */
    elem_ptr = list_exp.head;
    for( i = 0; i < 10; i++ )
    {
        printf("%d ",  *(int *)list_data(elem_ptr) );
        elem_ptr = list_next(elem_ptr);
    }
    printf("\n");
    
    /* Remove the element, its value of the data equal 4,then traverse and print again */
    elem_ptr = list_exp.head;
    for( i = 0; i < list_size(&list_exp); i++ )
    {
        if( *(int *)list_data(elem_ptr) == 5 )
        {
            ret = list_rem_next(&list_exp, elem_ptr, (void **)&data);
            if( ret == 0 )
            {
                destroy(data);
            }
        }
        elem_ptr = list_next(elem_ptr);
    }
    
    printf("after remove the element: value = 4\n");
    
    //traverse and print again
    elem_ptr = list_exp.head;
    for( i = 0; i <list_size(&list_exp); i++ )
    {
        printf("%d ",  *(int *)list_data(elem_ptr) );
        elem_ptr = list_next(elem_ptr);
    }
    printf("\n\n");
    
    printf("here begin to destroy the list :\n");
    //destroy the linked list
    list_destroy(&list_exp);
    
    return 0;
}
