#include "MyForm.h"
#include <string>
#include <vector>
#include <ctime>
#include <msclr\marshal_cppstd.h>


using namespace System;
using namespace System::Windows::Forms;


int main(array<String^>^ args_main)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Tetsttypes::Login login;
	Application::Run(% login);
	Tetsttypes::MyForm form;
	Application::Run(% form);
	return 0;
}

Tetsttypes::Login::Login(void)
{
	InitializeComponent();
}

System::Void Tetsttypes::Login::buttEnter_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(textBox_log->Text == "doniyb" && textBox_pasword->Text == "cde3322wsxzaq11")
		this->Close();
}


//---------------
//�������� ����:
//---------------

Tetsttypes::MyForm::MyForm(void)
{
	InitializeComponent();
}

std::vector <std::string> words{ "������", "���", "����", "���", "������", "�����", "��", "���", 
"���", "���", "������", "����", "����", "����", "�����", "�����", "����", "�����", 
"���", "������", "���", "�������", "����", "�����", "������", "�������", "������", "�������", 
"����", "�����", "������", "��������", "����", "������", "����", "�����", "����" , "�����" ,
"����" , "���������" 
, "��������" , "������" , "��������" , "�������" , "������" , "�������" , "��������" , "��������" 
, "�����" , "������" , "������" , "�����", "�������", "������", "���", "������", "��������", "�����", 
"�����", "�����", "������", "�����", "���", "������", "�����"
, "�������" , "�������" , "�������" , "���������������" , "�������" , "���������" , "�������" 
, "���������" , "�����" , "������" , "�����" , "��������", "������", "���������"
, "������" , "����������" , "�����������" , "������" , "������" , "���" , "����" ,
"�" , "��" , "����" , "�����" , "����", "���", "���"
, "����" , "������" , "���������" , "������" , "����", "����", "����" };
int num_word = 0; //������ ������ � ������� ����
int typech = -1; //���������� ���������� ����
//����� -1 �. �. � ����� ������ ���� ����� � ������ ����� => �����


System::Void Tetsttypes::MyForm::textBoxOut_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void Tetsttypes::MyForm::textBoxInp_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

	label_timer->Text = gcnew String(std::to_string(timer->Interval).c_str());

	msclr::interop::marshal_context context;
	std::string str1 = context.marshal_as<std::string>(textInput->Text);
	std::string str3 = context.marshal_as<std::string>(textOutput->Text);


	for (int i = 0; i < str1.size(); ++i) {
		if (str1[i] != str3[i]) {
			str1.erase(str1.begin() + i);
			textInput->Text = gcnew String(str1.c_str());
		}
	}

	if (textInput->Text == textOutput->Text) {
		typech++;
		srand(time(0));
		num_word = rand() % words.size();
		textOutput->Text = gcnew String(words[num_word].c_str());
		textInput->Text = "";
	}
	Typed->Text = "���������: " + gcnew String(std::to_string(typech).c_str());
}

System::Void Tetsttypes::MyForm::labelTyped(System::Object^ sender, System::EventArgs^ e)
{
}





