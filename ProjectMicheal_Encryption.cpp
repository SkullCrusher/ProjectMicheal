/*
*	**_ Project Micheal - Encryption and decryption _**
*
*	Coded by SkullCrusher for Micheal.
*
*	MIT License - Do what you want with it.
*/


#include <iostream>
#include <Windows.h>
#include <string>

void Encrypt(std::string &a, int Seed){

	//32 - 126 (The printable characters)
	unsigned int LastValue = Seed; //Set the last character to the seed.

	//The transformation loop (loops through all of the characters).
	for (unsigned int i = 0; i < a.size(); i++){

		unsigned char CurrentChar = a[i]; //Create a unsigned char to work with. (unsigned is required because unsigned is max 128?)

		CurrentChar += LastValue;

		//while the varable is over the limit remove 94
		while(CurrentChar > 126){
			CurrentChar -= 94;
		}		

		//Set the LastValue to the CurrentChar.
		LastValue = (unsigned int) CurrentChar;

		//Update the argument a
		a[i] = CurrentChar;

		//Debugging display.
		std::cout << CurrentChar;
	}
}


void Decrypt(std::string &a, int Seed){

	//Decrypt all of the string but the first character.
	for (int i = a.size() - 1; i > 0; i--){
		char CurrentChar = a[i]; //Grab the current character from the array.

		CurrentChar -= a[i - 1]; //Subtract the value of the character before it.

		//Force it to be in the correct range.
		while (CurrentChar < 32){
			CurrentChar += 94;
		}

		//Update the string.
		a[i] = CurrentChar;
	}

	//Grab the first character.
	char FirstCharacter = a[0];

	//Use the seed as the starting point.
	FirstCharacter -= Seed;

	//Force it to be in the correct range
	while (FirstCharacter < 32){
		FirstCharacter += 94;
	}

	//Set the character to the updated one.
	a[0] = FirstCharacter;
}



int main(){	

	//https://github.com/SkullCrusher/ProjectMicheal

	//"Lol you can decrypt I see. try the rest."
	//Encrypted with Seed 23: "ct$D_p)INQa#)05Idv.N9Ynu|Ll$8Ss+5<\\pw.Dr"

	//"SkullCrusher: I hope this works right, I did not test alot."
	//Encrypted with Seed 43: "~-DR`EYp'18L(H3S]n\")I_it+Kdu+8Mm#.7AW%E0PVag)9J`\"8?Tj,/=Nd4"

	//http://i.imgur.com/4SBSgDo.jpg
	//Encrypted with Seed 50: "<RhzV'Va1<KTk!OTetEynRGP6Gu#5>"

	//"This was encrypted here is a url: http://i.imgur.com/OTz3RH1.gif"
	//Encrypted with Seed 42: "~*5Jj%(=]dty/J\\ry!AKRfm/:Oor4K_mIis+AS/^/:hs$-DX(->M|mc!TH2c3<GO"
	
	//An example encryption string.
	std::string Message = "http://www.cplusplus.com/doc/tutorial/variables/";
	
	Encrypt(Message, 17);
	Decrypt(Message, 17);

	return 0;
}