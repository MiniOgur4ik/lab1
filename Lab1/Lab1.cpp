//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lab1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tf_main *f_main;
//---------------------------------------------------------------------------
__fastcall Tf_main::Tf_main(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tf_main::b_sendClick(TObject *Sender)
{
	TDateTime* myTime = new TDateTime(Now());//
	String data_text = myTime->FormatString("dd.mm.yyyy") + " " +  myTime->FormatString("hh:mm:ss");

	String text = data_text + " Я: " + e_msg->Text;

	m_chat->Lines->Add(text);

	if (e_msg->Text.Pos("ривет")) {
		text = "\n" + data_text + " Бот: Привет";
		m_chat->Lines->Add(text);
	}
/*
поиск знака вопроса в конце
*/
	else if (e_msg->Text.Pos("ак дела") && e_msg->Text.Pos("?") == e_msg->Text.Length() ) {
		text = "\n" +  data_text + " Бот: Хорошо";
		m_chat->Lines->Add(text);
	}
/*
проверка пустого сообщения через длину строки
*/
	else if (e_msg->Text.Length() < 1) {
		return;
	}
	else {
		text = "\n" +  data_text + " Бот: Не понимаю тебя";
		m_chat->Lines->Add(text);
	}

// если не вопрос - сохранияем в памяти
	String info_msg = e_msg->Text;
}
//---------------------------------------------------------------------------
void __fastcall Tf_main::e_msgKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == '\r') {
		b_sendClick(Sender);
	}
}
//---------------------------------------------------------------------------
