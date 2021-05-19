#include <iostream>

class Player
{
public:
    static int x, y;
    int z;

    Player()
    {
        x = y = z = -1;
    }

    Player(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void display()
    {
        std::cout << "X:" << x << " Y:" << y << " Z:" << z << std::endl;
    }

    // static function can only access static data members
    static void display2()
    {
        std::cout << "X:" << x << " Y:" << y << std::endl;
    }
};

// We need to create reference for static variables
// Otherwise we'll get undefined reference error by linker
int Player::x;
int Player::y;

int main()
{
    Player o1(1, 2, 3);
    Player o2(4, 5, 6);

    o1.display();
    o2.display();

    o2.display2();

    return 0;
}