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
        if(vet[1] == 4){
            //instruçao ADD  Ld, Hm
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nADD ");
            fclose(file2);

            ADD_MOV_com_HM_HD(vet, file2);

        }
        if((vet[1] == 6) && ((vet[2] & 12) == 4)){
            //instruçao  MOV Ld, Hm
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nMOV ");
            fclose(file2);

            ADD_MOV_com_HM_HD(vet, file2);

        }
        if((vet[1] == 4) && ((vet[2] & 12) == 8)){
            //instruçao ADD Hd, Lm
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nADD ");
            fclose(file2);

            ADD_MOV_com_HM_HD(vet, file2);

        }
        if((vet[1] == 6) && ((vet[2] & 12) == 8)){
            //instruçao  MOV Hd, Lm
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nMOV ");
            fclose(file2);

            ADD_MOV_com_HM_HD(vet, file2);

        }
        if((vet[1] == 4) && ((vet[2] & 12) == 12)){
            //instruçao ADD Hd, Hm
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nADD ");
            fclose(file2);

            ADD_MOV_com_HM_HD(vet, file2);

        }
        if((vet[1] == 6) && ((vet[2] & 12) == 12)){
            //instruçao MOV Hd, Hm
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nMOV ");
            fclose(file2);

            ADD_MOV_com_HM_HD(vet, file2);

        }
        if((vet[1] == 5)){
            //instruçao CPY HM HD
            CMP(vet, file2);
        }
        if(vet[1] == 7){
            //instruçoes BX |BLX
            if((vet[2] & 8) == 0){
                //instRUÇAO BX
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nBX ");
                fclose(file2);
                BX_BLX(vet, file2);


            }
            if((vet[2] & 8) == 8){
                //instRUÇAO BLX
                file2 = fopen("output.txt", "a");
                fprintf(file2,"\nBLX ");
                fclose(file2);
                BX_BLX(vet, file2);

            }
        }
        if((vet[1] & 8) == 8){
            //instruçao LDR Ld, [pc, #immed*4]
            LDR_com_imediado8(vet, file2);
        }


        break;
    
     case 5:
        if(vet[1] == 0){
            //instruçao STR 
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nSTR ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);

        }
        if(vet[1] == 1){
            //instruçao | STRH 
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nSTRH ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);

        }
        if(vet[1] == 2){
            //instruçao | STRB
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nSTRB ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);

        }
        if(vet[1] == 3){
            //instruçao | LDRSB pre
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDRSB ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);

        }
        if(vet[1] == 8){
            //instruçao LDR 
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDR ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);

        }
        if(vet[1] == 9){
            //instruçao | LDRH 
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDRH ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);
        }
        if(vet[1] == 10){
            //instruçao | LDRB 
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDRB ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);

        }
        if(vet[1] == 11){
            //instruçao  LDRSH pre
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDRSH ");
            fclose(file2);
            STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(vet, file2);
        }

        break;
    
     case 6:
        if((vet[1] & 8) == 0){
            //instruçao STR  Ld, [Ln, #immed*4]
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nSTR ");
            fclose(file2);
            STR_LDR_com_Ln_immed_x4(vet,file2);
        }
        if((vet[1] & 8) == 8){
            //instruçao LDR Ld, [Ln, #immed*4]
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDR ");
            fclose(file2);
            STR_LDR_com_Ln_immed_x4(vet,file2);
        }

        break;

     case 7:
        if((vet[1] & 8) == 0){
           //instruçao  STRB Ld, [Ln, #immed]
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nSTRB ");
            fclose(file2);
            STRB_LDRB_com_ln_imediado(vet, file2);
        }
        if((vet[1] & 8) == 8){
           //instruçao   LDRB Ld, [Ln, #immed]
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDR ");
            fclose(file2);
            STRB_LDRB_com_ln_imediado(vet, file2);        }
        break;
    
     case 8:
       if((vet[1] & 8) == 0){
           //instruçao  STRH Ld, [Ln, #immed*2]
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nSTRH ");
            fclose(file2);
            STRH_LDRH_com_Ln_immed_x2(vet, file2);
        }
        if((vet[1] & 8) == 8){
           //instruçao LDRH Ld, [Ln, #immed*2]
            file2 = fopen("output.txt", "a");
            fprintf(file2,"\nLDRH ");
            fclose(file2);
            STRH_LDRH_com_Ln_immed_x2(vet, file2);
        }
        break;
     case 9:
        if ((vet[1] >> 3) == 0){
            // instruçao STR Ld, [sp, #immed*4]
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nADD ");
            fclose(file2);
            STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(vet, file2);
        }
        if ((vet[1] >> 3) == 1){
            //instruçao LDR Ld, [sp, #immed*4]
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nLDR ");
            fclose(file2);
            STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(vet, file2);

        }
        break;

     case 10: 
        if ((vet[1] >> 3) == 0){
            // instruçao ADD Ld, pc, #immed*4 |
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nADD ");
            fclose(file2);
            ADD_Ld_pc_immed_x4(vet, file2);
        }
        if ((vet[1] >> 3) == 1){
            //instruçao ADD Ld, sp, #immed*4
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nADD ");
            fclose(file2);
            ADD_Ld_sp_immed_x4(vet, file2);

        }
        break;
        
     case 11:
        if((vet[1] == 0) && ((vet[2] & 8) == 0)){
            // instruçao ADD sp, #immed*4
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nADD ");
            fclose(file2);
            ADD_SUB_com_sp_imediato7(vet , file2);
        }

        if((vet[1] == 0) && ((vet[2] & 8) == 8)){
            // instruçao SUB sp, #immed*4
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nSUB ");
            fclose(file2);
            ADD_SUB_com_sp_imediato7(vet , file2);
        }
        if((vet[1] == 2) && ((vet[2] & 12) == 0)){
            //instruçao SXTH
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nSXTH ");
            fclose(file2);
            SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(vet, file2);

        }
        if((vet[1] == 2) && ((vet[2] & 12) == 4)){
            //instruçao SXTB
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nSXTB ");
            fclose(file2);
            SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(vet, file2);

        }
        if((vet[1] == 2) && ((vet[2] & 12) == 8)){
            //instruçao UXTH
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nUXTH ");
            fclose(file2);
            SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(vet, file2);

        }
        if((vet[1] == 2) && ((vet[2] & 12) == 12)){
            //instruçao UXTB
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nUXTB ");
            fclose(file2);
            SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(vet, file2);

        }
        if((vet[1] == 10) && ((vet[2] & 12) == 0)){
            // instrucao REV 
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nREV ");
            fclose(file2);
            SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(vet, file2);

        }
        if((vet[1] == 10) && ((vet[2] & 12) == 4)){
            // instrucao REV16 | 
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nREV16 ");
            fclose(file2);
            SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(vet, file2);

        }
        if((vet[1] == 10) && ((vet[2] & 12) == 8)){
            // instrucao  | REVSH
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nREVSH ");
            fclose(file2);
            SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(vet, file2);

        }
        if((vet[1] == 4)){
            // instruçao push 
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nPUSH ");
            fclose(file2);
            PUSH_POP(vet, file2);

        }
        if((vet[1] == 12)){
            // instruçao POP
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nPOP ");
            fclose(file2);
            PUSH_POP(vet, file2);

        }
        if((vet[1] == 6) && (vet[2] == 5)){
            if((vet[3] & 8) == 0){
                // instruçao SETEND_LE
                file2 = fopen("output.txt", "a");    
                fprintf(file2,"\nSETEND LE ");
                fclose(file2);

            }
            if((vet[3] & 8) == 8){
                // instruçao SETEND_LE
                file2 = fopen("output.txt", "a");    
                fprintf(file2,"\nSETEND BE ");
                fclose(file2);

            }
        }
        if((vet[1] == 6) && (vet[2] == 6)){
            // instruçao CPSIE
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nCPSIE ");
            fclose(file2);

        }
        if((vet[1] == 6) && (vet[2] == 7)){
            // instruçao CPSID
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nCPSID ");
            fclose(file2);
        }
        if(vet[1] == 14){
            //instruçao BKPT
            BKPT(vet, file2);

        }

        break;
    
     case 12:
        if((vet[1] & 8) == 0){
            // instruçao STMIA 
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nSTMIA ");
            fclose(file2);
            STMIA_LDMIA(vet, file2);
        }
        if((vet[1] & 8 ) == 8){
            //instruçao LDMIA 
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nLDMIA ");
            fclose(file2);
            STMIA_LDMIA(vet, file2);
        }

        break;
     case 13:
        if(vet[1] == 14){
            file2 = fopen("output.txt", "a");    
            fprintf(file2,"\nINDEFINIDO ");
            fclose(file2);
            
        }
        if(vet[1] == 15){
            SWI_immed8(vet, file2);

        }


        break;
    
    
    default:
        break;
    }


}

