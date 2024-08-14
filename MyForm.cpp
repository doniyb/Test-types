#include <string>
#include <vector>
#include <ctime>
#include <msclr\marshal_cppstd.h>

//слова
#include "VectorWords.h"

//данные пользователя и БД
#include "BD.h"
#include "User.h"

//окна
#include "Login.h"
#include "RegisterWind.h"
#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

bool openform = false;//вошел ли пользователь
bool openregister = false;
bool openlogin = false;

Mode mode(1000);//режим
User user;//пользователь

int main(array<String^>^ args_main)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Tetsttypes::Login login;
	Application::Run(% login);

	if (openregister)
	{
		Tetsttypes::RegisterWind registerWind;
		Application::Run(% registerWind);

		if (openlogin)
		{
			Tetsttypes::Login login;
			Application::Run(% login);
		}
	}

	if (openform)
	{
		Fillwords();
		Tetsttypes::MyForm form;
		Application::Run(% form);
	}

	return 0;
}

//окно входа
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
		user.set(us.ReadRecord(gcnew String(user.getName().c_str()), 200));
		user.set(us.ReadRecord(gcnew String(user.getName().c_str()), 500));
		user.set(us.ReadRecord(gcnew String(user.getName().c_str()), 1000));

		openform = true;
		this->Close();
	}
}

System::Void Tetsttypes::Login::Register_Click(System::Object^ sender, System::EventArgs^ e)
{
	openregister = true;
	this->Close();
}


//регистрация
Tetsttypes::RegisterWind::RegisterWind(void)
{
	InitializeComponent();
}

System::Void Tetsttypes::RegisterWind::buttRegReg_Click(System::Object^ sender, System::EventArgs^ e)
{
	BD us;
	msclr::interop::marshal_context context;

	if (RegLog->Text != "" && RegPassw->Text != "" && !us.CheckRegist(RegLog->Text, RegPassw->Text)
		&& count((context.marshal_as<std::string>(RegLog->Text)).begin(), (context.marshal_as<std::string>(RegLog->Text)).end(), ' ') == 0
		&& count((context.marshal_as<std::string>(RegPassw->Text)).begin(), (context.marshal_as<std::string>(RegPassw->Text)).end(), ' ') == 0)
	{
		us.InsertAk(RegLog->Text, RegPassw->Text);
		us.InsertRec(RegLog->Text);

		openlogin = true;

		this->Close();
	}
	else
	{
		ErrorLogin->Text = "Поменяйте пароль или имя пользователя";
		ErrorPassw->Text = "Поменяйте пароль или имя пользователя";
	}
}



//Основное окно:
int second = 0;// нынешнее время
int max_seconds = 180;// максимальное время в секундах
int num_word = 0;//номер слова в списке
int typech = 0; //количество набранных слов
int reightep = 0; // правильные символы


void CheckResultTest();
std::string outtime(const int& seconds);
bool endtime(int& seconds, const int maxsec);
bool similar(const std::string& strinp, const std::string& strout);
bool proverkaOut(std::string& strinp, const std::string& strout);
void FindProbel(std::string& str);


Tetsttypes::MyForm::MyForm(void)
{
	InitializeComponent();

	Timing->SelectedItem = "3 мин.";

	OutProf();
}
//Вывод данных в профиле
void Tetsttypes::MyForm::OutProf()
{
	profLog->Text = gcnew String(user.getName().c_str());

	prof_speed200->Text = "Скорость: " + gcnew String(std::to_string(user.getspeed(200)).c_str()) + "зн/мин";
	prof_right200->Text = "Точность: " + gcnew String(std::to_string(user.getright(200)).c_str()) + "%";

	prof_speed500->Text = "Скорость: " + gcnew String(std::to_string(user.getspeed(500)).c_str()) + "зн/мин";
	prof_right500->Text = "Точность: " + gcnew String(std::to_string(user.getright(500)).c_str()) + "%";

	prof_speed1000->Text = "Скорость: " + gcnew String(std::to_string(user.getspeed(1000)).c_str()) + "зн/мин";
	prof_right1000->Text = "Точность: " + gcnew String(std::to_string(user.getright(1000)).c_str()) + "%";
}


//кнопка начать тестирование на 200
System::Void Tetsttypes::MyForm::buttStart200_Click(System::Object^ sender, System::EventArgs^ e)
{
	mode.setsize(200);
	FullstrTest(mode.getsize());
	textOutput->Text = gcnew String(strTest.c_str());;
	Minuts();
	max_seconds = minuts * 60;
	test();
}
//кнопка начать тестирование на 500
System::Void Tetsttypes::MyForm::buttStart500_Click(System::Object^ sender, System::EventArgs^ e)
{
	mode.setsize(500);
	FullstrTest(mode.getsize());
	textOutput->Text = gcnew String(strTest.c_str());
	Minuts();
	max_seconds = minuts * 60;
	test();
}
//кнопка начать тестирование на 1000
System::Void Tetsttypes::MyForm::buttStart1000_Click(System::Object^ sender, System::EventArgs^ e)
{
	mode.setsize(1000);
	FullstrTest(mode.getsize());
	textOutput->Text = gcnew String(strTest.c_str());
	Minuts();
	max_seconds = minuts * 60;
	test();
}


