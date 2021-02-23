#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


void ConvertChar(char vet[]);
void LSL(char vet[], FILE *file2);
void LSR(char vet[], FILE *file2);
void Decodifica(char vet[], FILE *file2);
void ASR(char vet[], FILE *file2);
void ADD_com_LM(char vet[], FILE *file2);
void SUB_com_LM(char vet[], FILE *file2);
void ADD_com_imediato3(char vet[], FILE *file2);
void SUB_com_imdeiado3(char vet[], FILE *file2);
void CMP_com_imediado8(char vet[], FILE *file2);
void MOV_com_imediado8(char vet[], FILE *file2);
void ADD_com_imediado8(char vet[], FILE *file2);
void SUB_com_imediado8(char vet[], FILE *file2);
void AND_EOR_LSL_LSR_ASR_ADC_SBC_ROR_TST_NEG_CMP_CMN_ORR_MUL_BIC_MVN(char vet[], FILE *file2);
void ADD_MOV_com_HM_HD(char vet[], FILE *file2);
void CMP(char vet[], FILE *file2);
void BX_BLX(char vet[], FILE *file2);
void LDR_com_imediado8(char vet[], FILE *file2);
void STR_STRH_STRB_LDRSBpre_LDR_LDRH_LDRB_LDRSHpre(char vet[], FILE *file2);
void STR_LDR_com_Ln_immed_x4(char vet[], FILE *file2);
void STRB_LDRB_com_ln_imediado(char vet[], FILE *file2);
void STRH_LDRH_com_Ln_immed_x2(char vet[], FILE *file2);
void STR_LDR_ADD_com_ld_sp_pc_com_immediato8_x4(char vet[], FILE *file2);
void ADD_SUB_com_sp_imediato7(char vet[], FILE *file2);
void ADD_Ld_pc_immed_x4(char vet[], FILE *file2);
void ADD_Ld_sp_immed_x4(char vet[], FILE *file2);
void SXTH_SXTB_UXTH_UXTB_REV_REV16_REVSH(char vet[], FILE *file2);
void PUSH_POP(char vet[], FILE *file2);
void BKPT(char vet[], FILE *file2);
void STMIA_LDMIA (char vet[], FILE *file2);
void SWI_immed8(char vet[], FILE *file2);



#endif // HEADER_H_INCLUDED
