MOV P2, #07H
MOV TMOD,#20H
MOV TH1, #0FAH
MOV SCON, #50H
SETB TR1
MOV R7,#00H
LCALL PRIME
CJNE R7, #01H, PRIMEGEN
MOV DPTR, #MYDATA





START:
Mov A,#00H
MOVC A, @A+DPTR
CJNE A, #'.', SEND
jmp $
SEND:
MOV SBUF, A
INC DPTR
SERIAL:
JNB TI, SERIAL
CLR TI
JMP START





JMP $





PRIME:
MOV A, P2
MOV B, #02H
DIV AB
MOV R0, A
CJNE R0, #01H, LABEL2
INC R7
RET





LABEL1:
DEC R0
CJNE R0, #01H, LABEL2
INC R7
RET





LABEL2:
MOV A, P2
MOV B, R0
DIV AB
MOV R5, B
CJNE R5, #00H, LABEL1
RET





PRIMEGEN:
INC P2
MOV R4, P2
LCALL PRIME
CJNE R7, #01H, PRIMEGEN
MOV R4, P2
JMP $





MYDATA: DB "HELLO."
