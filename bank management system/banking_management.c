#include<stdio.h>
#include<string.h>

void create_account();
void deposit_money();
void withdraw_money();
void checck_balance();

const char* Account_FILE="account.dat";
typedef struct{
    char name[50];
    int acc_no;
    float balance;
} Account;

int main(){

    while(1){
        int choice;
        printf("*** Bank Management System ***\n");
        printf("1. create Account\n");
        printf("2. deposit money\n");
        printf("3. withdraw money\n");
        printf("4. check balance\n");
        printf("5. exit\n");
        printf("enter your choice: \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
           create_account();
            break;
        case 2:
            deposit_money();
            break;
        case 3:
            withdraw_money();
            break;
        case 4:
            checck_balance();
            break;
        case 5:
            printf("Closing the bank.\n");
            return 0;
            break;
        default:
        printf("Invalid choice\n");
            break;
        }
    }
}
void create_account(){
   Account acc;
   FILE *file=  fopen(Account_FILE,"ab+");
   if (file==NULL)
   {
    printf("unable to open file!!\n");
    return;
   }
   char c;
   do
   {
    c = getchar();
   } while (c != '\n' && c!=EOF);
   
   printf("enter your namee: \n");
   fgets(acc.name,sizeof(acc.name),stdin);
   int ind= strcspn(acc.name,"\n");
   acc.name[ind]='\0';
   printf("Enter your account number: \n");
   scanf("%d",&acc.acc_no);
   acc.balance=0;
  
   fwrite(&acc,sizeof(acc),1,file);
   fclose(file);
   printf("Account created successfully!");
}

void deposit_money(){
 FILE*file= fopen(Account_FILE,"rb+");
 if (file==NULL)
   {
    printf("unable to open file!!\n");
    return;
   }
   int acc_no;
   float money;
   Account acc_r;
   printf("Enter your account number:");
   scanf("%d",&acc_no);
   printf("enter amount to deposit:");
   scanf("%f",&money);
   
   while(fread(&acc_r,sizeof(acc_no),1,file)){
     if (acc_r.acc_no==acc_no)
     {
        acc_r.balance  += money;
        fseek(file,-sizeof(acc_r),SEEK_CUR);
        fwrite(&acc_r,sizeof(acc_r),1,file);
        fclose(file);
        printf("successfully deposited Rs.%.2f New balance is Rs.%.2f\n",money,acc_r.balance);
        return;
     }
     
   }
  fclose(file);
  printf("Money could not be deposited as the account no %d was not found in records.\n",acc_no);
}
void withdraw_money(){
 FILE*file= fopen(Account_FILE,"rb+");
 if (file==NULL)
 {
    printf("unable to open file!!\n");
    return;
 }
 int acc_no;
 float money;
 Account acc_r;
 printf("enter your account number:");
 scanf("%d",&acc_no);
 printf("enter the amount you wish to withdraw");
 scanf("%f",&money);
 while(fread(&acc_r,sizeof(acc_r),1,file)){
   if(acc_r.acc_no == acc_no){
    if(acc_r.balance>=money){
        acc_r.balance -= money;
        fseek(file,-sizeof(acc_r),SEEK_CUR);
        fwrite(&acc_r,sizeof(acc_r),1,file);
        printf("successfully withdrawn Rs.%.2f remaining balance is Rs.%.2f",money,acc_r.balance);

    }else{
        printf("Insufficient balance");
    }
    fclose(file);
    return;
   }
 }
 fclose(file);
  printf("Money could not be withdrawn as the account no %d was not found in records.\n",acc_no);
}
void checck_balance(){
    FILE *file=  fopen(Account_FILE,"rb");
    if (file==NULL)
   {
    printf("unable to open file!!\n");
    return;
   }
    int acc_no;
    Account acc_read;
   printf("Enter your account number: \n");
   scanf("%d",&acc_no);
   
   while(fread(&acc_read,sizeof(acc_read),1,file)){
    if (acc_read.acc_no == acc_no)
    {
        printf("your current balance is Rs .%.2f\n",acc_read.balance);
        fclose(file);
        return;
    }
    fclose(file);
   }
   printf("Account No :%d was not found.\n",acc_no);
}