#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>

#include <unistd.h>

#include <stdio.h>

int main(int argc, char **argv)

{

struct {

long mestype; 

long mes;

} messageto; // отправляемое сообщение

struct { 

long mestype; 
char mes[100];

} messagefrom; // полученный ответ

key_t key;

int mesid;

long pid = getpid();

key = ftok("file", 'r');

mesid = msgget(key, 0); // подключаемся к очереди

messageto.mestype = 1; // устанавливаем тип сообщения

messageto.mes = pid; // записываем идентификатор процесса

msgsnd (mesid, &messageto, sizeof(messageto), 0); // отправка серверу, устанавливаем флаг 0 для корректной работы

while ( msgrcv (mesid, &messagefrom, sizeof(messagefrom), pid, 0) <= 0);// пока не обнаружится ошибка получаем сообщения из очереди с типом, совпадающим с клиентом

/*прием сообщения */

printf("%s\n", messagefrom.mes);   // вывод полученного сообщения

return 0;

}
