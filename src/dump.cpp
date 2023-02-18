#include "lists.h"

void list_dump(list* list)
{
    FILE* list_dump_file = fopen("list_dump_file.txt", "a+");   

    print_list_data(list, list_dump_file);
    print_arr_elem(list, list_dump_file);
    print_arr_next(list, list_dump_file);

    fclose(list_dump_file);
}

void draw_line(list* list, FILE* list_dump_file)
{
    fprintf(list_dump_file, "\n-------");
    for(size_t i = 0; i < list->num_elem_in_list; i ++)
    {   
        fprintf(list_dump_file, "--------");
    }
}

void print_list_data(list* list, FILE* list_dump_file)
{   
    fprintf(list_dump_file, "\n\n-------LIST_DATA-------\n");
    fprintf(list_dump_file, "Head: %ld\n", list->head);
    fprintf(list_dump_file, "Tail: %ld\n", list->tail);
    fprintf(list_dump_file, "Free: %ld\n", list->free);
    fprintf(list_dump_file, "Number of elements: %ld\n", list->num_elem_in_list);
    fprintf(list_dump_file, "-------LIST_DATA-------\n\n");
}

void print_arr_elem(list* list, FILE* list_dump_file)
{
    fprintf(list_dump_file, "LIST: ");
    draw_line(list, list_dump_file);

    fprintf(list_dump_file, "\nIndex: ");
    for(size_t i = 0; i < list->num_elem_in_list; i ++)
    {   
        fprintf(list_dump_file, "|", i);
        fprintf(list_dump_file, "\t%ld\t", i);
    }

    draw_line(list, list_dump_file);

    fprintf(list_dump_file, "\nValue: ");
    for(size_t i = 0; i < list->num_elem_in_list; i ++)
    {   
        fprintf(list_dump_file, "|", i);
        fprintf(list_dump_file, "\t%d\t", list->list_elem_arr[i]);
    }
    draw_line(list, list_dump_file);   
}

void print_arr_next(list* list, FILE* list_dump_file)
{
    fprintf(list_dump_file, "\n\n");
    fprintf(list_dump_file, "NEXT: ");
    draw_line(list, list_dump_file);
    fprintf(list_dump_file, "\nIndex: ");
    for(size_t i = 0; i < list->num_elem_in_list; i ++)
    {   
        fprintf(list_dump_file, "|", i);
        fprintf(list_dump_file, "\t%ld\t", i);
    }

    draw_line(list, list_dump_file);

    fprintf(list_dump_file, "\nValue: ");
    for(size_t i = 0; i < list->num_elem_in_list; i ++)
    {   
        fprintf(list_dump_file, "|", i);
        fprintf(list_dump_file, "\t%d\t", list->list_next_arr[i]);
    }
    draw_line(list, list_dump_file); 
}

