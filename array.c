// Dynamic allocation
// Lab Work 6. Exercise 1.
// The program search the most friquent item in array of strings.
// The Program has option search a custom item from user in array of strings.
/********************************************************
*	File name:	lab6ex1.c								*
*	Students:	Dariia Shemiakina and Tamir Yurovskiy	*
*	Deadline:	18.11.2019								*
*	Date:		17.11.2019								*
********************************************************/
#include <stdio.h>	// printf()
#include <stdlib.h>	// system()
#include <string.h>	// strlen()

#pragma warning (disable: 4996)	// hide warning for scanf()

#define N 5				// number of strings
#define MAX_LENGHT 100	// maximum lenght of one string
#define CHAR_VALUES 256	// number of symbols

/*************** FillArray ***************
Description:
function fills the array of strings.

Complexity:
O(N)

Arguments:
arr_str[]	- array of pointers to strings
size		- strings quantity

Return value:
none
*****************************************/
void FillArray(char *arr_str[], int size);

/************ SearchFriqChar ************
Description:
function search the most friquent char in array of strings

Complexity:
O(N*MAX_LENGTH)

Arguments:
arr_str[]	- array of pointers to strings
size		- strings quantity
ch			- the most friquent char

Return value:
how much times appeared the most friquent char in array of strings
****************************************/
int SearchFriqChar(char *arr_str[], int size, char *ch);

/************** SearchChar **************
Description:
function search how much times appeared custom char in array of strings

Complexity:
O(N*MAX_LENGTH)

Arguments:
arr_str[]	- array of pointers to strings
size		- strings quantity
ch			- custom char from user

Return value:
how much times appeared custom char in array of strings
****************************************/
int SearchChar(char *arr_str[], int size, char ch);

/*************** FreeArray ***************
Description:
function free the memory from array

Complexity:
O(N)

Arguments:
arr_str[]	- array of pointers to strings
size		- strings quantity

Return value:
none
*****************************************/
void FreeArray(char *arr_str[], int size);

// MAIN function
void main(void)
{
	char *arr_str[N] = { 0 };
	char max_ch, custom_ch;

	FillArray(arr_str, N);

	printf("The most symbol is '%c' appeared %d times.\n",
								max_ch, SearchFriqChar(arr_str, N, &max_ch));

	printf("Enter symbol: ");
	custom_ch = getchar();

	printf("The symbol '%c' appeared %d times.\n",
								custom_ch, SearchChar(arr_str, N, custom_ch));

	FreeArray(arr_str, N);

	system("pause");
}

void FillArray(char *arr_str[], int size)
{
	int i;
	char string[MAX_LENGHT];

	for (i = 0; i < size; ++i)
	{
		printf("Enter %d line from %d: ", i + 1, size);
		gets(string);

		// allocate memory for srting
		arr_str[i] = (char *)malloc((strlen(string) + 1) * sizeof(char));

		if (arr_str[i]) // check allocate success
		{
			strcpy(arr_str[i], string);
		}
		else
		{
			printf("Couldn`t allocate the array!\n");
			exit(1);
		}
	}
}

int SearchFriqChar(char *arr_str[], int size, char *ch)
{
	int i, max_ind = 0;
	int LUT[CHAR_VALUES] = { 0 }; // look up table
	char *tmp_arr[N];

	for (i = 0; i < size; ++i)
	{
		tmp_arr[i] = arr_str[i];

		while (*(tmp_arr[i]) != '\0')
		{
			LUT[*(tmp_arr[i])]++;

			if (LUT[max_ind] < LUT[*(tmp_arr[i])])
			{
				max_ind = *(tmp_arr[i]);
				*ch = max_ind;
			}

			++tmp_arr[i];
		}
	}

	return(LUT[*ch]);
}

int SearchChar(char *arr_str[], int size, char ch)
{
	int i;
	int LUT[CHAR_VALUES] = { 0 }; // look up table
	char *tmp_arr[N];

	for (i = 0; i < size; ++i)
	{
		tmp_arr[i] = arr_str[i];

		while (*(tmp_arr[i]) != '\0')
		{
			LUT[*(tmp_arr[i])]++;
			++tmp_arr[i];
		}
	}

	return(LUT[(int)ch]);
}

void FreeArray(char *arr_str[], int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		// free each string
		free(arr_str[i]);
	}
}
