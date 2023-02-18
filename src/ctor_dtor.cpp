#include "lists.h"

void list_ctor(list* list)
{
    
    list->num_elem_in_list = LIST_SIZE;
    list->list_elem_arr = (list_type*)calloc(list->num_elem_in_list, sizeof(list_type));
    list->list_next_arr = (list_type*)calloc(list->num_elem_in_list, sizeof(list_type));

    for(size_t i = 1; i < list->num_elem_in_list; i++)
    {
        list->list_next_arr[i] = -1;
        list->list_elem_arr[i] = -1;
    }

    list->list_next_arr[0] = 0;
    list->list_elem_arr[0] = 0;

    list->head = 0;
    list->tail = 0;
    list->free = 1;
}

void list_dtor(list* list)
{
    for(size_t i = 1; i < list->num_elem_in_list; i++)
    {
        list->list_next_arr[i] = -1;
        list->list_elem_arr[i] = -1;
    }

    list->head = 0;
    list->tail = 0;
    list->free = 1;

    list->num_elem_in_list = 0;
    free(list->list_elem_arr);
    free(list->list_next_arr);
    list->list_elem_arr = nullptr;
    list->list_next_arr = nullptr;
}

