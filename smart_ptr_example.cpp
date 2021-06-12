#include <iostream>
#include <memory>

class Player
{
	int x, y;

public:
	Player(int x, int y)
	{
		std::cout << "Constructor called" << std::endl;

		this->x = x;
		this->y = y;
	}

	~Player()
	{
		std::cout << "Destructor called for " << this << std::endl;
	}

	friend std::ostream &operator<<(std::ostream &o1, std::unique_ptr<Player> &obj);
	friend std::ostream &operator<<(std::ostream &o1, Player *obj);
};

std::ostream &operator<<(std::ostream &o1, std::unique_ptr<Player> &obj)
{
	o1 << "X:" << obj->x << " Y:" << obj->y << std::endl;
	return o1;
}

std::ostream &operator<<(std::ostream &o1, Player *obj)
{
	o1 << "X:" << obj->x << " Y:" << obj->y << std::endl;
	return o1;
}

int main()
{
	Player *obj = new Player(1, 2);
	std::cout << obj;

	std::shared_ptr<Player> s1 = std::make_shared<Player>(10, 200);
	std::cout << s1;

	//std::cin.get();
	{
		std::unique_ptr<Player> obj2 = std::make_unique<Player>(3, 4);
		std::cout << obj2;

		// We cannot write below line --Unique Pointers cannot be copied
		//std::unique_ptr<Player> e0 = obj2;

		// On the other hand, shared pts can be copied
		std::shared_ptr<Player> s2 = s1;
		std::cout << s2;

		std::cin.get();
	}

	std::cout << s1;

	return 0;
}