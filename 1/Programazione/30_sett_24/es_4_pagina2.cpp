#include <iostream>
using namespace std;

int main(){
  // 4 interi in input dare in output il valore piu vicino alla media
  printf("Avvio\n");
  int n1,n2,n3,n4;
  cin >> n1 >> n2 >> n3 >>n4;
  int media = (n1+n2+n3+n4)/4;
  if (abs(n1-media) < abs(n2-media) && abs(n1-media) < abs(n3-media) && abs(n1-media) < abs(n4-media)){
    printf("%d\n",n1);
  }
  else if (abs(n2-media) < abs(n1-media) && abs(n2-media) < abs(n3-media) && abs(n2-media) < abs(n4-media)){
    printf("%d\n",n2);
  }
  else if (abs(n3-media) < abs(n2-media) && abs(n3-media) < abs(n1-media) && abs(n3-media) < abs(n4-media)){
    printf("%d\n", n3);
  }
  else {
    printf("%d\n",n4);
  }


}
