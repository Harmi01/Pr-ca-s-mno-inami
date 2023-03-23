#include<stdio.h>
#include<stdlib.h>
#define n_M 5
#define n_K 6

int prienik_pocet(int M[],int K[]){
    int n=0;
    for(int i=0; i<n_M; i++){
        for(int j=0; j<n_K; j++){
            if(M[i]==K[j])
                n++;
        }
    }
    return n;
}

void prienik(int M[],int K[],int P[]){
    int tmp=0;
    for(int i=0; i<n_M; i++){
        for(int j=0; j<n_K; j++){
            if(M[i]==K[j]){
                P[tmp]=K[j];
                tmp++;
            }
        }
    }
}

void zjednotenie(int M[],int K[],int Z[],int P[]){
    
    for(int i=0; i<n_M; i++){
        Z[i]=M[i];
    }
    for(int j=0,z=5; j<n_K; j++,z++){
        if(K[j]==P[0] || K[j]==P[1])
            continue;
        Z[z]=K[j];
        
    }
}


int main(){
    int M[n_M]={3,6,7,10,18}, K[n_K]={2,8,10,11,15,18};
    int n_P=prienik_pocet(M,K);
    int P[n_P];
    int Z[(n_M+n_K)-n_P];
    
    prienik(M,K,P);
    zjednotenie(M,K,Z,P);
    
    for(int i=0; i<n_P; i++){
        printf("%d ",P[i]);
    }
    printf("\n");
    for(int j=0; j<(n_M+n_K)-n_P; j++){
        printf("%d ",Z[j]);
    }

}