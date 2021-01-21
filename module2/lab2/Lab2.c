/*Упакованная строка, содержащая символьное представление длинных целых чисел. Все символы строки, кроме цифр, помещаются в последовательность в исходном виде. Последовательность цифр преобразуется в целую переменную, которая записывается в упакованную строку, предваренная символом \1. Конец строки - символ \0. Пример
-исходная строка: "aa0x24FFbbb0xAA65"

-упакованная строка: 'a' 'a''\0' 0x24FF 'b' 'b' 'b' '\0' 0xAA65 '\0' '\0'*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 30
void getData(char * str)
{
    printf("Введите последовательность(не более %d) буквенно-числовых символов:\n", LEN - 1);
    fgets(str, LEN, stdin);
}
void strPack(char * str)
{
    char packstr[256] = "3";//строка для упаковки
    char *num;
    num = packstr;
    while (1) {
        if ((*str)=='\n') {
        *num = '\\0';
        num++;
        break;

        }

    if ((*str) == '0') {
        str++;
        if ((*str) == 'x') {
                *num = '\1';
                num++;
                str--;
                for (int i = 0;i < 6;i++) {
                    *num = *str;
                    num++;
                    str++;
                    }

        }
        else {
                str--;
                *num = *str;
                num++;
                str++;
                }

    }
    else {
        *num = *str;
        num++;
        str++;
    }

    }
    num = packstr;
    while (1) {
        if ((*num) == '\1') {
            num++;
            for (int i = 0;i < 6;i++)
                {
                    printf("%c", *num);
                    num++;
                }

            }
        else {
            printf("'%c'", *num);
            num++;
            }
    if (!*num) {

        break;
        }
    }

}
int main()
{
    char str[LEN];
    getData(str);
    strPack(str);
    printf("Hello");
    return 0;
}
