#include <stdio.h>
#include <stdlib.h>
typedef struct carType Car;
struct carType {
 int vehicleID;
 char make[20];
 char model[20];
 int year;
 int mileage;
 double cost;
 Car *next;
};
typedef struct carType Car;
void print_node(Car*head)
{

        printf("ID: %d - ",head->vehicleID);
        printf("Make: %s - ",head->make);
        printf("Model: %s - ",head->model);
        printf("Year: %d - ",head->year);
        printf("Milage: %d - ",head->mileage);
        printf("Cost: %3f - \n",head->cost);


}
void print_ll(Car*head)
{

    Car *temp=head;

    while(temp!=NULL)
    {
        printf("ID: %d - ",temp->vehicleID);
        printf("Make: %s - ",temp->make);
        printf("Model: %s - ",temp->model);
        printf("Year: %d - ",temp->year);
        printf("Milage: %d - ",temp->mileage);
        printf("Cost: %0.3f - \n",temp->cost);
        temp=temp->next;
    }
    printf("\n");
}


void insert_at_end(Car**head,int vehicleID,
 char make[20],
 char model[20],
 int year,
 int mileage,
 double cost)
{
    Car *result;
    result=malloc(sizeof(Car));


    result->vehicleID=vehicleID;
    strcpy(result->make,make);
    strcpy(result->model,model);
    result->year=year;
    result->mileage=mileage;
    result->cost=cost;
    result->next=NULL;

   if(*head==NULL)
   {

    *head=result;
   }
   else
   {
    Car *last=*head;

   while(last->next!=NULL)
   {
       last=last->next;
   }
   last->next=result;
   }
   //return result;

}

Car *Search_car(Car *head, int searchID){
    searchID=searchID+1;
 Car *previous, *current;
 previous = head;
 current = head->next;
 /* Traverse until ID >= searchID */
 while ((current!=NULL)
 && (current->vehicleID < searchID)) {
 previous = current;
 current = current->next;
 }
 return previous;
}



void delete_Node(Car** head, int key)
{
    // Store head node
    Car *temp = *head, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->vehicleID == key) {
        *head = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->vehicleID != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}
Car insert(Car *head,int id)
{
    //int id;
    char make[20];
    char model[20];
    int year;
    int mileage;
    double cost;
    //printf("ID:");
//scanf("%d",&id);
printf("Make:");
scanf("%s",&make);
printf("Model:");
scanf("%s",&model);
printf("Year:");
scanf("%d",&year);
printf("Millage:");
scanf("%d",&mileage);
printf("Cost:");
scanf("%f",&cost);


insert_at_end(&head,id,make,model,year,mileage,cost);
}


Car *  lastID(Car *head)
{
    head=NULL;



   while(head->next!=NULL)
   {
       head=head->next;
   }

    return head;
}
   //return result;





int main()
{

    Car *head=NULL;
    Car *temp;
    Car *temp2,*temp3;
    int ID;

insert_at_end(&head,1,"VW","Golf",2013,130000,12.750);
insert_at_end(&head,2,"VW","Passat",2015,137000,15);
insert_at_end(&head,3,"VW","Tiguan",2017,10000,70);
insert_at_end(&head,4,"Nissan","Juke",2018,50000,30);
insert_at_end(&head,5,"Nissan","Qashqai",2016,160000,30);
insert_at_end(&head,6,"Peugeot","208",2016,190000,10);
insert_at_end(&head,7,"Peugeot","3008",2017,110000,20);
insert_at_end(&head,8,"VW","Tuareg",2014,210000,25.45);
insert_at_end(&head,9,"VW","Polo",2004,210000,5.45);
insert_at_end(&head,10,"VW","T-Roc",2021,1000,45.32);

    int choice;
    int id;
    int lastID;
    int lastID4;
    int lastID5;
    Car *temp4;
    Car *temp5;

while(1)
    {
        printf("1. Add Car \n");
        printf("2. Show all Car\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Exit\n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                temp4=NULL;
                temp4=head;
                while(temp4->next!=NULL)
                    {
                        temp4=temp4->next;
                    }

                lastID4=temp4->vehicleID;
                lastID4=lastID4+1;
                insert(head,lastID4);
                print_ll(head);
                break;

            case 2:
                print_ll(head);
                break;
            case 3:
                temp3=NULL;
                temp3=head;
                while(temp3->next!=NULL)
                    {
                        temp3=temp3->next;
                    }

                lastID=temp3->vehicleID;
                //printf("%d,",lastID);

                printf("Enter ID you want to delete: ");
                scanf("%d",&id);
                if(id>lastID)
                {
                    printf(" ID not found  \n ");
                    break;
                }
                else
                    {
                delete_Node(&head,id);
                printf(" DELETED ! \n");
                break;
                }
            case 4:
                temp5=NULL;
                temp5=head;
                while(temp5->next!=NULL)
                    {
                        temp5=temp5->next;
                    }

                lastID5=temp5->vehicleID;
                printf("Enter ID you want to search: ");
                scanf("%d",&id);
                if(id>lastID5)
                {
                    printf("Car with that ID is not found \n");
                    break;
                }
                else{
                temp=Search_car(head,id);
                print_node(temp);
                break;
                }
            case 5:
                printf("\n\n\t\t\t Goodbye \n\n\n");
                exit(0);    // terminates the complete program execution
        }
        }
        return 0;
}