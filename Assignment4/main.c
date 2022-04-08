//Turns LED on and off as per half adder truth table
#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
  //Declaring the input ports	
  DDRD |= 0b11110011;		
  /* Arduino boards have a LED at PB5 */
  //set PB5, pin 13 of arduino as output
  DDRB    |= ((1 << DDB5));
  DDRB    |= ((1 << DDB4));
  
  //Taking variables for input and output
  int input, a, b, sum, carry;

  while (1) {
    input = PIND;

    a = (input & 0b00000100)>>2;
    b = (input & 0b00001000)>>3;

    sum = (a^b);
    carry = a && b;

    if(sum == 0 && carry == 0) {
          
      PORTB = 0b00000000;
    }
    else if (sum== 0 && carry == 1) {
      
      PORTB = 0b00010000;
    }
    
    else if(sum ==1 && carry == 0) {
        
      PORTB = 0b00100000;
    }
    else {
      
      PORTB = 0b00110000;
    }
  }
  /* . */
  return 0;
}
