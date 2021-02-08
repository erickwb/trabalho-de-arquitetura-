#include <stdio.h>
#include <stdlib.h>
#include "heade.h"
/*
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
    fprintf(file2,"\nLSR ");
    fprintf(file2,"#:%d", imediato);
    fprintf(file2," LM:%d", registrador_origem);
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
        printf("caso o primeiro digito e 1");
        break;
    
     case 2:
        printf("caso o primeiro digito e 2");
        break;
    
     case 3:
        printf("caso o primeiro digito e 3");
        break;
    
     case 4:
        printf("caso o primeiro digito e 4");
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
*/


int main(){


    FILE *file;
    file = fopen("input.txt", "r"); //lendo o arquivo input.txt
    FILE *file2;
    file2 = fopen("output.txt", "w"); //arquivo de destino 

    char frase[100]; //buffer
    
    if(file == NULL){
        printf("Nao e possivel abrir o arquivo:");
        getchar();
        exit(0);
    }

    while (fgets(frase,100, file) != NULL){
     //   printf("%s\n", frase); //printando o conteudo da linha
        ConvertChar(frase); 
        

        Decodifica(frase, file2);

    };
   
        
    
   

  
    return 0;
}