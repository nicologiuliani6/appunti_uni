#include <iostream>
using namespace std;

void initialize(int A[], const int length){
    srand( time(0) ) ;
    for (int i = 0; i < length ; i=i+1){
        A[i] = rand()%(3*length +1);
        }
    }
void print_array(const int A[], const int length){
    for (int i = 0; i < length ; i=i+1){
        cout << A[i] << ' ' ;
        }
    cout << endl ;
    }

void scambia(int& x, int& y){
  int temp=x;
  x=y;
  y=temp;
}

void selection_sort(int A[], const int length){
  int min;
  for(int i=0; i<length-1; i++){
    min=i;
    for(int j=i+1;j<length; j++){
      if(A[min]>A[j]){
        min=j;
      }
    }          
    scambia(A[i],A[min]);
  }
}
void bubble_sort(int A[], int length){
  int i, j ;
  for (i = 0 ; i < length ; i = i+1){
    for (j = 0 ; j < length-1-i ; j = j+1)
      if (A[j] > A[j+1]) scambia(A[j], A[j+1]) ;
    }
}

int bin_search(int A[], const int length, int num){
  int l=0, r=length;
  bool find=false;
  while (l<r && !find) {
    if(A[(l+r)/2]==num){
      find=true;
    }
    else if(A[(l+r)/2]>num){
      r=((l+r)/2);
    }
    else{
      l=(l+r)/2+1;  
    }
  }
  if(find){
    return (l+r)/2;
  }
  else{
    return -1;
  }
}

int main(){
  int length=20;
  int arr[length];
  initialize(arr, length);
  //print_array(arr, length);
  
  //selection_sort(arr, length);
  bubble_sort(arr,length);
  print_array(arr, length);
  cout << bin_search(arr,length,20)<<endl;
  cout << endl;
  return 0;
}
