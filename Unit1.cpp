//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
class PictureLoader : public TThread
{
private:
    TImage* m_Image;
    UnicodeString m_FileName;

public:
    PictureLoader(TImage* Image, const UnicodeString& FileName)
        : m_Image(Image)
        , m_FileName(FileName)
    {}

protected:
    void __fastcall Execute()
    {
        m_Image->Picture->LoadFromFile(m_FileName);
    }
};
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{

	Form2->Constraints->MaxWidth = Form2->Width;
	Form2->Constraints->MinWidth = Form2->Width;
	Form2->Constraints->MaxHeight = Form2->Height;
	Form2->Constraints->MinHeight = Form2->Height;
	imgbackground->Picture->LoadFromFile("back.jpg");
	imgHome->Picture->LoadFromFile("back.jpg");
	imgPay->Picture->LoadFromFile("back.jpg");
	imgBuy->Picture->LoadFromFile("back.jpg");
	imgLimit->Picture->LoadFromFile("back.jpg");
	imgTransaction->Picture->LoadFromFile("back.jpg");
	imgSettings->Picture->LoadFromFile("back.jpg");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    TTextWriter *twSave = new  TStreamWriter("logins.txt", false);

	for(int i = 0; i < lstdatabase->Items->Count; i++)
	{
		AnsiString line;
		line = lstdatabase->Items->Strings[i];
		twSave->WriteLine(line);
	}
	twSave->Close();
	Action = caHide;
	Form1->Show();
	//Form2->Close();
	Form1->Visible = true;
	Form2->Visible = false;
	Form1->lblwelcome->Caption = "";
	Form1->lblusername->Caption = "";
	lstdatabase->Clear();
	lstmoneyout->Clear();
	lstMoneyIn->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Shape6ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)

{
	 Panel7->Visible = true;
	 Panel6->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Shape10ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)

