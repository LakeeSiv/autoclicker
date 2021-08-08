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

    cout << "\n\n\n\n";
    cout << "Press X to right click\n";
    cout << "Press F to left click\n";
};

void clicker() {
    bool clickedRight = false;
    bool clickedLeft = false;
    for (;;) {
        float n = rand() % 1 + 4.5;
        float randTime = rand() % 200 / n + 250 / n;
        if (GetKeyState('X') & 0x8000) {
            clickedRight = !clickedRight;
            if (clickedRight) {
                cout << "Right Click Toggled on\n";
            }
            else {
                cout << "Right Click Toggled off\n";
            }
            Sleep(200);
        }
        if (GetKeyState('F') & 0x8000) {
            clickedLeft = !clickedLeft;
            if (clickedLeft) {
                cout << "Left Click Toggled on\n";
                /* Beep(523, 500); */
            }
            else {
                cout << "Left Click Toggled off\n";
                /* Beep(300, 500); */
            }
            Sleep(200);
        }

        if (clickedRight) {
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            Sleep(5);
            // cout << randTime << "\n";
        }

        if (clickedLeft) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(randTime);

        }

    }
};


int main() {
    description();
    clicker();
    return 0;
}

