#include <iostream>

using namespace std;

class Entity
{
	int name = 1, id = 1;
public:
	Entity()
	{
		display();
		cout << "\nInside Entity constructor";
	}
	Entity(int a, int b)
	{
		cout << "\nInside Entity parameterized constructor";
		name = a;
		id = b;
	}
	~Entity()
	{
		cout << "\nInside Entity destructor";
	}

	void display()
	{
		cout << "\n Name:"<< name << " ID:" << id;
	}

};

class Player : public Entity
{
	int x = 5, y = 5;
public:
	Player()
	{
		display();
		cout << "\nInside constructor";
		//x = y = 0;
	}
	Player(int a, int b)
	{
		cout << "\nInside parameterized constructor";
		x = a;
		y = b;
	}
	Player(const Player& obj2)
	{
		cout << "\n Inside Copy constructor.";
		x = obj2.x;
		y = obj2.y;
	}

	~Player()
	{
		cout << "\nInside destructor";
	}

	void display()
	{
		cout << "\nInside display";
		cout << "\n X:"<< x << " Y:" << y;
	}

	Player& operator=(const Player& o1);
};

Player& Player::operator=(const Player& o1)
{
	cout << "\n Inside overloaded operator=";
	Player o2(o1.x, o1.y);
	return o2;
}


int main()
{
	Player player(1, 2);
	Player p2;

	p2 = player;

	p2.display();

	return 0;
}