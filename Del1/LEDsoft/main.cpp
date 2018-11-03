/*
 * LEDsoft.cpp
 *
 * Created: 03.11.2018 19.03.39
 * Author : Jennie Andersen
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

void Delay_ms(int n)	//lager en funksjon "Delay_ms" som kan brukes sammen med variabler 
{
	while (n--)		//true frem til n=0
	{
		_delay_ms(1);	//gir en konstant ved komplimentering, (det programmet vil ha)
	}
}
//denne funksjonen vil kalles s� mange ganger som variabelen tilsier. Dvs om "time_on" er 5ms, s� kalles funksjonen 5 ganger


int main(void)
{
DDRD |= (1<<3);				//setter output til PortD Pin3

const int PwmPeriod = 10;						//her defineres alle de konstante verdiene.
const int RampPeriod = 1000;					//dvs: om man skriver RampPeriod senere s� skriver man egentlig 1000.
const int RampSteps = RampPeriod/PwmPeriod;		//1000/10=100


	while(1)
	{
		int i = 0;
		i < RampSteps;		//i<100
		i++;			
		
		for(int i=0; i<RampSteps; i++)	//loop som starter med i=0, g�r til i<100 og adder �n per runde (i++)
		{
			int time_on = (i*PwmPeriod) / RampSteps; //samme som: map(i, 0, RampSteps, 0 PwmPeriod);	
			int time_off = PwmPeriod-time_on;
			//time_on:	(i*10)/100   resulterer i at "time_on" vil bli st�rre for hver runde frem til   max (100*10)/100= 10 ms
			//time_off:	10-((i*10)/100   g�r til   10-((100*10))/100= 0ms 
			//dvs: "time_on" g�r fra 0-10ms mens "time_off" g�r fra 10-0ms
			
			PORTD |= (1<<3);		//setter D3 til H�Y
			Delay_ms(time_on);								//kaller funksjonen "Delay_ms" og bruker variabelen "time_on" til � definere antall ganger funksjonens loop kj�rer
			PORTD ^= (1<<3);		//setter D3 til LOW
			Delay_ms(time_off);
		}
		
		for(int i=0; i<RampSteps; i++)
		{
			int time_off = (i*PwmPeriod) / RampSteps;	
			int time_on = PwmPeriod-time_off;
			//samme greia bare motsatt, her g�r "time_on" fra 10-0ms mens "time_off" g�r fra 0-10ms
			
			PORTD |= (1<<3);
			Delay_ms(time_on);
			PORTD ^= (1<<3);
			Delay_ms(time_off);
		}
}
}
