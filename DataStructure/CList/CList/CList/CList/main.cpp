//
//  main.cpp
//  CList
//
//  Copyright © 2017年 koogong. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "clist.c"

/* destroy */
void destroy(void *data)
{
    printf("in destroy\n");
    free(data);
    return;
}

typedef struct Cuboid_
{
    int length;
    int width;
    int height;
}Cuboid;


Cuboid *cube_instance(const int length, const int width, const int height)
{
    Cuboid *cb_ptr;
    cb_ptr = (Cuboid *)malloc(sizeof(Cuboid));
    if( cb_ptr == NULL )
        return NULL;
    
    cb_ptr->length = length;
    cb_ptr->width = width;
    cb_ptr->height = height;
    
    return cb_ptr;
}


/* main */
int main(int argc, char **argv)
{
    int i;
    int ret = 0;
    CList clist;
    CListElmt *p = NULL;
    
    Cuboid *cb1_ptr, *cb2_ptr, *cb3_ptr, *cb4_ptr, *cb5_ptr;
    Cuboid *cb_ptr;
    
    //cb1_ptr ~ cb5_ptr are the data of the 5 elements.
    cb1_ptr = cube_instance(1,2,3);
    cb2_ptr = cube_instance(6,10,8);
    cb3_ptr = cube_instance(5,20,30);
    cb4_ptr = cube_instance(17,100,25);
    cb5_ptr = cube_instance(3,6,9);
    
    //init the clist
    clist_init(&clist, destroy);
    
    //insert the above 5 element
    /* cb1 -> cb1 */
    ret = clist_ins_next(&clist, NULL, (void *)cb1_ptr);
    if( ret != 0 )
    {
        printf("insert cb1 error\n");
        return -1;
    }
    
    /* cb1 -> cb2 -> cb1 */
    p = clist_head(&clist);
    ret = clist_ins_next(&clist, p, (void *)cb2_ptr);
    if( ret != 0 )
    {
        printf("insert cb2 error\n");
        return -1;
    }
    
    /* cb1 -> cb2 ->cb3 ->cb1*/
    p = clist_next(p);
    ret = clist_ins_next(&clist, p, (void *)cb3_ptr);
    if( ret != 0 )
    {
        printf("insert cb3 error\n");
        return -1;
    }
    
    /* cb1 -> cb2 -> cb3 -> cb4 ->cb1 */
    p = clist_next(p);
    ret = clist_ins_next(&clist, p, (void *)cb4_ptr);
    if( ret != 0 )
    {
        printf("insert cb4 error\n");
        return -1;
    }
    
    /* cb1 -> cb2 -> cb3 -> cb4 ->cb5 -> cb1 */
    p = clist_next(p);
    ret = clist_ins_next(&clist, p, (void *)cb5_ptr);
    if( ret != 0 )
    {
        printf("insert cb5 error\n");
        return -1;
    }
    
    p = clist_head(&clist); //get the head element
    for(i = 0; i < clist_size(&clist) + 1; i++ )
    {
        cb_ptr = (Cuboid *)clist_data(p); // get the element's data, every data is a Cuboid 's pointer.
        printf("i = %d: ",i);
        printf("length = %d, width = %d, height = %d\n",
               cb_ptr->length,
               cb_ptr->width,
               cb_ptr->height);
        p = clist_next(p); //pointer to next element.
    }
    
    //remove the head element
    clist_rem_next(&clist, p, (void **)&cb_ptr);
    printf("the removed element: length = %d, width = %d, height = %d\n",
           cb_ptr->length,
           cb_ptr->width,
           cb_ptr->height);
    
    destroy(cb_ptr); //free the memeory
    
    //destroy the circle list
    clist_destroy(&clist);
    printf("after destroy the list, its size = %d\n", clist_size(&clist));
    return 0;
}











