#pragma once

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
};

