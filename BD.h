#pragma once
#include "User.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class BD
{
public:
	BD(){}

	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStringBuilder;

	//подключение к БД
	void ConnectDB()
	{
		//Data Source=DESKTOP-5J3M7TI\SQLSERVERDONIYB;Initial Catalog=Type_test;Integrated Security=True;Trust Server Certificate=True
		//Надо что-то менять
		connStringBuilder = gcnew SqlConnectionStringBuilder();
		connStringBuilder->DataSource = "DESKTOP-5J3M7TI\\SQLSERVERDONIYB";
		connStringBuilder->InitialCatalog = "Type_test";
		connStringBuilder->IntegratedSecurity = true;

		conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));

		
	}

	// вставка логина и пароля в БД
	void InsertAk(String^ login, String^ password)
	{
		try {
			ConnectDB();
			conn->Open();
			String^ cmdText = "INSERT INTO dbo.akkaunt(name, pasword) VALUES(@loginVstavka, @passwordVstavka)";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			cmd->Parameters->AddWithValue("@loginVstavka", login);
			cmd->Parameters->AddWithValue("@passwordVstavka", password);
			
			cmd->ExecuteNonQuery();
		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}

	//вставка рекордов в БД (0)
	void InsertRec(String^ login)
	{
		try {
			ConnectDB();
			conn->Open();
			String^ cmdText = "INSERT INTO dbo.record_speed(akkaunt_id, speed200, right200, speed500, right500, speed1000, right1000, hras_speed, hras_right) VALUES(@idVstavka, 0, 0, 0, 0, 0, 0, 0, 0)";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			String^ id = Getid(login);
			cmd->Parameters->AddWithValue("@loginVstavka", login);
			cmd->Parameters->AddWithValue("@idVstavka", id);


			cmd->ExecuteNonQuery();
		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}

	//проверка логина и пароля
	bool Check_login_and_password(String^ login, String^ password)
	{
		try {
			ConnectDB();

			String^ cmdText = "SELECT name, pasword FROM dbo.akkaunt WHERE name = @loginVstavka and pasword = @passwordVstavka";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			cmd->Parameters->AddWithValue("@loginVstavka", login);
			cmd->Parameters->AddWithValue("@passwordVstavka", password);

			conn->Open();

			SqlDataReader^ reader = cmd->ExecuteReader();


			return reader->HasRows;

		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}

	bool CheckLogin(String^ login)
	{
		try {
			ConnectDB();
			conn->Open();

			String^ cmdText = "SELECT name FROM dbo.akkaunt WHERE name = @loginVstavka";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			cmd->Parameters->AddWithValue("@loginVstavka", login);

			SqlDataReader^ reader = cmd->ExecuteReader();


			return reader->HasRows;
		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}

	bool CheckPassword(String^ password)
	{
		try {
			ConnectDB();
			conn->Open();

			String^ cmdText = "SELECT pasword FROM dbo.akkaunt WHERE pasword = @passwordVstavka";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			cmd->Parameters->AddWithValue("@passwordVstavka", password);

			SqlDataReader^ reader = cmd->ExecuteReader();

			return reader->HasRows;
		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}

	bool CheckRegist(String^ login, String^ password)
	{
		return CheckLogin(login) || CheckPassword(password);
	}

	//получение id
	String^ Getid(String^ login)
	{
		try {
			ConnectDB();

			String^ cmdText = "SELECT id FROM dbo.akkaunt WHERE name = @loginVstavka";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			cmd->Parameters->AddWithValue("@loginVstavka", login);

			conn->Open();

			SqlDataReader^ reader = cmd->ExecuteReader();
			String^ id;
			while (reader->Read())
			{
				id = reader["id"]->ToString();
			}

			return id;
		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}

	//чтение рекордов из БД
	Mode ReadRecord(String^ login, int size)
	{
		try {
			ConnectDB();
			conn->Open();
			Mode record(size);
			String^ cmdText;
			if (size == 200)
				cmdText = "select dbo.record_speed.speed200, dbo.record_speed.right200 from dbo.akkaunt join dbo.record_speed on dbo.akkaunt.id = dbo.record_speed.akkaunt_id where dbo.akkaunt.id = @idVstavka";
			if (size == 500)
				cmdText = "select dbo.record_speed.speed500, dbo.record_speed.right500 from dbo.akkaunt join dbo.record_speed on dbo.akkaunt.id = dbo.record_speed.akkaunt_id where dbo.akkaunt.id = @idVstavka";
			if (size == 1000)
				cmdText = "select dbo.record_speed.speed1000, dbo.record_speed.right1000 from dbo.akkaunt join dbo.record_speed on dbo.akkaunt.id = dbo.record_speed.akkaunt_id where dbo.akkaunt.id = @idVstavka";
			if (size == 10)
				cmdText = "select dbo.record_speed.hras_speed, dbo.record_speed.hras_right from dbo.akkaunt join dbo.record_speed on dbo.akkaunt.id = dbo.record_speed.akkaunt_id where dbo.akkaunt.id = @idVstavka";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
			
			String^ id = Getid(login);
			cmd->Parameters->AddWithValue("@idVstavka", id);
			
			SqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read())
			{
				if (size == 200 && reader["speed200"]->ToString()!="")
				{
					record.speed = Convert::ToInt16(reader["speed200"]->ToString());
					record.right = Convert::ToDouble(reader["right200"]->ToString());
				}
				if (size == 500 && reader["speed500"]->ToString() != "")
				{
					record.speed = Convert::ToInt16(reader["speed500"]->ToString());
					record.right = Convert::ToDouble(reader["right500"]->ToString());
				}
				if (size == 1000 && reader["speed1000"]->ToString() != "")
				{
					record.speed = Convert::ToInt16(reader["speed1000"]->ToString());
					record.right = Convert::ToDouble(reader["right1000"]->ToString());
				}
				if (size == 10 && reader["hras_speed"]->ToString() != "")
				{
					record.speed = Convert::ToInt16(reader["hras_speed"]->ToString());
					record.right = Convert::ToDouble(reader["hras_right"]->ToString());
				}
			}

			return record;
		}
		finally {
			if (conn != nullptr) 
			{
				conn->Close();
			}
		}
	}

	//сохранение рекордов
	void Change(User& user, int size)
	{
		{
			try {
				ConnectDB();
				String^ cmdText;
				if(size==200)
					cmdText = "update dbo.record_speed set speed200 = @speedVstavka, right200 = @rightVstavka where akkaunt_id = @idVstavka";
				if (size == 500)
					cmdText = "update dbo.record_speed set speed500 = @speedVstavka, right500 = @rightVstavka where akkaunt_id = @idVstavka";
				if (size == 1000)
					cmdText = "update dbo.record_speed set speed1000 = @speedVstavka, right1000 = @rightVstavka where akkaunt_id = @idVstavka";
				if (size == 10)
					cmdText = "update dbo.record_speed set hras_speed = @speedVstavka, hras_right = @rightVstavka where akkaunt_id = @idVstavka";
				
				SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

				conn->Open();
				if (size == 200)
				{
					cmd->Parameters->AddWithValue("@speedVstavka", user.getspeed(200));
					cmd->Parameters->AddWithValue("@rightVstavka", user.getright(200));
				}
				if (size == 500)
				{
					cmd->Parameters->AddWithValue("@speedVstavka", user.getspeed(500));
					cmd->Parameters->AddWithValue("@rightVstavka", user.getright(500));
				}
				if (size == 1000)
				{
					cmd->Parameters->AddWithValue("@speedVstavka", user.getspeed(1000));
					cmd->Parameters->AddWithValue("@rightVstavka", user.getright(1000));
				}
				if (size == 10)
				{
					cmd->Parameters->AddWithValue("@speedVstavka", user.getspeed(10));
					cmd->Parameters->AddWithValue("@rightVstavka", user.getright(10));
				}
				cmd->Parameters->AddWithValue("@idVstavka", Getid(gcnew String(user.getName().c_str())));

				cmd->ExecuteNonQuery();
			}
			finally {
				if (conn != nullptr) {
					conn->Close();
				}
			}
		}
	}
};

