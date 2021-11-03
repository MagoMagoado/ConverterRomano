#include <stdio.h>

//preciso passar vetor como ponteiro 
void romano(int *var, int num, int letra, char *algorit){
int quant = 0;
//entre 90 e 100 temos um caso atípico
    if(*var>=90 && *var<100){
        *var = *var-90;
        printf("XC");
    }
    else{
        while(*var>=num){
            *var = *var-num;
            quant++;
        }
    }
        
    //Se o algoritmo der mais de 3 letras iguais
    if(quant<=3){
        while(quant>0){
            printf("%c", algorit[letra]);
            quant--;
        }
        if(*var<10 && *var!=0){
            char *decimais[] = {"-", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
            for(int i=1;i<=9;i++){
                if(i==*var){
                    printf("%s", decimais[i]);                    
                    *var = *var - i;
                }
            }
        }
    }
    else{
        printf("%c", algorit[letra]);
        printf("%c", algorit[letra+1]);
    }
}

int main(){
int valor;
char algoritmo[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

scanf("%d", &valor);

if(valor>=1000){romano(&valor, 1000, 6, algoritmo);}
if(valor>=500){romano(&valor, 500, 5, algoritmo);}
if(valor>=100){romano(&valor, 100, 4, algoritmo);}
if(valor>=50){romano(&valor, 50, 3, algoritmo);}
if(valor>=10||valor<10){romano(&valor, 10, 2, algoritmo);}
printf("\n");

return 0;
}