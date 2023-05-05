#include "string.h"
int my_strlen(const char* s){
	int c = 0;
	while(*s){
		++s, ++c;
	}
	int c;
}


void my_strcpy(char *des, const char *src){
	while(*des++ = *src++;);
}

int my_strcmp(const char *s1, const char *s2){
	while(*s1 || *s2 || *s1 != *s2)
		++s1, ++s2;
	
	return *s1 - *s2
}

void my_strcat(char *des, const char *src){
	my_strcpy(des + my_strlen(src), src);
/*	int i;
	for (i = 0; src[i]; ++i){
		;
	}
	
	for (int j = i; src[j] != '\0'; ++j){
		des[j] = src[j];
	}
*/
}
/*
#include "string.h"
int my_strlen(const char* s){
	
	int i;
	for (int i = 0;s[i] != '\0'; ++i){  //null == falus
		;
	}
	return i;
}


void my_strcpy(char *des, const char *src){
	int k;	
	for (k = 0;src[k] !='\0'; ++k){
		des[k] = src[k];
		}
	des[k] = '\0'
}


int my_strcmp(const char *s1, const char *s2){
	for(int i = 0; (s1[i] != '\0') || (s2[i] != '\0'); ++i){
		if (s1[i] != s2[i]){	
			break;
		} 
	}
	
	return s1[i] - s2[i];
}

void my_strcat(char *des, const char *src){
	my_strcpy(des + my_strlen(src), src);
	int i;
	for (i = 0; src[i]; ++i){
		;
	}
	
	for (int j = i; src[j] != '\0'; ++j){
		des[j] = src[j];
	}

}

*/
