.include "m328Pdef.inc"

	ldi r17, 0b11110011 ; input pin 2,3
	out DDRD,r17		; declaring pins as input
Start:

	in r17,PIND

	
	ldi r20, 0b00000010 ; counter set to 2
	rcall loopin
	
	ldi r21,0b00000001	; mask 
	
	; read pin 2 
	mov r18, r17		
	and r18,r21 		; a
	
	; read pin 3
	lsr r17
	mov r19, r17
	and r19, r21 		; b
	
	mov r23, r18
	mov r22, r19
	eor r22, r23  		; sum = a^b
	
	and r18, r19		; carry = a.b
	
	
	
	ldi r20, 0b00000101
	rcall loopout1

	ldi r16, 0b00110000 
	out DDRB,r16		;set pin 13 as output
	
	ldi r20, 0b00000100
	rcall loopout2
	
	or r18, r22
	
	out PORTB, r18

	rjmp Start
	
	
loopin: lsr r17
	dec r20
	brne loopin
	ret
loopout1: lsl r22
	 dec r20
	 brne loopout1
	 ret
loopout2: lsl r18
	 dec r20
	 brne loopout2
	 ret
