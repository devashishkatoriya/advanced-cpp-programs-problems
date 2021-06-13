
#include <iostream>

class HashMap
{
    std::string *hashArray;
    int n;

    const int hash_function(const std::string &input_str)
    {
        return (input_str[input_str.length() - 1] + input_str.length() + 7) % n;
    }

    int findEmptyPos(const std::string &input_str)
    {
        const int hash_val = hash_function(input_str);

        if (hashArray[hash_val] == "" || hashArray[hash_val] == input_str)
        {
            return hash_val;
        }
        else
        {
            int temp = (hash_val + 1) % n;

            while (temp != hash_val)
            {
                if (hashArray[temp] == "" || hashArray[temp] == input_str)
                    return temp;
                temp = (temp + 1) % n;
            }
            return -1;
        }
    }

public:
    HashMap(const int &num)
    {
        n = num;
        hashArray = new std::string[num];

        for (int i = 0; i < n; i++)
        {
            hashArray[i] = "";
        }
    }

    int size() const
    {
        return n;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << hashArray[i] << std::endl;
        }
    }

    const int checkIfPresent(const std::string &input_str)
    {
        const int hash_val = hash_function(input_str);

        if (hashArray[hash_val] == input_str)
        {
            return hash_val;
        }
        else if (hashArray[hash_val] == "")
        {
            return -1;
        }
        else
        {
            int temp = (hash_val + 1) % n;

            while (temp != hash_val)
            {
                if (hashArray[temp] == "")
                    return -1;
                else if (hashArray[temp] == input_str)
                    return temp;
                temp = (temp + 1) % n;
            }
            return -1;
        }
    }

    bool insert(const std::string &input_str)
    {
        int position = findEmptyPos(input_str);

        if (position == -1)
        {
            std::cout << "HashTable is full." << std::endl;
            return false;
        }
        else
        {
            hashArray[position] = input_str;
            return true;
        }
    }

    bool remove(const std::string &input_str)
    {
        int position = checkIfPresent(input_str);

        if (position == -1)
        {
            std::cout << "Key not found." << std::endl;
            return false;
        }
        else
        {
            hashArray[position] = "";
            return true;
        }
    }
};

int main()
{
    HashMap hm(5);

    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("World") << std::endl;
    std::cout << hm.insert("How") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;

    std::cout << hm.remove("Hello") << std::endl;
    std::cout << hm.remove("Hello") << std::endl;
    std::cout << hm.remove("Www") << std::endl;

    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;
    std::cout << hm.insert("Hello") << std::endl;

    for (int i = 0; i < 21; i++)
    {
        std::string temp = "Hello";
        std::string seed = "Hello";

        for (int j = 0; j < i; j++)
            temp += seed;
        std::cout << hm.insert(temp) << std::endl;
    }

    hm.display();

    return 0;
}