//BOOK MANAGMENT SYSTEM PROJECT 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Book
{
	int BookId;
	char BookName[50];
	char BookAuthor[50];
	char BookCategory[50];
	int BookPrice;
	double BookRating;
	
}Book;
void AddBook(Book *);
void HardcodeBook1(Book*);
void DisplayBook(Book *);
void DisplayBook1(Book);
int SearchById(Book *,int);
void SearchByName(Book *,char*);
void RemoveBook(Book *);
void UpdateBook(Book *,int);
void SortBook(Book *);
void SortPrice(Book *);
void SortRating(Book *);
void SortBook(Book *);
int n=5;//track of memory

void main()
{
    /*Book b[10]={{01,"THE GOD OF SMALL THINGS","ABDUL KALAM","FICTION",1000,5},
              {02,"THE GUIDE","ARVIND ADIGA","CLASSIC",1400,3},
              {03,"THE WHITE TIGER","R.K.NARAYAN","FICTION",1200,6},
              {04,"EARLY INDIA","ROMILA THAPARS","HISTORY",800,1},
              {05,"ABHANG","SANT TUKARAM","HISTORY",500,2}};*/
              
              
    Book *b=(Book*)malloc(n*sizeof(Book));
    HardcodeBook1(b);
	int choice;
	do{
 		printf("\n\nBOOK MANAGEMENT MENU : \n");
 		printf("\n1.add book");
 		printf("\n2.display book");
 		printf("\n3.search book");
 		printf("\n4.remove book");
 		printf("\n5.update book");
 		printf("\n6.sort book");
 		printf("\n0.exist");
 		
 		printf("\nEnter choice :");
 		scanf("%d",&choice);
 		
 		switch(choice)
 		{
 			case 1:{
 				AddBook(b);
				break;
			 }
			 case 2:{
			 	DisplayBook(b);
				break;
			 }
			 case 3:{	
			 	printf("Enter choice:1.searchbyid 2.searchbyname: ");
			 	scanf("%d",&choice);
			 	if(choice==1)
			 	{
			 	   int SearchId;
			 	
			 	   printf("Enter the id of the book to search:");
			 	   scanf("%d",&SearchId);
			 	
			 	   int index=SearchById(b,SearchId);
			 	   if(index==-1)
			 	   {
			 		  printf("The Book id is not found");
			    	}
				   else
				   {
				 	  DisplayBook1(b[index]);
				   }
		    	}
				else if(choice==2)
				{
			 	    char SearchName[20];
			 	    printf("Enter the name of the book to search:");
			 	    fflush(stdin);
			 	    gets(SearchName);			 	
			 	    SearchByName(b,SearchName);
				}
				break;
			}
	        case 4:{
			 	RemoveBook(b);
				break;
			}
			case 5:{
			 	int BookId;
			 	printf("Enter the book id:");
			 	scanf("%d",&BookId);
			 	UpdateBook(b,BookId);
				break;
			}
			case 6:{
				
			 	SortBook(b);
				break;
			 }
			 case 0:{
			 	printf("Thank you visit again to my book managment system !!");
				break;
			 }
			default:
			printf("Invalid choice");	 	
		 }
	 }while(choice!=0);
 }
	

void AddBook(Book* b)//defination
{
	   printf("Enter Book Details:\n");
	   printf("Enter book id:");  
	   scanf("%d",&b[n].BookId);
		
	   printf("Enter book name:");
	   fflush(stdin);//buffer clean function
	   gets(b[n].BookName);
	   
	   printf("Enter book author name: ");
	   fflush(stdin);
	   gets(b[n].BookAuthor);
		
	   printf("Enter book category name:");
	   fflush(stdin);
	   gets(b[n].BookCategory);
		
	   printf("Enter book price:");
	   scanf("%d",&b[n].BookPrice);
		
	   printf("Enter book rating: ");
	   scanf("%lf",&b[n].BookRating);
	   n++;
	   
}

void DisplayBook(Book *b)//defination
{
	printf("+----------+------------------------+--------------------+--------------------+----------------------+-----------------+\n");
	printf("| Book Id  |     Book Name          |   Book Author Name |  Book Category Name|      Book Price      | Book Rating     |\n");
	printf("+----------+------------------------+--------------------+--------------------+----------------------+-----------------+\n");
	for(int i=0;i<n;i++)
	{
	   printf("|%-10d|%-24s|%-20s|%-20s|%-22d|%-17lf|\n",b[i].BookId,b[i].BookName,b[i].BookAuthor,b[i].BookCategory,b[i].BookPrice,b[i].BookRating);
    
    printf("+----------+------------------------+--------------------+--------------------+----------------------+-----------------+\n");
	}
}

