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

UltraSonicDistanceSensor distanciaSonar(trigger, echo);

int infraEsq = digitalRead(infraE);
int infaDir = digitalRead(infraD);

int sonar = distanciaSonar.measureDistanceCM()


void setup()
{
  //Motores
  pinMode(motorEsquerdo1, OUTPUT);
  pinMode(motorEsquerdo2, OUTPUT);
  pinMode(motorDireito1, OUTPUT);
  pinMode(motorDireito2, OUTPUT);

  //Sensores infravermelhos
  pinMode(infraE, INPUT);
  pinMode(InfraD, INPUT);

  //Sensor UltraSonico
  pinMode(trigger, INPUT);
  pinMode(echo, INPUT);
  
  //Comunicação por bps
  Serial.begin(9600);
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
  if(infraEsq && infraDir){
    if(sonar <= 40){
      frente();
    else(){
      giradaSonar();
    }
  else if(infraEsq){
    direita();
  }
  else if(infraDir){
    esquerda();
  }
  else{
    re();
    delay(1500);
    esquerda();
    delay(2000);
  }
    
}
