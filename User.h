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
	Mode()
	{
		speed = 0;
		right = 0;
	}
	Mode(int size) : Mode()
	{
		this->size = size;
	}

	int getsize()
	{
		return size;
	}
	void setsize(int size)
	{
		this->size = size;
	}

	int speed = 0;
	int right = 0;
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

	User() {}


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

	void set(Mode& mode)
	{
		if (mode.getsize() == 200)
		{
			if (this->m200.speed < mode.speed)
				this->m200.speed = mode.speed;
			if (this->m200.right < mode.right)
				this->m200.right = mode.right;
		}
		if (mode.getsize() == 500)
		{
			if (this->m500.speed < mode.speed)
				this->m500.speed = mode.speed;
			if (this->m500.right < mode.right)
				this->m500.right = mode.right;
		}
		if (mode.getsize() == 1000)
		{
			if (this->m1000.speed < mode.speed)
				this->m1000.speed = mode.speed;
			if (this->m1000.right < mode.right)
				this->m1000.right = mode.right;
		}
	}
	int getspeed(int size)
	{
		if (size == 200)
			return m200.speed;
	}
	float getright(int size)
	{
		if (size == 200)
			return m200.right;
	}
};

