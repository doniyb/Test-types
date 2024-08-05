#include "MyForm.h"
#include "Login.h"
#include "Data_base.cpp"
#include <string>
#include <vector>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#include <SQLAPI.h>


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
//Основное окно:
//---------------
int second = 0;
const int max_seconds = 180;
std::vector <std::string> words{ "привет", "дом", "рука", "вид", "вопрос", "время", "он", "как",
"его", "год", "голова", "дело", "день", "друг", "жизнь", "конец", "лицо", "место",
"мир", "работа", "раз", "ребенок", "сила", "слово", "случай", "сторона", "страна", "человек",
"быть", "взять", "видеть", "говорить", "дать", "думать", "жить", "знать", "идти" , "иметь" ,
"мочь" , "оказаться"
, "получить" , "понять" , "работать" , "сделать" , "сидеть" , "сказать" , "смотреть" , "спросить"
, "стать" , "хотеть" , "больше" , "вдруг", "вмесете", "вообще", "еще", "меньше", "особенно", "очень",
"почти", "снова", "совсем", "сразу", "уже", "хорошо", "белый"
, "большой" , "высокий" , "главный" , "государственный" , "далекий" , "маленький" , "молодой"
, "настоящий" , "новый" , "нужный" , "общий" , "основной", "полный", "последний"
, "разный" , "российский" , "собственный" , "старый" , "черный" , "где" , "свой" ,
"я" , "ты" , "этот" , "такой" , "свой", "она", "они"
, "себя" , "бежать" , "продовать" , "водить" , "петь", "пить", "есть" };
int num_word = 0; //индекс слоава в векторе слов
int typech = -1; //количество набаранных слов
//равно -1 т. к. в самом начале поле ввода и вывода пусты => равны

Tetsttypes::MyForm::MyForm(void)
{
	InitializeComponent();

	second = 0;
	timer->Interval = 1000;
	timer->Enabled = true;
}

std::string outtime(const int& seconds) {
	int min = second / 60;
	int sec = second % 60;

	std::string res = "Таймер: ";
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
bool endtime(int& seconds, const int maxsec) {
	if (seconds == maxsec) {
		MessageBox::Show("Вы набрали " + typech.ToString() + " слова");
		second = 0;
		typech = -1;
	}
	return seconds == maxsec;
}
System::Void Tetsttypes::MyForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	++second;
	
	label_timer->Text = gcnew String(outtime(second).c_str());

	
	endtime(second, max_seconds) ? Typed->Text = "Набранные: 0" : 1;
}

System::Void Tetsttypes::MyForm::textBoxOut_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}

void proverkaOut(std::string& strinp, const std::string& strout) {
	
}
bool similar(const std::string& strinp, const std::string& strout) {
	if (strinp == strout) {
		typech++;
		srand(time(0));
		num_word = rand() % words.size();	
	}
	return strinp == strout;
}
System::Void Tetsttypes::MyForm::textBoxInp_TextChanged(System::Object^ sender, System::EventArgs^ e)
{

	msclr::interop::marshal_context context;
	std::string strinp = context.marshal_as<std::string>(textInput->Text);
	std::string strout = context.marshal_as<std::string>(textOutput->Text);

	proverkaOut(strinp, strout);
	textInput->Text = gcnew String(strinp.c_str());

	if (similar(strinp, strout)) {
		textOutput->Text = gcnew String(words[num_word].c_str());
		textInput->Text = "";
	}
	
	Typed->Text = "Набранные: " + gcnew String(std::to_string(typech).c_str());
}






