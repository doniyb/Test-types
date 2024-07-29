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
	private: System::Windows::Forms::Label^ typed;
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
			this->textInput = (gcnew System::Windows::Forms::TextBox());
			this->textOutput = (gcnew System::Windows::Forms::TextBox());
			this->typed = (gcnew System::Windows::Forms::Label());
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
			this->textInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
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
			this->textOutput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// typed
			// 
			this->typed->AutoSize = true;
			this->typed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->typed->Location = System::Drawing::Point(182, 251);
			this->typed->Name = L"typed";
			this->typed->Size = System::Drawing::Size(132, 25);
			this->typed->TabIndex = 3;
			this->typed->Text = L"Ќабранные:";
			this->typed->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 461);
			this->Controls->Add(this->typed);
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
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
	};



}

