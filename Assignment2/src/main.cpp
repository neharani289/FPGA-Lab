#include <Arduino.h>

#define A 2
#define B 3
#define NAND_Sum 12

//variables 

int a , b , HA_Sum, HA_Carry , nand_sum,nand_carry ;

//Function for 2 input NAND Gate

int NAND(int i1, int i2)
{
        return !(i1&&i2);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(NAND_Sum,OUTPUT);
  pinMode(A,INPUT);
  pinMode(B,INPUT);

  // put your setup code here, to run once:
}

void loop() {
  a=digitalRead(A);
  b=digitalRead(B);
  HA_Sum = a^b;
  HA_Carry = a&b;

  nand_sum = NAND(NAND(NAND(a,b),a),NAND(NAND(a,b),b));
  nand_carry = NAND(NAND(a,b),NAND(a,b));

  if(HA_Sum==1)
          digitalWrite(LED_BUILTIN,HIGH);
  else
          digitalWrite(LED_BUILTIN,LOW);
  if(nand_sum==1)
          digitalWrite(NAND_Sum,HIGH);
  else
          digitalWrite(NAND_Sum,LOW);

}

