/*Hyungi kim
025 741 125
assignment 3
ISBN.cpp*/
#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include"ISBNPrefix.h"
#include"ISBN.h"
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE 

bool isValid(const char* str)
{
   int i, dc=0, cd=10, rc, sum=0;
 
   if( str != NULL )//is it null value?
   {
      if( strlen( str ) != 10 ){
         return false;
	  }//str is not 10 digit return false
      else
         if( str[9] == 'X' || ( str[9] >= '0' && str[9] <= '9' ) )
         {
            for( i = 0; i < 9; i++ )
            {
               if( str[i] < '0' && str[i] > '9' )
                  return false;
            }
         }
 
      if( str[9] == 'X' ){
         rc = 10;
	  }
      else{
         rc = str[9] - '0';
	  }
 
      for(dc=0;dc<9;dc++){
         sum += ( str[dc] - '0' ) * cd;
         cd--;                
      }
 
      sum += rc;
 
      if( sum % 11 == 0 ){
         return true;
	  }//modulo 11 ==0 than return true
      else{
         return false;
	  }
   }
 
   return false;
}//end of IsValid
bool operator==(const ISBN& left, const ISBN& right){
	ISBN temp = left;

}
ISBN::ISBN(){
	int t = 0, a = 0, p = 0,i=0;
	while(i < 11){
		ISBNcd[i]='\0';
		i++;
	}//while i<11;
	while( t < 7 ){
      title[t] = '\0';
      t++;
   }//while t<7
 
   while( a < 6 ){
      area[a] = '\0';
      a++;
   }//a<6
 
   while( p < 8 ){
      publisher[p] = '\0';
      p++;
   }//p<8
   registered=false;//safe declarition of null values and false
}//ISBN Constructior ends
bool ISBN::empty() const{
	ISBNcd[0]=='\0';
	return !ISBNcd[0];//return str[0];
}//ISBN::empty ends
ISBN::ISBN(const char* s2, const ISBNPrefix& list){
	if(isValid(s2)==true){//is valid str?
		strcpy(ISBNcd,s2);
		registered=isRegistered(list);
	}//if isVlaid=true
	else{
		*this =ISBN();
	}
}//ISBN::ISBN(const char*,const ISBNprefix&) ends
 bool ISBN::isRegistered() const{
	 return registered;
 }//end of ISBN::isRegistered()
 bool ISBN::isRegistered(const ISBNPrefix& list){
   for(int a = 0; a < 5; a++ ){
      area[a] = ISBNcd[a];
      for(int p = 1; p < 8; p++ ){
         publisher[p - 1] = ISBNcd[a + p];
         if( list.isRegistered(atoi( area ), publisher ) ){
            for(int t = 1; t < 7; t++ ){
               if( a + p + t == 9 ){
				   t = 7;}
               else{
				   title[t - 1] = ISBNcd[a + p + t];}
            }//3rdfor
            return true;}//if list.isregi,pub
	  }//2nd for
      for(int p=0;p<8;p++){
         publisher[p] = '\0';}//reset publisher string
   }//1st for
  
return false;
 }//ISBN::isRegistered const ISBNPrefix & ends

 void ISBN::tostr(char* str) const{
	 if(str!=NULL){
	 strcpy(str,area);
	 strcat(str,publisher);
	 strcat(str,title);
	 str += ISBNcd[10];
	 }//make sure its not NULL
	 else{
		 ISBN();
	 }
 }//tostr ends

 void ISBN::toStrWithStyle(char* str) const{
	if(str!=NULL){
	strcpy(str,area);
	str += '-';
	strcat(str,publisher);
	str += '-';
	strcat(str,title);
	str += '-';
	str += ISBNcd[10];
	 }//make sure its not NULL
	 else{
		 ISBN();
	 }
 }//tostrwithstyle ends

 bool ISBN::read(istream& is, const ISBNPrefix& list){
	 char temp[11];
	 int i=0;
	 while (i==0){
		 cout<<"ISBN 0 to quit :"<<endl;
		 is>> temp;
		 if(strlen(temp)>10 && temp[0]=='0'){
			 return false;
		 }
		 else if(strlen(temp) ==10 && isValid(temp) == true){
			 i++;
			 ISBN(temp, list);
		 }
		 else{
			 cout<<"Invalid check digit. Please try again"<<endl;
		 }	 
	 }
	 return true;
 }//read ends

 void ISBN::display(ostream& os) const{
	 char temp[13];
	 if(registered==true){
		 toStrWithStyle(temp);
	 }
	 else{
		 tostr(temp);
	 }
	 os.width(13);
	 os<<temp<<endl;
 }//display ends