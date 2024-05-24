#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

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
private:
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

int main() {
    Block genesisBlock(0, "Genesis Block");
    Block block1(1, "Ceci est une donnee", &genesisBlock);
    Block block2(2, "Les nuages dansaient lentement dans le ciel, peignant des formes mysterieuses au-dessus de la ville endormie.", &block1);
    Block block3(3, "Le parfum enivrant des roses emplissait l'air, transportant les souvenirs d'un ete lointain.", &block2);
    Block block4(4, "Les eclats de rire resonnaient a travers la foret, accompagnant le murmure apaisant du ruisseau voisin.", &block3);
    Block block5(5, "Sous le clair de lune argente, les etoiles semblaient chuchoter des secrets anciens a ceux qui ecoutaient attentivement.", &block4);
    Block block6(6, "Les pages du livre tournaient avec impatience, revelant des mondes imaginaires et des aventures inattendues a chaque tournant.", &block5);
    Block block7(7, "Le vent soufflait doucement a travers les champs de ble, apportant une sensation de paix et de tranquillite.", &block6);
    Block block8(8, "Les enfants couraient dans le parc, leurs rires s'elevaient dans l'air frais du matin.", &block7);
    Block block9(9, "Le crepuscule enveloppait la ville, les lumieres des lampadaires se refletant sur les paves mouilles.", &block8);
    Block block10(10, "Les vagues s'ecrasaient contre les rochers, creant une melodie apaisante et eternelle.", &block9);


    genesisBlock.print();
    block1.print();
    block2.print();
    block3.print();
    block4.print();
    block5.print();
    block6.print();
    block7.print();
    block8.print();
    block9.print();
    block10.print();


    return 0;
}
