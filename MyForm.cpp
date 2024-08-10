#include <string>
#include <vector>
#include <ctime>
#include <msclr\marshal_cppstd.h>

#include "MyForm.h"
#include "Login.h"
#include "BD.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;

Mode mode;
User user;

int main(array<String^>^ args_main)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

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
	BD us;
	msclr::interop::marshal_context context;
	
	if (us.Check_login_and_password(textBox_log->Text, textBox_pasword->Text)) 
	{
		user.setName(context.marshal_as<std::string>(textBox_log->Text));
		user.setPassword(context.marshal_as<std::string>(textBox_pasword->Text));
		user.set(us.ReadRecord(gcnew String(user.getName().c_str())));

		this->Close();
	}
}


//---------------
//�������� ����:
//---------------
int second = 0;
const int max_seconds = 60;
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
int num_word = 0;
int typech = -1; //���������� ���������� ����
int reightep = -1;
//����� -1 �. �. � ����� ������ ���� ����� � ������ ����� => �����


void CheckResultTest();

Tetsttypes::MyForm::MyForm(void)
{
	InitializeComponent();

	profLog->Text = gcnew String(user.getName().c_str());
	prof_speed200->Text = "��������: " + gcnew String(std::to_string(user.getspeed(200)).c_str()) + "��/���";
	prof_right200->Text = "��������: " + gcnew String(std::to_string(user.getright(200)).c_str()) + "%";
}

//��������� �������
void Tetsttypes::MyForm::timerOn()
{
	second = 0;
	timer->Interval = 1000;
	timer->Enabled = true;
}
//���������� �������
void Tetsttypes::MyForm::timerOff()
{
	second = 0;
	timer->Interval = 1000;
	timer->Enabled = false;
}

//������ ������
std::string outtime(const int& seconds) {
	int min = second / 60;
	int sec = second % 60;

	std::string res = "������: ";
	if (min == 0) {
		if (sec > 9) {
			res += ("00 : " + std::to_string(sec));
		}
		else {
			res += ("00 : 0" + std::to_string(sec));
		}
	}

	else {
		if (sec > 9)
			res += ("0" + std::to_string(min) + " : " + std::to_string(sec));
		else
			res += ("0" + std::to_string(min) + " : 0" + std::to_string(sec));
	}
	return res;
}

//��������� �������
bool endtime(int& seconds, const int maxsec) {
	double r = reightep;
	double t = typech;
	if (seconds == maxsec) {
		CheckResultTest();
		MessageBox::Show("�� �������\n" + reightep.ToString() + " ���������� ��������\n" + typech.ToString() + " �����\n" + float(r / t * 100).ToString() + "% ��������");
		second = 0;
		typech = -1;
		reightep = 0;
		return 1;
	}
	return 0;
}

void CheckResultTest()
{
	double r = reightep;
	double t = typech;
	mode.right = float(r/ t)*100;
	mode.speed = reightep/max_seconds*60;

	user.set(mode);
	mode.setsize(0);
	mode.right = 0;
	mode.speed = 0;
	BD save;
	save.Change(user);
}

//������ �����
void Tetsttypes::MyForm::test()
{
	timerOn();
	tabControl1->SelectTab("tabPage2");
}




//�������� ���������� �� ������ ������
bool proverkaOut(std::string& strinp, const std::string& strout) {
	for (int i = 0; i < strinp.size(); ++i) 
	{
		if (strinp[i] != strout[i])
		{
			strinp.erase(strinp.begin() + i);
			return false;
		}
	}
	return true;
}
//�������� �� ���������� �����
bool similar(const std::string& strinp, const std::string& strout) {
	if (strinp == strout) {
		srand(time(0));
		num_word = rand() % words.size();
		reightep += strinp.size();
	}
	if (strinp != strout && second >= max_seconds)
		reightep += strinp.size();
	return strinp == strout;
}
//������ �����
System::Void Tetsttypes::MyForm::textBoxInp_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

	msclr::interop::marshal_context context;
	std::string strinp = context.marshal_as<std::string>(textInput->Text);
	std::string strout = context.marshal_as<std::string>(textOutput->Text);
	++typech;
	proverkaOut(strinp, strout) ? 1 : --typech;
	textInput->Text = gcnew String(strinp.c_str());
	if(strinp.size()>0)
		textInput->SelectionStart = strinp.size();
	else
		textInput->SelectionStart = 0;

	if (similar(strinp, strout)) {
		textOutput->Text = gcnew String(words[num_word].c_str());
		textInput->Text = "";
	}
	
	Typed->Text = "���������: " + gcnew String(std::to_string(typech).c_str());
}

//������ ������ ������������ �� 200
System::Void Tetsttypes::MyForm::buttStart200_Click(System::Object^ sender, System::EventArgs^ e)
{
	mode.setsize(200);
	test();
}

//������
System::Void Tetsttypes::MyForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	++second;

	label_timer->Text = gcnew String(outtime(second).c_str());


	endtime(second, max_seconds) ? Typed->Text = "���������: 0", timerOff() : 1;
}


