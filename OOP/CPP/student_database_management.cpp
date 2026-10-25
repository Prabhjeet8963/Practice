#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;      

int main()
{
    FILE *fp, *ft;

    char another,choice;

    struct student{
        char first_name[50],last_name[50];
        char course[100];
        int batch;
 };
 struct student e;
 char xfirst_name[50],xlast_name[50];
 long int recsize;
 fp=fopen ("user.txt","rb+");
 if(fp == NULL)
 {
    fp =fopen("user.txt","wb+");

    if(fp == NULL)
    {
        puts("Cannot openfile");
        return 0;
    }
 }
 recsize = sizeof(e);
 while(1)
  {
    system("cls");
    cout<< "\t\t======Student Database managment system======";
    cout<< "\n\n                                             ";
    cout<<"\n\n";
    cout<<"\n\t\t\t  1.Add REcords ";
    cout<<"\n\t\t\t  2.List REcords ";
    cout<<"\n\t\t\t  3.Modify REcords ";
    cout<<"\n\t\t\t  4.DElete REcords ";
    cout<<"\n\t\t\t  5.Exit REcords ";
    cout<<"\n\n";
    cout<<"\n\nSelect ur choice   -------> :";

    fflush(stdin);
    choice=getche();
    switch (choice)
    {
        case '1': 
        fseek(fp,0,SEEK_END);
        another ='Y';
        while(another =='Y' || another=='Y')
        {
            system("cls");
            cout<<"ENter the first name";
            cin>>e.first_name;
            cout<<"Enter the last name ";
            cin>>e.last_name;
            cout<<"enter the course";
            cin>>e.course;
            cout<<"enter the batch";
            cin>>e.batch;
            fwrite(&e,recsize,1,fp);
            cout << "\n add another record (Y/N)";
            fflush(stdin);
            another=getchar();
        }
        break;
        case '2':
        system("cls");
        rewind(fp);
        cout<<"===View the record in the database ===";
        cout<<"\n";
        while(fread( &e,recsize,1,fp)==1)
        {
            cout<<"\n";
            cout<<"\n"<< e.first_name << setw(10) << e.last_name;
            cout<<"\n";
            cout<<"\n" <<e.course <<setw(8) << e.batch;
        }
        cout << "\n\n";
        system("pause");
        break;
        case '3':
        system ("cls");
        another ='Y';
        while(another == 'Y' || another == 'y')
        {
            cout << "\n Enter the last name of the student ";
            cin>>xlast_name;

            rewind(fp);
            while ((fread( &e,recsize,1,fp)==1))
            {
                if(strcmp(e.last_name,xlast_name)==0)
                {
                    cout<< "Enter new the first name ";
                    cin>>e.first_name;
                    cout<<"Enter the last name ";
                    cin>>e.last_name;
                    cout<<"enter the course";
                    cin>>e.course;
                    cout<<"enter the batch";
                    cin>>e.batch;
                    fwrite(&e,recsize,1,fp);
                    break;
                }
                else
                cout<<"record not found";
            }
            cout << "\n Modify another record (Y/N)";
            fflush(stdin);
            another=getchar();
        }
        break;

        case '4':
        system("cls");
        another = 'Y';
        while(another=='Y' || another == 'y')
        {
            cout<<"\n enter the last name of the student to delete :";
            cin>>xlast_name;

            ft=fopen("temp.dat","wb");   
            rewind(fp);
            while((fread( &e,recsize,1,fp)==1))
            if (strcmp(e.last_name,xlast_name)!=0)
            {
                fwrite(&e,recsize,1,ft);
                
            }
           fclose(fp);
           fclose(ft);
           remove("user.txt");
           rename("temp.dat","user.txt");

           fp=fopen("user.txt","rb+");
           cout<< "\nDelete another record (Y/n)";
           fflush(stdin);
           another = getchar();
        }
        break;
        case '5':
        fclose(fp);
        cout<<"\n\n";
        cout<<"\t\t thank you";
        cout<<"\n\n";
        exit(0);  


        }
    }
    system("pause");
    return 0;

   }
