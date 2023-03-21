# DIVOC

Divoc is an application which allows us to monitor patients suffering certain infectious disease called divoc.

It is divided in three modules: divoc.c , database.c, with its library database.h, and inout.c, also with its library inout.h.

## divoc.c
This module only contains the main function of the program, which consists in calling some other functions, which are written in inout.c and database.c. It prints the headboard and the menu, the whole interface of the program.
We call the function p_init() which has the responsibility to open a file, or create if it doesn’t exist yet, and pass all the information of the patients written there to our struct aPatients.
By means of the functions stripe() and headline() the int main() prints the headboard, which only appears at the first execution of the program. Then, it displays the menu where the user will choose what option he wants to execute, it is repeated each time that an action is finished until the user confirms that he/she wants to exit the program. 


## inout.c
This module contains the functions used in the database.c. We can say that this is the base of the program. Moreover, we have some other functions such as stripe() or headline() which appear directly in the divoc.c
- **get_string()** is in charge of generating the strings DNI and Name and saving them in the struct of patients. It is called by p_register when the user wants to register a patient and he/she has to enter a valid DNI and Name. The strings must have a required length and until the requirements are correct the function doesn’t copy the word to its parameter my_string, which is saved in the table. It is a void function because it does not return anything.
- **get_integer()** has the purpose of generating a number, which is going to be the date of the patient that the user wants to register. The function is going to ask for the user to enter a date between two years and read it until the date has a valid value, which is bigger than the minimum and lower than the maximum. It is an int function because it returns an integer.
- **get_character()** creates a character that it finally returns, so it is a char function. It is called two times, one when the user has to choose an option in the menu, and the second time when the user is registering a patient, for writing the symptom that he/she has. This function is going to repeat the process until the character is inside the string checkword, that is, until the character is valid.
- **yes_or_no()** asks the user to answer a question with a character in orden to select an option. The answer must be a ‘Y’ or an ‘N’. If the user enters a different letter or a string, the function repeats the same question until having a right answer. Its parameter, which is received by reference, is the string that the program wants to display to the screen.
- **display_patient()** prints to the screen the name, dni, birth date, if the patient has fever(1) or not(0), if the patient has cough(1) or not(0) and if the patient has another symptom that appears with one of these letters “RSDLPX”.
- **verify_DNI()** takes care of the verification of the DNI in the option Register. It controls that the string entered by the user is correct, that is, 8 numbers and one letter. Is an int function because it returns 1,when the DNI is valid, and 0 if it is incorrect.
- **stripe()** is the first inout’s function that appears in the divoc.c. It works for making the headboard with the headline(). It prints the first and the third lines of the headboard by means of the parameter that it receives by reference, the symbol (character) that it has to print, in this case is a ‘-’.
- **headline()** function has the purpose of making the headboard too. It prints the second line of it with the parameters that it receives by reference, the string “DIVOC_” and the symbol (character) ‘-’. 


## database.c
In this module we can find the functions that carry on each menu action, at the same time, as we have explained, these functions are declared using the inout’s functions.
- **p_init():** We have included this function here because it has a fundamental job in our program, here we create the file where we will save all the data of our patients. It is used at the beginning of divoc.c
- **p_register():** The main purpose of this function is to receive and save all the important data of a patient: name, DNI, year of birth and if he/she presents some symptoms such as fever, cough, fatigue, loss of smell, loss of taste or muscle aches. It is used when we select the option ‘R’ (Register a Patient) in the menu
- **p_search():** Its work is based on receiving a DNI and searching if it corresponds to any patients who have been registered, if there is a coincidence it prints his/her corresponding data.
- **p_discharge():** It is used to remove a patient from the array thePatients. It receives a DNI and if it belongs to any of the registered patients, it is removed.
- **p_list():** It receives a year and displays all the patients who have born before 
- **p_mark():** It displays the infected patients, checking his/her symptoms.
- **p_exit():** It confirms and realizes the action of exiting the program, it also passes all the information saved in the array to the file and closes it.
