//Samet Köser  150119910

#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct students{// define the struct students
	char name[100];
	char surname[100];
	long int ID;
	struct students* name_next;
	struct students* surname_next;
	struct students* ID_next;
};

struct students* delete_from_name(struct students* root,long int id){//control all the students if any student's ýd is same with wanted ýd deletes the student from name_next linked list
	struct students* iter;
	iter=root;
	if (iter->ID==id){
		printf("The student %s %s	%d deleted from the list!\n",iter->name,iter->surname,iter->ID);
		root=root->name_next;
	}
	else{
		while(iter!=NULL){
			if(iter->name_next->ID==id){
				printf("The student %s %s	%d deleted from the list!\n",iter->name_next->name,iter->name_next->surname,iter->name_next->ID);
				iter->name_next=iter->name_next->name_next;
				break;
			}
			iter=iter->name_next;
		}
	}
	return root;

	
}

struct students* delete_from_surname(struct students* root,long int id){//control all the students if any student's ýd is same with wanted ýd deletes the student from surname_next linked list
	struct students* iter;
	iter=root;
	if (iter->ID==id){
		root=root->surname_next;
	}
	else{
		while(iter!=NULL){
			if(iter->surname_next->ID==id){
				iter->surname_next=iter->surname_next->surname_next;
				break;
			}
			iter=iter->surname_next;
		}
	}
	return root;
	
}

struct students* delete_from_ID(struct students* root,long int id){//control all the students if any student's ýd is same with wanted ýd deletes the student from ýd_next linked list
	struct students* iter;
	iter=root;
	if (iter->ID==id){
		root=root->ID_next;
	}
	else{
		while(iter!=NULL){
			if(iter->ID_next->ID==id){
				iter->ID_next=iter->ID_next->ID_next;
				break;
			}
			iter=iter->ID_next;
		}
	}
	return root;
	
}

struct students* add_by_name(struct students* root,struct students* temp){//add the wanted name surname and number to the name sorted list
	
	int i=0;
	struct students* iter;
	iter=root;
	
	if(root==NULL){// if there is no student in the list add the wanted student
		root=temp;
		root->name_next=NULL;
		return root;
	}

	else{
		for(i = 0; i < strlen(temp->name); i++){//if there are students and the wanted student should be at the first then add it 
			if((int)temp->name[i]==(int)iter->name[i]){
				continue;
			}
			else if((int)temp->name[i]<(int)iter->name[i]){
				temp->name_next=iter;
				
				root=temp;
				return root;
				break;
			}
			else{
				break;
			}

		}
		while(1){//if there are students and the wanted student should be after first place then add it to needed place
			if(iter->name_next==NULL){
				iter->name_next=temp;
				temp->name_next=NULL;
				return root;
				break;
			}
			else{
				for(i = 0; i < strlen(temp->name)+1; i++){
					if((int)temp->name[i]==(int)iter->name_next->name[i]){
						continue;
					}
					else if((int)temp->name[i]<(int)iter->name_next->name[i]){
						temp->name_next=iter->name_next;
						iter->name_next=temp;
						return root;
						break;
						
					}
					else{
						iter=iter->name_next;
						break;
						
					}
					
					
				
				}
			}
			
			
			
		}
	}
}

struct students* add_by_surname(struct students* root,struct students* temp){//add the wanted name surname and number to the surname sorted list
	int i=0;
	struct students* iter;
	iter=root;
	if(root==NULL){// if there is no student in the list add the wanted student
		root=temp;
		root->surname_next=NULL;
		return root;
	}

	else{
		for(i = 0; i < strlen(temp->surname); i++){//if there are students and the wanted student should be at the first then add it 
			if((int)temp->surname[i]==(int)iter->surname[i]){
				continue;
			}
			else if((int)temp->surname[i]<(int)iter->surname[i]){
				temp->surname_next=iter;
				
				root=temp;
				return root;
				break;
			}
			else{
				break;
			}

		}
		while(1){//if there are students and the wanted student should be after first place then add it to needed place
			if(iter->surname_next==NULL){
				iter->surname_next=temp;
				temp->surname_next=NULL;
				return root;
				break;
			}
			else{
				for(i = 0; i < strlen(temp->surname)+1; i++){
					if((int)temp->surname[i]==(int)iter->surname_next->surname[i]){
						continue;
					}
					else if((int)temp->surname[i]<(int)iter->surname_next->surname[i]){
						temp->surname_next=iter->surname_next;
						iter->surname_next=temp;
						return root;
						break;
						
					}
					else{
						iter=iter->surname_next;
						break;
						
					}
					
					
				
				}
			}
			
			
			
		}
	}
}

struct students* add_by_ID(struct students* root,struct students* temp){//add the wanted name surname and number to the ýd sorted list
	int i=0;
	struct students* iter;
	iter=root;
	if(root==NULL){// if there is no student in the list add the wanted student
		root=temp;
		root->ID_next=NULL;
		return root;
	}

	else{
		if(temp->ID<iter->ID){//if there are students and the wanted student should be at the first then add it 
			temp->ID_next=iter;
			
			root=temp;
			return root;
			
		}

		while(1){//if there are students and the wanted student should be after first place then add it to needed place
			if(iter->ID_next==NULL){
				iter->ID_next=temp;
				temp->ID_next=NULL;
				return root;
				break;
			}
			else{

				if(temp->ID<iter->ID_next->ID){
					temp->ID_next=iter->ID_next;
					iter->ID_next=temp;
					return root;
					break;
					
				}
				else{
					iter=iter->ID_next;
					
					
				}
					
					
				
			}
			
			
			
		}
	}
}

