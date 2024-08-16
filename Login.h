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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
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
			this->name_user->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name_user->ForeColor = System::Drawing::Color::Khaki;
			this->name_user->Location = System::Drawing::Point(57, 79);
			this->name_user->Name = L"name_user";
			this->name_user->Size = System::Drawing::Size(154, 18);
			this->name_user->TabIndex = 0;
			this->name_user->Text = L"имя пользователя";
			// 
			// pasword
			// 
			this->pasword->AutoSize = true;
			this->pasword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pasword->ForeColor = System::Drawing::Color::Khaki;
			this->pasword->Location = System::Drawing::Point(57, 145);
			this->pasword->Name = L"pasword";
			this->pasword->Size = System::Drawing::Size(64, 18);
			this->pasword->TabIndex = 1;
			this->pasword->Text = L"пароль";
			// 
			// textBox_pasword
			// 
			this->textBox_pasword->BackColor = System::Drawing::SystemColors::Info;
			this->textBox_pasword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_pasword->Location = System::Drawing::Point(50, 166);
			this->textBox_pasword->Name = L"textBox_pasword";
			this->textBox_pasword->Size = System::Drawing::Size(192, 26);
			this->textBox_pasword->TabIndex = 2;
			// 
			// textBox_log
			// 
			this->textBox_log->BackColor = System::Drawing::SystemColors::Info;
			this->textBox_log->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_log->Location = System::Drawing::Point(50, 100);
			this->textBox_log->Name = L"textBox_log";
			this->textBox_log->Size = System::Drawing::Size(192, 26);
			this->textBox_log->TabIndex = 3;
			// 
			// buttEnter
			// 
			this->buttEnter->BackColor = System::Drawing::Color::SteelBlue;
			this->buttEnter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttEnter->ForeColor = System::Drawing::Color::NavajoWhite;
			this->buttEnter->Location = System::Drawing::Point(112, 243);
			this->buttEnter->Name = L"buttEnter";
			this->buttEnter->Size = System::Drawing::Size(80, 32);
			this->buttEnter->TabIndex = 4;
			this->buttEnter->Text = L"Войти";
			this->buttEnter->UseVisualStyleBackColor = false;
			this->buttEnter->Click += gcnew System::EventHandler(this, &Login::buttEnter_Click);
			// 
			// Register
			// 
			this->Register->BackColor = System::Drawing::Color::Teal;
			this->Register->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register->ForeColor = System::Drawing::Color::NavajoWhite;
			this->Register->Location = System::Drawing::Point(50, 327);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(192, 38);
			this->Register->TabIndex = 5;
			this->Register->Text = L"Зарегестрироваться";
			this->Register->UseVisualStyleBackColor = false;
			this->Register->Click += gcnew System::EventHandler(this, &Login::Register_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateGray;
			this->ClientSize = System::Drawing::Size(284, 377);
			this->Controls->Add(this->Register);
			this->Controls->Add(this->buttEnter);
			this->Controls->Add(this->textBox_log);
			this->Controls->Add(this->textBox_pasword);
			this->Controls->Add(this->pasword);
			this->Controls->Add(this->name_user);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
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