//запуск теста
void Tetsttypes::MyForm::test()
{
	timerOn();
	tabControl1->SelectTab("tabPage2");
}
//проверка результатов тестирования
void CheckResultTest()
{
	double r = reightep;
	double t = typech;
	mode.right = float(r / t) * 100;
	mode.speed = float(reightep / (max_seconds / 60));

	user.set(mode);

	BD save;
	save.Change(user, mode.getsize());

	mode.setsize(0);
	mode.right = 0;
	mode.speed = 0;

}


//включение таймера
void Tetsttypes::MyForm::timerOn()
{
	second = 0;
	timer->Interval = 1000;
	timer->Enabled = true;
}
//выключение таймера
void Tetsttypes::MyForm::timerOff()
{
	second = 0;
	timer->Interval = 1000;
	timer->Enabled = false;
}
//таймер
System::Void Tetsttypes::MyForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	++second;
	label_timer->Text = gcnew String(outtime(second).c_str());

	if (endtime(second, max_seconds))
	{
		label_timer->Text = "Таймер 00 : 00";
		Typed->Text = "Набранные: 0";
		timerOff();
		textInput->Text = "";
		textOutput->Text = "";
	}

	OutProf();
}
//формат вывода
std::string outtime(const int& seconds) {
	int min = second / 60;
	int sec = second % 60;

	std::string res = "Таймер ";
	if (min == 0) {
		if (sec > 9) {
			res += ("00 : " + std::to_string(sec));
		}
		else {
			res += ("00 : 0" + std::to_string(sec));
		}
	}

	else if(min<9) {
		if (sec > 9)
			res += ("0" + std::to_string(min) + " : " + std::to_string(sec));
		else
			res += ("0" + std::to_string(min) + " : 0" + std::to_string(sec));
	}
	
	else {
		if (sec > 9)
			res += (std::to_string(min) + " : " + std::to_string(sec));
		else
			res += (std::to_string(min) + " : 0" + std::to_string(sec));
	}
	return res;
}
//окончание времени
bool endtime(int& seconds, const int maxsec) {
	double r = reightep;
	double t = typech;
	if (seconds == maxsec) {
		CheckResultTest();
		MessageBox::Show("Вы набрали\n" + reightep.ToString() + " правильных символов\n" + typech.ToString() + " всего\n" + int(r / t * 100).ToString() + "% точность\n" + float(reightep / (max_seconds / 60)) + "зн./мин. скорость");
		second = 0;
		typech = -1;
		reightep = 0;
		return 1;
	}
	return 0;
}



//проверка правильный ли символ введен
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
//проверка на совподение строк
bool similar(const std::string& strinp, const std::string& strout) 
{
	return count(strinp.begin(), strinp.end(), ' ') == 2;
}
//удаление самого левого слова
void FindProbel(std::string& str)
{
	str.erase(str.begin(), str.begin() + str.find(' ') + 1);
}
//3 слова в выводе
void Tetsttypes::MyForm::ThreeStr(std::string& strinp, std::string& strout)
{
	if (similar(strinp, strout)) {
		FindProbel(strout);
		strinp = "";
		for (int i = 0; i < strout.size(); ++i)
		{
			strinp += strout[i];
			if (strout[i] == ' ')
				break;
		}
		textOutput->Text = gcnew String(strout.c_str());
		textInput->Text = gcnew String(strinp.c_str());

		srand(time(0));
		textOutput->Text += " ";
		textOutput->Text += gcnew String(words[rand() % mode.getsize()].c_str());
	}
}
//строка ввода
System::Void Tetsttypes::MyForm::textBoxInp_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context context;
	std::string strinp = context.marshal_as<std::string>(textInput->Text);
	std::string strout = context.marshal_as<std::string>(textOutput->Text);
	++typech;
	++reightep;
	if (!proverkaOut(strinp, strout))
	{
		--typech;
		reightep -= 2;
	}
	textInput->Text = gcnew String(strinp.c_str());
	if (strinp.size() > 0)
	{
		textInput->SelectionStart = strinp.size();
		textOutput->SelectionStart = strinp.size();
	}
	else
	{
		textInput->SelectionStart = 0;
		textOutput->SelectionStart = 0;
	}
	
	ThreeStr(strinp, strout);

	
	Typed->Text = "Набранные: " + gcnew String(std::to_string(typech).c_str());
}






