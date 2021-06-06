#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using std::cout;
using std::string;

void description() {
    std::ifstream fin("ascii.txt");
    string line;

    while (std::getline(fin, line))
    {
        cout << line << '\n';
    }

    cout << "\n";
    cout << "Hold down X to right click\n";
    cout << "Hold down Z to left click\n";
};

void clicker() {
    bool clickedRight = false;
    bool clickedLeft = false;
    for (;;) {
        int randTime = rand() % 50 + 100;
        if (GetKeyState('X') & 0x8000) {
            clickedRight = !clickedRight;
            cout << clickedRight;
        }
        if (GetKeyState('Z') & 0x8000) {
            clickedLeft = !clickedLeft;
            cout << clickedLeft;
        }

        if (clickedRight) {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            Sleep(1000);
            // cout << randTime << "\n";
        }

        if (clickedLeft) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(10);

        }

    }
};


int main() {
    description();
    clicker();
    return 0;
}

