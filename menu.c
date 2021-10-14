
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int i,ch,index,pubyear,newyear[20];
    int j,temp, newcost[20];
    char pubname[20],authorname[20],newauthor[20],sortname[20],tempchar[50];

    char* pub[10] = { "BPB","Classical","Lakshmi", "Krishna", "Anuradha","Dhanam","Magnus", "Khanna", "Royalbook", "Technical"};

    char author[20][10] = {  "Yashwanth", "Jain", "Maheshwari", "Veerarajan", "Singh", "Gupta","Rajan", "Bala", "kanesh","Patel"};

    char* name[10] = {"Data Structures", "Computer fundamentals","Computer Architecture", "Operating system","Data structure with c","Digital Electronics", "Computer Organization & Architecture", "Data Structures", "Computer fundamentals","Computer Architecture",};
    int cost[20] = {200,300,250,500,600, 400, 210, 330, 550,120};
    int accno[20] = {333345,123490,555325,789342,136378,157836,345673,982344,532466,334672};

    int year[20] = {1950,1980,1890,1945,1923,1933,1999,2000,2020,2010};

    printf("Book Details");

    for(i=0; i<10; i++)
    {
        printf("\n\t ..........Book Details %d: .........\n",i);
        printf("Book Name           : %s \n",name[i]);
        printf("Book Author         : %s \n",author[i]);
        printf("Book Version        : %d \n",accno[i]);
        printf("Book publication    : %s \n",pub[i]);
        printf("Book Publishing year: %d \n",year[i]);
        printf("Book Price          : %d \n",cost[i]);

    }

    while(1)
    {
        printf("\n\t\tMENU\n");
        printf("------------------------------------------\n");
        printf("\n1.Books of Specific Author");
        printf("\n2.Increasing order of book price");
        printf("\n3.Books of publisher by year");
        printf("\n4.Sort of books in author and year");
        printf("\n5.Exit");
        printf("\n------------------------------------------\n");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
        case 1:
            printf("Enter Author Name : ");
            scanf("%s",authorname);
            for(i=0; i<10; i++)
            {
                if(strcmp(author[i],authorname)==0)
                    printf("\nBook Name        : %s\nBook version : %d\nBook publishing year : %d\n Book price : %d",name[i],accno[i],year[i],cost[i]);
            }
            break;
        case 2:
            //Copying  the array before sorting
            for(i=0; i<10; i++)
            {
                newcost[i] =cost[i];

            }
            for (i = 0; i < 10; ++i)
            {

                for (j = i + 1; j < 10-1; ++j)
                {

                    if (cost[i] > cost[j])
                    {

                        temp =  cost[i];
                        cost[i] = cost[j];
                        cost[j] = temp;

                    }

                }

            }
            //Print after sorting
            for(i=0; i<10; i++)
            {
                for(j=0; j<10; j++)
                {

                    if(cost[i]== newcost[j])  // comparing the value based on sort and unsorted array
                    {

                        index=j;     //find the index

                        printf("\n\t ..........After sorting of price %d: .........\n",i);
                        printf("Book Name           : %s \n",name[index]);
                        printf("Book Author         : %s \n",author[index]);
                        printf("Book Version        : %d \n",accno[index]);
                        printf("Book Publishing year: %d \n",year[index]);
                        printf("Book Price          : %d \n",cost[i]);

                    }
                }
            }



            break;
        case 3:

            printf("Enter publisher Name and year: ");
            scanf("%s %d",&pubname,&pubyear);

            for(i=0; i<10; i++)
            {

                if(strcmp(pub[i],pubname)==0 && (year[i] == pubyear))
                {
                    printf("\nBook Name        : %s\n\nBook Author        : %s\nBook version : %d\nBook publishing year : %d Book price : %d",name[i],author[i],accno[i],year[i],cost[i]);
                }
            }

            break;
        case 4:

            for(i=0; i<10; i++)
            {
                newyear[i] =year[i];
                newauthor[i]=author[i];

            }
            for (i = 0; i < 10; ++i)
            {

                for (j = i+1; j < 10; ++j)
                {

                    if (year[i] > year[j])
                    {

                        temp =  year[i];
                        year[i] = year[j];
                        year[j] = temp;

                    }

                    if(strcmp(author[i], author[j]) > 0)
                    {

                        strcpy(tempchar, author[i]);

                        strcpy(author[i], author[j]);

                        strcpy(author[j], tempchar);



                    }

                }

            }

            //Print after sorting
            for(i=0; i<10; i++)
            {
                for(j=0; j<10; j++)
                {

                    if(year[i]== newyear[j] || author[i] == newauthor[j] )  // comparing the value based on sort and unsorted array
                    {
                        index=j;     //find the index
                        printf("\n\t ..........After sorting of price %d: .........\n",i);
                        printf("Book Name           : %s \n",name[index]);
                        printf("Book Author         : %s \n",author[index]);
                        printf("Book Version        : %d \n",accno[index]);
                        printf("Book Publishing year: %d \n",year[i]);
                        printf("Book Price          : %d \n",cost[index]);

                    }
                }

            }


            for(i=0; i<10; i++)
            {
                for(j=0; j<10; j++)
                {

                    if(author[i]== newauthor[j])  // comparing the value based on sort and unsorted array
                    {
                        index=j;     //find the index
                        printf("\n\t ..........After sorting of author %d: .........\n",i);
                        printf("Book Name           : %s \n",name[index]);
                        printf("Book Author         : %s \n",author[i]);
                        printf("Book Version        : %d \n",accno[index]);
                        printf("Book Publishing year: %d \n",year[index]);
                        printf("Book Price          : %d \n",cost[index]);
                    }
                }
            }



            break;


        case 5:
            exit(0);
        }
    }
    return 0;
}


