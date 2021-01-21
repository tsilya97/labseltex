#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
int main(){
 void *map = mmap(NULL, sysconf(_SC_PAGESIZE), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
struct locks {sem_t l1;sem_t l2;} *locks = (struct locks *)map;
sem_t l1;
sem_t l2;
int fd[2], result;
size_t size;
char resstring[14];
sem_init(&locks->l1, 1, 0);     //Инициализация семафоров
sem_init(&locks->l2, 1, 0);

/* Попытаемся создать pipe */

if(pipe(fd) < 0){

/* Если создать pipe не удалось, печатаем об этом сообщение и прекращаем работу */

printf("Can\'t create pipe\n");
exit(-1);
}

/* Порождаем новый процесс */

result = fork();

if(result <0){

/* Если создать процесс не удалось, сообщаем об этом и завершаем работу */

printf("Can\'t fork child\n");
exit(-1);

} else if (result > 0) {
while (1) {               // если это родитель
            
printf("give string parrent\n");
            fgets(resstring,14, stdin);  // ждет ввода строки для передачи
            write(fd[1], resstring, 14);  // записывает в пайп полученную строку
            
            sem_post(&locks->l2);  // семафор дает разрешение потомку
 
            sem_wait(&locks->l1);   // семафор ждет разрешения от потомка
           
size = read(fd[0], resstring, 14); 

if(size < 0){       

/* Если прочитать не смогли, сообщаем об ошибке и завершаем работу */

printf("Can\'t read string\n");
exit(-1);
}
            printf("parrent-child say: ");
             printf("%s\n",resstring);   // печатаем строку полученную от потомка

            
        }
/* Мы находимся в родительском процессе, который будет передавать введеную информацию процессу-ребенку . */





} else {
 while (1) {
            sem_wait(&locks->l2); // ждет сигнала от родителя

size = read(fd[0], resstring, 14);

if(size < 0){

/* Если прочитать не смогли, сообщаем об ошибке и завершаем работу */

printf("Can\'t read string\n");
exit(-1);
}
  printf("child-parrent say: ");
             printf("%s\n",resstring);// печатает строку от родителя
             printf("give string Child\n");
            fgets(resstring,14, stdin); // получает строку на отправление от пользователя
            write(fd[1], resstring, 1); // записываем в пайп 
           
            sem_post(&locks->l1); // даем сигнал родителю
        }



/* Закрываем входной поток и завершаем работу */

}
sleep (5);
return 0;
}
