//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDMod : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *conSchool;
	TADODataSet *DataSetStudent;
	TDataSource *dsStudent;
	TADOCommand *ADOCommand1;
	TADOCommand *ADOCommand2;
	TADOCommand *ADOCommand3;
	TDataSource *dsStudent1;
private:	// User declarations
public:		// User declarations
	__fastcall TDMod(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMod *DMod;
//---------------------------------------------------------------------------
#endif
