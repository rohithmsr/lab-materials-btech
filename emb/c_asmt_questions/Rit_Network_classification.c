#include<reg51.h>

void serial0() interrupt 4{
	
	if(TI)
	   TI=0;
}

void main(void){
	unsigned char z;
	TMOD=0x20;
	TH1=0xFA;
	SCON=0x50;
	TR1=1;
	IE=0x90;
	
	z=P3;
	
	if((z & 0x80)==0){   //10000000
		SBUF='A';
	}
	else if((z & 0x40)==0){ //0100 0000
		SBUF='B';
	}
	else if((z & 0x20)==0){    //00100000
		SBUF='C';
	}
	else if((z & 0x10)==0){     //00010000
		SBUF='D';
	}
	else{
		SBUF='E';
	}
	
	while(1);
}