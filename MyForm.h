#pragma once

namespace Tetsttypes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textInput;
	private: System::Windows::Forms::TextBox^ textOutput;
	private: System::Windows::Forms::Label^ Typed;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ label_timer;
	private: System::ComponentModel::IContainer^ components;

	protected:


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textInput = (gcnew System::Windows::Forms::TextBox());
			this->textOutput = (gcnew System::Windows::Forms::TextBox());
			this->Typed = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_timer = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textInput
			// 
			this->textInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textInput->Location = System::Drawing::Point(71, 192);
			this->textInput->Name = L"textInput";
			this->textInput->Size = System::Drawing::Size(243, 35);
			this->textInput->TabIndex = 0;
			this->textInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxInp_TextChanged);
			// 
			// textOutput
			// 
			this->textOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textOutput->Location = System::Drawing::Point(71, 68);
			this->textOutput->Name = L"textOutput";
			this->textOutput->ReadOnly = true;
			this->textOutput->Size = System::Drawing::Size(243, 35);
			this->textOutput->TabIndex = 2;
			this->textOutput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxOut_TextChanged);
			// 
			// Typed
			// 
			this->Typed->AutoSize = true;
			this->Typed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Typed->Location = System::Drawing::Point(164, 250);
			this->Typed->Name = L"Typed";
			this->Typed->Size = System::Drawing::Size(150, 25);
			this->Typed->TabIndex = 3;
			this->Typed->Text = L"Ќабранные: 0";
			this->Typed->Click += gcnew System::EventHandler(this, &MyForm::labelTyped);
			// 
			// timer
			// 
			this->timer->Interval = 6000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// label_timer
			// 
			this->label_timer->AutoSize = true;
			this->label_timer->Location = System::Drawing::Point(68, 9);
			this->label_timer->Name = L"label_timer";
			this->label_timer->Size = System::Drawing::Size(46, 13);
			this->label_timer->TabIndex = 4;
			this->label_timer->Text = L"¬рем€: ";
			this->label_timer->Click += gcnew System::EventHandler(this, &MyForm::label_timer_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 461);
			this->Controls->Add(this->label_timer);
			this->Controls->Add(this->Typed);
			this->Controls->Add(this->textOutput);
			this->Controls->Add(this->textInput);
			this->Name = L"MyForm";
			this->Text = L"Speed Print";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBoxOut_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxInp_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void labelTyped(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void label_timer_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	
};


	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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

	protected:


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->name_user = (gcnew System::Windows::Forms::Label());
			this->pasword = (gcnew System::Windows::Forms::Label());
			this->textBox_pasword = (gcnew System::Windows::Forms::TextBox());
			this->textBox_log = (gcnew System::Windows::Forms::TextBox());
			this->buttEnter = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->name_user->AutoSize = true;
			this->name_user->Location = System::Drawing::Point(57, 53);
			this->name_user->Name = L"name_user";
			this->name_user->Size = System::Drawing::Size(101, 13);
			this->name_user->TabIndex = 0;
			this->name_user->Text = L"им€ пользовател€";
			this->pasword->AutoSize = true;
			this->pasword->Location = System::Drawing::Point(57, 125);
			this->pasword->Name = L"pasword";
			this->pasword->Size = System::Drawing::Size(43, 13);
			this->pasword->TabIndex = 1;
			this->pasword->Text = L"пароль";
			this->textBox_pasword->Location = System::Drawing::Point(60, 141);
			this->textBox_pasword->Name = L"textBox_pasword";
			this->textBox_pasword->Size = System::Drawing::Size(171, 20);
			this->textBox_pasword->TabIndex = 2;
			this->textBox_log->Location = System::Drawing::Point(60, 69);
			this->textBox_log->Name = L"textBox_log";
			this->textBox_log->Size = System::Drawing::Size(171, 20);
			this->textBox_log->TabIndex = 3;
			this->buttEnter->Location = System::Drawing::Point(110, 167);
			this->buttEnter->Name = L"buttEnter";
			this->buttEnter->Size = System::Drawing::Size(80, 24);
			this->buttEnter->TabIndex = 4;
			this->buttEnter->Text = L"¬ойти";
			this->buttEnter->UseVisualStyleBackColor = true;
			this->buttEnter->Click += gcnew System::EventHandler(this, &Login::buttEnter_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
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
	};



}

