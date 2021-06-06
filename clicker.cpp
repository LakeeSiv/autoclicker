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
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0,0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0,0);
            Sleep(10);
        }
        if (GetKeyState('Z') & 0x8000){
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0,0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0,0);
            Sleep(10);
        }

    }
};


int main(){
    description();
    clicker();
    return 0;
}

