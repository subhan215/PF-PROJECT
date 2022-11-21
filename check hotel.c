#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <time.h>
bool password_verify(char *password);
char* vemail();
int signUpFunc() ; 
int logInFunc() ; 
int main()
{    
    logInFunc() ; 
    return 0 ; 
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
void homeFunc(int *choice) {
      FILE * homePtr ;
	  printf("What do you want to see: \n1: Hotels\n2: Restaurants\n") ;
	  int ans ;  
	  scanf("%d" , &ans) ; 
	  if(ans == 1) {
	  	homePtr = fopen("home page hotels.txt" , "r") ; 
	  }  else {
	  	homePtr = fopen("home page.txt" , "r") ; 
	  }
      char line[50]; 
			  while(fgets(line, sizeof line, homePtr) != NULL){
	        		 printf("%s" , line) ; 
			
			}
	fclose(homePtr) ;
	*choice = ans ;
}  

void encrypted_pass(char password[]){
	int counter;
	for(counter = 0; (counter < 100 && password[counter] != '\0'); counter++){
        password[counter] = password[counter] + 3;
	}
}

void decrypted_pass(char password[]){
	int passCounter;
	for(passCounter = 0; (passCounter < 100 && password[passCounter] != '\0'); passCounter++){
        password[passCounter] = password[passCounter] - 3;
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
void readingDetails(int *counter ,  FILE* filePtr , char *role) {
	system("cls") ; 
	 char line[50] ; 
	 int i = 0 ; 
	 while (fgets(line, sizeof line, filePtr) != NULL) 
    {
	if(i == 0) {
		decrypted_pass(line) ; 
		printf("Password : %s" , line) ; 
		
		i++ ; 
	} else if(i == 1) {
		    *role = line[0] ; 
			printf("\nRole : %s" , line) ;
			i++ ;  
	} else if(i == 2) {
			printf("Email : %s" , line) ;
			i++ ;  
	} else if(i ==3 ) {
			printf("User Name : %s" , line) ;
			i++ ;  
	} else {
		printf("%s" , line) ; 
		i++ ; 
	}
	}
	*counter = i  ; 
}
void readingCustomer(int *counter , FILE *filePtr , char *role) {
	system("cls") ; 
		 char line[50] ; 
	 int i = 0 ; 
	 while (fgets(line, sizeof line, filePtr) != NULL) 
    {
	if(i == 0) {
		decrypted_pass(line) ; 
		printf("Password : %s" , line) ; 
		
		i++ ; 
	} else if(i == 1) {
		    *role = line[0] ; 
			printf("\nRole : %s" , line) ;
			i++ ;  
	} else if(i == 2) {
			printf("Email : %s" , line) ;
			i++ ;  
	} else if(i ==3 ) {
			printf("User Name : %s" , line) ;
			i++ ;  
	} else if(i ==4) {
		printf("Previous Hotel Booking Details: %s" , line) ; 
		i++ ; 
	} else {
		printf("%s\t" , line) ; 
		i++ ; 
	}
	}
	*counter = i  ; 
}
typedef struct {
	int noOfRooms  , cost , disc , disc_type , noOfDays , discount , discount_cost , free , paid_Chosen , num_paid, paid_Charge ; 
	char paid_Fac[50] , free_Fac[50]  ; 
}roomDetails;
typedef struct {
	char name[50] , location[50] , description[200] , free_Fac[50] , paid_Fac[50] ; 
	int hotel_Fac , paid_Fac_Charge , single , _double , triple , noOfPaidFac , noOfRooms ;  
}hotelDetails;
typedef struct {
	int noOfRooms  , noOfDays; 
	char hotelEmail[50] , paymentMethod[20]  , cardNo[20] , nameOnCard[20] , expireDate[50] , cvv[5];
	int singleBedRooms,doubleBedRooms, tripleBedRooms; 
	float singleBedRoomsCost , doubleBedRoomsCost , tripleBedRoomsCost , totalCost ; 
}hotelBookDetails;
int profile(char filePath[]) {
	char role ; 
	FILE *filePtr = fopen(filePath , "r")  , *homeHotelPtr , *homeResPtr;
	int counter = 0 ;  
	system("cls") ; 
    readingDetails(&counter , filePtr , &role) ;
    fclose(filePtr) ; 
	char menuAns, line[50] ; 
	if(counter == 4 && role == 'r') {
		printf("\nYou have not entered your restautant details: ") ; 
		printf("\nEnter it (Y or y/N or n): ") ;
	 	fflush(stdin) ; 
	 	scanf("%c" , &menuAns) ;
	 	menuAns = menuAns < 91 ? menuAns + 26 : menuAns ;  
	 		 if(menuAns == 'y') {
	 		filePtr = fopen(filePath , "a") ; 
	 		homeResPtr = fopen("home page.txt" , "a") ; 
		 	int typeCounter , dishesCounter;
		 	char name[50]; 
		 	printf("Enter your restaurant name: ") ; 
		 	fflush(stdin) ; 
		 	gets(name) ; 
		 	printf("Enter how many types of dishes are there in your restaurant: ") ; 
		 	scanf("%d" , &typeCounter) ; 
		 	printf("Enter how many dishes in each type: ") ; 
		 	scanf("%d" , &dishesCounter) ; 
		 	char restaurantMenu[typeCounter][dishesCounter + 1][50];
	        int restaurantMenuPrice[typeCounter][dishesCounter + 1] , i , j ; 
		     for(i = 0 ; i < typeCounter  ; i++)  {
		      	printf("Enter Dish type %d: " , i + 1) ; 
		      	fflush(stdin) ; 
		      	gets(restaurantMenu[i][0]) ; 
				  for( j = 1 ; j <= dishesCounter  ; j++){
				  	printf("Enter Dish %d Name : " , j) ;
				  	fflush(stdin) ; 
					gets(restaurantMenu[i][j]) ;
					fflush(stdin) ;  
					printf("Enter dish price: ") ; 
					scanf("%d" , &restaurantMenuPrice[i][j]) ; 
				  }  
			} 
			fprintf(filePtr, "%s", name) ; 
			fprintf(homeResPtr, "%s", name) ; 
			fprintf(filePtr , "\nYour Restaurant Menu: ") ; 
			fprintf(homeResPtr , "\nYour Restaurant Menu: ") ; 
			  for(i = 0 ;  i < typeCounter ; i++) {
			  	for(j = 0 ; j < dishesCounter + 1 ; j++) {
			  		if(j == 0 ) {
			  			fprintf(filePtr , "\n%d: Dish Type : %s" , i+1,  restaurantMenu[i][j]) ; 
			  			fprintf(homeResPtr , "\n%d: Dish Type : %s" , i+1,  restaurantMenu[i][j]) ; 
					  }
					else {
						fprintf(filePtr , "\n%d: %s" , j, restaurantMenu[i][j]) ; 
						fprintf(homeResPtr , "\n%d: %s" , j, restaurantMenu[i][j]) ; 
						
					}  
				  }
			  }
			    for(i = 0 ;  i < typeCounter ; i++) {
			  	for(j = 0 ; j < dishesCounter + 1 ; j++) {
			  		if(j == 0 ) {
			  			fprintf(filePtr , "\n%d: Dish Type : %s" ,i+1 ,  restaurantMenu[i][j]) ; 
			  			fprintf(homeResPtr , "\n%d: Dish Type : %s" ,i+1 ,  restaurantMenu[i][j]) ; 
					  }
					else {
						fprintf(filePtr , "\n%d: %d" , j, restaurantMenuPrice[i][j]) ; 
						fprintf(homeResPtr , "\n%d: %d" , j, restaurantMenuPrice[i][j]) ; 
					}  
				  }
			  } 
			  fclose(filePtr) ;
			  fclose(homeResPtr) ; 
			  counter = 0 ; 
			  system("cls") ; 
			  filePtr = fopen(filePath, "r") ; 
			  readingDetails(&counter , filePtr , &role) ;
			  fclose(filePtr) ;  
			  } 
			  else {
			  	printf("As your wish! ") ; 
			  }
	}
	
	else if(counter==4 && role=='h'){
		int choice,choose,i, j ,k,l,chosen;
		hotelDetails hotel ; 
		printf("Do you want to add details of your Hotel ? \n1.Yes\n2.No\n") ;
		scanf("%d",&choice);
		if(choice==1){
			filePtr = fopen(filePath , "a") ; 
			homeHotelPtr = fopen("home page hotels.txt" , "a") ; 
			printf("--->Hotel Details<---\n");
			printf("Enter The name of your hotel : ");
			fflush(stdin);
			gets(hotel.name);
			fprintf(filePtr , "\n%s" , hotel.name) ; 
			fprintf(homeHotelPtr , "\n%s" , hotel.name) ; 
			printf("Enter the location of your Hotel : ");
			fflush(stdin);
			gets(hotel.location);
			fprintf(filePtr , "\n%s" , hotel.location) ; 
			fprintf(homeHotelPtr , "\n%s" , hotel.location) ; 
			printf("--->Hotel Facilities<---\n");
			printf("\nHow many free facilities are there in your hotel : ");
					scanf("%d",&hotel.hotel_Fac);
					if(hotel.hotel_Fac>0)
					{
					printf("Enter all free facilities : \n");
					fprintf(filePtr , "\nHotel Free Facilities: ") ; 
					fprintf(homeHotelPtr , "\nHotel Free Facilities: ") ; 
					for(l=0;l<hotel.hotel_Fac;l++)
					{
						printf("%d. ",l+1);
						fflush(stdin);
						gets(hotel.free_Fac);
						fprintf( filePtr, "\n%d: %s" , l + 1 , hotel.free_Fac) ; 
						fprintf( homeHotelPtr, "\n%d: %s" , l + 1 , hotel.free_Fac) ; 
					}
					}
					printf("Is there any paid facility : \n1.Yes\t2.No\n");
					scanf("%d",&chosen);
					if(chosen==1){
						printf("How many paid facilities are there : ");
						scanf("%d",&hotel.noOfPaidFac);
						printf("Enter all paid facilities : \n");
						fprintf(filePtr , "\nHotel Paid Facilities: ") ;
						fprintf(homeHotelPtr , "\nHotel Paid Facilities: ") ;
						for(i=0;i<hotel.noOfPaidFac;i++){
							printf("%d. ",i+1);
							fflush(stdin);
							gets(hotel.paid_Fac);
							printf("Enter charges of facility #0%d : ",i+1);
							scanf("%d",&hotel.paid_Fac_Charge);
							fprintf(filePtr , "\n%d: %s     %d" , i + 1 , hotel.paid_Fac , hotel.paid_Fac_Charge ) ; 
							fprintf(homeHotelPtr , "\n%d: %s     %d" , i + 1 , hotel.paid_Fac , hotel.paid_Fac_Charge ) ; 
						}
					} 
			printf("Add any description for the users to read when they visit your profile(minimum 50 characters) : ");
			fflush(stdin);
			gets(hotel.description);
			fprintf(filePtr , "\ndescription: %s" , hotel.description) ; 
			fprintf(homeHotelPtr , "\ndescription: %s" , hotel.description) ; 
			printf("Enter Room details of your hotel ?  :\n1.Yes\n2.No\n3.Exit\n");
			scanf("%d",&choose);
			if(choose==1) 
			{
			printf("--->Room Details<---\n");
			fprintf(filePtr , "\n--->Room Details<---") ;
			fprintf(homeHotelPtr , "\n--->Room Details<---") ;
			printf("How many rooms are there in your Hotel? : ");
			scanf("%d",&hotel.noOfRooms);
			fprintf(filePtr , "\nNo Of Rooms : %d" , hotel.noOfRooms) ; 
			fprintf(homeHotelPtr , "\nNo Of Rooms : %d" , hotel.noOfRooms) ; 
			printf("Are there any single-bed rooms :\n1.Yes\n2.No");
			scanf("%d",&hotel.single);
			if(hotel.single==1){
				roomDetails singleBedRooms ; 
				fprintf(filePtr , "\nSingle Bed Rooms: ") ; 
				fprintf(homeHotelPtr , "\nSingle Bed Rooms: ") ; 
				printf("How many single bed rooms are there? : ");
				scanf("%d",&singleBedRooms.noOfRooms);
				fprintf(filePtr , "\nNo Of Rooms: %d" , singleBedRooms.noOfRooms) ; 
				fprintf(homeHotelPtr , "\nNo Of Rooms: %d" , singleBedRooms.noOfRooms) ; 
				printf("Enter the cost of per day in single-bed room : ");
				scanf("%d",&singleBedRooms.cost);
				fprintf(filePtr , "\nPer Night Cost: \n%d" , singleBedRooms.cost) ; 
				fprintf(homeHotelPtr , "\nPer Night Cost: \n%d" , singleBedRooms.cost) ; 
				printf("Is there any special discount for staying longer days in these rooms :\n1.Yes\n2.No");
				scanf("%d",&singleBedRooms.disc);
				if(singleBedRooms.disc==1){
				printf("How many special discount offers are available for customers : ");
				scanf("%d",&singleBedRooms.disc_type);
				for(j=0;j<singleBedRooms.disc_type;j++)
				{
						printf("\nEnter the number of days : ");
						scanf("%d",&singleBedRooms.noOfDays);
						printf("\nEnter the discount without percentage sign : ");
						scanf("%d",&singleBedRooms.discount);
						singleBedRooms.discount_cost=((singleBedRooms.cost)*singleBedRooms.noOfDays*(singleBedRooms.discount)/100);
						printf("%d rupees discount on %d days \n",	singleBedRooms.discount_cost,singleBedRooms.noOfDays);
						fprintf(filePtr,"\n%d rupees discount on %d days \n",	singleBedRooms.discount_cost,singleBedRooms.noOfDays);
					   	fprintf(homeHotelPtr,"\n%d rupees discount on %d days \n",	singleBedRooms.discount_cost,singleBedRooms.noOfDays);	
				}
			}
				printf("--->Room Facilities<---");
				fprintf(filePtr , "\n--->Room Facilities<---");
				fprintf(homeHotelPtr , "\n--->Room Facilities<---");	
				printf("\nHow many free facilities are there in single-bed room ? : ");
					scanf("%d",&singleBedRooms.free);
					if(singleBedRooms.free>0)
					{
					printf("Enter all free facilities : \n");
					fprintf(filePtr , "\nFree Facilities: ") ; 
					fprintf(homeHotelPtr , "\nFree Facilities: ") ; 
					for(l=0;l<singleBedRooms.free;l++)
					{
						printf("%d. ",l+1);
						fflush(stdin);
						gets(singleBedRooms.free_Fac);
						fprintf(filePtr , "\n%d: %s" , l + 1 , singleBedRooms.free_Fac) ; 
						fprintf(homeHotelPtr , "\n%d: %s" , l + 1 , singleBedRooms.free_Fac) ; 

					}
					}
					printf("Is there any paid facility : \n1.Yes\t2.No\n");
					scanf("%d",&singleBedRooms.paid_Chosen);
					if(singleBedRooms.paid_Chosen==1){
							fprintf( filePtr, "\nPaid Facilities: ") ; 
							fprintf( homeHotelPtr, "\nPaid Facilities: ") ; 
						printf("How many paid facilities are there : ");
						scanf("%d",&singleBedRooms.num_paid);
						printf("Enter all paid facilities : \n");
						for(i=0;i<singleBedRooms.num_paid;i++){
							printf("%d. ",i+1);
							fflush(stdin);
							gets(singleBedRooms.paid_Fac);
							printf("Enter charges of facility #0%d : ",i+1);
							scanf("%d",&singleBedRooms.paid_Charge);
							fprintf(filePtr , "\n%d: %s   %d" , i+1 , singleBedRooms.paid_Fac , singleBedRooms.paid_Charge) ; 
							fprintf(homeHotelPtr , "\n%d: %s   %d" , i+1 , singleBedRooms.paid_Fac , singleBedRooms.paid_Charge) ; 
						}
					}	
				}
				printf("Are there any Double-bed rooms :\n1.Yes\n2.No");
				scanf("%d",&hotel._double);
				if(hotel._double==1){
				roomDetails doubleBedRooms ; 
				fprintf(filePtr , "\n Double-Bed Rooms:") ; 
				fprintf(homeHotelPtr , "\n Double-Bed Rooms:") ; 	
				printf("How many double bed rooms are there? : ");
				scanf("%d",&doubleBedRooms.noOfRooms);
				fprintf(filePtr , "\nNo Of Rooms: %d" , doubleBedRooms.noOfRooms) ; 
				fprintf(homeHotelPtr , "\nNo Of Rooms: %d" , doubleBedRooms.noOfRooms) ; 
				printf("Enter the cost of per day in double-bed room : ");
				scanf("%d",&doubleBedRooms.cost);
				fprintf(filePtr , "\nPer Night Cost: \n%d" , doubleBedRooms.cost) ; 
			    fprintf(homeHotelPtr , "\nPer Night Cost: \n%d" , doubleBedRooms.cost) ; 	
				printf("Is there any special discount for staying longer days in these rooms :\n1.Yes\n2.No");
				scanf("%d",&doubleBedRooms.disc);
				if(doubleBedRooms.disc==1){
				printf("How many special discount offers are available for customers : ");
				scanf("%d",&doubleBedRooms.disc_type);
				fprintf(filePtr , "\nDiscount Offers: ") ;
				fprintf(homeHotelPtr , "\nDiscount Offers: ") ;
				for(j=0;j<doubleBedRooms.disc_type;j++)
				{
						printf("\nEnter the number of days : ");
						scanf("%d",&doubleBedRooms.noOfDays);
						printf("\nEnter the discount without percentage sign : ");
						scanf("%d",&doubleBedRooms.discount);
						doubleBedRooms.discount_cost=((doubleBedRooms.cost)*doubleBedRooms.noOfDays*(doubleBedRooms.discount)/100);
						printf("%d rupees discount on %d days \n",doubleBedRooms.discount_cost,doubleBedRooms.noOfDays);
						fprintf(filePtr , "\n%d rupees discount on %d days \n",doubleBedRooms.discount_cost,doubleBedRooms.noOfDays);
					    fprintf( homeHotelPtr , "\n%d rupees discount on %d days \n",doubleBedRooms.discount_cost,doubleBedRooms.noOfDays);		
				}
			}
				printf("--->Room Facilities<---");
				fprintf(filePtr , "\n--->Room Facilities<---");
				fprintf(homeHotelPtr , "\n--->Room Facilities<---");
				printf("\nHow many free facilities are there in Double-bed room ? : ");
					scanf("%d",&doubleBedRooms.free);
					if(doubleBedRooms.free>0)
					{
					printf("Enter all free facilities : \n");
					fprintf( filePtr, "\nFree facilities :");
					fprintf( homeHotelPtr, "\nFree facilities :");
					for(l=0;l<doubleBedRooms.free;l++)
					{
						printf("%d. ",l+1);
						fflush(stdin);
						gets(doubleBedRooms.free_Fac);
						fprintf( filePtr, "\n%d: %s" , l + 1 , doubleBedRooms.free_Fac);
					    fprintf( homeHotelPtr, "\n%d: %s" , l + 1 , doubleBedRooms.free_Fac);
					}
					}
					printf("Is there any paid facility in Double-bed room? : \n1.Yes\t2.No\n");
					scanf("%d",&doubleBedRooms.paid_Chosen);
			
					if(doubleBedRooms.paid_Chosen==1){
						fprintf(filePtr , "\nPaid Facilities: ") ; 
						fprintf(homeHotelPtr , "\nPaid Facilities: ") ; 
						printf("How many paid facilities are there : ");
						scanf("%d",&doubleBedRooms.num_paid);
						printf("Enter all paid facilities : \n");
						for(i=0;i<doubleBedRooms.num_paid;i++){
							printf("%d. ",i+1);
							fflush(stdin);
							gets(doubleBedRooms.paid_Fac);
							printf("Enter charges of facility #0%d : ",i+1);
							scanf("%d",&doubleBedRooms.paid_Charge);
							fprintf(filePtr , "\n%d: %s      %d" , i+1  , doubleBedRooms.paid_Fac , doubleBedRooms.paid_Charge) ;
							fprintf(homeHotelPtr , "\n%d: %s      %d" , i+1  , doubleBedRooms.paid_Fac , doubleBedRooms.paid_Charge) ;  
						}
					}
				}
				printf("Are there any Triple-bed rooms :\n1.Yes\n2.No");
				scanf("%d",&hotel.triple);
				if(hotel.triple==1){
					fprintf(filePtr , "\nTriple Bed Rooms: ") ; 
					fprintf(homeHotelPtr , "\nTriple Bed Rooms: ") ; 
				roomDetails tripleBedRooms ; 
				printf("How many Triple bed rooms are there? : ");
				scanf("%d",&tripleBedRooms.noOfRooms);
				fprintf(filePtr , "\nNo Of Rooms: %d", tripleBedRooms.noOfRooms) ; 
				fprintf(homeHotelPtr , "\nNo Of Rooms: %d", tripleBedRooms.noOfRooms) ; 
				printf("Enter the cost of per day in Triple-bed room : ");
				scanf("%d",&tripleBedRooms.cost);
				fprintf(filePtr , "\nPer Night Cost: %d", tripleBedRooms.cost) ;
				fprintf(homeHotelPtr , "\nPer Night Cost: %d", tripleBedRooms.cost) ;  
				printf("Is there any special discount for staying longer days in these rooms :\n1.Yes\n2.No");
				scanf("%d",&tripleBedRooms.disc); 
				if(tripleBedRooms.disc==1){
				printf("How many special discount offers are available for customers : ");
				scanf("%d",&tripleBedRooms.disc_type);
				fprintf(filePtr , "\nDiscount Offers: ") ;
				fprintf(homeHotelPtr , "\nDiscount Offers: ") ;  
				for(j=0;j<tripleBedRooms.disc_type;j++)
				{
						printf("\nEnter the number of days : ");
						scanf("%d",&tripleBedRooms.noOfDays);
						printf("\nEnter the discount without percentage sign : ");
						scanf("%d",&tripleBedRooms.discount);
						tripleBedRooms.discount_cost=((tripleBedRooms.cost)*tripleBedRooms.noOfDays*(tripleBedRooms.discount)/100);
						printf("%d rupees discount on %d days \n",tripleBedRooms.discount_cost,tripleBedRooms.noOfDays);
				        fprintf(filePtr , "\n%d rupees discount on %d days \n",tripleBedRooms.discount_cost,tripleBedRooms.noOfDays);
				        fprintf(homeHotelPtr , "\n%d rupees discount on %d days \n",tripleBedRooms.discount_cost,tripleBedRooms.noOfDays);
				}
			}
				printf("--->Room Facilities<---");
				fprintf(filePtr , "\n--->Room Facilities<---");
				fprintf(homeHotelPtr , "\n--->Room Facilities<---");
				printf("\nHow many free facilities are there in triple-bed room ? : ");
					scanf("%d",&tripleBedRooms.free);
					if(tripleBedRooms.free>0)
					{
					printf("Enter all free facilities : \n");
					fprintf( filePtr , "\nFree Facilities: ") ; 
					fprintf( homeHotelPtr , "\nFree Facilities: ") ; 
					for(l=0;l<tripleBedRooms.free;l++)
					{
						printf("%d. ",l+1);
						fflush(stdin);
						gets(tripleBedRooms.free_Fac);
						fprintf(filePtr , "\n%d: %s" , l + 1  , tripleBedRooms.free_Fac) ; 
                        fprintf(homeHotelPtr , "\n%d: %s" , l + 1  , tripleBedRooms.free_Fac) ; 					
					}
					}
					printf("Is there any paid facility : \n1.Yes\t2.No\n");
					scanf("%d",&tripleBedRooms.paid_Chosen);
					if(tripleBedRooms.paid_Chosen==1)
					{
						printf("How many paid facilities are there : ");
						scanf("%d",&tripleBedRooms.num_paid);
						printf("Enter all paid facilities : \n");
						fprintf(filePtr , "\nPaid Facilities: ") ; 
						fprintf(homeHotelPtr , "\nPaid Facilities: ") ; 
						for(i=0;i<tripleBedRooms.num_paid;i++)
						{
							printf("%d. ",i+1);
							fflush(stdin);
							gets(tripleBedRooms.paid_Fac);
							printf("Enter charges of facility #0%d : ",i+1);
							scanf("%d",&tripleBedRooms.paid_Charge);
							fprintf(filePtr , "\n%d: %s         %d" , i + 1 , tripleBedRooms.paid_Fac , tripleBedRooms.paid_Charge) ; 
							fprintf(homeHotelPtr , "\n%d: %s         %d" , i + 1 , tripleBedRooms.paid_Fac , tripleBedRooms.paid_Charge) ; 
						}
					}
}}
                fclose(filePtr) ; 
                fclose(homeHotelPtr) ; 
  				counter = 0 ; 
			  	system("cls") ; 
			  	filePtr = fopen(filePath, "r") ; 
			  	readingDetails(&counter , filePtr , &role) ; 
				fclose(filePtr) ; 
				   }		
			   } else if(counter == 4 && role == 'c' ){
			          int choice ;  
			         homeFunc(&choice) ; 
			         char hotelName[50] ; 
			         if(choice == 1) {
			         	hotelBookDetails hotelBooking ; 
			         	printf("\nEnter hotel email which you want to book: ") ; 
			         	fflush(stdin) ; 
			         	gets(hotelBooking.hotelEmail) ;
						strcat(hotelBooking.hotelEmail , ".txt") ;  
						filePtr = fopen(hotelBooking.hotelEmail , "r") ; 
						if(filePtr == NULL) {
							printf("\nPlease enter correct email: ") ; 
						} else {
							//system("cls") ;
							counter= 0 ; 
							while(fgets(line , sizeof line , filePtr )!=NULL) { 
								if(counter == 5 ) {
									printf("%s" , line) ; 
									strcpy(hotelName , line) ; 
								}
								counter++ ; 
							}
							printf("\nEnter how many rooms do you want to book: ") ;
						    scanf("%d" , &hotelBooking.noOfRooms) ;
							printf("\nEnter single bed rooms: ") ; 
							scanf("%d" , &hotelBooking.singleBedRooms) ; 
							if(hotelBooking.noOfRooms - hotelBooking.singleBedRooms > 0) {
								printf("\nEnter how many double bed rooms: ") ; 
								scanf("%d" , &hotelBooking.doubleBedRooms) ; 
								
						}
						if(hotelBooking.noOfRooms - hotelBooking.singleBedRooms - hotelBooking.doubleBedRooms > 0) {
							      	printf("\nEnter how many triple bed rooms: ") ; 
								    scanf("%d" , &hotelBooking.tripleBedRooms) ; 
							} 
						printf("\nFor how many days you want to book these rooms: ") ; 
						scanf("%d" , &hotelBooking.noOfDays) ; 
						int bedRoomMatch = 0  , counter = 0 , priceCounter = 0 , matchTime = 0 , i = 0  ;
						float bedRoomPrice  ;  
						fclose(filePtr) ; 
						filePtr = fopen(hotelBooking.hotelEmail , "r") ; 
						while(fgets(line , sizeof line , filePtr) != NULL) {
							char costMatch[15] ; 
							for(i = 0 ; i < 15 ; i++) {
								costMatch[i] = line[i] ; 
							}
							if(strcmp(costMatch , "Per Night Cost:") == 0) {
								bedRoomMatch = counter ; 
								break ; 
							}
							counter ++ ; 
						}
						fclose(filePtr) ; 
						filePtr = fopen(hotelBooking.hotelEmail , "r") ; 
							while(fgets(line , sizeof line , filePtr) != NULL) {
							    if(priceCounter == bedRoomMatch + 1) {
							    	bedRoomPrice =  ((float)(line[0] - '0')*100) + ((float)(line[1] - '0')*10) + (float)(line[2] - '0') ;   
								}
								priceCounter++ ; 
							}
							hotelBooking.singleBedRoomsCost = hotelBooking.singleBedRooms * bedRoomPrice * hotelBooking.noOfDays ; 
							counter = 0  , priceCounter = 0  , bedRoomMatch = 0 , bedRoomPrice  = 0;   
							if(hotelBooking.doubleBedRooms > 0) {
								fclose(filePtr) ; 
						        filePtr = fopen(hotelBooking.hotelEmail , "r") ;
								while(fgets(line , sizeof line , filePtr) != NULL) {
							char costMatch[15] ; 
							for(i = 0 ; i < 15 ; i++) {
								costMatch[i] = line[i] ; 
							}
							if(strcmp(costMatch , "Per Night Cost:") == 0) {
								matchTime++ ; 
								if(matchTime == 2) {
										bedRoomMatch = counter ; 
								        break ; 
								}
							
							}
							counter ++ ; 
						}
						fclose(filePtr) ; 
						filePtr = fopen(hotelBooking.hotelEmail , "r") ;
						while(fgets(line , sizeof line , filePtr) != NULL) {
							    if(priceCounter == counter + 1) {
							    	bedRoomPrice =  ((int)(line[0] - '0')*100) + ((int)(line[1] - '0')*10) + (int)(line[2] - '0') ;   
								}
								priceCounter++ ; 
							}
						hotelBooking.doubleBedRoomsCost = hotelBooking.doubleBedRooms * bedRoomPrice * hotelBooking.noOfDays ; 
							}
							
					    if(hotelBooking.tripleBedRooms > 0){
					    	bedRoomMatch = 0 , counter = 0 , priceCounter = 0 , matchTime = 0 , bedRoomPrice = 0  ; 
					    	fclose(filePtr) ; 
						    filePtr = fopen(hotelBooking.hotelEmail , "r") ;
					    	while(fgets(line , sizeof line , filePtr) != NULL) {
							char costMatch[15] ; 
							for(i = 0 ; i < 15 ; i++) {
								costMatch[i] = line[i] ; 
							}
							if(strcmp(costMatch , "Per Night Cost:") == 0) {
								matchTime++ ; 
								if(matchTime == 3) {
										bedRoomMatch = counter ; 
								        break ; 
								}
							
							}
							counter ++ ; 
						}
						fclose(filePtr) ; 
						filePtr = fopen(hotelBooking.hotelEmail , "r") ;
						while(fgets(line , sizeof line , filePtr) != NULL) {
							    if(priceCounter == counter + 1) {
							    	bedRoomPrice =  ((int)(line[0] - '0')*100) + ((int)(line[1] - '0')*10) + (int)(line[2] - '0') ;   
								}
								priceCounter++ ; 
							}
						hotelBooking.tripleBedRoomsCost = hotelBooking.tripleBedRooms * bedRoomPrice * hotelBooking.noOfDays ; 
						}		 
					 }
			           fclose(filePtr) ; 
			           printf("\nYour Selected Details: ") ; 
			           printf("\nNo Of Rooms: %d" , hotelBooking.noOfRooms) ; 
			           printf("\nNo Of Days: %d" , hotelBooking.noOfDays) ; 
			           if(hotelBooking.singleBedRooms > 0) {
			           	printf("\nNo Of Single Bed Rooms: %d" , hotelBooking.singleBedRooms) ; 
			           	printf("\nSingle Bed Rooms Cost: %.2f" , hotelBooking.singleBedRoomsCost) ; 
					   }
					    if(hotelBooking.doubleBedRooms > 0) {
			           	printf("\nNo Of Double Bed Rooms: %d" , hotelBooking.doubleBedRooms) ; 
			           	printf("\nDouble Bed Rooms Cost: %.2f" , hotelBooking.doubleBedRoomsCost) ; 
					   }
					    if(hotelBooking.tripleBedRooms > 0) {
			           	printf("\nNo Of Triple Bed Rooms: %d" , hotelBooking.tripleBedRooms) ; 
			           	printf("\nTriple Bed Rooms Cost: %.2f" , hotelBooking.tripleBedRoomsCost) ; 
					   }
					   hotelBooking.totalCost = hotelBooking.singleBedRoomsCost + hotelBooking.doubleBedRoomsCost + hotelBooking.tripleBedRoomsCost ; 
					   printf("\nTotal Cost: %.2f" , hotelBooking.totalCost) ;
					   printf("\nProceed to Payment Method (yes or no): ") ;
					   char paymentMethodChoice[50] ; 
					   fflush(stdin) ; 
					   gets(paymentMethodChoice) ; 
					   if(strcmp(paymentMethodChoice , "yes") == 0) {
					   	    system("cls") ; 
					   	    printf("\nWhat payment method will you prefer(cash or card): ") ;
							fflush(stdin) ;  
					   	    gets(hotelBooking.paymentMethod) ; 
					   	     time_t t = time(NULL);
                            struct tm tm = *localtime(&t);
					   	    filePtr = fopen(filePath , "a") ; 
					   	    fprintf(filePtr , "\nHotel Booking Details: ") ; 
					   	    fprintf(filePtr , "\n%s" , hotelName) ; 
					   	    fprintf(filePtr , "\n%d" , hotelBooking.noOfDays) ; 
					   	    fprintf(filePtr , "\n%d" , hotelBooking.noOfRooms) ;
					   	     if(hotelBooking.singleBedRooms > 0) {
			           	      fprintf(filePtr , "\n%d" , hotelBooking.singleBedRooms) ;    
			           	      	fprintf(filePtr , "\n%.0f" , hotelBooking.singleBedRoomsCost) ;
					   }
					    if(hotelBooking.doubleBedRooms > 0) {
			           		fprintf(filePtr , "\n%d" , hotelBooking.doubleBedRooms) ;
			           			fprintf(filePtr , "\n%.0f" , hotelBooking.doubleBedRoomsCost) ;
					   }
					    if(hotelBooking.tripleBedRooms > 0) {
			           		fprintf(filePtr , "\n%d" , hotelBooking.tripleBedRooms) ;
			           			fprintf(filePtr , "\n%.0f" , hotelBooking.tripleBedRoomsCost) ;
					   }
							fprintf(filePtr , "\n%.0f" , hotelBooking.totalCost) ;  
							fprintf(filePtr , "\n%d-%02d-%02d" , tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900) ;        
							fprintf(filePtr , "\n%s" , hotelBooking.paymentMethod) ;
					   	    if(strcmp(hotelBooking.paymentMethod , "card") == 0) {
					   	             printf("\nCard Details: ") ;
					   	             printf("\nCard No: ") ;
									fflush(stdin) ;  
					   	             gets(hotelBooking.cardNo) ; 
					   	             printf("Name on Card: ") ;
									fflush(stdin) ;  
					   	             gets(hotelBooking.nameOnCard) ; 
					   	             printf("expire Date (Format should be like Day/Month/Year)") ; 
					   	             fflush(stdin) ; 
									gets(hotelBooking.expireDate) ; 
					   	             printf("Enter card cvv: ") ;
										fflush(stdin) ;  
					   	             gets(hotelBooking.cvv) ; 
					   	             fprintf(filePtr , "\n%s" , hotelBooking.cardNo) ; 
					   	             fprintf(filePtr , "\n%s" , hotelBooking.nameOnCard) ; 
					   	             fprintf(filePtr , "\n%s" , hotelBooking.expireDate) ; 
					   	             fprintf(filePtr , "\n%s" , hotelBooking.cvv) ; 
							   }
							   fclose(filePtr) ; 
					   }  
			   }
			  filePtr = fopen(filePath, "r") ; 
			  readingDetails(&counter , filePtr , &role) ;
			  fclose(filePtr) ;  
} 
}
int signUpFunc() {
	char role;
	char Name[20],email[30] = {0};
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
	printf("\nconfirm your password:");
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
	FILE *resFPtr ; 
	counter = 0 ;

	strcpy(filePath , email) ;  
	strcat(filePath , ".txt"); 
		fPtr = fopen(filePath , "a") ;	  
		fprintf(fPtr , "%s\n" , password); 
		fprintf(fPtr , "%c\n" , role) ; 
		fprintf(fPtr , "%s\n" , email);  
		fprintf(fPtr , "%s\n" , Name); 
    fclose(fPtr) ;
    resFPtr = fopen("restaurantAccounts.txt" , "a") ; 
    if(role == 'r') {
    	fprintf(resFPtr , "\n%s" , filePath) ; 
	}
	fclose(resFPtr) ; 
    
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
	char email[50] = {0} ; 
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
		hide_pass(password);
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
	FILE *fPtr ; 
	int counter,alpha=0,dot=0;
		printf("\t\t\nEnter your e-mail id : ");
		fflush(stdin) ; 
		gets(email);
		char filePath[50] ;
	   strcpy(filePath , email) ;  
	   strcat(filePath , ".txt");
	   fPtr = fopen(filePath , "r") ;  
	   if(fPtr != NULL) {
		printf("Your account already exists") ; 
		vemail() ; 
	}  else {
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

}


