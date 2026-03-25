#include <iostream>
using namespace std;

void scambia(int& num, int& min){
  int temp;
  temp=num;
  num=min;
  min=temp;
}


//FUNZIONE PER CONTROLLARE ARRAY
bool check_order(const int arr[], const int lenght){
  for(int i=0; i<lenght; i++){
    if(arr[i]>arr[i+1]){
      return false;
    }
  }
  return true;
}

void sort(int arr[], const int lenght){
      int i=lenght-1;
      while(i>0){
        if(arr[i]<arr[i-1]){
          scambia(arr[i],arr[i-1]);
          i=i+2;;
          }
        i--;
      }
}

void print_arr(const int arr[], const int lenght){
  for(int i=0; i<lenght; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  int lenght=10;
  int arr[lenght]={3,2,10,8,6,9,5,4,1,7};
  print_arr(arr,lenght);
  sort(arr, lenght);
  print_arr(arr, lenght);
  return 0;
}
