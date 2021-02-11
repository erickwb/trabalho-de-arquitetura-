
#include <stdio.h>
#include <stdlib.h>
#include "heade.h"

void ConvertChar(char vet[]){
    int i;
    for (i = 0; i < 4; i++){
        //caso seja de 0 a 9
        if((vet[i] >= '0') && (vet[i] <= '9')){
            vet[i] = vet[i] - '0'; //operacao para trasforma de char p/ int
        }
        //caso seja de a - f
        if((vet[i] >= 'a') && (vet[i] <= 'f')){
            vet[i] = vet[i] - 'W'; //operacao para trasforma de char p/ int

        }
        else if (vet[i] > 'f'){ //corrigir tal caso
            printf("O digito invalido, digite um digito em hexadecimal\n");
        }
    

    }

}


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
        fprintf(file2,"#:%d", imediato);
        fprintf(file2," LM:%d", registrador_origem);
        fprintf(file2," LD:%d", registrador_destino);
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
    fprintf(file2,"#:%d", imediato);
    fprintf(file2," LM:%d", registrador_origem);
    fprintf(file2," LD:%d", registrador_destino);
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
    fprintf(file2,"#:%d", imediato);
    fprintf(file2," LM:%d", registrador_origem);
    fprintf(file2," LD:%d", registrador_destino);
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
    fprintf(file2,"#:%d", LM);
    fprintf(file2," LN:%d", LN);
    fprintf(file2," LD:%d", registrador_destino);
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
    fprintf(file2,"#:%d", LM);
    fprintf(file2," LN:%d", LN);
    fprintf(file2," LD:%d", registrador_destino);
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
    fprintf(file2,"#:%d", imediado);
    fprintf(file2," LN:%d", LN);
    fprintf(file2," LD:%d", registrador_destino);
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
    fprintf(file2,"#:%d", imediado);
    fprintf(file2," LN:%d", LN);
    fprintf(file2," LD:%d", registrador_destino);
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
    fprintf(file2," Ld_LN:%d", LD_LN);
    fprintf(file2,"#:%d", imediado);
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
    fprintf(file2," Ld_LN:%d", LD_LN);
    fprintf(file2,"#:%d", imediado);
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
    fprintf(file2," LD:%d", LD);
    fprintf(file2,"#:%d", imediado);
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
    fprintf(file2," LD:%d", LD);
    fprintf(file2,"#:%d", imediado);
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
        
    fprintf(file2," LM_LS:%d", LM_LS);
    fprintf(file2," LD:%d", registrador_destino);
    fclose(file2);

}




//parametros: vetor de char, arquivo de destino
void Decodifica(char vet[], FILE *file2){

    //primeiro digito = 4bits primeiros da instruçao thumb
    switch (vet[0]){
    case 0:
        if((vet[1] >> 3) == 0){
            //caso LSL
            LSL(vet, file2);
            
        }
        if((vet[1] >> 3) == 1){
            //caso LSR
            LSR(vet, file2);
            
        }     
        break;
    
     case 1:
        //instruçao ASR
        if((vet[1] >> 3) == 0){
            ASR(vet, file2);
        }
        //instruçoes ADD / SUB com LM
        if ((vet[1] >> 1) == 4 ){
            //instruçao ADD com LM
            ADD_com_LM(vet, file2);

        }
        if ((vet[1] >> 1) == 5 ){
            //instruçao SUB com LM
            SUB_com_LM(vet, file2);

        }
        //instrução ADD/SUB imediado de 3bits
        if ((vet[1] >> 1) == 6 ){
            ADD_com_imediato3(vet, file2);

        }
        if ((vet[1] >> 1) == 7 ){
            //instruçao SUB com imediado
            SUB_com_imdeiado3(vet, file2);

        }

        break;
    
     case 2:
        //Instruçoes MOV/ CMP com imediado de 8bits 
        if ((vet[1] >> 3) == 0){
            MOV_com_imediado8(vet, file2);

        }
        if ((vet[1] >> 3) == 1){
            CMP_com_imediado8(vet,file2);
        }
       
        break;
    
     case 3:
     //instrução ADD/ SUB com imediado de 8 bits
      if ((vet[1] >> 3) == 0){
            ADD_com_imediado8(vet, file2);

        }
        if ((vet[1] >> 3) == 1){
            SUB_com_imediado8(vet,file2);
        }
        
        break;
    
     case 4:
     /**instruçoes AND | EOR | LSL | LSR |ASR | ADC | SBC | ROR| TST | NEG | CMP | CMN | ORR | MUL | BIC | MVN
        CPY Ld, Lm |ADD | MOV Ld, Hm| ADD | MOV Hd, Lm| ADD | MOV Hd, Hm|CMP|CMP|CMP|BX | BLX |LDR Ld, [pc, #immed*4]*/

        if (vet[1]  == 0){
            //instruçoes AND | EOR | LSL | LSR 
            if((vet[2] & 12) == 0){
                //instruçao AND
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nADD ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            } 
            if((vet[2] & 12) == 4){
                //instrução EOR
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nEOR ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 8){
                //instrução LSL
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nLSL ");
                fclose(file2);
               AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 12){
                //instrução LSR
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nLSR ");
                fclose(file2);
               AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
        }
        if (vet[1] == 1){
            //instruçoes ASR | ADC | SBC | ROR
            if((vet[2] & 12) == 0){
                 //instrução ASR
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nASR ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);

            }
            if((vet[2] & 12) == 4){
                 //instrução ADC
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nADC ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 8){
                 //instrução SBC
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nSBC ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 12){
                 //instrução ROR
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nROR ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }

        }
        if (vet[1] == 2){
            //instruçoes TST | NEG | CMP | CMN |
            if((vet[2] & 12) == 0){
                 //instrução TST
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nTST ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);

            }
            if((vet[2] & 12) == 4){
                 //instrução NEG
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nNEG ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 8){
                 //instrução CMP
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nCMP ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 12){
                 //instrução CMN
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nCMN ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }

        }
        if (vet[1] == 3){
            //instruçoes ORR | MUL | BIC | MVN
            if((vet[2] & 12) == 0){
                 //instrução ORR
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nORR ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);

            }
            if((vet[2] & 12) == 4){
                 //instrução NEG
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nMUL ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 8){
                 //instrução CMP
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nBIC ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
            if((vet[2] & 12) == 12){
                 //instrução CMN
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nMVN ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);
            }
        }
        if (vet[1] == 6){
            //INSTRUÇOES CPY Ld, Lm
            if((vet[2] & 12) == 0){
                 //instrução CPY 
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nCPY ");
                fclose(file2);
                AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(vet, file2);

            }
            
        }


        break;
    
     case 5:
        printf("caso o primeiro digito e 5");
        break;
    
     case 6:
        printf("caso o primeiro digito e 6");
        break;

     case 7:
        printf("caso o primeiro digito e 7");
        break;
    
     case 8:
        printf("caso o primeiro digito e 8");
        break;
    
    
    default:
        break;
    }


}

