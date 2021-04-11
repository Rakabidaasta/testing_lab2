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
#include <fstream>

#include "common.h"
#include "text/text.h"

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, std::string filename)
{
    std::ifstream f;
    f.open(filename);

    if (!f.good()) {
        std::cerr << "The file " << filename << " cannot be opened\n";
        return;
    }

    /* Удаляем предыдущее содержимое */
    remove_all(txt);

    std::string buf;

    while (f.good()) {
        f.getline(&buf[0], MAXLINE);
        append_line(txt, buf);
    }

    f.close();
}
