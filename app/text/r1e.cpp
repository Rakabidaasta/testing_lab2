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

    while (current != txt->lines->end()) {
        
        /*Если текущая строка нулевая */
        if ((*current).length() == 0) {

            /*Если в строке есть курсор */

            if (txt->cursor->line == current) {
                cursor_line = current;
                txt->cursor->position = 0;

                if(current != txt->lines->begin()) {
                    txt->cursor->line = --cursor_line;
                } else {
                    txt->cursor->line = ++cursor_line;
                }
            }

            txt->lines->erase(current);

            break;
        }

        /*Переходим на следующую строку */
        current++;
    }
}
