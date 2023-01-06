// TODO1: Add file header documentation ...

#include "q.h" // encrypt and decrypt function declarations
// TODO2: Add necessary C standard library headers ...
#include <stdio.h>	// for FILE, printf
#include <string.h> // for strlen
#define SIZE 255

int main(void)
{

	int c = 0, i = 0, key_len = 0;
	char word;
	char keyword[SIZE];
	FILE *key = fopen("key.txt", "r");

	if (NULL == key)
	{
		printf("Unable to open file key.txt\n");
		return 1;
	}

	while ((c = fgetc(key)) != EOF)
	{
		if (c == '\n' || c == '\0')
		{
			break;
		}
		keyword[key_len] = (char)c;
		key_len += 1;
	}
	fclose(key);

#ifdef ENCRYPT

	// TODO3: read characters from input file plain.txt and write the
	// corresponding encrypted characters to output file cipher.txt
	// using the keyword in file key.txt
	//c = 0;
	i = 0;
	FILE *plain = fopen("plain.txt", "r");
	FILE *cipher = fopen("cipher.txt", "w");

	if (NULL == plain)
	{
		printf("Unable to open file plain.txt\n");
	}
	if (NULL == cipher)
	{
		printf("Unable to open file cipher.txt\n");
	}

	while ((c = fgetc(plain)) != EOF)
	{
		word = (char)c;
		encrypt(&word, keyword[i % key_len]);
		fputc(word, cipher);
		i += 1;
	}
	fclose(plain);
	fclose(cipher);

#else

	// TODO4: read characters from input file cipher.txt and write the
	// corresponding decrypted characters to output file out-plain.txt
	// using the keyword in file key.txt
	FILE *cipher = fopen("cipher.txt", "r");
	if (NULL == cipher)
	{
		printf("Unable to open file cipher.txt\n");
	}
	FILE *out_plain = fopen("out-plain.txt", "w");
	if (NULL == out_plain)
	{
		printf("Unable to open file out-plain.txt\n");
	}
	i = 0;

	while ((c = fgetc(cipher)) != EOF){
		word = (char)c;
		decrypt(&word, keyword[i % key_len]);
		fputc(word, out_plain);
		i+=1;
	}
	fclose(cipher);
	fclose(out_plain);

	// TODO5: write count of words into stderr
	int space = 0;
	int count = 0;
	FILE *input_file = fopen("out-plain.txt", "r");
	while ((c = fgetc(input_file)) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		{
			space = 0;
		}
		else if (space == 0)
		{
			count++;
			space = 1;
		}
	}
	fprintf(stderr, "Words: %d\n", count);
	fclose(input_file);

#endif

	return 0;
}
