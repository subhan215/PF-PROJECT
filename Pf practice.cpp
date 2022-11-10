#include <stdio.h>
/*int main() {
	int num , sum = 0 , length; 
	printf("Enter Number : ") ; 
	scanf("%d" , &num) ; 
	printf("Enter Length of array") ; 
	scanf("%d" , &length) ; 
	int array[length];
	for(int i = 0 ; i < length ; i++) {
		printf("Element %d: " , i + 1) ; 
		scanf("%d" , &array[i]) ; 
	}
	for(int i = 0 ; i < length ; i++) {
		sum = array[i] ;
		if(sum == num ) {
			printf("Sum found at index %d" , i) ; 
			break ; 
		} else {
			for(int j = i + 1 ; j < length ; j++) {
			    sum += array[j] ; 
				if(sum == num) {
					printf("Sum found between elements %d to %d" , i +1 , j + 1) ; 
					break ;
				} 	
			}
			if(sum == num) {
				break ; 
			}
		}
	}
	if(sum != num) {
		printf("\nNo sub-array found!") ; 
	}
	return 0 ;
} */
/*int main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10} , rotateArr[10] , position , j = 0; 
	printf("Enter at which position you want to rotate the array") ; 
	scanf("%d" , &position) ; 
	for(int i = position   ; i < 10 ; i++ , j++) {
		rotateArr[j] = arr[i] ; 
	}
    for(int i = 0 ; j < 10 ; j++ , i++) {
    	rotateArr[j] = arr[i] ; 
	}
	
	printf("[") ; 
	for(int i = 0 ; i < 10 ; i++) {
		if(i == 0) {
			printf(" %d" , rotateArr[i]) ; 
		} else {
			printf(", %d" , rotateArr[i]) ; 
		}
	
	}
	printf("]") ; 
	return 0 ; 
} */
/*int main() {
	int X, Y ; 
	int companyData[Y + 1 ][X] , mobilePrices[Y][X] , totalBill = 0  ; 
	printf("Enter how many branches your company have? ") ; 
	scanf("%d" , &X) ; 
	printf("Enter how many mobile phones are there in each company") ; 
	scanf("%d" , &Y) ; 
	for(int i = 0 ; i <= Y ; i++) {
	      for(int j = 0 ; j < X ; j++) {
	      	if(i ==0) {
	      		printf("Enter the company branch %d id: " , j + 1 ) ; 
	      		scanf("%d" , companyData[i][j]) ; 
			  }
			  else {
			  	printf("Enter the company branch %d mobile %d price" , j + 1 , i + 1) ; 
			  	scanf("%d" , companyData[i][j]) ; 
			  	printf("Enter the mobile price : ") ; 
			  	scanf("%d" , &mobilePrices[i - 1][j]) ; 
			  }
			  
		  }
	}
	for(int i = 0 ; i < Y ; i++) {
		for(int j = 0 ; j < X ; j++) {
			totalBill += mobilePrices[i][j] ; 
		}
	}
	
	return 0 ; 
} */
/*int main() {
int rows ;
scanf("%d" , &rows) ; 
for(int i = 0 ; i < rows ; i++) {
	for(int j = 0 ; j < i ; j++) {
		printf(" ") ; 
	}
	for(int k = 1 ; k <= rows - i ;  k++) {
		printf("%d" , k) ; 
	}
	printf("\n")  ;
} 
return 0 ; 
}*/
/*int main() {
	int i = 2 , k = 1 ; 
	while(i < 5) {
		for(int j = 1 ; j <= i ; ++j) 
			do{
				printf("i = %d , j = %d , k = %d\n" , i , j , k) ; 
				k++;
			} while(k <2) ;
			i++ ;  
		
	}
}*/
/*int main() {
	char line[100] = "subhan Is Good" ;
	int i = 0  , count = 0 ;  
	while(line[i] != 0) {
		if(i == 0 ) {
			if(line[i] >= 'a' && line[i] <= 'z') {
			line[i] = line[i] - 32 ;
			count++ ; 
			i++ ;  
			continue ; 
		}
		}
		if(line[i] >= 'a' && line[i] <= 'z') {
			count++ ; 
			i++ ;  
		} else if(line[i] == ' '){
			count++ , i++ ; 
			if(line[i] >= 'A' && line[i] <= 'Z') {
				line[i] + line[i] + 32 ; 
				count++ , i++ ;
			}
		}
	}
	puts(line); 
	printf("%d" , count) ; 
	return 0 ; 
}*/

