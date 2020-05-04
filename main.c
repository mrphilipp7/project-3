#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input();
void load();
void search();
void del();
void printData();


//STRUCTURE that will contain struct information on person
struct personNode {
  int id;
  char lastName[20];
  char firstName[20];
  int age[3];
  struct personNode *next;
};
typedef struct personNode node_t;



int main(void) {
  int choice = 0;
  
  while (choice != 5){
    printf("Select which subset to use \n1: input 20 names\n2: load names\n3: search name\nor 4: delete name\nchoose 5 to exit\n");
    scanf("%d", &choice);

    if (choice == 1){
      input();
    }
    else if (choice == 2){
      load();
    }
    else if (choice == 3){

    }
    else if (choice == 4){
      
    }
    else{
      printf("Not a valid input\n");
      fopen("person.csv", "w");
    }
  }
  return 0;
}


void input(){
  //create file pointer, open file for 'a' appending
  FILE *fptr;
  struct personNode person;
  fptr = fopen("person.csv" , "a");
  fprintf(fptr,"lastName, firstName, age, id");
  //error handling
  if(fptr == NULL){
    printf("ERROR: file cannot be found\n");
    //exit(1);
  }
  else{
    for(int i =0; i<1;i++){
      printf("Enter a last name: ");
      scanf("%13s",lastName);

      printf("Enter a first name: ");
      scanf("%13s",firstName);

      printf("Enter an age: ");
      scanf("%8d",&age);

      printf("Enter their ID: ");
      scanf("%d", &id);

      //fwrite display lastname, firstname, then pointer to age to display contents
      fprintf(fptr, "%s %s %d %d\n", lastName,firstName,*person.age,person.id);
      
    }
    
  }
  fclose(fptr);
  printData();
} 

void load()
{
  //printData();
}











void printData(){
  int read;
  FILE *fptr;
  struct personNode person;
  fptr = fopen("person.csv", "r");
  if (fptr == NULL){
    printf("File could not be opened");
  }
  else{
    while(!feof(fptr)){
      if (person.age > 0){
        printf("\n");
        printf("Last name: ");
        printf("%s\n", person.lastName);
        printf("First name: ");
        printf("%s\n", person.firstName);
        printf("Age: ");
        printf("%d\n", *person.age);
        printf("Id: ");
        printf("%d\n",person.id);
      }
      fscanf(fptr,"%21s%21s%4d%d", person.lastName,person.firstName,person.age,&person.id);
    }
    fclose(fptr);
  }
}
   

//fscanf(fptr,"&21s %21s %d %d", person.lastName,person.firstName,*person.age,person.id);

/*
printf("\n");
      printf("Last name: ");
      printf("%s\n", person.lastName);
      printf("First name: ");
      printf("%s\n", person.firstName);
      printf("Age: ");
      printf("%d\n", *person.age);
      printf("Id: ");
      printf("%d\n",person.id);
*/