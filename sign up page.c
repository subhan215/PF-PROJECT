#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

bool password_verify(password);
char* vemail();
int signUpFunc() ; 
int logInFunc() ; 
int home() ; 
int main()
{
	
    logInFunc() ; 
}
char readRole(char filePath[]) {
	int count = 0 ;
	FILE *filePtr = fopen(filePath , "r") ; 
	char role ; 
		 while (fgets(role, sizeof role, filePtr) != NULL) 
    {
        if (count == 1)
        {
            return role ; 
            fclose(filePtr) ; 
        }
        else
        {
            count++;
        }
    }
    fclose(filePtr);
	}
	
void encrypted_pass(char password[]){
	int counter;
	for(counter = 0; (counter < 100 && password[counter] != '\0'); counter++){
        password[counter] = password[counter] + 3;
	}
}

void decrypted_pass(char password[]){
	int counter;
	for(counter = 0; (counter < 100 && password[counter] != '\0'); counter++){
        password[counter] = password[counter] - 3;
	}
}

void hide_pass(char password[]){
	char character;
	int counter=0 , i;
	while((character=_getch())!=13 ){
		if(character == 8 ) {
			fflush(stdout) ; 
			printf("\b \b") ; 
			password[--counter] = '\0' ; 
			continue ; 
		}
		printf("*") ;
		password[counter]=character;
		counter++;
		
		}
	
	
	password[counter]='\0';
}
int profile(char filePath[]) {
	char role = readRole(filePath) ;
	FILE *filePtr = fopen(filePath , "r") ;
	char line[50] ; 
	int counter = 0 ;  
	system("cls") ; 
    while (fgets(line, sizeof line, filePtr) != NULL) 
    {
	if(counter == 0) {
		decrypted_pass(line) ; 
		printf("Password : %s" , line) ; 
		
		counter++ ; 
	} else if(counter == 1) {
			printf("\nRole : %s" , line) ;
			counter++ ;  
	} else if(counter == 2) {
			printf("Email : %s" , line) ;
			counter++ ;  
	} else if(counter ==3 ) {
			printf("User Name : %s" , line) ;
			counter++ ;  
	}
	} 
	
	
}

int signUpFunc() {
	char role;
	char Name[20],email[30];
		char filePath[50] ;
	printf("For which type you want to create an account(customer , hotel , or resturant)\n(c for customer , h for hotel ,  r for restaurant):");
	fflush(stdin) ; 
	scanf("%c",&role);
	printf("Enter user name:");
	fflush(stdin) ; 
	gets(Name);
	char *emailPtr = vemail();
	int counter = 0 ;
	while(*emailPtr !='\0') {
		email[counter] = *emailPtr ; 
		emailPtr++ , counter++ ; 
	} 
	char password[16],cPassword[16],confirm[16];
    while(1){
	printf("\ncreate your password:");
	fflush(stdin) ; 
	hide_pass(password);
	bool result=password_verify(password);
	if (result){
	while(1)
	{
	printf("\ncomfirm your password:");
	hide_pass(cPassword);
	int x;
	x=strcmp(password,cPassword);
	if(x>0||x<0)
	{
	printf("\nPlease insert the same password..\n");
	continue;
	}
	else
	{printf("\n\t\t..account created..\n\n");
	encrypted_pass(password);
	system("cls") ;   
	FILE *fPtr ;
	counter = 0 ;

	strcpy(filePath , email) ;  
	strcat(filePath , ".txt"); 
		fPtr = fopen(filePath , "a") ;  
		fprintf(fPtr , "%s\n" , password); 
		fprintf(fPtr , "%c\n" , role) ; 
		fprintf(fPtr , "%s\n" , email);  
		fprintf(fPtr , "%s\n" , Name); 
    fclose(fPtr) ;
	break;
	}
	}
	break;
}
	else{
	 printf("\nInvalid password!!\n");
	 continue;
	}
	} 
	
	return 0 ;   
}
int logInFunc() {
	char email[50] ; 
	char password[50]; 
	printf("Enter your email: ") ; 
	gets(email) ; 
	FILE *fPtr ; 
	char filePath[50] ;
	strcpy(filePath , email) ;  
	strcat(filePath , ".txt");
	fPtr = fopen(filePath , "r") ;  
    if(fPtr == NULL) {
    	perror("Can't find your account!") ; 
	} else {
		printf("Enter your password: ") ; 
	    gets(password) ;
	    int length = strlen(password) ; 
		char filePass[length + 1] ;  
		fgets(filePass, sizeof(filePass) , fPtr) ; 
		decrypted_pass(filePass) ; 
		int match = strcmp(password , filePass);
        if( match == 0) {
        	printf("Login Successfull!") ;
			profile(filePath) ;  
		} else {
			printf("Password Incorrect!") ; 
		}
	}
	return 0 ; 
}
bool password_verify(char*password){
	int length=strlen(password);
	if(length<8||length>16)
	return false;
	bool has_upper=false;
	bool has_lower=false;
	bool has_digit=false;
	bool has_symbol=false;
	int i ; 
	for(i=0;i<length;i++)
	{
	if(isupper(password[i]))
	has_upper=true;
	if(islower(password[i]))
	has_lower=true;	
	if(isdigit(password[i]))
	has_digit=true;	
	if(ispunct(password[i]))
	has_symbol=true;	
	}
	if(!has_upper) return false;
	if(!has_lower) return false;
	if(!has_digit) return false;
	if(!has_symbol) return false;
	return true;
}

char* vemail(){
	char email[50];
	char* ptrEmail = email; 
	int counter,alpha=0,dot=0;
		printf("\t\t\nEnter your e-mail id : ");
		fflush(stdin) ; 
		gets(email);
	do{
	for(counter=0;email[counter]!='\0';counter++)
		{
			if(email[counter]=='@')
			alpha=counter;	
			if(email[counter]=='.')
			dot=counter;
		}
			if(alpha>2 && (dot-alpha)>3){
			printf("e-mail Verified..\n");
			    
				return ptrEmail;
			}
		  
			else{
					printf("Invalid E-mail\n");
					printf("\t\t\nEnter your e-mail id : ");
					scanf("%s",&email);	
		}}while(alpha<2 && (dot-alpha)<3);
}

