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

int operation::StringLength(string StrName, int length)
{	
	length = strlen(StrName.c_str());
      
	return length;
}

bool operation::sorting(string kelime_1, string kelime_2, int m, int a, int paper, int paper1, int frek, int frek1)
{
	char alfabe[30] = {' ', 'a', 'b', 'c', 'ç', 'd', 'e', 'f', 'g', 'ð', 'h', 'ý', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'ö', 'p', 'r', 's', 'þ', 't', 'u', 'ü', 'v', 'y', 'z'};
	
	int i, j, k, temp, kelime1deger, kelime2deger, yap1 = 0, yap2 = 0, sonuc = 0, deger;
	
	char kontrol, kontrol1;

	if ( m < a )
	{
		temp = m;
		m = a;
		a = temp;	
	}
		
	for( i = 0; i <= m; i++ )
	{	
		if( (kelime_1[i] != '\0') && (kelime_2[i] != '\0') ) 
		{			
			kontrol = kelime_1[i];
			kontrol1 = kelime_2[i];
			
			for( j = 0; j < 30; j++ )
			{
				if( sonuc == 0 )
				{
					if( alfabe[j] == kontrol )
					{
						kelime1deger = j;	
						yap1 = 1;	
					}
				
					if( (alfabe[j] == kontrol1) )
					{	
						kelime2deger = j;
						yap2 = 1;
					}
						
					if( (yap1 == 1) && (yap2 == 1) )
					{
								
						if ( kelime1deger < kelime2deger )
						{
							sonuc = 1;
							
							return true;
						}
					
						else if ( kelime1deger > kelime2deger )
						{
							sonuc = 1;
								
							return false;
						}
					
						else if ( kelime1deger == kelime2deger )
						{
							yap1 = 0;
							yap2 = 0;
							
							deger = 1;
						}		
					}	
				}
			
				else if ( sonuc == 1 )
				{
					break;
				}						
			}
		}
		
		else if ( (kelime_1[i] == '\0') && (kelime_2[i] != '\0') && sonuc == 0 )
		{
			sonuc = 1;
			return true;
		}
		else if ( (kelime_1[i] != '\0') && (kelime_2[i] == '\0') && sonuc == 0 )
		{
			sonuc = 1;
			return false;
		}
		
		else if ( (kelime_1[i] == '\0') && (kelime_2[i] == '\0') && deger == 1 && sonuc == 0 )
		{
			
			if ( paper < paper1 )
			{	
				return true;			
			}
			
			else if ( paper > paper1 )
			{
				return false;
			}
							
			else if ( paper == paper1 )
			{			
				if ( frek < frek1 )
				{
					return true;			
				}
								
				else if ( frek > frek1 )
				{
					return false;	
				}
				
				else if ( frek == frek1 )
				{
					//Böyle bir durum olamaz.
				}
			}
		}
	}
}

