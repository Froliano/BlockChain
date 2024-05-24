#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <vector>

std::string calculateHash(int index, const std::string& previousHash, const std::string& data, const std::tm& time)
{
    std::hash<std::string> hasher;
    std::stringstream ss;
    ss << index << previousHash << data << std::put_time(&time, "%Y-%m-%d %H:%M:%S");
    size_t hashValue = hasher(ss.str());
    std::stringstream hexStream;
    hexStream << std::hex << hashValue;
    return hexStream.str();
}

class Block
{
protected:
    int index;
    std::string hash;
    std::string previousHash;
    std::tm time;
    std::string data;

public:
    Block(int index, const std::string& data, Block* previousBlock = nullptr) : index(index), data(data)
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
        localtime_s(&time, &t);
        hash = calculateHash(index, previousHash, data, time);
    }

    void print()
    {
        std::cout << "hash : " << hash << std::endl;
        std::cout << "previous hash : " << previousHash << std::endl;
        std::cout << "Date actuelle : "
            << (time.tm_year + 1900) << '-'
            << (time.tm_mon + 1) << '-'
            << time.tm_mday << " "
            << time.tm_hour << ':'
            << time.tm_min << ':'
            << time.tm_sec
            << std::endl;
        std::cout << "donnee : " << data << "\n" << std::endl;
    }

    std::string getHash()
    {
        return hash;
    }
};

class Blockchain
{
private:
    std::vector<Block> chain;

public:
    Blockchain()
    {
        chain.push_back(Block(0, "Genesis Block"));
    }

    void addBlock(const std::string& data)
    {
        int index = chain.size();
        Block* previousBlock = &chain.back();
        chain.push_back(Block(index, data, previousBlock));
    }

    void printBlockchain()
    {
        for (auto& block : chain)
        {
            block.print();
        }
    }
};

int main()
{
    Blockchain myBlockchain;

    Block block1(1, "");
    myBlockchain.addBlock("Ceci est une donnee");

    Block block2(2, "", &block1);
    myBlockchain.addBlock("Les nuages dansaient lentement dans le ciel, peignant des formes mysterieuses au-dessus de la ville endormie.");


    Block block3(3, "", &block2);
    myBlockchain.addBlock("Le parfum enivrant des roses emplissait l'air, transportant les souvenirs d'un ete lointain.");

    Block block4(4, "", &block3);
    myBlockchain.addBlock("Les eclats de rire resonnaient a travers la foret, accompagnant le murmure apaisant du ruisseau voisin.");

    std::cout << "Blockchain Original :" << std::endl;
    myBlockchain.printBlockchain();
    return 0;
}

