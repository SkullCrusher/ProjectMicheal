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

int main(){	

	//https://github.com/SkullCrusher/ProjectMicheal

	//Encrypted with Seed 23: "ct$D_p)INQa#)05Idv.N9Ynu|Ll$8Ss+5<\\pw.Dr"

	//Encrypted with Seed 43: "~-DR`EYp'18L(H3S]n\")I_it+Kdu+8Mm#.7AW%E0PVag)9J`\"8?Tj,/=Nd4"

	//Encrypted with Seed 50: "<RhzV'Va1<KTk!OTetEynRGP6Gu#5>"

	//Encrypted with Seed (Unknown): "~*5Jj%(=]dty/J\\ry!AKRfm/:Oor4K_mIis+AS/^/:hs$-DX(->M|mc!TH2c3<GO"


	//An example encryption string.
	std::string Message = "http://www.cplusplus.com/doc/tutorial/variables/";
	
	Encrypt(Message, 23);

	return 0;
}