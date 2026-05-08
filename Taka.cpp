#include<iostream>
#include<cmath>
#include<string>
using namespace std;

template <typename Taka>
class Informaition {
    private : 
        Taka data ; 
        int *next ; 

    public :
        void setData(Taka d) {
            data = d ; 
        }

        Taka getData() {
            return data ; 
        }

} ; 

int main(){
    Informaition<string> str ; 
    str.setData("Hello World") ;
    cout << str.getData() << endl ;
    Informaition<int> num ;
    num.setData(42) ;
    cout << num.getData() << endl ;

}