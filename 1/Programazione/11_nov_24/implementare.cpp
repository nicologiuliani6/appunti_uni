#include <iostream>
using namespace std;
const int length=10;

struct set{
    int data[length];
    int num_element;
};
set empty_set{
    set tmp;
    tmp.num_element=0;
    return tmp;
};

bool is_in(set s, int element){
    if(s.num_element==0) return false;
    else{
        int media;
        int l=0, r=s.num_element;
        for(int i=0; i<s.num_element; i++){
            media=(l+r)/2;
            if(s.data[media]==element) return true;
            else if(s.data[media]>s.data[element]) r=media-1;
            else l=media+1;
        }
    }
}

set intersection(set s1, set s2){
    if ((s1.num_element == 0)||(s2.num_element == 0)) return empty_set();
    else{
        set s = empty_set();
        int i = 0 ;
        int j = 0 ;
        while ((i < s1.num_element) && (j < s2.num_element)) {
        if (s1.data[i] == s2.data[j]) {
            s.data[s.num_element] = s1.data[i] ;
            s.num_element = s.num_element + 1 ;
            i = i+1 ;
            j = j+1 ;
        } 
        else if (s1.data[i] < s2.data[j]) i = i+1 ;
        else j = j+1 ;
    }
    return s;
    }
}



int main(){

    return 0;
}