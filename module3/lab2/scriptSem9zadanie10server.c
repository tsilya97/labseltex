#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/msg.h>

int main()
{ 
struct {

long mestype;

char mes [100];

} messageto; //структура для полученного сообщения от клиента
struct {

long mestype;

long mes;

} messagefrom;// структура сообщения, отправляемого клиенту

key_t key;  // Ipc ключ

int mesid;

key = ftok("file",'r');

mesid = msgget (key, 0666 | IPC_CREAT); // создаем очередь и получаем идентификатор очереди

while(1)

{

if (msgrcv(mesid, &messagefrom, sizeof(messagefrom), 1, 0) <= 0) continue;

messageto.mestype = messagefrom.mes;  // получаем pid клиента из полученного сообщения и записываем его в тип сообщения ответа

strcpy( messageto.mes, "Otpravka klientu");

msgsnd (mesid, &messageto, sizeof(messageto), 0);   // отправка сообщения- ответа клиенту

}

msgctl (mesid, IPC_RMID, 0); // удаляем очередь

return 0;

}
