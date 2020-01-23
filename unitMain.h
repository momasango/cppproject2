//---------------------------------------------------------------------------

#ifndef unitMainH
#define unitMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TToolBar *tlBar1;
	TPageControl *PageControl1;
	TTabSheet *tbsheetManStudent;
	TDBGrid *DBGrid1;
	TButton *btnDelete;
	TButton *btnUpdate;
	TEdit *edtName;
	TEdit *edtSurname;
	TEdit *edtPhone;
	TEdit *edtGroup;
	TComboBox *cmbEdtYear;
	TEdit *studentIDcheck;
	TDateTimePicker *DateTimePicker1;
	TButton *btnFirst;
	TButton *btnLast;
	TButton *btnNext;
	TButton *btnPrevious;
	TButton *Button1;
	TADOConnection *conSchool;
	TADODataSet *DataSetStudent;
	TDataSource *dsStudent;
	TADOCommand *ADOCommand2;
	TADOCommand *ADOCommand3;
	TButton *btnRefresh;
	TTabSheet *tbshtRecordMarks;
	TDBGrid *DBGrid2;
	TButton *btnEditMarks;
	TDataSource *dsGrades;
	TADODataSet *DataSetGrades;
	TLabel *Label3;
	TMemo *Memo1;
	void __fastcall btnFirstClick(TObject *Sender);
	void __fastcall btnPreviousClick(TObject *Sender);
	void __fastcall btnNextClick(TObject *Sender);
	void __fastcall btnLastClick(TObject *Sender);
	void __fastcall btnUpdateClick(TObject *Sender);
	void __fastcall btnDeleteClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnRefreshClick(TObject *Sender);
	void __fastcall btnEditMarksClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    void showCurrentRecord(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
