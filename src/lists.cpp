#include "lists.h"

void list_add(list* list, size_t elem_id, list_type val)
{
    if((list->head == 0) && (list->tail == 0) && (elem_id == 0))
    {
        list->head = list->free;
        list->tail = 2;
        list->list_elem_arr[list->head] = val;
        list->list_elem_arr[list->tail] = 0;
        list->list_next_arr[list->head] = 2;
        list->list_next_arr[list->tail] = 0;
        search_free(list);
    }
    else if((list->free != 0) && (elem_id < list->num_elem_in_list) && (list->list_next_arr[elem_id] != -1) && (elem_id != list->tail))
    {
        size_t next = list->list_next_arr[elem_id];
        list->list_next_arr[elem_id] = list->free;
        list->list_next_arr[list->free] = next;
        list->list_elem_arr[list->free] = val;
        search_free(list);
    }
    else if((list->free != 0) && (elem_id < list->num_elem_in_list) && (list->list_next_arr[elem_id] == -1) && (elem_id != list->tail))
    {
        printf("Element with id = %ld does not exists\n", elem_id);
    }
    else if(elem_id == list->tail)
    {
        printf("I cannot write after tail\n");
    }
    else if(elem_id >= list->num_elem_in_list)
    {
        printf("You are trying to write out of list\n");
    }
    else
    {
        printf("LIST IF FULL!\n");
    }
}

void list_delete(list* list, size_t elem_id)
{
    if(list->head == 0 && list->tail == 0)
    {
        printf("LIST IS FULL\n");
    }
    else if((elem_id != list->head) && (list->list_next_arr[elem_id] != list->tail))
    {
        list->list_elem_arr[elem_id] = -1;
        size_t index_to_del = list->list_next_arr[elem_id];
        size_t new_next = list->list_next_arr[index_to_del];
        list->list_next_arr[index_to_del] = -1;
        list->list_next_arr[elem_id] = new_next;
        list->list_elem_arr[index_to_del] = -1;
    }
    else if((elem_id == list->head) && (list->list_next_arr[elem_id] == list->tail))
    {
        list->list_elem_arr[elem_id] = -1;
        list->list_elem_arr[list->list_next_arr[elem_id]] = -1;
        list->list_next_arr[list->list_next_arr[elem_id]] = -1;
        list->list_next_arr[elem_id] = -1;
        list->head = 0;
        list->tail = 0;
    }
    else if((elem_id == list->head) && (list->list_next_arr[elem_id] != list->tail))
    {
        list->head = list->list_next_arr[elem_id];
        list->list_elem_arr[elem_id] = -1;
        list->list_next_arr[elem_id] = -1;
    }
}

void search_free(list* list)
{
    size_t free_index = 0; // nullptr cell
    
    for(size_t i = 1; i < list->num_elem_in_list; i++)
    {   
        if(list->list_next_arr[i] == -1)
        {
            free_index = i;
            //printf("free_index: %ld", free_index);
            break;
        }
    }

    list->free = free_index; // index of free cell or 0 if list is full
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

void logic(list* list)
{
    int cmd = 0;
    size_t id = 0;
    list_type val = 0;
    while(cmd != 3)
    {   
        printf("1 - add to list, 2 - delete from list, 3 - exit\n");
        scanf("%d", &cmd);
        switch (cmd)
        {
            case 1:
                scanf(" %ld %d", &id, &val);
                list_add(list, id, val);
                list_dump(list);
                break;
            case 2:
                scanf(" %ld", &id);
                list_delete(list, id);
                list_dump(list);
                break;
            case 3:
                break;
            default:
                printf("invalid command, try again\n");
                break;
        }
    }
}