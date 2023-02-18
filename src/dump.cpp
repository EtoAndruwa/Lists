#include "lists.h"

void list_dump(list* list)
{
    FILE* list_dump_file = fopen("list_dump_file.txt", "w");

    fprintf(list_dump_file, "\nIndex: ");
    for(size_t i = 0; i < list->num_elem_in_list; i ++)
    {   
        fprintf(list_dump_file, "|", i);
        fprintf(list_dump_file, "\t%ld\t", i);
    }
    
    fprintf(list_dump_file, "\nValue: ");
    for(size_t i = 0; i < list->num_elem_in_list; i ++)
    {   
        fprintf(list_dump_file, "|", i);
        fprintf(list_dump_file, "\t%d\t", list->list_elem_arr[i].elem_value);
    }
    fprintf(list_dump_file, "\n");

    fclose(list_dump_file);
}