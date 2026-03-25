#include <iostream>
#define BUFFER_SIZE 100
class heap{
private:
    int arr[BUFFER_SIZE];
    int index=0;
public:
    heap(){
        for(auto i=0; i<BUFFER_SIZE; i++){
            arr[i]=0;
        }
    }
private:
    void go_one(int arr[], const int position_free){
        int tmp[BUFFER_SIZE];
        for(auto i=0; i<BUFFER_SIZE-1; i++){
            if(i>=position_free){
                tmp[i+1]=arr[i];
            }
            else {
                tmp[i]=arr[i];
            }
        }
        for(auto i=0; i<BUFFER_SIZE; i++){
            arr[i]=tmp[i];
        }
    } 
public:
    void insert(const int val){
        for(auto i=0; i<=index; i++){
            if(arr[i]<val){
                if(i!=0){
                    go_one(arr,i);
                    arr[i]=val; 
                }
                else {
                    arr[1]=arr[0];
                    arr[0]=val;
                }
                break;
            }
        }
        index++;
    }
    void print(){
         for(auto i=0; i<index; i++){
            std::cout << arr[i] << std::endl;
         }
    }
};

int main(){
    heap H;
    H.insert(5);
    H.insert(10);
    H.insert(7);
    H.insert(1);
    H.print();

}
