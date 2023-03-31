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
    free(pset->p);
    tmp.p[tmp.length-1]=rand()%100;
    pset->p=(&tmp)->p;
}

void sum(MNOZINA* pset){
    MNOZINA temp;
    MNOZINA set2;
    temp.length=rand()%15;
    set2.length=temp.length+pset->length;
    set2.p=(int*)malloc(set2.length *sizeof(int));
    for(unsigned int i=0; i<pset->length; i++){
        set2.p[i]=pset->p[i];
    }
    for(unsigned int j=pset->length, i=0; j<set2.length; j++,i++){
        temp.p[i]=rand()%100;
        set2.p[j]=temp.p[i];
    }
    free(pset->p);
    pset->length+=temp.length;
    pset->p=(&set2)->p;
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
    
    //printf("\n");
    //append(&set);
    //for(unsigned int i=0; i<set.length; i++){
    //    printf("%d ",set.p[i]);
    //}

    //printf("\n");
    //emptyset(&set);
    //printf("{ }");
    //for(unsigned int i=0; i<set.length; i++){
    //      printf("%d ",set.p[i]);
    //}
    
    printf("\n");
    sum(&set);
    for(unsigned int i=0; i<set.length; i++){
        printf("%d ",set.p[i]);
    }
    
}