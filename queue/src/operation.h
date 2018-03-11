#include <iostream>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "queue.h"

/*
Resul Emre Aygan
*/

class operation
{
	public:
		int kuyruk1say, kuyruk2say;
		bool sorting(std::string kelime_1, std::string kelime_2, int m, int a, int paper, int paper1, int frek, int frek1);
		int StringLength(std::string StrName, int length);
		
		Queue algorithm(Queue q1, Queue q2, int satirSay);
};
