namespace liba{
enum class Key { Up, Down, Left, Right, Enter, Quit, Other };
    enum  Color{
        WHITE = 37,
        YELLOW = 33,
    };

    void goTo(int x, int y);
    void setColor(Color color);
    void print( const char * text);
    void resetColor();
    void display(int x, int y,  const char* text, Color color=Color::WHITE);
    void clearScreen();
    Key readKey();
    char getch_linux();
}

