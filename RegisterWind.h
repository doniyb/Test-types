#pragma once

namespace Tetsttypes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class RegisterWind : public System::Windows::Forms::Form
	{
	public:
		RegisterWind(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~RegisterWind()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ RegLog;
	private: System::Windows::Forms::TextBox^ RegPassw;
	private: System::Windows::Forms::Label^ labRegLog;
	private: System::Windows::Forms::Label^ labRegPassw;
	private: System::Windows::Forms::Button^ buttRegReg;
	private: System::Windows::Forms::Label^ ErrorLogin;
	private: System::Windows::Forms::Label^ ErrorPassw;




	protected:


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterWind::typeid));
			this->RegLog = (gcnew System::Windows::Forms::TextBox());
			this->RegPassw = (gcnew System::Windows::Forms::TextBox());
			this->labRegLog = (gcnew System::Windows::Forms::Label());
			this->labRegPassw = (gcnew System::Windows::Forms::Label());
			this->buttRegReg = (gcnew System::Windows::Forms::Button());
			this->ErrorLogin = (gcnew System::Windows::Forms::Label());
			this->ErrorPassw = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// RegLog
			// 
			this->RegLog->BackColor = System::Drawing::SystemColors::Info;
			this->RegLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RegLog->Location = System::Drawing::Point(42, 100);
			this->RegLog->Name = L"RegLog";
			this->RegLog->Size = System::Drawing::Size(200, 26);
			this->RegLog->TabIndex = 0;
			// 
			// RegPassw
			// 
			this->RegPassw->BackColor = System::Drawing::SystemColors::Info;
			this->RegPassw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RegPassw->Location = System::Drawing::Point(42, 166);
			this->RegPassw->Name = L"RegPassw";
			this->RegPassw->Size = System::Drawing::Size(200, 26);
			this->RegPassw->TabIndex = 1;
			// 
			// labRegLog
			// 
			this->labRegLog->AutoSize = true;
			this->labRegLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labRegLog->ForeColor = System::Drawing::Color::Khaki;
			this->labRegLog->Location = System::Drawing::Point(46, 77);
			this->labRegLog->Name = L"labRegLog";
			this->labRegLog->Size = System::Drawing::Size(167, 20);
			this->labRegLog->TabIndex = 2;
			this->labRegLog->Text = L"им€ пользовател€";
			this->labRegLog->Click += gcnew System::EventHandler(this, &RegisterWind::labRegLog_Click);
			// 
			// labRegPassw
			// 
			this->labRegPassw->AutoSize = true;
			this->labRegPassw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labRegPassw->ForeColor = System::Drawing::Color::Khaki;
			this->labRegPassw->Location = System::Drawing::Point(46, 144);
			this->labRegPassw->Name = L"labRegPassw";
			this->labRegPassw->Size = System::Drawing::Size(70, 20);
			this->labRegPassw->TabIndex = 3;
			this->labRegPassw->Text = L"пароль";
			// 
			// buttRegReg
			// 
			this->buttRegReg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttRegReg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttRegReg->Location = System::Drawing::Point(42, 266);
			this->buttRegReg->Name = L"buttRegReg";
			this->buttRegReg->Size = System::Drawing::Size(200, 36);
			this->buttRegReg->TabIndex = 4;
			this->buttRegReg->Text = L"«арегестрироватьс€";
			this->buttRegReg->UseVisualStyleBackColor = false;
			this->buttRegReg->Click += gcnew System::EventHandler(this, &RegisterWind::buttRegReg_Click);
			// 
			// ErrorLogin
			// 
			this->ErrorLogin->AutoSize = true;
			this->ErrorLogin->Location = System::Drawing::Point(57, 92);
			this->ErrorLogin->Name = L"ErrorLogin";
			this->ErrorLogin->Size = System::Drawing::Size(0, 16);
			this->ErrorLogin->TabIndex = 5;
			this->ErrorLogin->UseCompatibleTextRendering = true;
			this->ErrorLogin->Click += gcnew System::EventHandler(this, &RegisterWind::label1_Click);
			// 
			// ErrorPassw
			// 
			this->ErrorPassw->AutoSize = true;
			this->ErrorPassw->Location = System::Drawing::Point(57, 164);
			this->ErrorPassw->Name = L"ErrorPassw";
			this->ErrorPassw->Size = System::Drawing::Size(0, 13);
			this->ErrorPassw->TabIndex = 6;
			// 
			// RegisterWind
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateGray;
			this->ClientSize = System::Drawing::Size(284, 377);
			this->Controls->Add(this->ErrorPassw);
			this->Controls->Add(this->ErrorLogin);
			this->Controls->Add(this->buttRegReg);
			this->Controls->Add(this->labRegPassw);
			this->Controls->Add(this->labRegLog);
			this->Controls->Add(this->RegPassw);
			this->Controls->Add(this->RegLog);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RegisterWind";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RegisterWind";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttRegReg_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void labRegLog_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
