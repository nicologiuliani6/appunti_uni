#include <iostream>
using namespace std;

const int lenght=10;
bool is_in(const int arr[], const int num){
  int i=0;
  while (i<lenght) {
    if(arr[i]==num){
      return true;
    }
    i++;
  }
  return false;
}

bool is_in_totheright(const int arr[], const int num, const int position){
  int i=position;
  while (i<lenght) {
    if (arr[i]==num) {
      return true;
    }
    i++;
  }

  return false;
}

void print_onlyonce(const int arr[]){
  for (int i=0; i < lenght; i++) {
    for (int j=i+1; j<=lenght; j++) {
      if(j==lenght){
        cout << arr[i] << " ";
      }
      else if(arr[i]==arr[j]){
        break;
    }
  }
}
  cout << endl;
}

int main(){
  printf("AVVIO... \n");
  int arr[lenght]={1,2,3,4,5,6,7,7,9,10}, num;
  printf("Inseirisci num: ");
  cin >> num;
  cout << is_in(arr,num) << endl;
  cout << is_in_totheright(arr, num, 6) << endl;
  print_onlyonce(arr);
  return 0;
}
