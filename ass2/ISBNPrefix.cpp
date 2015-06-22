/*Hyungi kim
025 741 125
assignment 2
ISBN.cpp*/
#include<iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
using namespace std;
#include"ISBNPrefix.h"
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE 

ISBNPrefix::ISBNPrefix(){
	fp=NULL;
}
ISBNPrefix::ISBNPrefix(const char* prefixRanges[]){
	if(prefixRanges !=NULL){
	fp = fopen ("prefixRanges.txt","r");
	}
	else{
		fp=NULL;
	}
}
bool ISBNPrefix::isRegistered(int area) const{
	int a,ps,pl;
    if(fp!=NULL){
		rewind(fp);
		do{
        fscanf(fp,"%d%d%d",&a,&ps,&pl);
        if (a == area){
			return true;
		}
		}while(a!=area && !feof(fp));
	}
    return false;
}
int ISBNPrefix::minNoDigits(int area) const{
	int a, minno=0;
    char ps[10],pl[10];
    if(fp!=NULL){
        rewind(fp);
		while(!feof(fp) && minno==0){
            fscanf(fp,"%d%s%s",&a,&ps,&pl);
            if(a==area){
                minno=2;
			}
			else if(area>a){
				minno=1;
			}
			else if(area<a){
				minno=0;
			}
		}
	}

return minno;
}
bool ISBNPrefix::isRegistered(int area, const char* publisher) const{
	int a,minck=0;
    char pu[10],pl[10];
    int is,il,ii;
    if(fp !=NULL){
		rewind(fp);		
		do{
        fscanf(fp,"%d%s%s",&a,pu,pl);
        if(a == area){
            if(strlen(publisher)==strlen(pu)){
				if((strcmp(publisher,pu) >=0) && (strcmp(publisher,pl)<=0)){
					return true;
				}
			}
		}//a==area;
	}while (minck==0 && !feof(fp));
	}// if !=NULL
    return false;
}
ISBNPrefix::~ISBNPrefix(){
	if( fp !=NULL){
		fclose(fp);
	}
}