/*int main()
{
    int n, c, k, space = 1;
    
    printf("Enter number of rows\n");
    scanf("%d", &n);
    
    space = n/2 ;
    
    for (k = 1; k <= (n / 2) + 1 ; k++)
    {
    
        for (c = 1; c <= space; c++)
        printf(" ");
        
        space--;
        
        for (c = 1; c <= 2*k-1; c++)
        printf("*");
        
        printf("\n");    
    
    }    
    space = 1;
    
    for (k = 1; k <= n/2 ; k++)
    {
    
        for (c = 1; c <= space; c++)
        printf(" ");
        
        space++;
        
        for (c = 0; c < 2*(n/2-k) + 1; c++)
        printf("*");
        
        printf("\n");    
        
    } 
    
    return 0; 
} */
/*int main() {
	int sales[6][5] = {0} , productSales = 0 , personSales = 0 ; 
	for(int i = 0 ; i < 5 ; i++) {
		for(int j = 0 ; j < 4 ; j++) {
			printf("Enter Sales Person %d Product %d Sales : " , j + 1  , i + 1 ) ; 
			scanf("%d" , &sales[i][j]) ; 
		}
	}
	for(int i = 0 ; i < 5 ; i++) {
		productSales = 0 ; //, personSales = 0; 
		for(int j = 0 ; j < 4 ; j++) {
			productSales = productSales + sales[i][j] ; 
		//	personSales = personSales + sales[j] [i] ; 
		}
		sales[i][4] = productSales ; 
		//sales[5][i] = personSales ; 
	}
	for(int i = 0 ; i < 4 ; i++){
		personSales = 0 ; 
		for(int j = 0 ; j < 5 ; j++) {
			personSales = personSales + sales[j][i] ; 
		}
		sales[5][i] = personSales ;  
	}
	for(int i = 0 ; i < 6 ; i++) {
		for(int j = 0 ; i < 5 ; j++) {
			printf("%d\t" , sales[i][j]); 
		}
		printf("\n") ; 
	}
	return 0 ; 
} */
int main() {
	int sales[6][5] = {0} , productSales = 0 , personSales = 0 ; 
	for(int i = 0 ; i < 5 ; i++) {
		for(int j = 0 ; j < 4 ; j++) {
			printf("Enter Sales Person %d Product %d Sales : " , j + 1  , i + 1 ) ; 
			scanf("%d" , &sales[i][j]) ; 
		}
	}
	for(int i = 0 ; i < 5 ; i++) {
		productSales = 0 ; //, personSales = 0; 
		for(int j = 0 ; j < 4 ; j++) {
			productSales = productSales + sales[i][j] ; 
		//	personSales = personSales + sales[j] [i] ; 
		}
		sales[5][i] = productSales ; 
		//sales[5][i] = personSales ; 
	}
	for(int i = 0 ; i < 6 ; i++){
		personSales = 0 ; 
		for(int j = 0 ; j < 4 ; j++) {
			personSales = personSales + sales[j][i] ; 
		}
		sales[i][4] = personSales ;  
	}
	for(int i = 0 ; i < 6 ; i++) {
		for(int j = 0 ; i < 5 ; j++) {
			printf("%d\t" , sales[i][j]); 
		}
		printf("\n") ; 
	}
	return 0 ; 
} 



