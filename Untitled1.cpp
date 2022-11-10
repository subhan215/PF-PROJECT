#include <stdio.h>
int main() {
	char id[10] ; 
	printf("Enter the id: ") ; 
	scanf("%s" , &id) ;
	int varCharges ; 
	printf("Enter ticket Charges: ") ; 
	scanf("%d" , &varCharges) ;  
	int noOfCities = int(id[7] - '0') + 2 ; 
	int noOfBuses = int(id[6] - '0') * 10 + int(id[7] - '0') ; 
	int noOfTickets = int(id[5] - '0') * 100 + int(id[6] - '0') * 10 + int(id[7] - '0') ; 
	int length = noOfCities * noOfBuses * noOfTickets ; 
	int allData[length][5] ;
	int busesInc = 0 , ticketsInc = 0 , citiesInc = 0 ; 
	int age  , discountC = 0 , discountE = 0 , discount = 0;  
	for(int i = 0 ; i < length ; i++) {
		printf("City : %d , Bus : %d , Passenger : %d\n" , citiesInc + 1  , busesInc + 1 , ticketsInc + 1) ; 
		printf("Enter your age : ") ; 
		scanf("%d" , &age) ; 
		allData[i][0] = citiesInc + 1 ; 
		allData[i][1]= busesInc + 1 ; 
		allData[i][2] = ticketsInc + 1 ; 
		allData[i][3] = age ; 
		allData[i][4] = (age < 6 ? varCharges * 0.5 : age > 60 ? varCharges * 0.7 : varCharges) ; 
		discount = discount + (age < 6 ? varCharges * 0.5 : age > 60 ? varCharges * 0.3 : 0 ) ; 
		discountC = discountC + (age < 6 ? varCharges * 0.5 : 0) ; 
		discountE = discountE + (age > 60 ? varCharges * 0.3 : 0) ; 
		ticketsInc++ ; 
		if(ticketsInc  == noOfTickets) {
		      busesInc++ ; 
		      ticketsInc = 0 ; 
		}
		if(busesInc == noOfBuses) {
			citiesInc ++ ; 
			busesInc  = 0 ;
		}
	}
	for(int i = 0 ; i < length ; i++) {
		for(int j = 0  ; j < 5 ; j++) {
			printf("%d\t" , allData[i][j]) ; 
		}
		printf("\n") ; 
	}
	int totalSales[noOfBuses * noOfCities][3] ; 
	busesInc = 0 ; ticketsInc = 0 ; citiesInc = 0  ;
     int eachBusSales = 0; 
	for(int i = 0 ; i < noOfBuses * noOfCities ; i++) {
		for(int j = 0 ; j < length ; j++) {
			if(allData[j][0] == citiesInc + 1 && allData[j][1] == busesInc + 1) {
				eachBusSales = eachBusSales + allData[j][4] ; 
			}
		}
		totalSales[i][0] = citiesInc + 1 ; 
		totalSales[i][1] = busesInc + 1 ; 
	    totalSales[i][2] = eachBusSales ; 
	    eachBusSales = 0 ; 
	    busesInc++ ; 
	    if(busesInc == noOfBuses) {
	    	citiesInc++ ; 
	    	busesInc = 0 ; 
		}
	}
	printf("Total Sales : \n") ; 
	for(int i = 0 ; i < noOfBuses * noOfCities ; i++) {
		for(int j = 0  ; j < 3 ; j++) {
			printf("%d\t" , totalSales[i][j]) ; 
		}
		printf("\n") ; 
	}
	printf("Total Discount : %d\n" , discount) ; 
	printf("Discount For Childrens : %d\n" , discountC) ; 
	printf("Discount For Elders : %d\n" , discountE) ; 
	return 0 ; 
	
}
