#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void drawbord(char *spaces);
void playermove(char *spaces ,char player);
void computermove(char *spaces ,char computer) ;
bool checkwinner(char *spaces ,char player,char computer);
bool checktie(char *spaces );

int main() {
    srand(time(0));
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool runing=true;
    drawbord(spaces);
    while(runing)
    {
      playermove(spaces,player);
      drawbord(spaces);
      if(checkwinner(spaces ,player,computer))
      {
        runing =false;
        break;
      }
      else if(checktie(spaces ))
      {
        runing=false;
        break;
      }
      computermove(spaces, computer);
      drawbord(spaces);
      if(checkwinner(spaces ,player,computer))
      {
        runing =false;
        break;
      }
      else if(checktie(spaces ))
      {
        runing=false;
        break;
      }
    }
    printf("Thanks for playing !\n");
    return 0;
}
void drawbord(char *spaces )
{
  printf("\n");
  printf("     |     |     \n");
  printf(" %c   |  %c  |  %c  \n",spaces[0],spaces[1],spaces[2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf(" %c   |  %c  |  %c  \n",spaces[3],spaces[4],spaces[5]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf(" %c   |  %c  |  %c  \n",spaces[6],spaces[7],spaces[8]);
  printf("     |     |     \n");
  printf("\n");
}
void playermove(char *spaces ,char player)
{
  int number;
  do
  { 
    printf("Enter a spot To place a Marker(1-9):");
    scanf("%d",&number);
    number--;
    if(spaces[number]==' ')
    { 
      spaces[number]=player;
      break;
    }
  }
  while(number<0||number>8|| spaces[number] != ' ');
}
void computermove(char *spaces ,char computer)
{
  int number;
  while(true)
  {
    number=rand()%9;
    if(spaces[number]==' ')
    {
      spaces[number]=computer;
      break;
    }
  }
}
bool checkwinner(char *spaces ,char player,char computer)
{
  if((spaces[0]!=' ')&&(spaces[0]==spaces[1])&&(spaces[1]==spaces[2]))
  {
    spaces[0]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else if((spaces[3]!=' ')&&(spaces[3]==spaces[4])&&(spaces[4]==spaces[5]))
  {
    spaces[3]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else if((spaces[6]!=' ')&&(spaces[6]==spaces[7])&&(spaces[7]==spaces[8]))
  {
    spaces[6]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else if((spaces[0]!=' ')&&(spaces[0]==spaces[3])&&(spaces[3]==spaces[6]))
  {
    spaces[0]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else if((spaces[1]!=' ')&&(spaces[1]==spaces[4])&&(spaces[4]==spaces[7]))
  {
    spaces[1]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else if((spaces[2]!=' ')&&(spaces[2]==spaces[5])&&(spaces[5]==spaces[8]))
  {
    spaces[2]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else if((spaces[0]!=' ')&&(spaces[0]==spaces[4])&&(spaces[4]==spaces[8]))
  {
    spaces[0]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else if((spaces[2]!=' ')&&(spaces[2]==spaces[4])&&(spaces[4]==spaces[6]))
  {
    spaces[2]==player?printf("You win!\n"):printf("You lose!\n");
  }
  else
  {
    return false;
  }
  return true;
}
bool checktie(char *spaces )
{
  for(int i=0;i<9;i++)
  {
    if(spaces[i]==' ')
    {
      return false;
    }
  }
  printf("IT is Tie!\n");
  return true;
}


    