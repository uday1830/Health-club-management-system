#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct members  // members structure
{
	int member_id;
	int age;
	char name[50];
	char gender[10];
	int numofprograms;
	int programs[4];
	int feespaid[4];
	
	struct members* next;
};

struct trainer   //trainer structure
{
	int trainer_id;
	char name[50];
	int totalprograms;
	int trainerprograms[4];
	int remun;
	
	struct trainer* next;
};
struct time
{
	int data;
	int itime;
	struct time* next;
};
struct request_slot  // structure of types required for requesting slot
{
	int member_id;
	int program;
	int timeslot;
	int trainer_id;

	int request_time;
	struct request_slot* next;
};
void traversal(struct members* lptr)   //traversal member
{
	struct members* nptr;
	nptr=lptr;
	while(nptr!=NULL)
	{
	
	printf("%d\n",nptr->member_id);
	nptr=nptr->next;
}
}
void traversal2(struct trainer* lptr)  //traversal trainer
{
	struct trainer* nptr;
	nptr=lptr;
	while(nptr!=NULL)
	{
	
	printf("%d\n",nptr->trainer_id);
	nptr=nptr->next;
}
}
void print_member(struct members* lptr)  //print member
{  
   int j;
   struct members* nptr;
   nptr=lptr;
	printf("\n the member id of the patients is %d",nptr->member_id);
			printf("\n the age of the member is %d",nptr->age);
			printf("\n the name of the member is %s",nptr->name);
			printf("\n the gender of the member is %s",nptr->gender);
			printf("\n no of programs taken by the member is %d",nptr->numofprograms);
			printf("\n the programs taken by the member is");
			for(j=0;j<nptr->numofprograms;j++)
			{
				if(nptr->programs[j]==1)
				{
					printf("\n yoga");
				}
				else if(nptr->programs[j]==2)
				{
					printf("\n cardio");
				}
				else if(nptr->programs[j]==3)
				{
					printf("\n zumba");
				}
				else if(nptr->programs[j]==4)
				{
					printf("\n weight lifting");
				}
			}
			printf("\n the fees paid by the member for the respected program is ");
			for(j=0;j<nptr->numofprograms;j++)
			{
				if(nptr->programs[j]==1)
				{
					printf("\n yoga - %d",nptr->feespaid[j]);
				}
				else if(nptr->programs[j]==2)
				{
					printf("\n cardio - %d",nptr->feespaid[j]);
				}
				else if(nptr->programs[j]==3)
				{
					printf("\n zumba - %d",nptr->feespaid[j]);
				}
				else if(nptr->programs[j]==4)
				{
					printf("\n weight lifting - %d",nptr->feespaid[j]);
				}
			}
}

void print_trainer(struct trainer* lptr)  // print trainer
{
	int j;
   struct trainer* nptr;
   nptr=lptr;
	printf("\n the trainer id is %d",nptr->trainer_id);
	printf("\n the name of the trainer is %s",nptr->name);
	printf("\n the programs trained by the trainer are");
	for(j=0;j<nptr->totalprograms;j++)
	{
		if(nptr->trainerprograms[j]==1)
		{
			printf("\n yoga");
		}
		else if(nptr->trainerprograms[j]==2)
		{
			printf("\n cardio");
		}
		else if(nptr->trainerprograms[j]==3)
		{
			printf("\n zumba");
		}
		else if(nptr->trainerprograms[j]==4)
		{
			printf("\n weight lifting");
		}
	}
	printf("\n the fees taken by trainer is %d ",nptr->remun);
}
struct trainer* add_trainer(struct trainer* lptr,struct trainer* list_ptr )   //add trainer
{
	
