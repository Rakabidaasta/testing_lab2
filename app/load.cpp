/**
 * load.cpp -- функция загрузки текста из файла
 * 
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru> 
 *                     Kvist Tatyana <kvist_tatyana@mail.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <iostream>

#include "common.h"
#include "text/text.h"

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, std::string filename)
{
    FILE *f;

    char buf[MAXLINE + 1];

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename.c_str(), "r")) == NULL) {
        std::cout << "The file " << filename << " cannot be opened\n";
        return;
    }

    /* Удаляем предыдущее содержимое */
    remove_all(txt);

    /* Считываем содержимое строка за строкой */
    while (fgets(buf, MAXLINE, f)) {
        buf[strlen(buf) - 1] = '\0';
        append_line(txt, std::string(buf));
    }

    fclose(f);
}