void DisplayBook1(Book b)//defination
{
	//printf("\n Display Book Details:\n");	   
	   
	//printf("book id:%d\n book name:%s\n book author name:%s\n book category name:%s\n book price:%d\n book rating:%lf\n",b.BookId,b.BookName,b.BookAuthor,b.BookCategory,b.BookPrice,b.BookRating);
    
    //printf("+----------+------------------------+--------------------+---------------------+----------------------+-----------------+\n");
	//printf("| Book Id  |     Book Name          |   Book Author Name |  Book Category Name |      Book Price      |    Book Rating  |\n");
	//printf("+----------+------------------------+--------------------+---------------------+----------------------+-----------------+\n");
	/*printf("|%d|%s|%s|%s|%d|%lf|\n",b.BookId,b.BookName,b.BookAuthor,b.BookCategory,b.BookPrice,b.BookRating);*/
	printf("+----------+------------------------+--------------------+--------------------+----------------------+-----------------+\n");
	printf("| Book Id  |     Book Name          |   Book Author Name |  Book Category Name|      Book Price      | Book Rating     |\n");
	printf("+----------+------------------------+--------------------+--------------------+----------------------+-----------------+\n");
	printf("|%-10d|%-24s|%-20s|%-20s|%-22d|%-17lf|\n",b.BookId,b.BookName,b.BookAuthor,b.BookCategory,b.BookPrice,b.BookRating);
    
    printf("+----------+------------------------+--------------------+--------------------+----------------------+-----------------+\n");

}

int SearchById(Book *b,int SearchId )//defination
{
	for(int i=0;i<n;i++)
	{
	   if(b[i].BookId==SearchId)
	   {
	   	return i;
	   }
    }
    return -1;
}
void SearchByName(Book *b,char *SearchName)//defination
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(strcasecmp(b[i].BookName,SearchName)==0)
		{
			flag=1;
			printf("Book name are found\n");
			DisplayBook1(b[i]);
		}
	}
	if(flag==0)
	printf("\n Book Name are not found");
}

void RemoveBook(Book *b)
{
	int removeid,found=0;
    printf("Enter the book id you want to remove :");
	scanf("%d",&removeid);
	int i,j;
	for(i=0;i<n;i++)
	{
		if(b[i].BookId==removeid)
		{
			found=1;
			break;
		}
	}
	if(found==1)
	{
		for(j=i;j<n-1;j++)
		{
			b[j]=b[j+1];
		}
		n--;
		printf("*******The book id deleted successfullly*******\n");
		
		DisplayBook(b);
    }
    else
    {
    	printf("Book id is not found");
	}
}

void UpdateBook(Book *b,int BookId)
{
	int i,choice,found=0;
	
	printf("Enter choice:1.update book price 2.update book rating: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		for(i=0;i<n;i++)
		{
			if(b[i].BookId==BookId)
			{
				printf("Enter book new price to update:");
				scanf("%d",&b[i].BookPrice);
				
				printf("********book price updated successfully*******\n");
				
				found++;
				break;
				
			}
		}
		DisplayBook(b);
		if(found==0)
		{
			printf("Book id is not found");
		}
	}
	else
	{
		if(choice==2)
		{
			for(i=0;i<n;i++)
			{
				if(b[i].BookId==BookId)
				{
					printf("Enter book new rating to update: ");
					scanf("%lf",&b[i].BookRating);
					
					printf("******book rating updated successfully********\n");
					found++;
					break;
					
				}
			}
		}
		DisplayBook(b);
		if(found==0)
		{
			printf("Book id is not found");
		}
	}
	
}

void SortBook(Book *b)
{
	int choice;
	Book temp;
	printf("Enter choice:1.Book price 2.Book rating: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		SortPrice(b);
		DisplayBook(b);
	}
	else
	{
		if(choice==2)
		{
			SortRating(b);
			DisplayBook(b);
		}
		else
		{
			printf("Invalid choice");
		}
	}
}
void SortPrice(Book *b)
{
	Book temp;
	for(int i=0;i<n;i++)
   {
		for(int j=i+1;j<n;j++)
		{
			if(b[i].BookPrice < b[j].BookPrice)
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
}

void SortRating(Book *b)
{
	Book temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(b[i].BookRating < b[j].BookRating)
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
}

void HardcodeBook1(Book *b)
{
	b[0].BookId=1;
	strcpy(b[0].BookName,"THE GOD OF SMALL THINGS");
	strcpy(b[0].BookAuthor,"ABDUL KALAM");
	strcpy(b[0].BookCategory,"science");
	b[0].BookPrice=1800;
	b[0].BookRating=3;
	
	b[1].BookId=2;
	strcpy(b[1].BookName,"THE WHITE TIGER");
	strcpy(b[1].BookAuthor,"ARVIND ADIGA"); 
	strcpy(b[1].BookCategory,"FICTION");
	b[1].BookPrice=1200;
	b[1].BookRating=4;
	
	b[2].BookId=3;
	strcpy(b[2].BookName,"THE GUIDE");
	strcpy(b[2].BookAuthor,"R.K.NARAYAN"); 
	strcpy(b[2].BookCategory,"CLASSICS");
	b[2].BookPrice=1400;
	b[2].BookRating=3.5;
	
	b[3].BookId=4;
	strcpy(b[3].BookName,"EARLY INDIA");
	strcpy(b[3].BookAuthor,"ROMILA THAPARS"); 
	strcpy(b[3].BookCategory,"HISTORY");
	b[3].BookPrice=800;
	b[3].BookRating=4.5;
	
	b[4].BookId=5;
	strcpy(b[4].BookName,"ABHANG");
	strcpy(b[4].BookAuthor,"SANT TUKARAM"); 
	strcpy(b[4].BookCategory,"HISTORY");
	b[4].BookPrice=500;
	b[4].BookRating=4.9;
}

	