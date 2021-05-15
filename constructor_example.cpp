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
	~Player()
	{
		cout << "\nInside destructor";
	}

	void display()
	{
		cout << "\n X:"<< x << " Y:" << y;
	}
};

int main()
{
	Player player;

	player.display();

	return 0;
}