	struct trainer* nptr;
	struct trainer* sptr;
	nptr=list_ptr;
	if(list_ptr==NULL)
	{
		list_ptr=lptr;
		list_ptr->next=NULL;
		return list_ptr;
	}
	else if((lptr->trainer_id<nptr->trainer_id))
	{
		lptr->next=nptr;
		return lptr;	
	}
		else if(nptr->next==NULL&&(lptr->trainer_id>nptr->trainer_id))
	{   
	    sptr=nptr->next;
	    
		nptr->next=lptr;
		lptr->next=sptr;
		return nptr;
	}
	else
	{
	
	while(nptr->next!=NULL&&(nptr->trainer_id<lptr->trainer_id))
	{
		sptr=nptr;
		nptr=nptr->next;
	}
	if(nptr->next==NULL&&(nptr->trainer_id<lptr->trainer_id))
	{
		nptr->next=lptr;
		lptr->next=NULL;
		return list_ptr;
	}
	else if(nptr->trainer_id>lptr->trainer_id)
	{
		sptr->next=lptr;
		lptr->next=nptr;
		return list_ptr;
	}
}
}
struct members* add_member(struct members* lptr,struct members* list_ptr )   //add member
{
	struct members* nptr;
	struct members* sptr;
	nptr=list_ptr;
	if(list_ptr==NULL)
	{
		list_ptr=lptr;
		list_ptr->next=NULL;
		return list_ptr;
	}
	else if((lptr->member_id<nptr->member_id))
	{
		lptr->next=nptr;
		return lptr;	
	}
	else if(nptr->next==NULL&&(lptr->member_id>nptr->member_id))
	{   
	    sptr=nptr->next;
	    
		nptr->next=lptr;
		lptr->next=sptr;
		return nptr;
	}
	else
	{
	
	while(nptr->next!=NULL&&(nptr->member_id<lptr->member_id))
	{
		sptr=nptr;
		nptr=nptr->next;
	}
	if(nptr->next==NULL&&(nptr->member_id<lptr->member_id))
	{
		nptr->next=lptr;
		lptr->next=NULL;
		return list_ptr;
	}
	else if(nptr->member_id>lptr->member_id)
	{
		sptr->next=lptr;
		lptr->next=nptr;
		return list_ptr;
	}
}
}
struct members* delete_member(int k,struct members* lptr)  //delete member 
{
	struct members* sptr;
	struct members* nptr;
	nptr=lptr;
if(nptr->member_id==k)
{
	sptr=nptr->next;
	free(nptr);
	return sptr;
}
else
{
	while(nptr->member_id!=k)
	{
		sptr=nptr;
		nptr=nptr->next;
	}
	sptr->next=nptr->next;
	free(nptr);
	return lptr;
}
}
struct trainer* delete_trainer(int k,struct trainer* lptr)   //delete trainer
{
	struct trainer* sptr;
	struct trainer* nptr;
	nptr=lptr;
if(nptr->trainer_id==k)
{
	sptr=nptr->next;
	free(nptr);
	return sptr;
}
else
{
	while(nptr->trainer_id!=k)
	{
		sptr=nptr;
		nptr=nptr->next;
	}
	sptr->next=nptr->next;
	free(nptr);
	return lptr;
}
}
void search_member(int i,struct members* lptr)  //search member
{
	struct members* nptr;
	int j;
	char str2[50];
	nptr=lptr;
	 int k2;
	if(i==1)
	{  
	    
	     printf("\n enter the member id ");
	     scanf("%d",&k2);
		if(nptr->member_id==k2)
		{
		  print_member(nptr);
		}
		else
		{
			while(nptr->member_id!=k2)
			{
				nptr=nptr->next;
			}
			if(nptr==NULL)
			{
				printf("\n invalid input");
			}
			else
			{
			print_member(nptr);
			
		}
			
		}
	}
	else if(i==2)
	{
		printf("\n enter the age of the member to be searched ");
		scanf("%d",&k2);
		
		while(nptr!=NULL)
		{
			if(nptr->age==k2)
		{
			print_member(nptr);
		}
		nptr=nptr->next;
		}
	}
	else if(i==3)
	{
		printf("\n enter the name of the members to be searched ");
		scanf("%s",str2);
		while(nptr!=NULL)
		{
			if(strcmp(nptr->name,str2)==0)
			{
				print_member(nptr);
			}
			
			
			nptr=nptr->next;
		
		}
	}
	else if(i==4)
	{
		printf("\n enter the gender of members to be searched ");
		scanf("%s",str2);
		while(nptr!=NULL)
		{
			if(strcmp(nptr->gender,str2)==0)
			{
				print_member(nptr);
			}
			
			
			nptr=nptr->next;
		
		}
	}
	else if(i==5)
	{
		printf("\n enter 1 for searching members who took yoga ");
		printf("\n enter 2 for searching members who took cardio");
		printf("\n enter 3 for searching members who took zumba ");
		printf("\n enter 4 for searching members who took weight lifting");
		scanf("%d",&k2);
		while(nptr!=NULL)
		{
			for(j=0;j<nptr->numofprograms;j++)
			{
				if(nptr->programs[j]==k2)
				{
					print_member(nptr);
				}
			}
			nptr=nptr->next;
		}
	}
}
void search_trainer(int i,struct trainer* lptr)
{
	int k2;
	char str2[50];
	int j;
	struct trainer* nptr;
	nptr=lptr;
	if(i==1)
	{  
	    
	     printf("\n enter the trainer id ");
	     scanf("%d",&k2);
		if(nptr->trainer_id==k2)
		{
		  print_trainer(nptr);
		}
		else
		{
			while(nptr->trainer_id!=k2)
			{
				nptr=nptr->next;
			}
			if(nptr==NULL)
			{
				printf("\n invalid input");
			}
			else
			{
			print_trainer(nptr);
			
		}
			
		}
	}
	else if(i==2)
	{
		printf("\n enter the name of the trainer for searching ");
		scanf("%s",str2);
		while(nptr!=NULL)
		{
			if(strcmp(nptr->name,str2)==0)
			{
				print_trainer(nptr);
			}
			nptr=nptr->next;
		}
	}
	else if(i==3)
	{
		printf("\n enter 1 for searching trainers who trains yoga ");
		printf("\n enter 2 for searching trainers who trains cardio");
		printf("\n enter 3 for searching trainers who trains zumba ");
		printf("\n enter 4 for searching trainers who trains weight lifting");
		scanf("%d",&k2);
		while(nptr!=NULL)
		{
			for(j=0;j<nptr->totalprograms;j++)
			{
				if(nptr->trainerprograms[j]==k2)
				{
					print_trainer(nptr);
				}
				
			}
			nptr=nptr->next;
		}
	}
	
}
struct time* timeinit(struct time* lptr,struct time* nptr)
{
	 struct time* sptr;
	 