{
     Panel7->Visible = false;
	 Panel6->Visible = true;
}
//---------------------------------------------------------------------------
AnsiString SecurityNum, CardNum, modCardNum;
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
void __fastcall TForm2::FormShow(TObject *Sender)
{
	SecurityNum = lblsecuritynum->Caption;
	lblsecuritynum->Caption = "***";
	CardNum = lblcardNum->Caption;
	lblcardNum->Caption = "**** **** **** ****";

    AnsiString cdnumf4, cardnuml4;
	int len;

	len = CardNum.Length();

	cdnumf4 = CardNum.SubString(0,4);
	cardnuml4 = CardNum.SubString(len-3,4);

	modCardNum = cdnumf4 + " **** **** " + cardnuml4;
	Form2->lblcardNum->Caption = modCardNum;

	AnsiString line, NameandSurname, AccountType, Pword, InitialAmount, AccountNumber, CardNumber, SecurityNumber,
	Email, IDNumber, StrtNmNmbr, Surburb, City, Country, PostalCode, Province, accountNum;

	TStreamReader *tread = new TStreamReader("logins.txt");

	while(!tread->EndOfStream)
	{

		line = tread->ReadLine();
		accountNum = getField(1, line, ',');
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


		lstdatabase->Items->Add(accountNum +","+ Pword +","+ NameandSurname +","+ AccountType +","+ InitialAmount +","+ CardNumber +","+
		SecurityNumber +","+ IDNumber +","+ Email +","+ Country +","+ Province +","+ City +","+ Surburb +","+ StrtNmNmbr  +","+ PostalCode );
		lstaccounts->Items->Add(accountNum);
	}

    tread->Close();

}
//---------------------------------------------------------------------------
bool click = false;
void __fastcall TForm2::lbldetailClick(TObject *Sender)
{
    if(click == false)
	{
		lblsecuritynum->Caption = SecurityNum;
		lblcardNum->Caption = CardNum;
		click = true;
		lbldetail->Caption = "Hide details";
	}
	else
	{
		lblsecuritynum->Caption = "***";
        Form2->lblcardNum->Caption = modCardNum;
		click = false;
        lbldetail->Caption = "Show details";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::cbxFilterMoneyChange(TObject *Sender)
{
    if(cbxFilterMoney->ItemIndex == 0)
	{
		pnlMoneyIn->Visible = true;
		pnlMoneyOut->Visible = false;
	}
	if(cbxFilterMoney->ItemIndex == 1)
	{
		pnlMoneyIn->Visible = false;
		pnlMoneyOut->Visible = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::cbxfiltertransacChange(TObject *Sender)
{
	if(cbxfiltertransac->ItemIndex == 0)
	{
		pnltransferMoney->Visible = true;
		pnladdbeneficiary->Visible = false;
	}
	else if(cbxfiltertransac->ItemIndex == 1)
	{
		pnltransferMoney->Visible = false;
		pnladdbeneficiary->Visible = true;
	}
	else
	{
		pnltransferMoney->Visible = false;
		pnladdbeneficiary->Visible = false;


	}
}
//---------------------------------------------------------------------------
class BankTransfer {
public:
	AnsiString transferFrom;
	AnsiString transferTo;
	double transferAmount;
	double remainingBalance;
	AnsiString Description;
	AnsiString Date;

	BankTransfer(AnsiString transferFrom, AnsiString transferTo, double transferAmount,double remainingBalance, AnsiString Description, AnsiString date)
	: transferFrom(transferFrom), transferTo(transferTo),transferAmount(transferAmount), remainingBalance(remainingBalance), Description(Description), Date(date) {}

	BankTransfer(){}

	void SaveTransaction(AnsiString filename)
	{
	   TTextWriter *twSave = new  TStreamWriter(filename, true);
	   twSave->WriteLine(transferFrom +","+ transferAmount+","+ remainingBalance +","+Description+","+Date);
	   twSave->Close();
	}
	void ReceiveTransaction(AnsiString filename)
	{
	   TTextWriter *twSave = new  TStreamWriter(filename, true);
	   twSave->WriteLine(transferFrom +","+transferTo +","+ transferAmount+","+ remainingBalance+","+Description+","+Date);
	   twSave->Close();
	}
};

//----------------------------------------------------------------------------
void __fastcall TForm2::btnaddbeneficClick(TObject *Sender)
{
	AnsiString searchAccount = edtbeneficaccount->Text;

	int index = lstaccounts->Items->IndexOf(searchAccount);

	if(index != -1)
	{
		int comboIndex = cbxtransferto->Items->IndexOf(searchAccount);

		if( comboIndex != -1)
		{
		  ShowMessage("The account already exists in the database. Select account from the combo box");
		}
		else
		{
		   cbxtransferto->Items->Add(searchAccount);
		   edtbeneficaccount->Text = "";
		   edtbeneficname->Text = "";
        }
	}
	else
	{
        MessageDlg("the account does not exist!", mtError, TMsgDlgButtons() <<mbOK, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btntransferClick(TObject *Sender)
{
	double amount = edtamounttrans->Text.ToDouble();

	std::time_t now = std::time(nullptr);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	AnsiString date(buffer);

	if(cbxtransferto->ItemIndex == -1)
	{
		MessageDlg("please select an account!", mtError, TMsgDlgButtons() <<mbOK, 0);

	}
    else if(edtlimit->Text.ToDouble() < amount)
	{
		MessageDlg("please ensure that ammount doest no exceed limit!", mtError, TMsgDlgButtons() <<mbOK, 0);
	}
	else if(edtamounttrans->Text == "" || cbxtransferto->ItemIndex == -1)
	{
		MessageDlg("please fill in the missing fields!", mtError, TMsgDlgButtons() <<mbOK, 0);
	}
	else{
		for(int i = 0; i < lstdatabase->Items->Count; i++)
		{
			AnsiString line, accountNum, NameandSurname, AccountType, Pword, InitialAmount, AccountNumber, CardNumber, SecurityNumber,
			Email, IDNumber, StrtNmNmbr, Surburb, City, Country, PostalCode, Province;

			AnsiString bal;

			double diff = 0;



			line = lstdatabase->Items->Strings[i];


			accountNum = getField(1, line, ',');
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

			bal = InitialAmount.SubString(2,InitialAmount.Length());
			double remain = bal.ToDouble();

			if(accountNum == lblcardaccountnr->Caption)
			{
				diff = (remain - amount);
				InitialAmount = "R"+ FloatToStr(diff);
				lstdatabase->Items->Strings[i] = (accountNum +","+ Pword +","+ NameandSurname +","+ AccountType +","+ InitialAmount +","+ CardNumber +","+
				SecurityNumber +","+ IDNumber +","+ Email +","+ Country +","+ Province +","+ City +","+ Surburb +","+ StrtNmNmbr  +","+ PostalCode );
				lblavlbal->Caption = InitialAmount;
				ShowMessage("You have succesfully transfered R"+ FloatToStr(amount) +" to "+ cbxtransferto->Text);
				BankTransfer myBank(edtreeffrom->Text, cbxtransferto->Text, amount, diff, "Payment", date);
				myBank.SaveTransaction("TransTo.txt");


			}
			for(int i = 0; i < lstdatabase->Items->Count; i++)
				{
					AnsiString line, accountNum, NameandSurname, AccountType, Pword, InitialAmount, AccountNumber, CardNumber, SecurityNumber,
					Email, IDNumber, StrtNmNmbr, Surburb, City, Country, PostalCode, Province;

					AnsiString bal;


					double diff = 0;

					line = lstdatabase->Items->Strings[i];


					accountNum = getField(1, line, ',');
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

					bal = InitialAmount.SubString(2,InitialAmount.Length());
					double remain = bal.ToDouble();

					if(accountNum == cbxtransferto->Text)
					{
						diff = (remain + amount);
						InitialAmount = "R"+ FloatToStr(diff);
						lstdatabase->Items->Strings[i] = (accountNum +","+ Pword +","+ NameandSurname +","+ AccountType +","+ InitialAmount +","+ CardNumber +","+
						SecurityNumber +","+ IDNumber +","+ Email +","+ Country +","+ Province +","+ City +","+ Surburb +","+ StrtNmNmbr  +","+ PostalCode );

						BankTransfer myBank(edtreeffrom->Text, cbxtransferto->Text, amount, diff, "Payment", date);
						myBank.ReceiveTransaction("receivedFrom.txt");
					}
			}
            cbxtransferto->ItemIndex = -1;
			edtamounttrans->Text = "";
		}


	}
}
//---------------------------------------------------------------------------
void RemoveDuplicatesFromListBox(TListBox *ListBox)
{
    for (int i = ListBox->Items->Count - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (ListBox->Items->Strings[i] == ListBox->Items->Strings[j]) {
                ListBox->Items->Delete(i);
                break;
            }
        }
    }
}

void __fastcall TForm2::btnloadhistClick(TObject *Sender)
{

   TStreamReader *tread = new TStreamReader("TransTo.txt");

	while(!tread->EndOfStream)
	{
		AnsiString line, accountnum, reference, amount, date,description, balance;
		line = tread->ReadLine();
		accountnum = getField(1, line, ',');
		amount = getField(2, line, ',');
		balance = getField(3, line, ',');
		description = getField(4, line, ',');
		date = getField(5, line, ',');

		if(accountnum == lblcardaccountnr->Caption)
		{
			lstmoneyout->Items->Add(date +"\t"+ description +"\t"+ "-R"+amount +"\t"+ "R"+balance);
		}
	}
	tread->Close();
	RemoveDuplicatesFromListBox(lstmoneyout);


   TStreamReader *Rread = new TStreamReader("receivedFrom.txt");

	while(!Rread->EndOfStream)
	{
        AnsiString line, accountnum, reference, amount, date,description, balance;
		line = Rread->ReadLine();
		reference = getField(1, line, ',');
		accountnum = getField(2, line, ',');
		amount = getField(3, line, ',');
		balance = getField(4, line, ',');
		description = getField(5, line, ',');
		date = getField(6, line, ',');

		if(accountnum == lblcardaccountnr->Caption)
		{
			lstMoneyIn->Items->Add(date +"\t"+ description +"\t"+ "R"+amount +"\t"+ "R"+balance +"\t"+ reference );
		}
	}
	Rread->Close();
	RemoveDuplicatesFromListBox(lstMoneyIn);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::cbxbuyselectChange(TObject *Sender)
{
	if(cbxbuyselect->ItemIndex == 0)
	{
		pnlairtime->Visible = true;
		pnlelectricity->Visible = false;

	}
	if(cbxbuyselect->ItemIndex == 1)
	{
		pnlelectricity->Visible = true;
		pnlairtime->Visible = false;

	}

}
//---------------------------------------------------------------------------
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
//------------------------------------------------------------------------------

void __fastcall TForm2::btnBuyElectricityClick(TObject *Sender)
{
	double amount = edtElectricityAmount->Text.ToDouble();

	std::time_t now = std::time(nullptr);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	AnsiString date(buffer);
	if(edtElectricityBenName->Text != "" && edtElectricityNum->Text != "" && edtElectricityMeterNum->Text != "" && edtElectricityAmount->Text != "")
	{
		for(int i = 0; i < lstdatabase->Items->Count; i++)
		{
				AnsiString line, accountNum, NameandSurname, AccountType, Pword, InitialAmount, AccountNumber, CardNumber, SecurityNumber,
				Email, IDNumber, StrtNmNmbr, Surburb, City, Country, PostalCode, Province;

				AnsiString bal;

				double diff = 0;



				line = lstdatabase->Items->Strings[i];


				accountNum = getField(1, line, ',');
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

				bal = InitialAmount.SubString(2,InitialAmount.Length());
				double remain = bal.ToDouble();

				if(accountNum == lblcardaccountnr->Caption)
				{
					diff = (remain - amount);
					InitialAmount = "R"+ FloatToStr(diff);
					lstdatabase->Items->Strings[i] = (accountNum +","+ Pword +","+ NameandSurname +","+ AccountType +","+ InitialAmount +","+ CardNumber +","+
					SecurityNumber +","+ IDNumber +","+ Email +","+ Country +","+ Province +","+ City +","+ Surburb +","+ StrtNmNmbr  +","+ PostalCode );
					lblavlbal->Caption = InitialAmount;
					AnsiString elec = Ran(16,9);
					ShowMessage("You have succesfully bought Electricity of ammount R" + FloatToStr(amount) +" Reference: "+elec);//edtElectricityMeterNum->Text);
					BankTransfer myBank(lblcardaccountnr->Caption, lblcardaccountnr->Caption, amount, diff, "Electricity", date);
					myBank.SaveTransaction("TransTo.txt");

					edtElectricityBenName->Text = "";
					edtElectricityNum->Text = "";
					edtElectricityMeterNum->Text = "";
					edtElectricityAmount->Text = "";
				}
		}
	}
	else
	{
       MessageDlg("please enter all fields!", mtError, TMsgDlgButtons() <<mbOK, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnBuyAirtimeClick(TObject *Sender)
{
   double amount = edtAirtimeAmount->Text.ToDouble();

	std::time_t now = std::time(nullptr);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	AnsiString date(buffer);
	if(edtAirtimeBenName->Text != "" && edtAirtimeNum->Text != "" && cmbNetworkType->ItemIndex != -1 && edtAirtimeAmount->Text != "")
	{
		for(int i = 0; i < lstdatabase->Items->Count; i++)
		{
				AnsiString line, accountNum, NameandSurname, AccountType, Pword, InitialAmount, AccountNumber, CardNumber, SecurityNumber,
				Email, IDNumber, StrtNmNmbr, Surburb, City, Country, PostalCode, Province;

				AnsiString bal;

				double diff = 0;



				line = lstdatabase->Items->Strings[i];


				accountNum = getField(1, line, ',');
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

				bal = InitialAmount.SubString(2,InitialAmount.Length());
				double remain = bal.ToDouble();

				if(accountNum == lblcardaccountnr->Caption)
				{
					diff = (remain - amount);
					InitialAmount = "R"+ FloatToStr(diff);
					lstdatabase->Items->Strings[i] = (accountNum +","+ Pword +","+ NameandSurname +","+ AccountType +","+ InitialAmount +","+ CardNumber +","+
					SecurityNumber +","+ IDNumber +","+ Email +","+ Country +","+ Province +","+ City +","+ Surburb +","+ StrtNmNmbr  +","+ PostalCode );
					lblavlbal->Caption = InitialAmount;
					ShowMessage("You have succesfully bought " + cmbNetworkType->Text+"Airtime of amount R" + FloatToStr(amount) +" to CellPhone: "+edtAirtimeNum->Text);
					BankTransfer myBank(lblcardaccountnr->Caption, lblcardaccountnr->Caption, amount, diff, "Airtime", date);
					myBank.SaveTransaction("TransTo.txt");

					edtAirtimeBenName->Text = "";
					edtAirtimeNum->Text = "";
					cmbNetworkType->ItemIndex = -1;
					edtAirtimeAmount->Text = "";
				}

		}
	}
	else
	{
		MessageDlg("please enter all fields!", mtError, TMsgDlgButtons() <<mbOK, 0);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image11Click(TObject *Sender)
{
    TTextWriter *twSave = new  TStreamWriter("logins.txt", false);

	for(int i = 0; i < lstdatabase->Items->Count; i++)
	{
		AnsiString line;
		line = lstdatabase->Items->Strings[i];
		twSave->WriteLine(line);
	}
	twSave->Close();
	Close();
	Form1->Show();
	Form1->Visible = true;
	Form2->Visible = false;
	Form1->lblwelcome->Caption = "";
	Form1->lblusername->Caption = "";
	lstdatabase->Clear();
	lstmoneyout->Clear();
	lstMoneyIn->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::edtreeffromChange(TObject *Sender)
{
    edtreeffrom->Text = lblcardaccountnr->Caption;
}
//---------------------------------------------------------------------------

