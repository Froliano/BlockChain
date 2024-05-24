#include <iostream>

class Block
{
private:
    int index;
    std::string hash;
    std::string previousHash;
    std::tm* time;
    std::string data;

public:
    Block()
    {
        std::time_t t = std::time(nullptr);
        std::tm* time = std::localtime(&t);

        std::cout << "Date actuelle : "
            << (time->tm_year + 1900) << '-'
            << (time->tm_mon + 1) << '-'
            << time->tm_mday
            << std::endl;
    }

    ~Block(){}

    void print()
    {
        std::cout << "index : " << index << std::endl;
        std::cout << "hash : " << hash << std::endl;
        std::cout << "previous hash : " << previousHash << std::endl;
        std::cout << "date/heure : " << time << std::endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    return 0;
}