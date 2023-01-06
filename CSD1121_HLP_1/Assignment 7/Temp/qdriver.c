// TODO1: Add file header documentation ...

#include "q.h"			// encrypt and decrypt function declarations
// TODO2: Add necessary C standard library headers ...
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int keyLength = 0, counter = 0, ch;
	char key[255], c;
	//Get access to read from file that contains the key used for future encryption/ decryption
	FILE *cipherKey = fopen("key.txt", "r");
	//return an error upon failure to open file
	if(NULL == cipherKey){
		printf("Unable to open file key.txt\n");
		return 1;
	}
	//From key.txt
	//get the value of the whole key for encryption/decryption
	//and store it in respective index of char array
	//assumming a max char length of 255
	while((ch = fgetc(cipherKey)) != EOF){
		if (ch == '\n' || ch == '\0'){
			break;
		}
		key[keyLength] = (char) ch;
		keyLength +=1;
	}
	//cloase files previously opened
	fclose(cipherKey);
#ifdef ENCRYPT
	// TODO3: read characters from input file plain.txt and write the
	// corresponding encrypted characters to output file cipher.txt
	// using the keyword in file key.txt

	//Get access to read from plain.txt
	FILE *plain = fopen("plain.txt", "r");
	//Get access to write to cipher.txt
	FILE *cipher = fopen("cipher.txt", "w");
	//reset counter to count for number of char
	counter = 0;
	//Error handling if file read results in an error
	if(NULL == plain){
		printf("Unable to open file plain.txt\n");
	}
	if(NULL == cipher){
		printf("Unable to open file cipher.txt\n");
	}

	while((ch=fgetc(plain)) != EOF){
		//Converts ch read from type int to char
		c = (char) ch;
		/*counter % keylength is used to find the corresponding key to use based of the current letter's index
			wrap the total ch so far with the length of key
			E.g key of Digipen and chars at 
			0	1	2	3	4	5	6	7	8	9	10
			D	i	g	i	p	e	n	D	i	g	i
		*/
		//encrypt ch read
		encrypt(&c, key[counter % keyLength]);
		//Output encrypted char to cipher.txt
		fputc(c, cipher);
		//increase char found
		counter += 1;

	}
	//Close files previously opened
	fclose(plain);
	fclose(cipher);

	//printf("%s Key Length: %d\n", key, keyLength);
#else

	//TODO4: read characters from input file cipher.txt and write the
	//corresponding decrypted characters to output file out-plain.txt
	//using the keyword in file key.txt
	//TODO5: write count of words into stderr
	
	//Get access to read from cipher.txt
	FILE *cipher = fopen("cipher.txt", "r");
	//Get access to write to out-plain.txt
	if(NULL==cipher){
		//error handling if unable to read file
		printf("Unable to read file cipher.txt\n");
	}

	FILE *output = fopen("out-plain.txt", "w");
	if(NULL == output){
		//error handling if unable to write to file
		printf("Unable to read file out-plain.txt\n");
	}
	//reset counter for number of char in file
	counter = 0;
	while ((ch = fgetc(cipher)) != EOF){
		//Converts ch of int type to char type
		c = (char)ch;
		//decrypt ch's value
		/*counter % keylength is used to find the corresponding key to use based of the current letter's index
			wrap the total ch so far with the length of key
			E.g key of Digipen and chars at 
			0	1	2	3	4	5	6	7	8	9	10
			D	i	g	i	p	e	n	D	i	g	i
		*/
		decrypt(&c, key[counter % keyLength]);
		//write to out-plain.txt
		fputc(c, output);
		//increase counter
		counter+=1;
	}
	//Close previously opened files
	fclose(cipher);
	fclose(output);

	int space = 0;
	int count = 0;
	//get access to read from out-plain.txt
	FILE *input = fopen("out-plain.txt", "r");
	/*counts the number of words in the deciphered text files 
		delimited by whitespace characters
		: includeing a space (" "), new line ("\n"), carriage return ("\r"), tab ("\t")
		Punctuations are assumed to be part of a word.
	*/
	while ((ch = fgetc(input)) != EOF) {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r'){
			space = 0;
		}
		else if (space == 0){
			count++;
			space = 1;
		}
	}
	//print out the total word count found.
	fprintf(stderr, "Words: %d\n", count);
	fclose(input);

#endif

	return 0;
}
