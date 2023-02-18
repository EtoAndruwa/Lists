#include "lists.h"

void list_ctor(list* list)
{
    
    list->num_elem_in_list = LIST_SIZE;
    list->list_elem_arr = (list_elem*)calloc(list->num_elem_in_list, sizeof(list_elem));

    for(size_t i = 1; i < list->num_elem_in_list; i++)
    {
        list->list_elem_arr[i].elem_value = -1;
        list->list_elem_arr[i].next_elem  = -1;
        list->list_elem_arr[i].prev_elem  = -1;
    }
    list->list_elem_arr[0].elem_value = 0;

    list->head = 0;
    list->tail = 0;
    list->free = 1;
}

void list_dtor(list* list)
{
    for(size_t i = 1; i < list->num_elem_in_list; i++)
    {
        list->list_elem_arr[i].elem_value = -1;
        list->list_elem_arr[i].next_elem  = -1;
        list->list_elem_arr[i].prev_elem  = -1;
    }

    list->head = 0;
    list->tail = 0;
    list->free = 1;

    list->num_elem_in_list = 0;
    free(list->list_elem_arr);
    list->list_elem_arr = nullptr;
}

