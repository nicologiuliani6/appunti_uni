#include <iostream>
using namespace std;

int position_most_common(const int arr[], const int lenght){
  int best=arr[0], position=-1;
  for (int i = 0; i < lenght; i++) {
    if(arr[i]>best){
      best=arr[i];
      position=i;
    }
  }
  if (position==-1) return -1;
  else{
    return position;
  }
}

int give_max(const int arr[], const int lenght){
  int occorrenze[lenght];
  for (int i=0; i<lenght; i++) {
    occorrenze[i]=0;
    for (int j=i+1; j<lenght; j++) {
      if(arr[i]==arr[j]){
        occorrenze[i]++;
      }
    }
    //cout << "occorrenze[i]=" << occorrenze[i]<<endl;
  }
  return position_most_common(occorrenze, lenght);
}
int main(){
  int lenght=10;
  int arr[lenght]={2,3,4,10,3,0,5,10,9,10};
  cout << give_max(arr, lenght) << endl;
  return 0;
}
