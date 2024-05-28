//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

	Form1->Constraints->MaxWidth = Form1->Width;
	Form1->Constraints->MinWidth = Form1->Width;
	Form1->Constraints->MaxHeight = Form1->Height;
	Form1->Constraints->MinHeight = Form1->Height;
	imgRegister->Picture->LoadFromFile("back.jpg");
	imgSignIn->Picture->LoadFromFile("back.jpg");
	imgLogoBack->Picture->LoadFromFile("back.jpg");


}
//---------------------------------------------------------------------------
void __fastcall TForm1::lblSnInClick(TObject *Sender)
{
	tbsSignIn->TabVisible = true;
	tbsRegister->TabVisible = false;
	tbsLogo->TabVisible = false;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::lblRgtrClick(TObject *Sender)
{
	tbsSignIn->TabVisible = false;
	tbsRegister->TabVisible = true;
	tbsLogo->TabVisible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lblregisterClick(TObject *Sender)
{
	tbsSignIn->TabVisible = false;
	tbsRegister->TabVisible = true;
	tbsLogo->TabVisible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lblsgnInClick(TObject *Sender)
{
    tbsSignIn->TabVisible = true;
	tbsRegister->TabVisible = false;
	tbsLogo->TabVisible = false;
}
//---------------------------------------------------------------------------
//Function to randomly create account number, security number and bank account number
AnsiString Ran(int l, int r)
{
	AnsiString line = "";
	 int i, N;
	 Randomize();
	 for(i = 1; i <= l; i++)
	 {
		N = Random(r) + 1;
		line += IntToStr(N);
		if(l == 16){
			if(i == 4 || i == 8 || i == 12)
			{
				line += " ";
			}
		}
	 }

	 return line;
}
//----------------------------------------------------------------------------
void __fastcall TForm1::btnregisterClick(TObject *Sender)
{
	AnsiString Name, Surname, AccountType, Pword, InitialAmount, AccountNumber, CardNumber, SecurityNumber,
	Email, IDNumber, StrtNmNmbr, Surburb, City, Country, PostalCode, Province;


	if(edtregName->Text == "" || edtregSurname->Text == "" || edtinitialAmount->Text == "" || edtregpassw->Text == "" || edtregconfmpass->Text == ""|| edtregID->Text == ""
	|| edtregEmail->Text == "" || edtregStNum->Text == "" ||edtSurburb->Text == "" || edtCity->Text == "" || edtProvince->Text == "" || edtPostal->Text == "" || edtCountry->Text == "")
	{
		MessageDlg("please fill in the missing fields!", mtError, TMsgDlgButtons() <<mbOK, 0);
	}
	else if(edtregpassw->Text != edtregconfmpass->Text)
	{
        MessageDlg("Passwords do no match!", mtError, TMsgDlgButtons() <<mbOK, 0);
	}
	else
	{
		Name = edtregName->Text;
		Surname = edtregSurname->Text;
		AccountType = "Savings Account";
		Pword =  edtregpassw->Text;
		InitialAmount = "R"+ edtinitialAmount->Text;
		Email =  edtregEmail->Text;
		IDNumber = edtregID->Text;
		StrtNmNmbr = edtregStNum->Text;
		Surburb =  edtSurburb->Text;
		City =  edtCity->Text;
		Country = edtCountry->Text;
		PostalCode = edtPostal->Text;
		Province = edtProvince->Text;

		AccountNumber = Ran(10,9);
		CardNumber =   Ran(16,9);
		SecurityNumber =  Ran(3,9);

		//
		TTextWriter *twSave = new  TStreamWriter("logins.txt", true);
		twSave->WriteLine(AccountNumber +","+ Pword +","+ Name +" "+ Surname +","+ AccountType +","+ InitialAmount +","+ CardNumber +","+ SecurityNumber+","+
		IDNumber +","+ Email +","+ Country +","+ Province +","+ City +","+ Surburb +","+ StrtNmNmbr+","+PostalCode);
		twSave->Close();

		edtregName->Text = "";
		edtregSurname->Text = "";
		edtregpassw->Text = "";
		edtinitialAmount->Text = "";
		edtregEmail->Text = "";
		edtregID->Text = "";
		edtregStNum->Text = "";
		edtSurburb->Text = "";
		edtCity->Text = "";
		edtCountry->Text = "";
		edtPostal->Text = "";
		edtProvince->Text = "";
		edtregconfmpass->Text = "";

		MessageDlg("Thank you for choosing EVOLVE bank!", mtInformation, TMsgDlgButtons() << mbOK, 0);
    }
}
//---------------------------------------------------------------------------
AnsiString USERNAME;
//---------------------------------------------------------------------------
AnsiString getField(int nr, AnsiString line, char delim)
{
	line += delim;

	for(int i =1; i < nr; i++)
	{
		line  = line.Delete(1,line.Pos(delim));
	}

	return line.SubString(1, line.Pos(delim)-1);
}
//----------------------------------------------------------------------------
void __fastcall TForm1::btnsigninClick(TObject *Sender)
{
	AnsiString line, NameandSurname, AccountType, Pword, InitialAmount, AccountNumber, CardNumber, SecurityNumber,
	Email, IDNumber, StrtNmNmbr, Surburb, City, Country, PostalCode, Province, accountNum;

	TStreamReader *tread = new TStreamReader("logins.txt");
	bool found = false;

	while(!tread->EndOfStream && found == false)
	{
		line = tread->ReadLine();
		AccountNumber = getField(1, line, ',');
		Pword = getField(2, line, ',');
		NameandSurname = getField(3, line, ',');
		AccountType = getField(4, line, ',');
		InitialAmount = getField(5, line, ',');
		CardNumber = getField(6, line,',');
		SecurityNumber = getField(7, line,',');
		IDNumber = getField(8, line,',');
		Email  = getField(9, line,',');
		Country = getField(10, line,',');
		Province = getField(11, line,',');
		City = getField(12, line,',');
		Surburb = getField(13, line,',');
		StrtNmNmbr = getField(14, line,',');
		PostalCode = getField(15, line,',');

		USERNAME = NameandSurname.SubString(1, NameandSurname.Pos(" "));

		if(edtaccountnr->Text == "" || edtpassword->Text == "")
		{
		   MessageDlg("Please make sure to enter all fields!", mtInformation, TMsgDlgButtons() << mbOK, 0);
		}
		else if(edtaccountnr->Text == AccountNumber && edtpassword->Text == Pword)
		{
			Form2->lblsecuritynum->Caption = SecurityNumber;
			Form2->lblcardNum->Caption = CardNumber;
			lblwelcome = new TLabel(Form2);
			lblwelcome->Parent = Form2;
			lblwelcome->Left = 330;
			lblwelcome->Top = 5;
			lblwelcome->Width = 103;
			lblwelcome->Height = 25;
			lblwelcome->Font->Size = 16;
			lblwelcome->Caption = "Welcome";
			lblwelcome->Font->Height = -21;

			lblusername = new TLabel(Form2);
			lblusername->Parent = Form2;
			lblusername->Left = 340;
			lblusername->Top = 33;
			lblusername->Width = 83;
			lblusername->Height = 19;
			lblusername->Font->Size = 12;
			lblusername->Caption = NameandSurname.SubString(1, NameandSurname.Pos(" "));
			lblusername->Font->Height = -16;

			Form1->Visible = false;
			Form2->Visible = true;

			Form2->lblcardaccountnr->Caption = AccountNumber;
			Form2->lblcardusername->Caption = NameandSurname;
			Form2->lblaccname->Caption = AccountType;
			Form2->lblaccnr->Caption = "Account Number";
			Form2->lblavlbal->Caption =  InitialAmount;

			Form2->lblUserName->Caption =  NameandSurname.SubString(1, NameandSurname.Pos(" "));
			Form2->lblUserID->Caption =  IDNumber;
			Form2->lblUserSurname->Caption =  NameandSurname.SubString(NameandSurname.Pos(" "), ((NameandSurname.Length()+ 1) - NameandSurname.Pos(" ")));
			Form2->lblUserEmailAddress->Caption = Email;
			Form2->lblUserStreetName->Caption = StrtNmNmbr;
			Form2->lblUserSurburb->Caption =  Surburb;
			Form2->lblUserProvince->Caption = Province;
			Form2->lblUserCountry->Caption = Country;
			Form2->lblUserCity->Caption = City;
			Form2->lblUserPostalCode->Caption = PostalCode;

			edtaccountnr->Text = "";
            edtpassword->Text =" ";
			found = true;
        }
	}
    tread->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------

