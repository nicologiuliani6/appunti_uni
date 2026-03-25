#include <iostream>
using namespace std;
const int BUFFER = 8;

int get_maxdup(int A[], int length){
    if(length<=0) return 0;
    // 
    int tmp[BUFFER];
    
    for(int i=0; i<length; i++){
        tmp[i]=0;
        for(int j=0; j<length; j++){
            //se arr in pos j è uguale a arr pos i allora aumenta il contatore
            if(A[i]==A[j]) tmp[i]++;
            
        }
    }
    int best=0;
    for(int i=0; i<length; i++){
        //se il tmp pos i è migliore del attuale best cambialo
        if(tmp[i]>best) best=tmp[i];
    }
    return best;
}

int main(){
    int arr[BUFFER];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=1;
    arr[4]=2;
    arr[5]=3;
    arr[5]=3;
    arr[6]=2;
    arr[7]=2;
    printf("BEST: %d\n",get_maxdup(arr,BUFFER));
    return 0;
}