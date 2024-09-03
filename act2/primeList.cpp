#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i <n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> processVector(const vector<int>& input){
    vector<int> primes;

    for (int num: input){
        if (isPrime(num)){
            primes.push_back(num);
        }
    }
    return primes;
}


void opcion1(){

}


void opcion2(){
    int num;
    do{
        cout<<"Ingresa el numero a verificar: ";
        cin>>num;
        if(num<1){
            cout<<endl<<"######################################"<<endl;
            cout<<"NO SE ADMITEN NUMEROS NEGATIVOS"<<endl;
            cout<<"######################################"<<endl<<endl;
        }
    }while(num<1);
    if (isPrime(num)){
        cout<<endl<<"El numero "<<num<<" es PRIMO"<<endl<<endl;
    }else{
        cout<<endl<<"El numero "<<num<<" NO es PRIMO"<<endl<<endl;
    }
}

void opcion3(){
    int left, right;
    do{
        cout<<"Ingresa el limite inferior del rango: ";
        cin>>left;
        cout<<"Ingresa el limite superior del rango: ";
        cin>>right;
        if(left>right || left<1 || right<1){
            cout<<endl<<"######################################"<<endl;
            cout<<"EL RANGO INGRESADO NO ES VALIDO"<<endl;
            cout<<"######################################"<<endl<<endl;
        }
    }while(left>right|| left<1 || right<1);

    vector<int> numbers;
    for(int i = left; i<=right; i++){
        numbers.push_back(i);
    }
    vector<int> primes = processVector(numbers);

    cout<<"Los numeros primos en el rango "<<left<<" - "<<right<<" son: "<<endl;
    for(int num : primes){
        cout << num << " ";
    }
}

int main(){

    cout<<"BIENVENIDO AL VERIFICADOR DE PRIMOS"<<endl;
    int option;
    do{
        cout<<"1) Verificar un numero"<<endl<<"2) Verificar una lista de numeros"<<endl<<"3) Verificar un rango de numeros"<<endl<<"0) Salir"<<endl;
        cin>>option;
        switch(option){
            case 1:
                opcion1();
                break;
            case 2:
                opcion2();
                break;
            case 3:
                opcion3();
                break;
            default:
                cout<<endl<<"Chao pescado"<<endl;
                break;
        }
    }while(option>1);
    return 0;
}
