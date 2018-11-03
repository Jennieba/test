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
							//Når man skal velge av D portene, så starter den som default på D0, så for å velge pin setter man hvor mange plasser den skal flytte på seg.
							//her er det valgt Pin3, dermed (1<<_3_).
							//Ved å bruke |= sier vi med "or" at porten alltid er output uansett hvilken kommando som står etter
	
	PORTD |= (1<<3);		//"The Port D Data Register - read/write" Setter PortD som høy og flytter denne høyverdien til Pin3.
	
	return 0;
}

