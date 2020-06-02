#include <stdio.h>
#include <stdlib.h>

//A C program to place an X on a 10x10 grid of dashes, and move X as per user's choice


//make cordinates globally accessible 
int num1,num2,i,j;

//display grid
void showGrid(int k,int m){
  for(i=1;i<=10;i++){
  //outer loop prints rows

   for(j=10;j<20;j++){
     //inner loop to print columns
     if(i==num1&&j==10+num2-1){//determine when cordinates are arrived, print X
       printf("X");
     }else{
       printf("-");//if cordinates don't match, print a dash
     }
   }
   printf("\n");
 }
}


//use this function to decide what to do with X if off-grid
int displayOptions(){
  printf("reached end of grid. Choose an option \n 1. Don't move X \n 2. Move X to opposite side \n");
  int choice;
  scanf(" %d",&choice);
  choice -=0; //convert char to int by subtractig 0
  if(choice==1){
    return 0;//use value 0 to retain the position of x
  }else if(choice==2){
    return 1;//use 1 to move X to opposite side
  }else{
    printf("invalid choice, will retain cordinates.");
  }
  return 0;
}

//declare a function to decide new x-cordinate of X
int gridX(int a){
  
  if(a-1<1){
    int action=displayOptions();
    if(action==0){
      //preserve cordinates of X
      return 0;
    }else if(action==1){
      //move X to opposite side
      num2+=9;
    }
  }else if(a+1>10){
    int action=displayOptions();
    //skip action==0 since it won't change cordinates
    if(action==1){
       num2-=9;
    }
   
  }
  return 0;
}//End of x-cord' check

//declare a function to decide new y-cordinate of X
int gridY(int a){
  //start grid-y
  if(a-1<1){
    int action=displayOptions();
    if(action==0){
      //preserve cordinates of X
      return 0;
    }else if(action==1){
      //move X to opposite side
      num1+=9;
    }
  }else if(a+1>10){
    int action=displayOptions();
    //skip action==0 since it won't change cordinates
    if(action==1){
       num1-=9;
    }
   
  }
  //end grid-y
  return 0;
}


//Function to Move X
void moveX(char mover){

 switch(mover){
   //use OR operator | to accept lower and uppercase letters
   case 'w'|'W':
   //change y cordinate by -1
   if(num1-1!=0){
      num1-=1;//if within grid, set new cordinate
   }else{
     gridY(num1); //if off grid, decide new cordinate
   }
  
      //Reprint grid
      for(i=1;i<=10;i++){
      //outer loop prints rows

      for(j=10;j<20;j++){
        //inner loop to print columns
        if(i==num1&&j==10+num2-1){//determine when cordinates are arrived, print X
          printf("X");
        }else{
          printf("-");//if cordinates don't match, print a dash
        }
      }
      printf("\n");
    }
   break;
   case 'a'|'A':
   //change x cordinate by -1
   if(num2-1>10){
     num2-=1;//within grid
     }else{
       gridX(num2);//off-grid
     }
      //Reprint grid
      for(i=1;i<=10;i++){
      //outer loop prints rows

      for(j=10;j<20;j++){
        //inner loop to print columns
        if(i==num1&&j==10+num2-1){//determine when cordinates are arrived, print X
          printf("X");
        }else{
          printf("-");//if cordinates don't match, print a dash
        }
      }
      printf("\n");
    }
   break;
   case 's'|'S':
   //change y cordinate by +1
   if(num1+1<10){
     num1+=1;   
   }else{
     gridY(num1);
   }
   //Reprint grid
      for(i=1;i<=10;i++){
      //outer loop prints rows

      for(j=10;j<20;j++){
        //inner loop to print columns
        if(i==num1&&j==10+num2-1){//determine when cordinates are arrived, print X
          printf("X");
        }else{
          printf("-");//if cordinates don't match, print a dash
        }
      }
      printf("\n");
    }
   break;
   case 'd'|'D':
   //change x cordinate by +1
   if(num2+1<10){
     num2+=1;
     }else{
       gridX(num2);
     }
      //Reprint grid
      for(i=1;i<=10;i++){
      //outer loop prints rows

      for(j=10;j<20;j++){
        //inner loop to print columns
        if(i==num1&&j==10+num2-1){//determine when cordinates are arrived, print X
          printf("X");
        }else{
          printf("-");//if cordinates don't match, print a dash
        }
      }
      printf("\n");
    }
   break;
   case 'x'|'X':
   //Exit program
   exit(0);
   break;
   default:
   printf("Sorry, you entered the wrong letter");
   break;
 }
}

//main function
int main(void) {

printf("Enter a x-cordinate between 1 and 10 :");
scanf("%d",&num1);
printf("Enter a y-cordinate between 1 and 10 :");
scanf("%d",&num2);

 //print grid
 showGrid(num1,num2);

 //Move X
 char mover; //hold the character
 printf("Enter a character (among[w, a, s, d, x]) :");
 scanf(" %c",&mover); //space before %c prevents compiler from skipping user input
 
 //function call to move x
moveX(mover);

  return 0;
}