void write(struct students* root_name,struct students* root_surname,struct students* root_ID){//print all the lists 
	struct students* iter;
	int num=0;
	
	iter=root_name;
	printf("\nThe list in name-alphabetical order:\n");
	while(iter!=NULL){
		num+=1;
		printf("	%d. %s %s %d\n",num,iter->name,iter->surname,iter->ID);
		iter=iter->name_next;
	}
	
	iter=root_surname;
	num=0;
	printf("\nThe list in surname-alphabetical order:\n");
	while(iter!=NULL){
		num+=1;
		printf("	%d. %s %s %d\n",num,iter->name,iter->surname,iter->ID);
		iter=iter->surname_next;
	}
	
	iter=root_ID;
	num=0;
	printf("\nThe list in ID sorted order:\n");
	while(iter!=NULL){
		num+=1;
		printf("	%d. %s %s %d\n",num,iter->name,iter->surname,iter->ID);
		iter=iter->ID_next;
	}
}

void write_to_txt(char output_txt[100],struct students* root_name,struct students* root_surname,struct students* root_ID){//print all the lists to the wanted txt file
	FILE *output;
	output= fopen(output_txt, "a");
	struct students* iter;
	int num=0;
	
	iter=root_name;
	fprintf(output,"The list in name-alphabetical order:\n");
	while(iter!=NULL){
		num+=1;
		fprintf(output,"	%d. %s %s %d\n",num,iter->name,iter->surname,iter->ID);
		iter=iter->name_next;
	}
	
	iter=root_surname;
	num=0;
	fprintf(output,"\nThe list in surname-alphabetical order:\n");
	while(iter!=NULL){
		num+=1;
		fprintf(output,"	%d. %s %s %d\n",num,iter->name,iter->surname,iter->ID);
		iter=iter->surname_next;
	}
	
	iter=root_ID;
	num=0;
	fprintf(output,"\nThe list in ID sorted order:\n");
	while(iter!=NULL){
		num+=1;
		fprintf(output,"	%d. %s %s %d\n",num,iter->name,iter->surname,iter->ID);
		iter=iter->ID_next;
	}
	printf("Output is printed to the file %s\n",output_txt);
}

int main(){//get the txt and direct to the wanted function.
	struct students* root_name;
	struct students* root_surname;
	struct students* root_ID;
	struct students* iter;
	root_name=NULL;
	root_surname=NULL;
	root_ID=NULL;
	
	
	int choice=0;
	long int number;
	int i;
	char line[1000];
	int num=0;
	int letter=0;
	int spaceness=0;
	char word[100];
	
	FILE *Ptr;
	if ((Ptr = fopen("students.txt", "r")) == NULL) { //control if the txt file is opened or not      
		puts("File could not be opened");   
	}    
	else{
		while (!feof(Ptr)) {//loop in the txt file's lines
			struct students* temp=(struct students*)malloc (sizeof(struct students));
			fscanf(Ptr, "%[^\n]\n", line);
			
			for (i = 0; i < strlen(line)+1; i++){//loop in the line's characters
				if ((int)line[i]==' '||(int)line[i]==9||i==strlen(line)){//control if the character is space or not if it is space get the word as name surname or ýd
					
					if(num==0){//getting name
						strcpy(temp->name,word);
						
					}
					else if(num==1){//getting surname
						strcpy(temp->surname,word);
						
					}
					else{//geting number
						sscanf(word, "%d", &number);
						temp->ID=number;
						
					}
					num+=1;
					
					
					letter=0;
					spaceness=1;
					memset(word, 0, sizeof word);
				}
				else{
					spaceness=0;
				}
				if(spaceness==0){//add the characters to the word if it is not a space
					word[letter]=line[i];
					letter+=1;
				}
				
			
			}
			root_name=add_by_name(root_name,temp);//add student to name_next linked list
			root_surname=add_by_surname(root_surname,temp);//add student to surname_next linked list
			root_ID=add_by_ID(root_ID,temp);//add student to ýd_next linked list
			num=0;
		}
		write(root_name,root_surname,root_ID);//write the students in three way
		while(choice!=5){//if user choose 5 loop end if not then the program get the choice again and again
			struct students* temp=(struct students*)malloc (sizeof(struct students));
			printf("\nEnter your choice:\n	1 to insert a student into the list.\n	2 to delete a student from the list.\n	3 to print the students in the list.\n	4 to print the students to an output file.\n	5 to end.\n? ");
			scanf("%d", &choice);
			if(choice==1){// if the choice is 1 then ask name surname and number and add it to lists
				printf("Enter a student name, suname, and ID:\n");
				scanf("%s %s %d",temp->name,temp->surname,&temp->ID);
				
				root_name=add_by_name(root_name,temp);
				root_surname=add_by_surname(root_surname,temp);
				root_ID=add_by_ID(root_ID,temp);
				write(root_name,root_surname,root_ID);
				
			}
			else if(choice==2){// if the choice is 1 then ask number and delete it from lists
				long int ID;
				printf("Enter a student ID:\n");
				scanf("%d", &ID);
				root_name=delete_from_name(root_name,ID);
				root_surname=delete_from_surname(root_surname,ID);
				root_ID=delete_from_ID(root_ID,ID);
			}
			else if(choice==3){// if the choice is 3 then print lists
				write(root_name,root_surname,root_ID);
			}
			else if(choice==4){// if the choice is 4 then ask file name and print lists to the file
				printf("Enter a file name:\n");
				char output_txt[100];
				scanf("%s", output_txt);
				write_to_txt(output_txt,root_name,root_surname,root_ID);
				
			}

			
		}


		
	}
}
