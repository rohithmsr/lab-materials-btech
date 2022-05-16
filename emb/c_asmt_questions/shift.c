#include<reg51.h>

void Delay(unsigned int);

void main(void){
	unsigned char z;
	unsigned char y;
	unsigned char x;
	
	while(1){
		z=P2;
		
		y=z&0x3;
		
		switch(y){
			case 0:{
				P1=~P1;
				break;
			}
			case 1:{
				P1=P0;
				break;
			}
			
			case 2:{
			
				x=P1;
				P1=(x<<1)|(x>>7);
				break;
			}
			case 3:{
				x=P1;
				P1=(x>>1)|(x<<7);
				break;
			}
		}
		
		Delay(1000);
	}
}

void Delay(unsigned int k){
	
	unsigned int i,j;
	for(i=0;i<k;i++)
	   for(j=0;j<1844;j++);
}
