/**
 * r1e.cpp - реализует удаление первой пустой строки
 * 
 * Copyright (c) 2021, Kvist Tatyana <kvist@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include "text.h"
#include "_text.h"

void r1e(text txt)
{
    /*Начинаем с начала txt */
    std::list<std::string>::iterator current = txt->lines->begin();
    std::list<std::string>::iterator cursor_line;

    bool flag = 0;

    while (current != txt->lines->end()) {
        
        /*Если текущая строка нулевая */
        if ((*current).length() == 0) {
            flag = 1;
            break;
        }

        /*Переходим на следующую строку */
        current++;
    }

    /*Если в строке есть курсор */

    if(flag == 1 && txt->cursor->line == current) {
        cursor_line = current;
        txt->cursor->position = 0;

        if(current != txt->lines->begin()) {
            txt->cursor->line = --cursor_line;
        } else {
            txt->cursor->line = ++cursor_line;
        }
    }

    if (flag == 1) {
        txt->lines->erase(current);
    }
}
