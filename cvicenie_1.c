#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//      ******************************
//      *<<<<Operacie s mnozinami>>>>*
//      ******************************

typedef struct{
    unsigned int length;
    int *p;
}MNOZINA;

void emptyset(MNOZINA* pset){
    pset->length-=pset->length;
}

void append(MNOZINA* pset){
    pset->length+=1;
    MNOZINA tmp;
    tmp.length=pset->length;
    tmp.p=(int*)malloc(pset->length *sizeof(int));

    for(unsigned int i=0; i<tmp.length; i++){
        tmp.p[i]=pset->p[i];
    }
    pset->p[tmp.length-1]=rand()%100;
}

int main(){
    MNOZINA set;
    scanf("%d",&set.length);
    set.p=(int*)malloc(set.length *sizeof (int));
    srand((unsigned int)time(NULL));
    for(unsigned int i=0; i<set.length; i++){
        set.p[i]=rand()%100;
        printf("%d ",set.p[i]);
    }
    
    printf("\n");
    append(&set);
    for(unsigned int i=0; i<set.length; i++){
        printf("%d ",set.p[i]);
    }

    printf("\n");
    emptyset(&set);
    printf("{ }");
    for(unsigned int i=0; i<set.length; i++){
          printf("%d ",set.p[i]);
    }
    
    
}