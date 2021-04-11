/**
 * showupper.cpp -- функция для вывода текста с капитализацией всех символов
 * 
 * Copyright (c) 2021, Kvist Tatyana <kvist@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, std::string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов
 */
void showupper(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов
 */
static void show_line(int index, std::string contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    /*Выделяем память под копию текущей строки */
    char contents_copy[MAXLINE + 1];

    /*Копируем текующую строку */
    if(contents.length() <= MAXLINE) {
        strcpy(contents_copy, contents.c_str());
    } else {
        return;
    }

    /*Поднимаем регистр в копии строки */
    char *c = contents_copy;
    while (*c) {
        *c = toupper(*c);
        c++;
    }

    /* Выводим копию строки на экран */
    printf("%s\n", contents_copy);
}
