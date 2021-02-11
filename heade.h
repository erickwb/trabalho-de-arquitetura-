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

#endif // HEADER_H_INCLUDED
