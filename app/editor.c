/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char load_file[MAXLINE + 1] = "output.txt";
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        if (fgets(cmdline, MAXLINE, stdin) == NULL){
            printf("bad read\n");
        }

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                strncpy (load_file, arg, MAXLINE);
                load(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                save(txt, load_file);
            } else {
                strncpy (load_file, arg, MAXLINE);
                save(txt, arg);
            }
            continue;            
        }


        /* перемещаем курсор по строке символу*/
        if (strcmp(cmd, "move") == 0) {
            int arr[2];
            int flag = 1;
            for (int i = 0; i < 2 && flag; i++){
                if ((arg = strtok(NULL, " \n")) == NULL) {
                    flag = 0;
                    break;
                }

                arr[i] = atoi(arg);
                if (arr[i] <= 0){
                    flag = 0;
                    break;
                }
            }

            if (flag){
                move(txt, arr[0], arr[1]);
            }else{
                fprintf(stderr, "Usage: move line row (1 numbering)\n");
            }

            continue;            
        }        
        
        if (strcmp(cmd, "showclassified") == 0) {
            showclassified(txt);
            continue;
        }

        if (strcmp(cmd, "plb") == 0){
            plb(txt);
            continue;
        }

        if (strcmp(cmd, "s") == 0){
            split(txt);
            continue;
        }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
