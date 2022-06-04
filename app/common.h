/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет содержимое в указанный файл
 */
void save(text txt, char *filename);

/**
 * выводит содержимое, меняя все буквы на *
 */
void showclassified(text txt);

/**
 * вывод на экран части строки от начала до курсора
 */
void plb(text txt);

/**
 * разбивает строку с курсором на 2 части, по курсору
 */
void split(text txt);

#endif
