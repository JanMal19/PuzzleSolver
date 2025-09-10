#pragma once

#include "pch.h"
#include "Player.h"


Player::Player(const std::string& name) : name(name) {}

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string& newName) {
    name = newName;
}