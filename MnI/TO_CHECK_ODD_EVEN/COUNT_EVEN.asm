MVI C,00H //Count of even numbers
MVI D,0AH //Numbers in array
LXI H,2000H // starting address of array where we store first element
//--------------------
LOOP1:  MOV A,M   //We store element in accumulator
               RAR //This is the most imortant instruction to check odd/even
               JC LABLE1
               INR C
               LABLE1: INX H
                               DCR D
                               JNZ LOOP1
                               MOV A,C
                               STA 3000H //We store our count at 3000H
HLT