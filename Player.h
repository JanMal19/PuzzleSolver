#pragma once

#include <string>

using namespace std;

public class Player {

private:
    string name;

protected:

public:
    Player(const std::string& name);

    std::string getName() const;

    void setName(const std::string& newName);

};