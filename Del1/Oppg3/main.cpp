/*
 * Oppg3.cpp
 *
 * Created: 03.11.2018 17.01.31
 * Author : Jennie Andersen
 */ 

#include <avr/io.h>


int main(void)
{
	
	DDRD |= (1<<3);			//"The Port D Data Direction Register - read/write"	Setter PortD Pin3 som output. Flytter verdien 1, 3 plasser til venstre (<<).
							//N�r man skal velge av D portene, s� starter den som default p� D0, s� for � velge pin setter man hvor mange plasser den skal flytte p� seg.
							//her er det valgt Pin3, dermed (1<<_3_).
							//Ved � bruke |= sier vi med "or" at porten alltid er output uansett hvilken kommando som st�r etter
	
	PORTD |= (1<<3);		//"The Port D Data Register - read/write" Setter PortD som h�y og flytter denne h�yverdien til Pin3.
	
	return 0;
}

