#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>


typedef int list_type;       // type of the list's element
const size_t LIST_SIZE = 10; // the number of elements in the list

typedef struct list_elem
{
    list_type elem_value    = 0; // value of this list element
    size_t next_elem        = 0; // index of the next list's element after this one
    size_t prev_elem        = 0; // indes of the previous list's element before this one
    size_t num_elem_in_list = 0; // the total number of elements in the list
}list_elem;


typedef struct list
{
    list_elem* list_elem_arr = nullptr; // pointer to the array of structs list_elem
    size_t head              = 0;       // index of the head element in the list
    size_t tail              = 0;       // index of the tail element in the list
    size_t free              = 0;       // index of the free element in the list
}list;



/**
 * @brief 
 * 
 */
void list_ctor(list* list);

/**
 * @brief 
 * 
 */
void list_dtor();





#endif