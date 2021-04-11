/**
 * editor.cpp -- строковый текстовый редактор
 * 
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru> 
 *                     Kvist Tatyana <kvist_tatyana@mail.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "text/text.h"
#include "common.h"

static int split(std::string &str_in, std::string &str_out, char del)
{
    int i = 0;

    while (str_in[i] == del) {
        i++;
    }

    str_in.erase(0, i);

    if (str_in == "") return -1;

    int pos = 0;
    if ((pos = (int) str_in.find(del)) == -1) {
        str_out = str_in;
        str_in.erase(str_in.begin(), str_in.end());
    } else {
        str_out = str_in.substr(0, pos);
        str_in.erase(0, pos + 1);
    }

    return 0;
}

int main()
{
    std::string cmdline;
    char del = ' ';
    std::string cmd;
    std::string line;
    std::string line2;

    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (true) {
        std::cout << "ed > ";

        /* Получаем команду */
        std::cin >> cmdline;

        split(cmdline, cmd, del);

        /* Извлекаем имя команды */
        if (cmd == "") {
            continue;
        }

        /* Распознаем поддерживаемую команду */

        /* Загружаем содержимое файла, заданного параметром */
        if (cmd == "load") {
            if (split(cmdline, line, del) == 0) {
                load(txt, line);
            } else {
                std::cerr << "Usage: load filename\n";
            }

            /*Сдвигаем курсор в нулевую позицию */
            if (m(txt, 0, 0) != 0) {
                fprintf(stderr, "Can't move to zero\n");
            }
            continue;
        }

        /*Обработка команды save */
        if (cmd == "save") {
            if (split(cmdline, line, del) == 0) {
                save(txt, line);
            } else {
                std::cerr << "Usage: save filename\n";
            }
            continue;
        }

        /* Выводим текст */
        if (cmd == "show") {
            show(txt);
            continue;
        }

        /* Завершаем работу редактора */
        if (cmd == "q") {
            std::cout << "Bye!\n";
            break;
        }


        /*__________________________________Изменённый вывод__________________________________*/

        /* Выводим текст с капитализацией всех символов Татьяна Квист + */
        if (cmd == "showupper") {
            showupper(txt);
            continue;
        }

        /*__________________________________Библиотечные функции__________________________________*/

        /*Обработка команды m Татьяна Квист */
        if (cmd == "m") {
            if (split(cmdline, line, del) == 0 && split(cmdline, line2, del) == 0) {
                    m(txt, atoi(line.c_str()), atoi(line2.c_str()));
            } else {
                std::cerr << "Usage: load filename\n";
            }

            continue;
        }

        /*Для перемещения курсора в начало строки Татьяна Квист */
        if (cmd == "mlb") {
            mlb(txt);
            continue;
        }

        /*Удаление первой пустой строки Татьяна Квист */
        if (cmd == "r1e") {
            r1e(txt);
            continue;
        }

        /* Если команда не известна */
        std::cerr << "Unknown command: " << cmd << std::endl;
    }

    return 0;
}
