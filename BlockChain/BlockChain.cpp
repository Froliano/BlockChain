#include <iostream>

class Block
{
private:
    int index;
    std::string hash;
    std::string previousHash;
    std::tm time;
    std::string data;

public:

    Block(int index, std::string data, Block* previousBlock = nullptr) : index(index), data(data)
    {

        if (previousBlock == nullptr)
        {
            previousHash = "0";
        }
        else
        {
            previousHash = previousBlock->getHash();
        }

        std::time_t t = std::time(nullptr);
        std::tm time;
        localtime_s(&time, &t);

    }

    ~Block(){}

    void print()
    {
        std::cout << "index : " << index << std::endl;
        std::cout << "hash : " << hash << std::endl;
        std::cout << "previous hash : " << previousHash << std::endl;
        std::cout << "Date actuelle : "
            << (time.tm_year + 1900) << '-'
            << (time.tm_mon + 1) << '-'
            << time.tm_mday
            << std::endl;
        std::cout << "donnee : " << data << std::endl;
    }

    std::string getHash()
    {
        return hash;
    }

};

int main()
{
    std::cout << "Hello World!\n";

    return 0;
}