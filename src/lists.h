/**
 * @file lists.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LISTS_H
#define LISTS_H


#include <stdio.h>
#include <stdlib.h>


typedef int list_type;       // type of the list's element
const size_t LIST_SIZE = 15; // the number of elements in the list

typedef struct list
{
    list_type* list_elem_arr = nullptr; /// \brief pointer to the array of structs list_elem
    list_type* list_next_arr = nullptr; /// 
    size_t head              = 0;       /// \brief index of the head element in the list
    size_t tail              = 0;       /// \brief index of the tail element in the list
    size_t free              = 0;       /// \brief index of the free element in the list
    size_t num_elem_in_list  = 0;       /// \brief the total number of elements in the list
}list;


enum error_code
{
    OK                = 0,
    ERR_OPEN_DMP_FILE = 1,
    ERR_LIST_FULL     = 2,
    ERR_LIST_EMPTY    = 3, 


};



/**
 * @brief 
 * 
 */
void list_ctor(list* list);

/**
 * @brief 
 * 
 */
void list_dtor(list* list);

/**
 * @brief 
 * 
 * @param list 
 */
void list_dump(list* list);

/**
 * @brief Prints horizontal line in the file, length depends on number of elements in the list
 * 
 * @param list is a struct which contains all data about list
 * @param list_dump_file 
 */
void draw_line(list* list, FILE* list_dump_file);

/**
 * @brief Prints the data about list struct
 * 
 */
void print_list_data(list* list, FILE* list_dump_file);

void print_arr_next(list* list, FILE* list_dump_file);

void print_arr_elem(list* list, FILE* list_dump_file);

void list_add(list* list, size_t elem_id);

void list_delete(list* list, size_t elem_id);

void list_add(list* list, size_t elem_id, list_type val);

size_t search_free(list* list);


#endif