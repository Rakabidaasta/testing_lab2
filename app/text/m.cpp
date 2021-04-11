/**
 * m.cpp -- функция для перемещения курсора в заданную позицию
 * 
 * Copyright (c) 2021, Kvist Tatyana <kvist@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "_text.h"

int m(text txt, int line_num, int cursor_pos)
{
    /*Если заданный номер строки или позиция курсора меньше 0 */
    if (line_num < 0 || cursor_pos < 0)
        return -1;

    /* Итератор строки, в которой должен стоять курсор */
    std::list<std::string>::iterator current = txt->lines->begin();
    int index = 0;


    /*Идём до заданной строки */
    bool find_flag = false;
    while (current != txt->lines->end()) {
        if (line_num == index) {
            find_flag = true;
            break;
        }
        current++;
        index++;
    }

    /*Если заданный номер строки больше строк в файле */
    if (!find_flag)
        return -1;

    /*Если заданный позиция курсора больше длины заданной строки */
    if ((*current).length() < (long unsigned int) cursor_pos)
        cursor_pos = (*current).length();

    /*Присваиваем новые позиции строки и курсора */
    txt->cursor->line = current;
    txt->cursor->position = cursor_pos;

    return 0;
}
