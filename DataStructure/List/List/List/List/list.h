//
//  list.h
//  List
//


#ifndef list_h
#define list_h

#include <stdio.h>

//define a struct for list element
typedef struct ListElmt_
{
    void *data;
    struct ListElmt_ *next;
}ListElmt;

//define a struct for linked list
typedef struct List_
{
    int size;       //count
    void (*match)(const void *key1,const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
}List;


//define public interface

//初始函数
void list_init(List *list,void (*destroy)(void *data));

//销毁函数
void list_destroy(List *list);

//插入函数
int list_ins_next(List *list,ListElmt *element,const void *data);

//删除函数
int list_rem_next(List *list,ListElmt *element,void **data);

#define list_size(list) ((list)->size)//取 链表中的大小（即结点数）

#define list_head(list) ((list)->head)//取 链表中的 头结点
#define list_tail(list) ((list)->tail)//取 链表中的 尾结点

#define list_is_head(list,element) ((element) == (list)->head ?1:0)
//判断头结点
#define list_is_tail(list,element) ((element) == (list)->tail ?1:0)
//判断尾结点
#define list_data(list) ((list)->data)//取 链表中的 值
#define list_next(list) ((list)->next)//取 链表中 指向下一地址的指针




#endif /* list_h */
