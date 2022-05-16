#include<reg51.h>

unsigned char mydata;
unsigned char flag = '0';
unsigned int num1 = 0;
unsigned int num2 = 0;
int res = 0;
unsigned char op = '+';

void myTx(unsigned char x);
void myTxNum(unsigned int x);
void myRx();

void main(){
	TMOD = 0x20;
	SCON = 0x50;
	TH1 = 0xFA;
	TR1 = 1;
	
	while(mydata != '='){
		myRx();
		
		if(mydata != '+' && mydata != '-' && mydata != '*' && mydata != '/' && mydata != '='){
			if(flag == '0'){
				num1 += (mydata - '0');
				num1 *= 10;
			}
			else if(flag == '1'){
				num2 += (mydata - '0');
				num2 *= 10;
			}
		}
		else if(mydata != '='){
			flag = '1';
			op = mydata;
		}
		
		myTx(mydata);
	}
	
	switch(op) {
		case '+':
			res = num1 + num2; break;
		case '-':
			res = num1 - num2; break;
		case '*':
			res = num1 * num2; break;
		case '/':
			res = num1 / num2; break;
		default:
			break;
	}
	
	myTxNum(res);
	myTx('\n');
	myTx('E');
	myTx('N');
	myTx('D');
}


void myTx(unsigned char x){
	SBUF = x;
	while(TI == 0);
	TI = 0;
}

void myTxNum(int temp){
	unsigned int rev = 0;
	
	if(temp < 0){
		temp *= -1;
		myTx('-');
	}
	
	while(temp != 0){
		rev += temp % 10;
		rev *= 10;
		temp /= 10;
	}
	rev /= 10;
	
	while(rev != 0){
		myTx(rev % 10 + '0');
		rev /= 10;
	}
}

void myRx(){
	RI = 0;
	while(RI == 0);
	mydata = SBUF;
}