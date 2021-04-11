/**
 * create_text.cpp -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru>
 *                     Kvist Tatyana <kvist_tatyana@mail.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{
    text txt;

    /* Создаем структуру описания текста */
    if ((txt = (list *) malloc(sizeof(list))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    /* Создаем структуру описания курсора */
    if ((txt->cursor = (crsr *) malloc(sizeof(crsr))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    /* Только что созданный текст не содержит ни одной строки */
    txt->length = 0;

    /* Создаём новый объект класса list<string>s */
    txt->lines = new std::list<std::string>();

    /* Курсор ставим в конец текста на последнюю позицию */
    txt->cursor->line = txt->lines->end();
    txt->cursor->position = 0;

    return txt;
}
