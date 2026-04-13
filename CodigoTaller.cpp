//parte uno
# include <iostream>
using namespace std;
void intercambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main () {
    int x = 6;
    int y = 13;
    
    cout << "Antes del intercambio:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    intercambio(&x, &y);
    cout<<"Valor despues de intercambiar\n";
    cout << "x = " << x << ", y = " << y << endl;
}

//parte 2
#include <iostream>
using namespace std;

int SumaElementos(int *arr, int n){
    int suma = 0;
    for (int i = 0; i<n;i++){
        suma += *(arr + i);
    }
    return suma;
}
    int main() {
        int n;
      cout << "Ingrese la cantidad de elementos" << endl;
        cin>>n;
        int *arreglo = new int[n];
        cout<<"Ingrese los elementos"<< endl;
        for (int i = 0; i<n; i++){
        cin>>arreglo[i];
        }
        int result = SumaElementos(arreglo, n);
        cout<<"La suma total de los valores es "<<result<<endl;
        delete[]arreglo;
        return 0;
    }

//parte 3
#include <iostream>
using namespace std;

int MayorElemento(int *arr, int n){
    if (n <= 0) {
        cout<<"No se puede crear un arreglo que no tenga valores, error"<<endl;
        return -1;
        }
        int max = *arr;
        for (int i = 1;i < n; i++){
            if (*(arr + i)> max){
                max = *(arr + i);
            }
        }
        return max;
    }


int main(){
    int n;
    cout<<"Porfavor ingrese la cantidad de valores del arreglo"<<endl;
    cin>>n;
    if (n <= 0){
        cout<<"No se puede crear un arreglo vacio, error";
    }
    int *arreglo = new int[n];

    cout<<"Ingrese los valores de los elementos del arreglo"<<endl;
    for (int i = 0; i < n; i++){
        cin>>arreglo[i];
    }
    int resultado = MayorElemento(arreglo, n);
    cout << "El numero mayor es "<<resultado<<endl;

    return 0;
}

//parte 4
#include <iostream>
using namespace std;

int DUPLICAR(int x){
return x * 2;
}

int Triplicar(int x){
    return x * 1.5;
}

void ArreglosMultiplicados(int *arr, int n, int (*operacion)(int)){
    for (int i = 0; i < n; i++){
        arr[i] = operacion(arr[i]);
    }
}


int main () {
    int n;
    cout<<"# de elementos de la lista: ";
    cin>>n;
    cout<<"Elementos de la lista:\n";
    int *arr = new int[n];
     
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    ArreglosMultiplicados(arr, n, DUPLICAR);
    cout<<"Numeros Duplicados:\n";
    
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<",";
    }
    
    ArreglosMultiplicados(arr, n, Triplicar);
    cout<<"Numeros Triplicados:\n";
    
        for (int i = 0; i < n; i++){
        cout<<arr[i]<<",";
    }
    delete[]arr;
}

//Parte 5
#include <iostream>
using namespace std;

void mostrarComoEntero(int* p) {
    cout << "\nReinterpretacion como int" << endl;
    cout << "Direccion recibida: " << p << endl;
    cout << "Valor entero (reinterpretado): " << *p << endl;
}

void mostrarBytes(char* p, size_t size) {
    cout << "\nRepresentacion en memoria (bytes)" << endl;
    
    for (size_t i = 0; i < size; i++) {
        cout << "Byte " << i << " -> Direccion: " << (void*)(p + i)
             << " | Valor: " << (int)*(p + i) << endl;
    }
}

int main() {
    float numero;

    cout << "Ingrese un numero float: ";
    cin >> numero;

    cout << "\nInformacion original" << endl;
    cout << "Direccion de numero: " << &numero << endl;
    cout << "Valor float: " << numero << endl;

    int* ptrInt = (int*)&numero;
    char* ptrChar = (char*)&numero;

    mostrarComoEntero(ptrInt);
    mostrarBytes(ptrChar, sizeof(float));

    return 0;
}
