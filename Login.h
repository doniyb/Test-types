#pragma once


namespace Tetsttypes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Login1
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ name_user;
	private: System::Windows::Forms::Label^ pasword;
	private: System::Windows::Forms::TextBox^ textBox_pasword;

	private: System::Windows::Forms::TextBox^ textBox_log;
	private: System::Windows::Forms::Button^ buttEnter;
	private: System::Windows::Forms::Button^ Register;



	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->name_user = (gcnew System::Windows::Forms::Label());
			this->pasword = (gcnew System::Windows::Forms::Label());
			this->textBox_pasword = (gcnew System::Windows::Forms::TextBox());
			this->textBox_log = (gcnew System::Windows::Forms::TextBox());
			this->buttEnter = (gcnew System::Windows::Forms::Button());
			this->Register = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// name_user
			// 
			this->name_user->AutoSize = true;
			this->name_user->Location = System::Drawing::Point(57, 53);
			this->name_user->Name = L"name_user";
			this->name_user->Size = System::Drawing::Size(101, 13);
			this->name_user->TabIndex = 0;
			this->name_user->Text = L"имя пользователя";
			// 
			// pasword
			// 
			this->pasword->AutoSize = true;
			this->pasword->Location = System::Drawing::Point(57, 125);
			this->pasword->Name = L"pasword";
			this->pasword->Size = System::Drawing::Size(43, 13);
			this->pasword->TabIndex = 1;
			this->pasword->Text = L"пароль";
			// 
			// textBox_pasword
			// 
			this->textBox_pasword->Location = System::Drawing::Point(60, 141);
			this->textBox_pasword->Name = L"textBox_pasword";
			this->textBox_pasword->Size = System::Drawing::Size(171, 20);
			this->textBox_pasword->TabIndex = 2;
			// 
			// textBox_log
			// 
			this->textBox_log->Location = System::Drawing::Point(60, 69);
			this->textBox_log->Name = L"textBox_log";
			this->textBox_log->Size = System::Drawing::Size(171, 20);
			this->textBox_log->TabIndex = 3;
			// 
			// buttEnter
			// 
			this->buttEnter->Location = System::Drawing::Point(110, 167);
			this->buttEnter->Name = L"buttEnter";
			this->buttEnter->Size = System::Drawing::Size(80, 24);
			this->buttEnter->TabIndex = 4;
			this->buttEnter->Text = L"Войти";
			this->buttEnter->UseVisualStyleBackColor = true;
			this->buttEnter->Click += gcnew System::EventHandler(this, &Login::buttEnter_Click);
			// 
			// Register
			// 
			this->Register->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register->Location = System::Drawing::Point(72, 224);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(159, 25);
			this->Register->TabIndex = 5;
			this->Register->Text = L"Зарегестрироваться";
			this->Register->UseVisualStyleBackColor = true;
			this->Register->Click += gcnew System::EventHandler(this, &Login::Register_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->Register);
			this->Controls->Add(this->buttEnter);
			this->Controls->Add(this->textBox_log);
			this->Controls->Add(this->textBox_pasword);
			this->Controls->Add(this->pasword);
			this->Controls->Add(this->name_user);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttEnter_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Register_Click(System::Object^ sender, System::EventArgs^ e);
};
}
