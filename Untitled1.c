#include <stdio.h>
int main() {
	int isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}
  
// Function to check the character
// is an digit or not
int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
  
// Function to check email id is
// valid or not
int is_valid(char[50] valEmail)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(valEmail[0])) {
  
        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;
  
    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;
         i < email.length(); i++) {
  
        // If the character is '@'
        if (email[i] == '@') {
  
            At = i;
        }
  
        // If character is '.'
        else if (email[i] == '.') {
  
            Dot = i;
        }
    }
  
    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;
  
    // If Dot is present before At
    if (At > Dot)
        return 0;
  
    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}

    // Given string email
    char[50] email ;
    printf("Enter your email: ") ; 
    scanf("%s" , &email) ; 
    // Function Call
    int ans = is_valid(email);
  
    // Print the result
    if (ans) {
        printf("valid : %s"  , email ) ; 
    }
    else {
        printf("invalid : %s"  , email ) ; 
    }
  
	printf("Welcome to Restaurant/Hotel Booking: \n") ;
	printf("What you want to book: \n") ;
	printf("1:Tables in Restaurants\n") ; 
	printf("2:Rooms in hotels\n") ;
	 
	  
}
