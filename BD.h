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

		connStringBuilder = gcnew SqlConnectionStringBuilder();
		connStringBuilder->DataSource = "DESKTOP-5J3M7TI\\SQLSERVERDONIYB";
		connStringBuilder->InitialCatalog = "Type_test";
		connStringBuilder->IntegratedSecurity = true;

		conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));
	}

	void Insert(String^ login, String^ password)
	{
		try {
			ConnectDB();

			String^ cmdText = "INSERT INTO dbo.akkaunt(name, pasword) VALUES(@loginVstavka, @passwordVstavka)";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);


			cmd->Parameters->AddWithValue("@loginVstavka", login);
			cmd->Parameters->AddWithValue("@passwordVstavka", password);

			conn->Open();
			cmd->ExecuteNonQuery();
		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}

	//проверка логина
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

	Mode ReadRecord(String^ login)
	{
		try {
			ConnectDB();
			conn->Open();
			Mode record(200);

			String^ cmdText = "select dbo.record_speed.speed200, dbo.record_speed.right200 from dbo.akkaunt join dbo.record_speed on dbo.akkaunt.id = dbo.record_speed.akkaunt_id where dbo.akkaunt.id = @idVstavka";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
			
			String^ id = Getid(login);
			cmd->Parameters->AddWithValue("@idVstavka", id);
			
			SqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read())
			{
				record.speed = Convert::ToInt16(reader["speed200"]->ToString());
				record.right = Convert::ToDouble(reader["right200"]->ToString());
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

	void Change(User& user, int size)
	{
		{
			try {
				ConnectDB();

				String^ cmdText = "update dbo.record_speed set speed200 = @speedVstavka, right200 = @rightVstavka where akkaunt_id = @idVstavka";
				SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

				conn->Open();

				cmd->Parameters->AddWithValue("@speedVstavka", user.getspeed(200));
				cmd->Parameters->AddWithValue("@rightVstavka", user.getright(200));
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

