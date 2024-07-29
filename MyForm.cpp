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
	Tetsttypes::MyForm form;
	Application::Run(% form);
	return 0;
}

Tetsttypes::MyForm::MyForm(void)
{
	InitializeComponent();
}

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
int num_word = 0;
int typech = 0;

System::Void Tetsttypes::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}


System::Void Tetsttypes::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{



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
	typed->Text = "Набранные: " + gcnew String(std::to_string(typech).c_str());
}


System::Void Tetsttypes::MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e)
{
}





