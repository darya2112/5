#include <mbed.h>                       //Библиотека для работы с Mbed OS
#include <ThisThread.h>                 //Библиотека для временной задержки
#include <Thread.h>                     //Библиотека для потоков


DigitalOut greenLed(LED4);              //Объявили пины микроконтроллера STM32F407
DigitalOut redLed(LED5);                
DigitalOut orangeLed(LED3);             
DigitalOut blueLed(LED6); 

DigitalOut externalLed(PD_11);          //Внешний светодиод. Сконфигурировали вывод PD11 для подключения к макетной плате

Thread thr;                             //Объявили объект потока под названием "thr"

void dowork()                           //Функция "dowork" выполняется в потоке "thr"
{
  for (int i=0;i<20;i++)                //10 раз включаем и 10 раз выключаем светодиод в потоке параллельно основному потоку цикла while
  {
    externalLed=!externalLed;           //Изменение состояния внешнего светодиода - вкл/выкл 10 раз 
    ThisThread::sleep_for(1000);        //Временная задержка 1с
 }
}

int main() 
{
thr.start(dowork);                      //начало исполнения функции "dowork" потока "thr"

    while(1) 
    {                                   

        greenLed=!greenLed;             //Изменение состояния четырех светодиодов на плате - вкл/выкл
        redLed=!redLed;
        orangeLed=!orangeLed;
        blueLed=!blueLed;

        ThisThread::sleep_for(1000);    //Временная задержка 1с
    }
}
