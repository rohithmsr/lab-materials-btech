#include<reg51.h>

unsigned char two_four_two_one[10][4] = 
 {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
unsigned char eight_four_two_one[10][4] = 
 {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1}};
unsigned int i, j;
	 
sbit one = P2^0;
sbit two = P2^1;
sbit three = P2^2;
sbit four = P2^3;
	
void delay();
void display8421(int temp);
void display2421(int temp);

void main(){
	unsigned char val;
	P0 = 0xFF;
	P2 = 0x00;
	
	while(1){
		val = P0;
		
		if(val < 100){
			display2421(val);
		}
		else{
			display8421(val);
		}
	}
}

void delay(){
	TMOD = 0x01;    // Timer 0 Mode 1
  TH0= 0xFC;     //initial value for 1ms
  TL0 = 0x66;
  TR0 = 1;     // timer start
  while (TF0 == 0); // check overflow condition
  TR0 = 0;    // Stop Timer
  TF0 = 0;   // Clear flag
}

void display8421(int temp){
	unsigned int rev = 0;
	
	while(temp != 0){
		rev += temp % 10;
		rev *= 10;
		temp /= 10;
	}
	rev /= 10;
	
	while(rev != 0){
		i = rev % 10;
		one=eight_four_two_one[i][3];
		delay();
		two=eight_four_two_one[i][2];
		delay();
		three=eight_four_two_one[i][1];
		delay();
		four=eight_four_two_one[i][0];
		delay();
		
		rev /= 10;
	}
}

void display2421(int temp){
	unsigned int rev = 0;
	
	while(temp != 0){
		rev += temp % 10;
		rev *= 10;
		temp /= 10;
	}
	rev /= 10;
	
	while(rev != 0){
		i = rev % 10;
		one=two_four_two_one[i][3];
		delay();
		two=two_four_two_one[i][2];
		delay();
		three=two_four_two_one[i][1];
		delay();
		four=two_four_two_one[i][0];
		delay();
		
		rev /= 10;
	}
}