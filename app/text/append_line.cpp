/**
 * append_line.cpp -- функции для добавления строк
 * 
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru> 
 *                     Kvist Tatyana <kvist_tatyana@mail.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, std::string contents)
{
    /* Добавляем в конец листа новую строку */ 
    txt->lines->push_back(contents);

    /* Указатель курсора ставим на последнюю строку (берём итератор на последнюю строку) */ 
    txt->cursor->line = txt->lines->end();
    /* Ставим курсор на последнюю позицию в строке */ 
    txt->cursor->position = contents.length();

    /* Увеличиваем количество строк в листе на единицу */ 
    txt->length++;
}

