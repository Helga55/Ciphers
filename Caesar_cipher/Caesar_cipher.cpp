/*******************
 * Caesar's cipher *
 * 2017_07_17	   *
 *******************/
 
#include <iostream>                                 // cout(), cin()
#include <string>                                   // size(), getline()
#include <cctype>                                   // isalpha(), isupper()

#define  ALPHNUM  26                                // number of letters of the alphabet

using namespace std;

void Right_Shift(string &line, int key);
void Left_Shift(string &line, int key);

int main(void) {
    int    k = 0;
    int    direction = 0;
    string s;
	
    cout << "Input string for encryption, key & direction (left = 0, right = 1): " 
         << endl << endl;
		 
    cout << "string = ";		
    getline(cin, s);
    cout << "key = "; 			
    cin  >> k;
    cout << "direction = "; 	
    cin  >> direction;

    if (direction) {
        Right_Shift(s, k);
    } else {
        Left_Shift(s, k);
    }

    cout << s << endl;
  
    return 0;
} 


// right shift -->
void Right_Shift(string &line, int key) {
    for (auto &letter : line) {			
        if (isalpha(letter)) {
            letter += key;			
            letter  = (isupper(letter)) ? ((letter > 'Z') ? (letter - ALPHNUM) : letter) :
                                          ((letter > 'z') ? (letter - ALPHNUM) : letter) ;
        } 	
    }
}


// <-- left shift
void Left_Shift(string &line, int key) {
    for (auto &letter : line) {			
        if (isalpha(letter)) {
            letter -= key;			
            letter  = (isupper(letter)) ? ((letter < 'A') ? (letter + ALPHNUM) : letter) :
                                          ((letter < 'a') ? (letter + ALPHNUM) : letter) ;
        } 	
    }
}

