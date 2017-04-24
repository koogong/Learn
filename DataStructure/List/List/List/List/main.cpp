//
//  main.cpp
//  List



#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.c"


void destroy(void *data)
{
    printf("in destroy\n");
    free(data);
    return;
}

int main()
{
    ListElmt *elem_ptr = NULL;
    int i,number;
    int ret;
    int *data = NULL;
    
    //Create a linked list
    List list_exp;
    
    //Init the list
    printf("\n Init the list:\n");
    list_init(&list_exp, destroy);
    
    //Insert the element
    printf("\n Creare a list :\n");
    printf("Please enter a number :\n");
    scanf("%d",&number);
    for (i = 0; i < number; i++) {
        data = (int *)malloc(sizeof(int));
        if(data == NULL)
            return -1;
        
        int kk;
        scanf("%d",&kk);
        *data = kk;
        list_ins_next(&list_exp, NULL, (void *)data);
    }
    
    //Now the list has 10 element ,then traverse and print every element
    elem_ptr = list_exp.head;
    
    for (i = 0; i < number; i++) {
        printf("%d ", *(int *)list_data(elem_ptr));
        elem_ptr = list_next(elem_ptr);
    }
    printf("\n");
    
    //Remove the element ,its value of the data equal 4,then traverse and print again
    elem_ptr = list_exp.head;
    for (i = 0; i < list_size(&list_exp); i++)
    {
        if( *(int *)list_data(elem_ptr) == 4)
        {
            ret = list_rem_next(&list_exp, elem_ptr, (void **)&data);
            if(ret == 0)
            {
                destroy(data);
            }
        }
        elem_ptr = list_next(elem_ptr);
    }
    
    
    printf("After remove the element : value = 4 \n");
    
    
    //taverse and print again
    elem_ptr = list_exp.head;
    
    for( i = 0; i <list_size(&list_exp); i++ )
    {
        printf("%d ",  *(int *)list_data(elem_ptr) );
        elem_ptr = list_next(elem_ptr);
    }
    printf("\n\n");
    
    printf("Here begain to destroy the list : \n");
    //destroy the linked list
    list_destroy(&list_exp);
    
    return 0;
}
















