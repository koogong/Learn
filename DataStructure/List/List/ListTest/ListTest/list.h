//
//  list.h  
//  ListTest


#ifndef list_h
#define list_h

/* define a struct for list element */
typedef struct ListElmt_
{
    void *data;
    struct ListElmt_ *next;
}ListElmt;

/* define a structure for linked list */
typedef struct List_
{
    int size;
    void (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
}List;

/* define public interface */
void list_init(List *list, void(*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *elemet, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(list, element) ((element) == (list)->tail ? 1 : 0)

#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif /* list_h */
