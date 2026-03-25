#include <iostream> // utilizzo sia to_string(), sia lenght()
#include <cmath> //serve per pow()
using namespace std;

int frat(int num){ //NON SERVE CON IL METODO 2 DEL BINOMIO, perchè si supera facilmente 2^(64)-1 con il frattoriale
  int sum=1;
  for(int i=1; i<=num; i++){
    sum*=i;
  }
  return sum;
}

int binomiale(int n, int k){
  int sum=1;

  //METODO 1 (piu semplice ma si arriva in fretta al overflow)
  //sum=frat(n)/(frat(k)*frat(n-k));

  //METODO 2 ottimizzato
  if (k==0 || k==n){return 1;} 
  if(k > n-k){ // se si supera i punti centrali si rifà il calcolo con i valori minori
    k=n-k;
  }
  for (int i=1; i <= k; i++) { //calcolo binomiale
    sum*=(n-i+1);
    sum/=i;
  }
  return sum;

}

int tart(int num, int posizione){
  if(num==0 || posizione==num){ //TORNA 1 SE è RIGA 0 O ULTIMA POSIZIONE DI RIGA "num"
    return 1;
  }
  return binomiale(num, posizione);
}

int main(){
  printf("Inserisci n: ");
  int n, tarta;
  int* ptart= &tarta; //puntatore per il controllo (non ha senso ma lo volevo mettere)
  cin >> n;

  //CALCOLO LUNGHEZZA MAX BASE TRAINGOLO
   int max_width = 0; //indica la lunghezza massima
    for (int i = 0; i < n; i++) {
        max_width += to_string(tart(n - 1, i)).length(); //calcolo della lunghezza di tutta la riga
        if (i < n - 1) {
            max_width += 1; //includo pure gli spazi nella lunghezza
        }
    }

  for (int i=0; i<n; i++){ //ciclo riga
      //calcolo lunghezza riga corrente
        int current_width = 0; //indica la lunghezza attuale
        for (int j = 0; j <= i; j++) {
            current_width += to_string(tart(i, j)).length(); //lunghezza totale dei numeri nella riga
            if (j < i) {
                current_width += 1; //includo pure gli spazi nella lunghezza
            }
        }

        //calcolo punto al centro e la relativa spaziatura
        int initial_spaces = (max_width - current_width) / 2; 
        for (int k = 0; k < initial_spaces; k++) {
            cout << " ";
        }
  
      for(int j=0;j<=i;j++){ //ciclo posizione (& riga)
        tarta=tart(i,j); //calcolo valore tartaglia riga i, posizione j
        if (*ptart<0){printf("\nERRORE: overflow"); break;} //CHECK if tart>2^(64)-1
        cout << tarta << " "; //out numeri e spaziatura post numero
    }
    printf("\n"); //tornare a capo dopo la riga n
  }
}
