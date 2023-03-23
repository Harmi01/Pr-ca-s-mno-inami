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

void prienik(int M[],int K[],int S[]){
    int tmp=0;
    for(int i=0; i<n_M; i++){
        for(int j=0; j<n_K; j++){
            if(M[i]==K[j]){
                S[tmp]=K[j];
                tmp++;
            }
        }
    }
}

void zjednotenie(int M[],int K[],int P[],int S[]){
    
    for(int i=0; i<n_M; i++){
        P[i]=M[i];
    }
    for(int j=0; j<n_K; j++){
        if(K[j]==S[0] || K[j]==S[1])
            continue;
        else
            P[j+6]=K[j];
        
    }
}


int main(){
    int M[n_M]={3,6,7,10,18}, K[n_K]={2,8,10,11,15,18};
    int n_S=prienik_pocet(M,K);
    int S[n_S];
    int P[n_M+n_K];
    prienik(M,K,S);

    for(int i=0; i<n_S; i++){
        printf("%d ",S[i]);
    }
    printf("\n");

    zjednotenie(M,K,P,S);
    for(int j=0; j<n_M+n_K; j++){
        printf("%d ",P[j]);
    }

}