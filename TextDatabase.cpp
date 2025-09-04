#include "pch.h"
#include "TextDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>

const string TextDatabase::playerDatabaseName = "ListaGraczy.txt";

bool TextDatabase::DataBaseExist(const std::string& path) {
    std::ifstream f(path);
    return f.good();
}

bool TextDatabase::SavePlayerToDatabase(Player p) {
    if (!DataBaseExist(playerDatabaseName))
    {
        std::ofstream createFile(playerDatabaseName);
        createFile.close();
    }

    std::ifstream inFile(playerDatabaseName);
    std::string line;
    while (std::getline(inFile, line))
    {
        if (line == p.getName())
        {
            System::Windows::Forms::MessageBox::Show("Gracz o podanej nazwie ju¿ istnieje!\n");
            return false;
        }
    }

    inFile.close();

    std::ofstream out(playerDatabaseName, std::ios::app);
    out << p.getName() << "\n";

    return true;
}

std::vector<std::string> TextDatabase::GetPlayers() {
    std::ifstream in(playerDatabaseName);
    std::vector<std::string> names;
    std::string line;

    while (std::getline(in, line))
    {
        if (!line.empty())
            names.push_back(line);
    }

    return names;
}