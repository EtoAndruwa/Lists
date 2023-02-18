#include "lists.h"

void list_add(list* list, size_t elem_id, list_type val)
{
    size_t free_cell = search_free(list);

    if((list->head == 0) && (list->tail == 0) && (elem_id == 0))
    {
        list->head = 1;
        list->tail = 2;
        list->list_elem_arr[1] = val;
        list->list_elem_arr[2] = 0;
        list->list_next_arr[1] = 2;
        list->list_next_arr[2] = 0;
    }
    else if(free_cell != 0)
    {
        size_t next = list->list_next_arr[elem_id];
        list->list_next_arr[elem_id] = free_cell;
        list->list_next_arr[free_cell] = next;
        list->list_elem_arr[free_cell] = val;
    }
}

void list_delete(list* list, size_t elem_id)
{


}

size_t search_free(list* list)
{
    size_t free_index = 0; // nullptr cell
    
    for(size_t i = 1; i < list->num_elem_in_list; i++)
    {   
        if(list->list_next_arr[i] == -1)
        {
            free_index = i;
        }
    }

    return free_index; // returns index of free cell or 0 if list is full
}

// void list_realloc_up(list* list)
// {
//     list->num_elem_in_list = list->num_elem_in_list + 10;
//     list->list_elem_arr = (list_elem*)realloc(list->list_elem_arr, list->num_elem_in_list * sizeof(list_elem));
//     list->list_elem_arr = (list_elem*)realloc(list->list_elem_arr, list->num_elem_in_list * sizeof(list_elem));
// }

// void list_realloc_down(list* list)
// {
//     list->
// }
