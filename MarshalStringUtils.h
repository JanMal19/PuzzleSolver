#pragma once

#include "pch.h"
#include <string>
#include <iostream>
using namespace std;
using namespace System;

public class MarshalStringUtils
{
public: static System::Void MarshalString(System::String ^ s, std::string& os);

public: static System::Void MarshalString(System::String^ s, wstring& os);
};

