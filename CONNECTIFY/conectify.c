#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CONTACTS 10

 char password[]="connectify";

struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact newContact[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    system("cls");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    printf("    |                                               CONNECTIFY                                               |\n");
    printf("    |                                       ~~~THE ART OF CONNECTIONS~~~                                     |\n");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    if (numContacts == MAX_CONTACTS) {
        printf("      Cannot add more contacts.\n");
        return;
    }

    else
    {
    printf("     Enter name: ");
    gets(newContact[numContacts].name);

    printf("     Enter phone number: ");
    scanf("%s",&newContact[numContacts].phone);

    printf("     Enter email address: ");
    scanf("%s",&newContact[numContacts].email);

    numContacts+=1;

    printf("     Contact added successfully.\n");
    }

}

void deleteContact()
{
    system("cls");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    printf("    |                                               CONNECTIFY                                               |\n");
    printf("    |                                       ~~~THE ART OF CONNECTIONS~~~                                     |\n");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    if (numContacts == 0) {
        printf("     There are no contacts to delete.\n");
        return;
    }
    else
    {
    printf("     Enter the name of the contact to delete: ");
    char name[50];
    scanf("%s",&name);

    int indexToDelete=-1;
    for (int i = 0; i < numContacts; i++) {
            if(strcmp(name,newContact[i].name)==0)
            {
            indexToDelete = i;
            break;
            }
        }


    if (indexToDelete == -1) {
        printf("    Contact not found.\n");
        return;
    }

    for (int i = indexToDelete; i < numContacts - 1; i++) {
        newContact[i] = newContact[i + 1];
    }

    numContacts--;
    printf("     Contact deleted successfully.\n");
    }
}

void searchContacts()
{
    system("cls");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    printf("    |                                               CONNECTIFY                                               |\n");
    printf("    |                                       ~~~THE ART OF CONNECTIONS~~~                                     |\n");
    printf("     --------------------------------------------------------------------------------------------------------\n");

    int numResults=0;
    if (numContacts == 0) {
        printf("There are no contacts to search.\n");
        return;
    }

    printf("enter your choice:\n 1.search by name \n 2.search by number \n 3.search by email   :");
    int choice;
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("enter the name of the contact to be searched:");
        char name[50];
        scanf("%s",&name);
        for(int i=0;i<numContacts;i++)
        {
            if(strcmp(name,newContact[i].name)==0)
            {
                numResults+=1;
                printf("NAME: %s \n",newContact[i].name);
                printf("NUMBER: %s \n",newContact[i].phone);
                printf("MAIL: %s \n",newContact[i].email);

            }
        }
    }
    else if(choice==2)
    {
        printf("enter the contact-number of the contact to be searched:");
        char num[10];
        scanf("%s",&num);
        for(int i=0;i<numContacts;i++)
        {
            if(strcmp(num,newContact[i].phone)==0)
            {
                numResults+=1;
                printf("NAME: %s \n",newContact[i].name);
                printf("NUMBER: %s \n",newContact[i].phone);
                printf("MAIL: %s \n",newContact[i].email);

            }
        }
    }
    else if(choice==3)
    {
        printf("enter the email of the contact to be searched:");
        char mail[20];
        scanf("%s",&mail);
        for(int i=0;i<numContacts;i++)
        {
            if(strcmp(mail,newContact[i].email)==0)
            {
                numResults+=1;
                printf("NAME: %s \n",newContact[i].name);
                printf("NUMBER: %s \n",newContact[i].phone);
                printf("MAIL: %s \n",newContact[i].email);

            }
        }
    }
    else
    {
        printf("!!!invalid option!!!");
    }



    if (numResults == 0) {
        printf("No results found.\n");
    } else {
        printf("Found %d result(s).\n", numResults);
    }
}
void displayContacts()
{
    system("cls");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    printf("    |                                               CONNECTIFY                                               |\n");
    printf("    |                                       ~~~THE ART OF CONNECTIONS~~~                                     |\n");
    printf("     --------------------------------------------------------------------------------------------------------\n");
     char s[100];
    if (numContacts == 0) {
        printf("There are no contacts to display.\n");
        return;
    }
    else
    {
        for(int i=0;i<numContacts;i++)
        {
            for(int j=i+1;j<numContacts;j++)
            {
                if(strcmp(newContact[i].name,newContact[j].name)>0)
                {
                    strcpy(s,newContact[i].name);
                    strcpy(newContact[i].name,newContact[j].name);
                    strcpy(newContact[j].name,s);
                }

            }
       }
            printf("\n                             | `````````````````````````````````````````````````````` |\n");
        for(int i=0; i<numContacts; i++)
        {
            printf("                                                  NAME    : %s                                  ",newContact[i].name);
            printf(" \n                             |                                                        |\n");
            printf("                                                  NUMBER  : %s                                  ",newContact[i].phone);
            printf(" \n                             |                                                        |\n");
            printf("                                                  MAIL    : %s                                  ",newContact[i].email);
            printf(" \n                             |                                                        |\n");

            printf("                               |--------------------------------------------------------|\n");
        }
            printf("                                   TOTAL NUMBER OF CONTACTS : %d",numContacts);
            printf("\n                             | `````````````````````````````````````````````````````` |\n\n\n");
    }
}