Queue operation::algorithm(Queue q1, Queue q2, int satirSay)
{
	char kelime_1[40], kelime_2[40];
	
	int value3, value4, value5, value6, say = 0, kac = 0, length, m, a, paper, paper1, frek, frek1;
	
	std::string temp1, temp2, temp3, temp4, temp5, temp6, gecici;
	
	bool kontrol = true, back;

	operation o;
	
	for( say = 0; say < satirSay; say++)
	{		
		if( kontrol == true )
		{
			int result = 1;	
			while ( q1.front != NULL )
			{
				if ( result == 1 )
				{	
					temp3 = q1.front -> evrak;
					temp1 = q1.front -> kelime;
					temp5 = q1.front -> frekans;
				
					q1.dequeue();
				
					temp4 = q1.front -> evrak;
					temp2 = q1.front -> kelime;
					temp6 = q1.front -> frekans;
				
					q1.dequeue();
				
					m = o.StringLength(temp1, length);
					a = o.StringLength(temp2, length);
					
					strncpy(kelime_1, temp1.c_str(), sizeof(kelime_1));
					strncpy(kelime_2, temp2.c_str(), sizeof(kelime_2));

					value3 = atoi(temp3.c_str());
					value4 = atoi(temp4.c_str());
					value5 = atoi(temp5.c_str());
					value6 = atoi(temp6.c_str());

					back = o.sorting(kelime_1, kelime_2, m, a, value3, value4, value5, value6);

					if ( back == true )
					{
						gecici = temp1;
						temp1 = temp2;
						temp2 = gecici;
					
						gecici = temp3;
						temp3 = temp4;
						temp4 = gecici;
					
						gecici = temp5;
						temp5 = temp6;
						temp6 = gecici;
					
						q2.enqueue(temp4, temp2, temp6);
						
						kuyruk2say++;
					}
				
					else if ( back == false )
					{
						q2.enqueue(temp4, temp2, temp6);
						
						kuyruk2say++;
					}
						
					result = 0;
				}
			
				else if ( result == 0 )
				{	
					temp4 = q1.front -> evrak;
					temp2 = q1.front -> kelime;
					temp6 = q1.front -> frekans;
				
					q1.dequeue();
				
					m = StringLength(temp1, length);
					a = StringLength(temp2, length);
				
					strncpy(kelime_1, temp1.c_str(), sizeof(kelime_1));
					strncpy(kelime_2, temp2.c_str(), sizeof(kelime_2));
					
					value3 = atoi(temp3.c_str());
					value4 = atoi(temp4.c_str());
					value5 = atoi(temp5.c_str());
					value6 = atoi(temp6.c_str());
				
					back = o.sorting(kelime_1, kelime_2, m, a, value3, value4, value5, value6);
				
					if ( back == true )
					{
						gecici = temp1;
						temp1 = temp2;
						temp2 = gecici;
					
						gecici = temp3;
						temp3 = temp4;
						temp4 = gecici;
					
						gecici = temp5;
						temp5 = temp6;
						temp6 = gecici;
					
						q2.enqueue(temp4, temp2, temp6);
						
						kuyruk2say++;		
					}
				
					else if ( back == false )
					{
						q2.enqueue(temp4, temp2, temp6);
						kuyruk2say++;
					
					}				
				}
			}
			q2.enqueue(temp3, temp1, temp5);

			kontrol = false;
		}
		
		else if ( kontrol == false )
		{
			int result2 = 1;
			while ( q2.front != NULL )
			{
				if ( result2 == 1 )
				{	
					temp3 = q2.front -> evrak;
					temp1 = q2.front -> kelime;
					temp5 = q2.front -> frekans;
				
					q2.dequeue();
					
					temp4 = q2.front -> evrak;
					temp2 = q2.front -> kelime;
					temp6 = q2.front -> frekans;
				
					q2.dequeue();
				
					m = o.StringLength(temp1, length);
					a = o.StringLength(temp2, length);
				
					strncpy(kelime_1, temp1.c_str(), sizeof(kelime_1));
					strncpy(kelime_2, temp2.c_str(), sizeof(kelime_2));

					value3 = atoi(temp3.c_str());
					value4 = atoi(temp4.c_str());
					value5 = atoi(temp5.c_str());
					value6 = atoi(temp6.c_str());

					back = o.sorting(kelime_1, kelime_2, m, a, value3, value4, value5, value6);

					if ( back == true )
					{
						gecici = temp1;
						temp1 = temp2;
						temp2 = gecici;
					
						gecici = temp3;
						temp3 = temp4;
						temp4 = gecici;
					
						gecici = temp5;
						temp5 = temp6;
						temp6 = gecici;
					
						q1.enqueue(temp4, temp2, temp6);
						kuyruk1say++;

					}
					
					else if ( back == false )
					{
						q1.enqueue(temp4, temp2, temp6);
						kuyruk1say++;

					}
				
					result2 = 0;
				}
			
				else if ( result2 == 0 )
				{	
			
					temp4 = q2.front -> evrak;
					temp2 = q2.front -> kelime;
					temp6 = q2.front -> frekans;
				
					q2.dequeue();
				
					m = o.StringLength(temp1, length);
					a = o.StringLength(temp2, length);
				
					strncpy(kelime_1, temp1.c_str(), sizeof(kelime_1));
					strncpy(kelime_2, temp2.c_str(), sizeof(kelime_2));
				
					value3 = atoi(temp3.c_str());
					value4 = atoi(temp4.c_str());
					value5 = atoi(temp5.c_str());
					value6 = atoi(temp6.c_str());
				
					back = o.sorting(kelime_1, kelime_2, m, a, value3, value4, value5, value6);
			
					if ( back == true )
					{
						gecici = temp1;
						temp1 = temp2;
						temp2 = gecici;
					
						gecici = temp3;
						temp3 = temp4;
						temp4 = gecici;
					
						gecici = temp5;
						temp5 = temp6;
						temp6 = gecici;
					
						q1.enqueue(temp4, temp2, temp6);	
						kuyruk1say++;
				
					}
				
					else if ( back == false )
					{
						q1.enqueue(temp4, temp2, temp6);
						kuyruk1say++;
					}
				}
			}
			q1.enqueue(temp3, temp1, temp5);
			kontrol = true;
		}
				
	}
	
	if( q1.isEmpty() == true )
	{
		return q2;
	}
	
	else if ( q2.isEmpty() == true )
	{
		return q1;
	}
}


