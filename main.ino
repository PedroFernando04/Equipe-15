// C++ code

//Motores
#define motorEsquerdo1 2
#define motorEsquerdo2 4
#define motorDireito1 12
#define motorDireito2 13

//Sensores infravermelhos
#define infraE 5
#define infraD 6

//Sensor UltraSonico
#include<HCSR04.h>
#define trigger 7
#define echo 8

UltraSonicDistanceSensor distanceSensor(trigger, echo);

void setup()
{
  pinMode(motorEsquerdo1, OUTPUT);
  pinMode(motorEsquerdo2, OUTPUT);
  pinMode(motorDireito1, OUTPUT);
  pinMode(motorDireito2, OUTPUT);

  pinMode(infraE, INPUT);
  pinMode(InfraD, INPUT);

  pinMode(trigger, INPUT);
  pinMode(echo, INPUT);
}

void motores(int e1,int e2,int d1,int d2)
{
 digitalWrite(motorEsquerdo1, e1);
 digitalWrite(motorEsquerdo2, e2);
 digitalWrite(motorDireito1, d1);
 digitalWrite(motorDireito2, d2);
           
}

void frente()
{
  motores(100,0,100,0);
}

void re(){
  motores(0,100,0,100);
}

void direita(){
  motores(100,0,0,100);
}

void esquerda(){
  motores(0,100,100,0);
}

void giradaSonar(){
  direita();
  delay(1000);
  esquerda();
  delay(1000);
}



void loop()
{
  /*incluir if de sensor infra
  frente();
  delay(1000); // Wait for 1000 millisecond(s)
  re();
  delay(1000); // Wait for 1000 millisecond(s)
 */
  
  /*incluir if do sonar
  giradaSonar();
  */
}
