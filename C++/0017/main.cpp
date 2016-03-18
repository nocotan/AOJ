#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
int main()
{
    char str[90];
     
    while( fgets( str, 81, stdin ) != 0 ){
        while( 1 ){
            for( int i = 0; i < strlen( str ); i++ ){
                if( isalpha( str[i] ) ) str[i]++;
                 
                if( str[i] > 'z' ){
                    str[i] = 'a';
                }
            }
             
            if( strstr( str, "the" ) != NULL || strstr( str, "this" ) != NULL || strstr( str, "that" ) != NULL ) break;
        }
         
        std::cout << str;
    }
 
    return 0;
}
