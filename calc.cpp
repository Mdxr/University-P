#include <iostream>

using namespace std;

int add(int x, int y){
    return x + y;
}
int subtract(int x, int y){
    return x - y;
}
int multiply(int x, int y){
    return x * y;
}
float divide(float x, float y){ // used float so that the values after decimal won't be discarded
    return x / y;
}

int main(){
    int x, y;
    char op;

    cout << "Enter the second value : ";
    cin >> x;
    cout << "Enter the operator (+ , - , / , x) : ";
    cin >> op;
    cout << "Enter the second value : ";
    cin >> y;

    if(op == '+'){
        cout << x << " + " << y << " = " << add(x, y) << endl; 
    } else if (op == '-'){
        cout << x << " - " << y << " = " << subtract(x, y) << endl;
    } else if(op == 'x'){
        cout << x << " x " << y << " = " << multiply(x, y) << endl;
    } else if(op == '/'){
        cout << x << " / " << y << " = " << divide(x, y) << endl;
    } else {
        cout << "Invalid operator, Try again!" << endl;
    }

}