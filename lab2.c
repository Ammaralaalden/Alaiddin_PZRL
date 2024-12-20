#include <stdio.h>
#include "lab2.h"
#include <string.h>
#include <stdlib.h>


void insert_text_front(char *filename, char *insert_text) 
{

	FILE *file = fopen(filename, "r");
	if (file == NULL) 
	{
		printf("Не удалось открыть файл.\n");
		return;
	}
	
	
	FILE *temp_file = fopen("temp.txt", "w");
	if (temp_file == NULL) 
	{
		printf("Не удалось открыть файл.\n");
		fclose(file);
		return;
	}
	
	char line[1000];
	while (fgets(line, sizeof(line), file)) 
	{
		fprintf(temp_file, "%s%s", insert_text, line);
	}
	
	fclose(file);
	fclose(temp_file);
	
	remove(filename);
	rename("temp.txt", filename);
}

void insert_text_end(char *filename, char *insert_text)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL) 
	{
		printf("Не удалось открыть файл.\n");
		return;
	}

	FILE *temp_file = fopen("temp.txt", "w");
	if (temp_file == NULL) 
	{
		printf("Не удалось создать файл.\n");
		fclose(file);
        	return;
    	}

    	char line[1000]; // Массив для хранения строки из файла
    	while (fgets(line, sizeof(line), file)) 
	{
        	// Удаляем символ новой строки, если он есть
       		line[strcspn(line, "\n")] = 0; 
        	// Записываем строку из файла и добавляем к ней вводимую строку
        	fprintf(temp_file, "%s%s\n", line, insert_text);
    	}

    	fclose(file);
    	fclose(temp_file);
	
    	remove(filename);
    	rename("temp.txt", filename);
}
