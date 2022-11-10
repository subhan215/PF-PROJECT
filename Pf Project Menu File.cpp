#include <stdio.h>
int main() {
     printf("1. Your Restaurant Menu:  ") ; 
     int isData = 0 ; 
     char menuAns ; 
	 if(isData == 0) {
	 	printf("\nYou have not entered your restaurant menu! \n") ; 
	 	printf("Enter it (Y or y/N or n): ") ;
	 	fflush(stdin) ; 
	 	scanf("%c" , &menuAns) ;
	 	menuAns = menuAns < 91 ? menuAns + 26 : menuAns ;  
		 if(menuAns == 'y') {
		 	int typeCounter , dishesCounter;
		 	printf("Enter how many types of dishes are there in your restaurant: ") ; 
		 	scanf("%d" , &typeCounter) ; 
		 	printf("Enter how many dishes in each type: ") ; 
		 	scanf("%d" , &dishesCounter) ; 
		 	char restaurantMenu[typeCounter][dishesCounter + 1][50];
	        int restaurantMenuPrice[typeCounter][dishesCounter + 1]; 
		     for(int i = 0 ; i < typeCounter  ; i++)  {
		      	printf("Enter Dish type %d: " , i + 1) ; 
		      	fflush(stdin) ; 
		      	scanf("%s" , &restaurantMenu[i][0]) ;
				  for(int j = 1 ; j <= dishesCounter  ; j++){
				  	printf("Enter Dish %d Name : " , j) ;
				  	fflush(stdin) ; 
					scanf( "%s", &restaurantMenu[i][j]) ; 
					printf("Enter dish price: ") ; 
					scanf("%d" , &restaurantMenuPrice[i][j]) ; 
				  	
				  }  
		      	
			  } 
			  printf("Your Restaurant Menu: \n") ; 
	 	   for(int i = 0 ; i < typeCounter ; i++) {
	 	   	printf("%s\n" , restaurantMenu[i][0]) ; 
	 	   	for(int j = 1 ; j <= dishesCounter ; j++) {
	 	   		printf("%s \t" , restaurantMenu[i][j]) ;
			    printf("%d \n" , restaurantMenuPrice[i][j]) ; 		 
				}
				printf("\n") ; 
			}
		 } 
	 } 
		   return 0 ; 	
	 } 
