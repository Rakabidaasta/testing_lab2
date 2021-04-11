/**
 * _text.h -- внутренние структуры представления текста
 * 
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <list>
// #include <iterator>

#include "text.h"

/**
 * @struct 
 * @brief Представление одной строки текста как элемента линейного списка
 * 
 */
typedef struct _node {
    char contents[MAXLINE + 1]; /**< содержимое строки текста */
    struct _node *previous;     /**< указатель на предыдущую строку */
    struct _node *next;         /**< указатель на следующую строку */
} node;


/**
 * @struct 
 * @brief Представление курсора
 * 
 */
typedef struct _crsr {
    std::list<std::string>::iterator line;         /**< указатель на строку с курсором */
    int position;               /**< позиция курсора в строке */
} crsr;


/**
 * @struct 
 * @brief Линейный двунаправленный список строк текста
 * 
 */
typedef struct _list {
    size_t length;              /**< число строк текста */
    std::list<std::string> *lines;
    struct _crsr *cursor;       /**< позиция в тексте, курсор */
} list;

typedef struct _list *text;

#endif
