#include <iostream>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "stack.h"

/*
Resul Emre Aygan
*/

class operations
{
	public:
		int v1Sayac, v2Sayac;
		bool sorting(std::string kelime_1, std::string kelime_2, int m, int a, int paper, int paper1, int frek, int frek1);
		
		int StringLength(std::string StrName, int length);
		
		Stack algorithm(Stack v1, Stack v2);
};
