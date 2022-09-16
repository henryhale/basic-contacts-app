#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Display width - max characters 
#define width 60

// Maximum number of characters
#define no_of_contacts 10

// Contact Interface
struct Contact {
	int id = NULL;
	char name[255];
	char telno[255];
	char email[255];
};

// Initialize contacts list
struct Contact contacts[no_of_contacts];

// Function to display a header with a dynamic title
void printHeader(char* str);

// Function to print user interface menu
int printMenu();

// Function to prompt the user 
void promptContact(char* qn, char* str);

// Function to add new contact to contacts list
int addNewContact(int lastId);

// Fuction to display all contacts
int printContacts();

// APP ENTRY POINT 
int main() {
	
    // titles
	char title_1[] = "Menu";
	char title_2[] = "New Contact Form";
	char title_3[] = "All Contacts";
	
    // track & store the next contact id
	int lastId = 0;
	
    // user's input | choice
	int choice = 0;
	
    // For windows only, set color scheme to green and black
	system("color A");
	
    // Event Loop block - for user actions
	MENU: 
		system("cls");
		choice = printMenu();
		switch(choice) {
			case 1:
				goto NEW;
				break;
			case 2:
				goto INFO;
				break;
			case 3:
				goto EXIT;
				break;
			default: 
				goto MENU;
		}
	
    // New contact form
	NEW: 
		system("cls");
		lastId = addNewContact(lastId);
		goto MENU;
	
    // All contacts
	INFO: 
		system("cls");
		choice = printContacts();
		if(choice == 1) {
			goto MENU;
		}
		goto EXIT;

    // Exit loop block
	EXIT:
		printf("\n\n\tDONE!");

	return 0;
}

// Display header with dynamic title
void printHeader(char* str) {
	int strlength = strlen(str);
	int padding = width - strlength;
	int leftLimit = floor(padding / 2);
	int rightLimit = width - leftLimit;
	int i = 0, j = 0;
	printf("\n\t");
	do {
		if(i >= leftLimit && i < rightLimit) {
			printf("%c",str[j]);
			j++;
		} else {
			printf("%s","-");
		}
		i++;
	} while(i < width);
	printf("\n");
}

// Display menu for  the user
int printMenu() {
	int choice = 0;
	char header[] = "Menu";
	char footer[] = "----";
	printf("\n");
	printHeader(header);
	printf("\n\t1. Add new contact");
	printf("\n\t2. Display all contacts");
	printf("\n\t3. Exit\n");
	printHeader(footer);
	printf("\n\tEnter menu number: ");
	scanf("%d",&choice);
	return choice;
}

// Prompt user for some input
void promptContact(char* qn, char* str) {
	printf("\n\tEnter %s:\n\t> ", qn);
	scanf("%s",&*str);
}

// New contact form
int addNewContact(int lastId) {
	struct Contact newContact;
	char header[] = "Contact Entry Form";
	char name[] = "name";
	char mobile[] = "mobile number";
	char email[] = "email"; 
	printHeader(header);
	promptContact(name, newContact.name);
	promptContact(mobile, newContact.telno);
	promptContact(email, newContact.email);
	newContact.id = lastId;
	contacts[lastId] = newContact;
	lastId++;
	return lastId;
}

// Display all contacts
int printContacts() {
	char header[] = "All Contacts";
	int i = 0;       
	char ans[255];
	printf("\n");
	printHeader(header);
	printf("\n\tNumber of Contacts: %d",no_of_contacts);
	if (no_of_contacts < 1) {
		printf("\n\n\t >> No records available");
	} else {
		printf("\n\n\tID\tNAME\t\tMOBILE\t\t\tEMAIL\n");
		for(i=0;i<no_of_contacts;i++) {
			if(strlen(contacts[i].name) > 0) {		
				printf("\n\t%d\t%s\t\t%s\t\t\t%s",contacts[i].id+1, contacts[i].name, contacts[i].telno, contacts[i].email);
			}
		}	
	}
	printf("\n\n\tPress any key to go back : ");
	scanf("%s",&ans);
	if(ans != NULL) {
		return 1;
	} else {
		return 0;
	}
}
