#include <avr/io.h>
#include <util/delay.h>
void wait()
{
//int i;
//for(i=0;i<100;i++)
//{
	_delay_ms(100);

}
void forward();
void backward();
void main()
{
	//setup port D pin 4,5 as output for motor a and 6,7 as output for motor b.
	DDRD = 0xf0;
	while(1)
	{
		//clockwise
		forward();
		//PORTD=0b00010000;
		wait();
		//stop
		PORTD = 0x00;
		//anti clockwise
		backward();
		//PORTD=0b00100000;
		wait();
		//stop
		PORTD=0x00;
		wait();
	}
}
void forward()
{
	PORTD = 0b01010000;
}
void backward()
{
	PORTD = 0b10100000;
}
