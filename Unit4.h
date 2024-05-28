//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pgeLogins;
	TTabSheet *tbsLogo;
	TTabSheet *tbsSignIn;
	TTabSheet *tbsRegister;
	TImage *imgRegister;
	TImage *imgLogoBack;
	TImage *imgSignIn;
	TImage *imgLogo;
	TLabel *lblBankName;
	TLabel *lblSlogan;
	TLabel *lblSnIn;
	TLabel *lblRgtr;
	TImage *Image4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel* lblwelcome;
    TLabel* lblusername;
	TLabel *lblaccountnr;
	TEdit *edtaccountnr;
	TLabel *lblpassword;
	TEdit *edtpassword;
	TButton *btnsignin;
	TLabel *lblregister;
	TLabel *lblregStName;
	TLabel *lblregSurburb;
	TLabel *lblregCity;
	TLabel *lblregProvince;
	TLabel *lblregPostalCode;
	TLabel *lblregCountry;
	TLabel *lblregID;
	TLabel *lblregEmail;
	TLabel *lblsgnIn;
	TLabel *lblregconfmpass;
	TLabel *lblregpassw;
	TLabel *lblInitialAmount;
	TLabel *lblregsurname;
	TLabel *lblregname;
	TLabel *lblRegIDHeading;
	TLabel *lblRegResHeading;
	TEdit *edtregName;
	TEdit *edtregSurname;
	TEdit *edtinitialAmount;
	TEdit *edtregpassw;
	TEdit *edtregconfmpass;
	TButton *btnregister;
	TEdit *edtregStNum;
	TEdit *edtSurburb;
	TEdit *edtCity;
	TEdit *edtCountry;
	TEdit *edtPostal;
	TEdit *edtProvince;
	TEdit *edtregID;
	TEdit *edtregEmail;
	TImage *Image1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall lblSnInClick(TObject *Sender);
	void __fastcall lblRgtrClick(TObject *Sender);
	void __fastcall lblregisterClick(TObject *Sender);
	void __fastcall lblsgnInClick(TObject *Sender);
	void __fastcall btnregisterClick(TObject *Sender);
	void __fastcall btnsigninClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
