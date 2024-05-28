//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *imgbackground;
	TPageControl *PageControl1;
	TTabSheet *tbsHome;
	TTabSheet *tbsPay;
	TTabSheet *tbsBuy;
	TTabSheet *tbsLimits;
	TTabSheet *tbsTransactions;
	TTabSheet *tbsSettings;
	TImage *imgSettings;
	TImage *imgPay;
	TImage *imgHome;
	TImage *imgBuy;
	TImage *imgLimit;
	TImage *imgTransaction;
	TPanel *Panel7;
	TShape *Shape10;
	TShape *Shape11;
	TShape *Shape12;
	TLabel *lblsecuritynum;
	TLabel *Label11;
	TLabel *lblcardNum;
	TLabel *Label13;
	TShape *Shape13;
	TLabel *Label14;
	TPanel *Panel6;
	TShape *Shape6;
	TShape *Shape8;
	TLabel *Label6;
	TLabel *lblaccnr;
	TLabel *lblcardaccountnr;
	TLabel *lblcardusername;
	TShape *Shape1;
	TImage *Image8;
	TPanel *pnlaccountstatus;
	TLabel *lblaccname;
	TLabel *Label5;
	TLabel *lblavlbal;
	TImage *imgSavingsAcc;
	TImage *Image11;
	TImage *Image9;
	TLabel *lblBankName;
	TLabel *lblSlogan;
	TLabel *lbldetail;
	TListBox *lstdatabase;
	TPanel *Panel14;
	TPanel *pnlIdentityDetails;
	TLabel *lblIDheading;
	TLabel *lblName;
	TLabel *lblSurname;
	TLabel *lblIDnumber;
	TLabel *lblUserName;
	TLabel *lblUserSurname;
	TLabel *lblUserID;
	TLabel *lblemailAddress;
	TLabel *lblUserEmailAddress;
	TPanel *pnlResidance;
	TLabel *lblResDetails;
	TLabel *lblStreetNme;
	TLabel *lblUserStreetName;
	TLabel *lblCity;
	TLabel *lblUserCity;
	TLabel *lblProvince;
	TLabel *lblUserProvince;
	TLabel *lblSurburb;
	TLabel *lblUserSurburb;
	TLabel *lblPostalCode;
	TLabel *lblUserPostalCode;
	TLabel *lblCountry;
	TLabel *lblUserCountry;
	TPanel *pnlMoneyOut;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label20;
	TComboBox *cbxFilterMoney;
	TButton *btnloadhist;
	TPanel *pnlMoneyIn;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label7;
	TPanel *pnladdbeneficiary;
	TLabel *lblbenficname;
	TLabel *lblBeneficaccount;
	TEdit *edtbeneficname;
	TEdit *edtbeneficaccount;
	TButton *btnaddbenefic;
	TComboBox *cbxfiltertransac;
	TPanel *pnltransferMoney;
	TLabel *Label10;
	TLabel *Label12;
	TLabel *Label15;
	TLabel *Label16;
	TComboBox *cbxtransferto;
	TEdit *edttransferfrom;
	TEdit *edtamounttrans;
	TEdit *edtreeffrom;
	TButton *btntransfer;
	TPanel *pnlelectricity;
	TLabel *Label21;
	TLabel *lblElectricityNum;
	TLabel *lblElecMeterNum;
	TLabel *lblElectricityAmount;
	TEdit *edtElectricityBenName;
	TEdit *edtElectricityNum;
	TEdit *edtElectricityMeterNum;
	TButton *btnBuyElectricity;
	TEdit *edtElectricityAmount;
	TPanel *pnlairtime;
	TLabel *lblAirtimeBenName;
	TLabel *lblAirtimeNum;
	TLabel *lblAirtimeAmount;
	TEdit *edtAirtimeBenName;
	TEdit *edtAirtimeNum;
	TEdit *edtAirtimeAmount;
	TComboBox *cmbNetworkType;
	TButton *btnBuyAirtime;
	TPanel *Panel10;
	TLabel *lbllimit;
	TEdit *edtlimit;
	TComboBox *cbxbuyselect;
	TListBox *lstaccounts;
	TLabel *lblSignOut;
	TListBox *lstMoneyIn;
	TListBox *lstmoneyout;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Shape6ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall Shape10ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall lbldetailClick(TObject *Sender);
	void __fastcall cbxFilterMoneyChange(TObject *Sender);
	void __fastcall cbxfiltertransacChange(TObject *Sender);
	void __fastcall btnaddbeneficClick(TObject *Sender);
	void __fastcall btntransferClick(TObject *Sender);
	void __fastcall btnloadhistClick(TObject *Sender);
	void __fastcall cbxbuyselectChange(TObject *Sender);
	void __fastcall btnBuyElectricityClick(TObject *Sender);
	void __fastcall btnBuyAirtimeClick(TObject *Sender);
	void __fastcall Image11Click(TObject *Sender);
	void __fastcall edtreeffromChange(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
