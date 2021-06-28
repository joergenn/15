//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdlib>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgame *game;
//---------------------------------------------------------------------------
__fastcall Tgame::Tgame(TComponent* Owner)
        : TForm(Owner)
{
        label1->Width = 150;
        label2->Visible = 0;
        int i,j,k;
        for(k=0;k<15;k++){
                mass[k]=k+1;
        }
        mass[15]=0;
        B=new TButton*[16];
        for(k=0;k<16;k++){
                B[k]=new TButton(Owner);
                B[k]->Caption=mass[k];
                B[k]->Parent=game;
                B[k]->Visible=1;
                i=k/4;j=k-4*i;
                B[k]->Height=50;
                B[k]->Width=50;
                B[k]->Top=0+i*64;
                B[k]->Left=0+j*64;
                B[k]->OnClick = Check;
        }
        B[15]->Caption=0;
        B[15]->Visible=1;
}
//---------------------------------------------------------------------------

void __fastcall Tgame::Check(TObject *Sender)
{
label2->Visible = 1;
label2->Caption = count;
int i,j,t,k, temp;

k=num(Sender);

if(k != -1){
        if(k == 0){
                if((B[k+1]->Caption) == 0){
                        temp = mass[k];
                        mass[k] = mass[k+1];
                        mass[k+1] = temp;
                        B[k]->Caption = mass[k];
                        B[k+1]->Caption = mass[k+1];
                        count++;
                }
                else if((B[k+4]->Caption) == 0){
                        temp = mass[k];
                        mass[k] = mass[k+4];
                        mass[k+4] = temp;
                        B[k]->Caption = mass[k];
                        B[k+4]->Caption = mass[k+4];
                        count++;
                        }
        }
        else if(k == 14){
                if((B[k+1]->Caption) == 0){
                        temp = mass[k];
                        mass[k] = mass[k-1];
                        mass[k+1] = temp;
                        B[k]->Caption = mass[k];
                        B[k+1]->Caption = mass[k+1];
                        count++;
                }
                else if((B[k-4]->Caption) == 0){
                        temp = mass[k];
                        mass[k] = mass[k-4];
                        mass[k-4] = temp;
                        B[k]->Caption = mass[k];
                        B[k-4]->Caption = mass[k-4];
                        count++;
                }
                else if((B[k-1]->Caption) == 0){
                        temp = mass[k];
                        mass[k] = mass[k-1];
                        mass[k-1] = temp;
                        B[k]->Caption = mass[k];
                        B[k-1]->Caption = mass[k-1];
                        count++;
                }
        }
 }
        if(check()){
                
        }
}

//-------------------------------------------------------------------------—
int __fastcall Tgame::num(TObject *Sender){
        for(int k=0;k<=16;k++){
                if(Sender==B[k]) return k;
        }
        return -1;
}
//-------------------------------------------------------------------------—
int Tgame::check(void){
        for(int k=0;k<15;k++){
                if(mass[k]!=k+1) return 0;
                if(mass[15]!=0) return 0;
        }
        return 1;
}

//---------------------------------------------------------------------------
void __fastcall Tgame::mixClick(TObject *Sender)
{
int i,j,k,n, random_number, temp;
        count=0;
        for(i = 0; i < 15; i++){
                random_number = rand()%15;
                temp = mass[i];
                mass[i] = mass[random_number];
                mass[random_number] = temp;
                B[i]->Caption = mass[i];
                B[random_number]->Caption = mass[random_number];
        }

}
//---------------------------------------------------------------------------

