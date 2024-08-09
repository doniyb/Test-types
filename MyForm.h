#pragma once
#include "User.h"

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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ profLog;
	private: System::Windows::Forms::Button^ buttStart200;

	private: System::Windows::Forms::Label^ prof_speed200;
	private: System::Windows::Forms::Label^ prof_200;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ prof_right200;






	private: System::ComponentModel::IContainer^ components;

	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->prof_right200 = (gcnew System::Windows::Forms::Label());
			this->buttStart200 = (gcnew System::Windows::Forms::Button());
			this->prof_speed200 = (gcnew System::Windows::Forms::Label());
			this->prof_200 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->profLog = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textInput
			// 
			this->textInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textInput->Location = System::Drawing::Point(80, 173);
			this->textInput->Name = L"textInput";
			this->textInput->Size = System::Drawing::Size(243, 35);
			this->textInput->TabIndex = 0;
			this->textInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxInp_TextChanged);
			// 
			// textOutput
			// 
			this->textOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textOutput->Location = System::Drawing::Point(80, 112);
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
			this->Typed->Location = System::Drawing::Point(173, 240);
			this->Typed->Name = L"Typed";
			this->Typed->Size = System::Drawing::Size(150, 25);
			this->Typed->TabIndex = 3;
			this->Typed->Text = L"Набранные: 0";
			this->Typed->Click += gcnew System::EventHandler(this, &MyForm::labelTyped);
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// label_timer
			// 
			this->label_timer->AutoSize = true;
			this->label_timer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_timer->Location = System::Drawing::Point(8, 3);
			this->label_timer->Name = L"label_timer";
			this->label_timer->Size = System::Drawing::Size(110, 20);
			this->label_timer->TabIndex = 4;
			this->label_timer->Text = L"Время 00 : 00";
			this->label_timer->Click += gcnew System::EventHandler(this, &MyForm::label_timer_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(384, 469);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->prof_right200);
			this->tabPage1->Controls->Add(this->prof_speed200);
			this->tabPage1->Controls->Add(this->prof_200);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->profLog);
			this->tabPage1->Controls->Add(this->buttStart200);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(376, 443);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Профиль";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// prof_right200
			// 
			this->prof_right200->AutoSize = true;
			this->prof_right200->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->prof_right200->Location = System::Drawing::Point(46, 173);
			this->prof_right200->Name = L"prof_right200";
			this->prof_right200->Size = System::Drawing::Size(89, 16);
			this->prof_right200->TabIndex = 5;
			this->prof_right200->Text = L"точность 0%";
			this->prof_right200->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// buttStart200
			// 
			this->buttStart200->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttStart200->Location = System::Drawing::Point(176, 150);
			this->buttStart200->Name = L"buttStart200";
			this->buttStart200->Size = System::Drawing::Size(83, 39);
			this->buttStart200->TabIndex = 4;
			this->buttStart200->Text = L"Начать";
			this->buttStart200->UseVisualStyleBackColor = true;
			this->buttStart200->Click += gcnew System::EventHandler(this, &MyForm::buttStart200_Click);
			// 
			// prof_speed200
			// 
			this->prof_speed200->AutoSize = true;
			this->prof_speed200->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->prof_speed200->Location = System::Drawing::Point(46, 157);
			this->prof_speed200->Name = L"prof_speed200";
			this->prof_speed200->Size = System::Drawing::Size(124, 16);
			this->prof_speed200->TabIndex = 3;
			this->prof_speed200->Text = L"скорость 0 зн/мин";
			this->prof_speed200->Click += gcnew System::EventHandler(this, &MyForm::prof_speed200_Click);
			// 
			// prof_200
			// 
			this->prof_200->AutoSize = true;
			this->prof_200->Location = System::Drawing::Point(46, 134);
			this->prof_200->Name = L"prof_200";
			this->prof_200->Size = System::Drawing::Size(72, 13);
			this->prof_200->TabIndex = 2;
			this->prof_200->Text = L"топ 200 слов";
			this->prof_200->Click += gcnew System::EventHandler(this, &MyForm::prof_200_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"имя пользователя";
			// 
			// profLog
			// 
			this->profLog->AutoSize = true;
			this->profLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->profLog->Location = System::Drawing::Point(43, 48);
			this->profLog->Name = L"profLog";
			this->profLog->Size = System::Drawing::Size(146, 31);
			this->profLog->TabIndex = 0;
			this->profLog->Text = L"Name user";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->textInput);
			this->tabPage2->Controls->Add(this->label_timer);
			this->tabPage2->Controls->Add(this->textOutput);
			this->tabPage2->Controls->Add(this->Typed);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(376, 443);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Тест";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 461);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"Speed Print";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}

	public: 
		void timerOn();
		void timerOff();
		void test(Mode& par);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBoxOut_TextChanged(System::Object^ sender, System::EventArgs^ e){}
	private: System::Void textBoxInp_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void labelTyped(System::Object^ sender, System::EventArgs^ e){}

	private: System::Void label_timer_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttStart200_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void prof_speed200_Click(System::Object^ sender, System::EventArgs^ e){
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void prof_200_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};

}

