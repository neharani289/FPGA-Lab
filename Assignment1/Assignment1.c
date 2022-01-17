#include <stdio.h>

//2-input NAND gate
unsigned int NAND (unsigned int A, unsigned int B) {
    return !(A & B);    
}

int main()
{
    //Binary inputs for half adder
    unsigned int A=0x00, B=0x00, n; 
    
    //Variables for output sum and carry
    unsigned int mask = 0x01;
    unsigned int sum,carry,nand_sum, nand_carry;
    printf("---------------------------------------------------- \n");
    printf("                                |  Using_NAND_only |  \n");
    printf("----------------------------------------------------  \n");
    printf("Binary_Input  |  Sum   | Carry  |  Sum  |  Carry   | \n");
    printf("----------------------------------------------------  \n");
    
    for (n = 0x00; n<0x04; n++)              
    {
        //Binary inputs
        A = n>>1;    
        B = n>>0;    

        //Using expression of sum and carry
        sum = A ^ B;
        carry = A & B;
        
        //verifying the expression obtained by 2-input nand gates only.
        nand_sum = NAND( NAND( NAND( A, B ), A ), NAND( NAND( A, B ), B ) );
        nand_carry = NAND( NAND( A, B ),NAND( A, B ) );
        
        //Printing the results.
        printf("    %x  %x          %x        %x        %x        %x\n", mask&A, mask&B, mask&sum, mask&carry, nand_sum, nand_carry);
    }
    printf("----------------------------------------------------  \n");
    return 0;
}
