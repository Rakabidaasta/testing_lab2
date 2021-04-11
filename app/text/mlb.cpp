/**
 * mlb.cpp -- функция для перемещения курсора в начало строки
 * 
 * Copyright (c) 2021, Kvist Tatyana <kvist@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "text.h"
#include "_text.h"

void mlb(text txt)
{
    /*Меняем позицию курсора в строке на нулевую */
    txt->cursor->position = 0;
}