	 sptr=nptr;
	if(sptr==NULL)
	{
		sptr=lptr;
		lptr->next=NULL;
		
		return sptr;
	}
	else
	{
		while(sptr->next!=NULL)
		{
			sptr=sptr->next;
		}
		sptr->next=lptr;
		lptr->next=NULL;
		return nptr;
	}
	
};
struct request_slot* sort_request_slot(struct request_slot* lptr,struct request_slot* nptr)
{
	struct request_slot* nptr2;
	nptr2=nptr;
	struct request_slot* sptr;
	
	if(nptr2==NULL)
	{
		nptr2=lptr;
		nptr2->next=NULL;
		return nptr2;
	}
	else if(lptr->request_time<nptr2->request_time)
	{
		lptr->next=nptr2;
		return lptr;	
	}
	else if(lptr->request_time>=nptr2->request_time)
	{   
	    sptr=nptr2->next;
	    
		nptr2->next=lptr;
		lptr->next=sptr;
		return nptr2;
	}
	else
	{
	
	while(nptr2->next!=NULL&&(nptr2->request_time<=lptr->request_time))
	{
		sptr=nptr2;
		nptr2=nptr2->next;
	}
	if(nptr2->next==NULL&&(nptr2->request_time<=lptr->request_time))
	{
		nptr2->next=lptr;
		lptr->next=NULL;
		return nptr;
	}
	else if(nptr2->request_time>lptr->request_time)
	{
		sptr->next=lptr;
		lptr->next=nptr2;
		return nptr;
	}
}
};
int main()
{
	struct members* member_list;  // pointer to the initial node of linked list containing 
	struct trainer* trainer_list;
	struct request_slot* slot_list;
	struct request_slot* allocated_list;
	struct request_slot* after_alloc;
	struct members* mptr;
	struct trainer* tptr;
	int req1;
	allocated_list=NULL;
	slot_list=NULL;
	trainer_list=NULL;
		int n,i,n1,j,n2,k1,l1,l2,k3,i1,req;
	struct time* time_slot,*time_slot1;
	time_slot=NULL;
	time_slot1=NULL;
	for(i1=6;i1<=21;i1++)
	{
		time_slot1=(struct time*)malloc(sizeof(struct time));
		time_slot1->data=0;
		time_slot1->itime=i1;
		time_slot=timeinit(time_slot1,time_slot);
		
		
	}
	
	printf("\n the member list is empty add the members to proceed");

	member_list=NULL;
	struct members* addlist;
	struct trainer* addlist2;
	
	

		printf("\n no of member nodes to be added");
		scanf("%d",&n1);
		for(i=0;i<n1;i++)
		{
		
		addlist=(struct members*)malloc(sizeof(struct members));
		printf("\n enter the 4 digit member id");
		scanf("%d",&addlist->member_id);
		printf("\n enter the age");
		scanf("%d",&addlist->age);
		printf("\n enter the name");
		scanf("%s",addlist->name);
		printf("\n enter the gender");
		scanf("%s",addlist->gender);
		printf("\n enter the no of programs enrolled");
		scanf("%d",&addlist->numofprograms);
	
		for(j=0;j<addlist->numofprograms;j++)
		{
			printf("\n enter 1 for yoga slot \n enter 2 for cardio slot \n enter 3 for zumba slot \n enter 4 for weight lifting slot ");
			scanf("%d",&addlist->programs[j]);
			printf("\n enter the fees that has paid for the respective program");
			scanf("%d",&addlist->feespaid[j]);
			
		}
		
		
		member_list=add_member(addlist,member_list);
		printf("\n succesfully added ");
	}
	
	
	printf("\n the trainer list is empty add the trainers to proceed");
		printf("\n no of trainer nodes to be added");
		scanf("%d",&n2);
		for(i=0;i<n2;i++)
		{
			addlist2=(struct trainer*)malloc(sizeof(struct trainer));
			printf("\n enter the trainer id");
			scanf("%d",&addlist2->trainer_id);
			printf("\n enter the name of the trainer");
			scanf("%s",addlist2->name);
			printf("\n enter the total no programs can be trained by the trainer");
			scanf("%d",&addlist2->totalprograms);
			for(j=0;j<addlist2->totalprograms;j++)
			{
				printf("\n enter 1 for yoga slot \n enter 2 for cardio slot \n enter 3 for zumba slot \n enter 4 for weight lifting slot ");
			scanf("%d",&addlist2->trainerprograms[j]);
			}
			printf("\n enter the remunaration taken by the trainer for each session");
			scanf("%d",&addlist2->remun);
			trainer_list=add_trainer(addlist2,trainer_list);
		}
		
	

	
	
	int n3;
	
	n3=0;
	while(n3!=9)
	{
		printf("\n input  1 for adding a member");
	printf("\n input 2 for adding a trainer");
	printf("\n input 3 for deleting a member");
	printf("\n input 4 for deleting a trainer");
	printf("\n input 5 for search a member");
	printf("\n input 6 for search a trainer");
	printf("\n input 7 for print the member list");
	printf("\n input 8 for print the trainer list");
	printf("\n input 9 for ending the process");
    scanf("%d",&n);
	
	
	if(n==1) 
	{
	printf("\n no of member nodes to be added");
		         scanf("%d",&n1);
		         for(i=0;i<n1;i++)
	           	 {
		
		         addlist=(struct members*)malloc(sizeof(struct members));
	           	 printf("\n enter the 4 digit member id");
		         scanf("%d",&addlist->member_id);
		         printf("\n enter the age");
		         scanf("%d",&addlist->age);
		         printf("\n enter the name");
		         scanf("%s",addlist->name);
	           	 printf("\n enter the gender");
		         scanf("%s",addlist->gender);
		         printf("\n enter the no of programs enrolled");
		         scanf("%d",&addlist->numofprograms);
	
		         for(j=0;j<addlist->numofprograms;j++)
		         {
			     printf("\n enter 1 for yoga slot \n enter 2 for cardio slot \n enter 3 for zumba slot \n enter 4 for weight lifting slot ");
			     scanf("%d",&addlist->programs[j]);
		       	 printf("\n enter the fees that has paid for the respective program");
			     scanf("%d",&addlist->feespaid[j]);
			
		         }
		
		
		         member_list=add_member(addlist,member_list);
		         printf("\n succesfully added ");
	             }
	         }
				  
	    else if(n==2)
	    {
		
		printf("\n no of trainer nodes to be added");
		         scanf("%d",&n2);
		         for(i=0;i<n2;i++)
	         	 {
			     addlist2=(struct trainer*)malloc(sizeof(struct trainer));
			     printf("\n enter the trainer id");
			     scanf("%d",&addlist2->trainer_id);
			     printf("\n enter the name of the trainer");
			     scanf("%s",addlist2->name);
		       	 printf("\n enter the total no programs can be trained by the trainer");
			     scanf("%d",&addlist2->totalprograms);
			     for(j=0;j<addlist2->totalprograms;j++)
			     {
				 printf("\n enter 1 for yoga slot \n enter 2 for cardio slot \n enter 3 for zumba slot \n enter 4 for weight lifting slot ");
			     scanf("%d",&addlist2->trainerprograms[j]);
		       	 }
			     printf("\n enter the remunaration taken by the trainer for each session");
			     scanf("%d",&addlist2->remun);
			     trainer_list=add_trainer(addlist2,trainer_list);
		         }
		     }
		else if (n==3)
		{
		printf("\n enter the member id of the member to be deleted");
		         scanf("%d",&k1);
				 member_list=delete_member(k1,member_list);
				 printf("\n succesfully deleted the member");
			}
		else if(n==4) 
		{
		printf("\n enter the trainer id of the trainer to be deleted");
		         scanf("%d",&k1);
		         trainer_list=delete_trainer(k1,trainer_list);
		         printf("\n succesfully deleted the trainer");
		     }
		else if(n==5) 
		{
		printf("\n enter 1 to search with member id \n enter 2 to search with age \n enter 3 to search with name \n enter 4 to search with gender \n enter 5 to search with programs taken");
		         scanf("%d",&k1);
		         search_member(k1,member_list);
	   }
		else if(n==6)
		{
		printf("\n enter 1 to search with trainers id \n enter 2 to search with name of the trainer \n enter 3 to search with programs they train");
		         scanf("%d",&k1);
		         search_trainer(k1,trainer_list);
	    }
		else if(n==7)
		{
			mptr=member_list;
			
			if(mptr==NULL)
			{
				printf("\n member list is empty");
			}
			
			while(mptr!=NULL)
			{
			
		print_member(mptr);
		mptr=mptr->next;
         	}
	    }
		else if(n==8) 
		{ 
		  tptr=trainer_list;
		  if(tptr==NULL)
		  {
		  	printf("\n trainer list is empty");
		  }
		  while(tptr!=NULL)
		  {
		print_trainer(tptr);
		tptr=tptr->next;
	      }
	   }
		else if(n==9)
		{
			n3=9;
		
		         printf("\n session expired");
	}
	}
	
	
	
      }
