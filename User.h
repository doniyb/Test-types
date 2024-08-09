#pragma once
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Mode
{
private:
	int size;

public:
	Mode(int size)
	{
		this->size = size;
	}

	int speed=0;
	float right=0;
};

class User
{
private:
	std::string name;
	std::string password;

	Mode m200{ 200 };
	Mode m500{ 500 };
	Mode m1000{ 1000 };

public:

	User(){}
	

	void setName(std::string name)
	{
		this->name = name;
	}
	void setPassword(std::string password)
	{
		this->password = password;
	}
	std::string getName()
	{
		return name;
	}
	std::string getPassword()
	{
		return password;
	}
};

