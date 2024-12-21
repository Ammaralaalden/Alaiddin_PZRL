#include <stdio.h>
#include "lab2.h"
#include <string.h>


int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		printf("Недостаточно аргументов.\n");
		return 1;
	}
	
	char* input_file = argv[1];

	FILE* file = fopen(input_file, "r"); // Проверка на корректный ввод названия файла.
	if (file == NULL)
	{
		printf("Ошибка чтения файла, возможно введено неправильное имя.\n");
		return 1;
	}
	fclose(file);
	
	if ((strlen(argv[2]) == 2) && (argv[2][0] == '-')) // Проверка на корректность 2 аргумента (размер и -).
	{
		if (argv[2][1] == 'i')
		{
			if (argc != 5)
			{
				printf("Некорректное число аргументов.\n");
				return 1;
			}
			char* insert_text = argv[4];
			if ((strlen(argv[3]) == 2) && (argv[3][0] == '-') && ((argv[3][1] == 'f') || (argv[3][1] == 'b')))
			{
				if (argv[3][1] =='f')
				{
 					insert_text_front(input_file, insert_text);
				}
				else
				{
					insert_text_end(input_file, insert_text);
				}
			}
			else
			{
				printf("Некорректный 3 аргумент (Допускается использование флагов -f, -b)\n");
				return 1;
			}
		}
		else if (argv[2][1] == 'r')
		{
			if (argc != 5)
			{
				printf("Некорректное число аргументов.\n");
				return 1;
			}
			char* old_str = argv[3];
			char* new_str = argv[4];
			replace_str(input_file, old_str, new_str);


		}

		
	}
	else
	{
		printf("Некорректный 2 аргумент (Допускается использование флагов -i, -d, -r)\n");
		return 1;
	}

}