void changePassword()
{
    system("cls");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    printf("    |                                               CONNECTIFY                                               |\n");
    printf("    |                                       ~~~THE ART OF CONNECTIONS~~~                                     |\n");
    printf("     --------------------------------------------------------------------------------------------------------\n");
    int a;
    int bkp;
    char oldpass[20];
    printf("      INCORRECT PASSWORD...!!!!!!!!\n");
    printf("      FORGOT PASSWORD??? \n           1.CHANGE PASSWORD \n           2.EXIT \n");
    scanf("%d",&a);
    if(a==1)
    {
    printf("      ENTER THE BACK UP CODE:");
    scanf("%d",&bkp);
    if(bkp==12345)
    {
       {
           printf("      ENTER THE NEW PASSWORD:");
           scanf("%s",&password);

           printf("     PASSWORD CHANGED SUCCESSFULLY..!!!\n");
           chkpassword();
       }
    }
       else
       {
           printf("      INCORRECT BACKUP CODE...!!!!!!!!\n");
       }
    }
    else
    {
        return 0;
    }

}

int chkpassword()
{
    char pass[20];
       printf("      ENTER THE PASSWORD:");
       scanf("%s",&pass);

       int i,passcnt;

       for(i=0;i<strlen(password);i++)
       {
           if(strlen(pass)==strlen(password))
           {
              if(password[i]==pass[i])
              {
                  passcnt=1;
              }
              else
              {
                  passcnt+=1;
              }

           }
       }
       if (passcnt!=1)
       {
          changePassword();
       }
       else
        {
         return passcnt;
       }



}




int main() {

    system("cls");
       printf("     --------------------------------------------------------------------------------------------------------\n");
       printf("    |                                               CONNECTIFY                                               |\n");
       printf("    |                                       ~~~THE ART OF CONNECTIONS~~~                                     |\n");
       printf("     --------------------------------------------------------------------------------------------------------\n");
       int i,passcnt;
       passcnt=chkpassword();


       if(passcnt==1)
       {
        while (1) {
        printf("                         ``````````````````````````````````````````````````````````\n");
        printf("                         |               1. Add Contact                           |\n");
        printf("                         |               2. Delete Contact                        |\n");
        printf("                         |               3. Search Contacts                       |\n");
        printf("                         |               4. Display Contacts                      |\n");
        printf("                         |               5. Exit                                  |\n");
        printf("                         ``````````````````````````````````````````````````````````\n");
        printf("                         Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContacts();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("\n----------------------!!!!!!!!CONNECTIFY!!!!!!!!---------------------------\n");
                return 0;
           default:
                printf("Invalid choice. Please try again.\n");
            }
           }

       }

else
    {
        printf("     !!!!!!!!!!!!!!INCORRECT PASSWORD!!!!!!!!!!!!!!!!!");
    }
}

