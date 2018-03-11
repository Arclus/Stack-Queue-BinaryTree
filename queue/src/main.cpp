#include <iostream>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "operation.h"
#include "queue.h"

/*
Resul Emre Aygan
*/

using namespace std;

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Turkish");
	
	Queue queue, queue2, queue3;
	
	operation o;
	
	int satirSay;
	
	ofstream myfile("sonuc.queue.csv");
    
	string w1, w2, w3, line, word;
	
	ifstream myFile("vya2016veriler.csv");
		
	if ( myFile.is_open() == false )
	{
		cout << "Can't Open The File" << endl;
		exit(EXIT_FAILURE);	
	}
	 
	else
	{
		while ( getline(myFile, line) )
		{
			stringstream ss(line);
			
		    int sayac = 0;
		    
			while ( getline(ss,word, ',') )
			{
				if ( sayac == 0 )
				{
					w1 = word;
					sayac++;
				}
				
				else if ( sayac == 1 )
				{
					w2 = word;
					sayac++;
				}
				
				else if ( sayac == 2 )
				{
					w3 = word;
					sayac=0;
				}		 
			}			
			queue.enqueue(w1, w2, w3); 
			satirSay++;	
     	}
       	myFile.close();		    
	} 
	
	queue3 = o.algorithm(queue, queue2, satirSay);
	
	//queue3.display();
	//cout << o.kuyruk1say << endl;
	//cout << o.kuyruk2say << endl;
	
	if ( queue3.front != NULL )
	{
		while ( queue3.front != NULL )
		{
			myfile << queue3.front -> evrak << "," << queue3.front -> kelime << "," << queue3.front -> frekans << endl;
			queue3.dequeue();
		}
	}
	
	myfile.close();
	
	return 0;
}
