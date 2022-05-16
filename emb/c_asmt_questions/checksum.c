#include<reg51.h>

// for 5ms, get 1 segement till 3 segments
// generate checksum
// transmit checksum + payload to UART
// 5ms = 0xEE01 in the timer mode 0

void myDelay();
void myTx(unsigned char x);
void myTxBits(unsigned char x);

unsigned char seg1;
unsigned char seg2;
unsigned char seg3;
unsigned char csum;

void main(){
	// P1 = 0xFF;

	// P1 = 0x01;
	seg1 = P1;
	myTxBits(P1);
	myDelay();
	
	// P1 = 0x02;
	seg2 = P1;
	myTxBits(P1);
	myDelay();
	
	// P1 = 0x04;
	seg3 = P1;
	myTxBits(P1);
	myDelay();
		
	csum = seg1 + seg2 + seg3;
	csum = ~csum;
	myTxBits(csum);
	myDelay();

}

void myTx(unsigned char x){
	SBUF = x;
	while(TI == 0);
	TI = 0;
}

void myTxBits(unsigned char x){
	unsigned char bit0;
	unsigned char bit1;
	unsigned char bit2;
	unsigned char bit3;
	unsigned char bit4;
	unsigned char bit5;
	unsigned char bit6;
	unsigned char bit7;
	
	bit0 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	bit1 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	bit2 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	bit3 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	bit4 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	bit5 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	bit6 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	bit7 = x % 2 == 0 ? '0' : '1';
	x = x / 2;
	
	myTx(bit7);
	myTx(bit6);
	myTx(bit5);
	myTx(bit4);
	myTx(bit3);
	myTx(bit2);
	myTx(bit1);
	myTx(bit0);
	myTx(' ');
}

void myDelay() {
	TMOD = 0x01;    // Timer 0 Mode 1
  TH0 = 0xEE;     //initial value for 5ms
  TL0 = 0x01;
  TR0 = 1;     // timer start
  while (TF0 == 0); // check overflow condition
  TR0 = 0;    // Stop Timer
  TF0 = 0;   // Clear flag
 }