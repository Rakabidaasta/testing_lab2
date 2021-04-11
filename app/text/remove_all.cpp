/**
 * remove_all.cpp -- реализует функцию очистки текста
 *
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru> 
 *                     Kvist Tatyana <kvist_tatyana@mail.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }

    /* Если список изначально пуст, делать ничего не надо */
    if (txt->length == 0) {
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(!txt->lines->empty());

    /* Очищаем лист */
    txt->lines->clear();
}
