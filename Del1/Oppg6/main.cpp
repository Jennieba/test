/*
 * Oppg6.cpp
 *
 * Created: 03.11.2018 17.10.24
 * Author : Jennie Andersen
 */ 


//HUSK hk på OPG6 og "set as startup project"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

int main(void)
{
	DDRD |= (1<<3);	//HUSK å sette PortD Pin3 som output! ellers får man blink med liiite lys
	
	while(1)	//setter (1) for å indikere true/alltid
	{
		PORTD |= (1<<3);		//setter PortD, Pin3 som HIGH, ved å bruke en "OR" |, da vil D alltid være høy uansett hvilken port som assignes.
		_delay_ms(350);		//setter en delay på 350ms
		
		PORTD ^= (1<<3);		//setter PortD til LOW, ved på bruke en AND/OR (^)
		_delay_ms(1000);	//setter delay på 1000ms
	}
}


