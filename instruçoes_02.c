#include <stdio.h>
#include <stdlib.h>
#include "heade.h"

void ADD_MOV_com_HM_HD(char vet[], FILE *file2){

    int LD_HD = 0;

    LD_HD = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LM_HM = 0;
    LM_HM =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LM_HM = (LM_HM | (vet[3] & 8)) >> 3;

    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LD_HD);
    fprintf(file2,"r%d", LM_HM);
    fclose(file2);

}

void CMP(char vet[], FILE *file2){
    int LD_HD = 0;

    LD_HD = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LM_HM = 0;
    LM_HM =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LM_HM = (LM_HM | (vet[3] & 8)) >> 3;

    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2, "\n CMP ");
    fprintf(file2,"r%d ,", LD_HD);
    fprintf(file2,"r%d", LM_HM);
    fclose(file2);

}

void BX_BLX(char vet[], FILE *file2){
    
    int RM = 0; //4b
    RM = ((vet[3] & 8) >> 3); //pegando o ultimmo bit de ultimo numero e >> para o inicio 
    RM = RM | ((vet[2] & 7) << 1); //pegando os 3 ultimos bits do terceiro numero e adicionando com 'ou' ultimo bit

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ", RM);
    fclose(file2);
}

void LDR_com_imediado8(char vet[], FILE *file2) {
    int imediado = 0;
    //pegando os 8 primeiros bits, no terceiro e quarto numero
    imediado = ((vet[2] & 15) << 4); 
    imediado = imediado |(vet[3] & 15);

    int LD = 0;
    LD = (vet[1] & 7); // 3 bits do segundo numero
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2, "\nLDR ");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"[pc, #%d]", imediado);
    fclose(file2);

}

void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(char vet[], FILE *file2){
    
    int LD = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LN = 0;
    LN =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LN = (LN | (vet[3] & 8)) >> 3;

    int LM = 0;
    LM = ((vet[2] & 7) << 1);
    LM = LM | ((vet[2] & 8) >> 3); 


    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d,  ", LM);
    fprintf(file2,"r%d, ", LN);
    fprintf(file2,"r%d ", LD);
    fclose(file2);
}


//////////revisar todas as essas funçoes (prints)  e testes 


void STR_LDR_com_Ln_immed_x4(char vet[], FILE *file2){
    int LD = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LN = 0;
    LN =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LN = (LN | (vet[3] & 8)) >> 3;

    int imediato = 0;
    imediato = ((vet[1] & 7) << 2);
    imediato = imediato | ((vet[2] & 12) >> 2);
    imediato = imediato * 4;
    

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"[r%d, ", LN);
    fprintf(file2," #imediado%d]", imediato);
    fclose(file2);

}

void STRB_LDRB_com_ln_imediado(char vet[], FILE *file2){
    int LD = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LN = 0;
    LN =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LN = (LN | (vet[3] & 8)) >> 3;

    int imediato = 0;
    imediato = ((vet[1] & 7) << 2);
    imediato = imediato | ((vet[2] & 12) >> 2);
    

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"[r%d, ", LN);
    fprintf(file2," #imediado%d]", imediato);
    fclose(file2);

}
void STRH_LDRH_com_Ln_immed_x2(char vet[], FILE *file2){
    
    int LD = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LN = 0;
    LN =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LN = (LN | (vet[3] & 8)) >> 3;

    int imediato = 0;
    imediato = ((vet[1] & 7) << 2);
    imediato = imediato | ((vet[2] & 12) >> 2);
    imediato = imediato * 2;
    

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"[r%d, ", LN);
    fprintf(file2," #imediado%d]", imediato);
    fclose(file2);

}

void STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(char vet[], FILE *file2){
    //concerta ADD prints 
    int LD = 0;
    LD = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediado = 0;
    imediado = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediado = imediado |(vet[3] & 15);

    imediado = imediado * 4;
    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"[sp ,#%d]", imediado);
    fclose(file2);

}
void ADD_Ld_pc_immed_x4(char vet[], FILE *file2){
    int LD = 0;
    LD = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediado = 0;
    imediado = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediado = imediado |(vet[3] & 15);

    imediado = imediado * 4;
    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"pc ,#%d", imediado);
    fclose(file2);

}

void ADD_Ld_sp_immed_x4(char vet[], FILE *file2){
    int LD = 0;
    LD = (vet[1] & 7); //descobrindo os 3 primeiros bits do segundo digito

    int imediado = 0;
    imediado = ((vet[2] & 15) << 4); //bits do 8 primeiros bits
    imediado = imediado |(vet[3] & 15);

    imediado = imediado * 4;
    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LD);
    fprintf(file2,"sp ,#%d", imediado);
    fclose(file2);

}

void ADD_SUB_com_sp_imediato7(char vet[], FILE *file2){

    int imediado = 0;
    imediado = ((vet[2] & 7) << 4);

    imediado = imediado | (vet[3]); //pegando os ultimos 7bits

    imediado = imediado * 4;

    //adicionando no arquivo de destino 
    
    file2 = fopen("output.txt", "a");
    fprintf(file2,"sp, ");
    fprintf(file2,"#%d", imediado);
    fclose(file2);


}
void SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(char vet[], FILE *file2){
    int LD = (vet[3] & 7); //3 primeiros bits do quarto digito ;

    int LM = 0;
    LM =((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
    LM = (LM | (vet[3] & 8)) >> 3;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d ,", LM);
    fprintf(file2,"r%d", LD);
    fclose(file2);

    
}
void PUSH_POP(char vet[], FILE *file2){

    int r1, r2 = 0;

    r1 = vet[3];
    r2 = vet[2];

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"r%d} ", r2);
    fprintf(file2,"{r%d ,", r1);
    fclose(file2);


}
void BKPT(char vet[], FILE *file2){
    int imediato = 0;

    imediato = (vet[2] << 4);
    imediato = imediato | vet[3];

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nBKPT ");
    fprintf(file2,"#%d ",imediato );
    fclose(file2);


}
void STMIA_LDMIA (char vet[], FILE *file2){
    int ln = 0;
    int r1 = 0;
    int r2 = 0;

    r1 = vet[3];
    r2 = vet[2];

    ln = (vet[1] & 7);

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"%d!, ", ln);
    fprintf(file2,"{r%d, ", r2);
    fprintf(file2,"r%d}", r1);
    fclose(file2);

}
void SWI_immed8(char vet[], FILE *file2){
    int imediato = 0;
    imediato = (vet[2] << 4);
    imediato = imediato | vet[3];

    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nSWI");
    fprintf(file2,"#%d ",imediato );
    fclose(file2);

}

