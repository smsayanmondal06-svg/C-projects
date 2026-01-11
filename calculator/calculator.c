#include<stdio.h>
#include<math.h>
double division(double,double);
int modulus(int,int);

void print_menu();
int main(){
     int choice;
     double first,second,result;
    
     while(1){
      print_menu();
     scanf("%d",&choice);
     if(choice == 7){
        break;
     }
     if(choice <1 || choice > 7){
        fprintf(stderr,"Invalid menu choice \n");
        continue;
     }
     printf("please enter the first number :\n");
     scanf("%lf",&first);
     printf("please enter the second number :\n");
     scanf("%lf",&second);

     switch(choice)
     {
        case 1://addition
         result=first+second;
        break;
        case 2://subtract
         result=first-second;
        break;
        case 3://multiply
         result=first*second;
        break;
        case 4://divide
         result= division(first,second);
        break;
        case 5://modulus;
         result=modulus(first,second);
        break;
        case 6://power
         result=pow(first,second);
        break;
        default:
        break;
     }
     if(result != NAN){
     printf("result of operation is : %.2f\n",result);
     }
    };
    return 0;
}
double division(double a,double b){
    if (b==0)
    {
        fprintf(stderr,"Invalid Argument for Division");
        return NAN;
    }  
    else{
        return a/b;
    }
}
int modulus(int a,int b){
    if (b==0)
    {
        fprintf(stderr,"Invalid Argument for modulus");
        return NAN;
    }  
    else{
        return a/b;
    }
}
void print_menu(){
    printf("----------------------------\n");
    printf("welcome to simple calculator : \n");
    printf("choose one of the following options :\n");
    printf("1. addition\n");
    printf("2. subtract\n");
    printf("3. multipy\n");
    printf("4. divide\n");
    printf("5. modulus\n");
    printf("6. power\n");
    printf("7. exit\n");
    printf("now enter your choice : \n");
}