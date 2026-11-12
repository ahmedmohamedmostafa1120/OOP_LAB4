#include "../include/lib.hpp"
#include <cstdio>
#include <iostream>   // Standard input/output library
#include <unistd.h>   // Provides Unix functions such as read
#include <termios.h>  // Used to control terminal settings



namespace liba{

void goTo(int x, int y) {
    printf("\033[%d;%dH", x, y);
    fflush(stdout); 
}


void setColor(Color color) {
    printf("\033[1;%dm",color);
    fflush(stdout);
}
void print( const char *text) {
    printf("%s", text);
    fflush(stdout);
}
  
void resetColor() {
    printf("\033[0m");
    fflush(stdout);
}
void display(int x, int y,  const char* text, Color color) {
    goTo(x, y);
    setColor(color);
    print(text);
    resetColor();
}
void clearScreen() {
    printf("\033[2J\033[H");
    fflush(stdout);
}
char getch_linux() {
    char buf = 0; // Variable to store the input character

    struct termios old = {0}; // Structure to save current terminal settings

    // Save the current terminal settings
    tcgetattr(0, &old);

    // Disable Canonical Mode (do not wait for Enter key)
    old.c_lflag &= ~ICANON;

    // Disable Echo so typed characters are not displayed
    old.c_lflag &= ~ECHO;

    // Require at least one character to be read
    old.c_cc[VMIN] = 1;

    // No timeout while waiting for input
    old.c_cc[VTIME] = 0;

    // Apply the modified settings immediately
    tcsetattr(0, TCSANOW, &old);

    // Read a single character immediately from the keyboard
    read(0, &buf, 1);

    // Re-enable Canonical Mode
    old.c_lflag |= ICANON;

    // Re-enable Echo
    old.c_lflag |= ECHO;

    // Restore the terminal to its original settings
    tcsetattr(0, TCSADRAIN, &old);

    // Return the character that was read
    return buf;
}


Key readKey() {
    char c = getch_linux();

    if (c == 27) {                       
        char c2 = getch_linux();         
        char c3 = getch_linux();         

        if (c2 == '[') {
            switch (c3) {
                case 'A': return Key::Up;
                case 'B': return Key::Down;
                case 'C': return Key::Right;
                case 'D': return Key::Left;
            }
        }
        return Key::Other;
    }

    if (c == '\n' || c == '\r') return Key::Enter;
    if (c == 'q')               return Key::Quit;
    return Key::Other;
}

};