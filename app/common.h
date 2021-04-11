/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru> 
 *                     Kvist Tatyana <kvist_tatyana@mail.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов (Квист Татьяна) +
 */
void showupper(text txt);

/**
 * Сохраняем содержимое в указанный файл (Квист Татьяна)
 */
void save(text txt, std::string filename);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, std::string filename);

#endif
