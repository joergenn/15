//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <stdlib.h>
#include <cstdlib>
//---------------------------------------------------------------------------
class Tgame : public TForm
{
__published:	// IDE-managed Components
        TLabel *label1;
        TLabel *label2;
        TButton *mix;
        void __fastcall mixClick(TObject *Sender);
        
private:	// User declarations
        int mass[16];
        TButton**B;
        int count;
public:		// User declarations
        __fastcall Tgame(TComponent* Owner);
        int check(void);
        void __fastcall Check(TObject *Sender);
        int __fastcall num(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE Tgame *game;
//---------------------------------------------------------------------------
#endif


