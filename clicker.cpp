#include <iostream>
#include <Windows.h>

using std::cout;

void description(){
    cout << "Hold down X to right click\n";
    cout << "Hold down Z to left click\n";
};

void clicker(){
    for (;;){
        if (GetKeyState('X') & 0x8000){
            cout << "a";
        }
    }
};


int main(){
    description();
    clicker();
    return 0;
}

