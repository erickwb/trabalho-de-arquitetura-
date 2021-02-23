
#include <stdio.h>
#include <stdlib.h>
#include "heade.h"


void LSL(char vet[], FILE *file2){
    //printf("caso LSL\n");
        int imediato = 0; 
        imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
        //deslocado 2 vez para <-
        imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
        
        int registrador_origem = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
        registrador_origem = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
        registrador_origem = (registrador_origem | (vet[3] & 8)) >> 3;
        int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
        //adicionando no arquivo de destino 
        file2 = fopen("output.txt", "a");
        fprintf(file2,"\nLSL ");
        fprintf(file2,"r%d ,", registrador_origem);
        fprintf(file2,"r%d ,", registrador_destino);
        fprintf(file2,"#%d", imediato);
        fclose(file2);

}

void LSR(char vet[], FILE *file2){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
    //deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int registrador_origem = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    registrador_origem = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    registrador_origem = (registrador_origem | (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nLSR ");
    fprintf(file2,"r%d ,", registrador_origem);
    fprintf(file2,"r%d ,", registrador_destino);
    fprintf(file2,"#%d", imediato);
    fclose(file2);




}

void ASR(char vet[], FILE *file2){

    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
    //deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int registrador_origem = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    registrador_origem = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    registrador_origem = (registrador_origem | (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nASR ");
    
    fprintf(file2,"r%d ,", registrador_origem);
    fprintf(file2,"r%d ,", registrador_destino);
    fprintf(file2,"%d", imediato);
    fclose(file2);

}
void ADD_com_LM(char vet[], FILE *file2){

    int LM = 0;
    LM = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do LM
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do LM
    //Assim teremos os 3 bits do LM
    LM = LM | ((vet[2] & 12) >> 2);
    int LN = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    LN = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    LN = (LN| (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nADD ");
    fprintf(file2,"r%d ,", LN);
    fprintf(file2,"r%d ,", registrador_destino);
    fprintf(file2,"r%d ", LM);
    fclose(file2);

}
void SUB_com_LM(char vet[], FILE *file2){
    int LM = 0;
    LM = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do LM
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do LM
    //Assim teremos os 3 bits do LM
    LM = LM | ((vet[2] & 12) >> 2);
    int LN = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    LN = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    LN = (LN| (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nSUB ");
    
    fprintf(file2,"r%d ,", LN);
    fprintf(file2,"r%d ," , registrador_destino);
    fprintf(file2,"r%d", LM);
    fclose(file2);

}
void ADD_com_imediato3(char vet[], FILE *file2){
    int imediado = 0; //imediado de 3 bit
    imediado = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do imediado
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do imediado
    //Assim teremos os 3 bits do imediado
    imediado = imediado | ((vet[2] & 12) >> 2);
    int LN = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    LN = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    LN = (LN| (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nADD ");
    fprintf(file2,"r%d ,", LN);
    fprintf(file2,"r%d ,", registrador_destino);
    fprintf(file2,"#%d", imediado);
    fclose(file2);

}
void SUB_com_imdeiado3(char vet[], FILE *file2){
    int imediado = 0; //imediado de 3 bit
    imediado = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do imediado
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do imediado
    //Assim teremos os 3 bits do imediado
    imediado = imediado | ((vet[2] & 12) >> 2);
    int LN = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    LN = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    LN = (LN| (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nSUB ");
    fprintf(file2,"r%d ,", LN);
    fprintf(file2,"r%d ,", registrador_destino);
    fprintf(file2,"#%d", imediado);
    fclose(file2);

}
void MOV_com_imediado8(char vet[], FILE *file2){

    int LD_LN = 0;
    LD_LN = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediado = 0;
    imediado = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediado = imediado |(vet[3] & 15);

    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nMOV ");
    fprintf(file2,"r%d ,", LD_LN);
    fprintf(file2,"#%d", imediado);
    fclose(file2);

}
void CMP_com_imediado8(char vet[], FILE *file2){
    int LD_LN = 0;
    LD_LN = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediado = 0;
    imediado = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediado = imediado |(vet[3] & 15);
    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nCMP ");
    fprintf(file2,"r%d ,", LD_LN);
    fprintf(file2,"#%d", imediado);
    fclose(file2);

}
void ADD_com_imediado8(char vet[], FILE *file2){
    int LD = 0;
    LD = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediado = 0;
    imediado = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediado = imediado |(vet[3] & 15);
    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nADD ");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"#%d", imediado);
    fclose(file2);

}
void SUB_com_imediado8(char vet[], FILE *file2){
    int LD = 0;
    LD = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediado = 0;
    imediado = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediado = imediado |(vet[3] & 15);

    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nSUB ");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"#%d", imediado);
    fclose(file2);
}

void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(char vet[], FILE *file2){
    
    int LM_LS = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    LM_LS = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    LM_LS = (LM_LS | (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
   // fprintf(file2,"\nADD ");
        
    fprintf(file2,"r%d ,", LM_LS);
    fprintf(file2,"r%d", registrador_destino);
    fclose(file2);

}




