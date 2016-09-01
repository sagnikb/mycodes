#include<stdio.h>
#include<stdlib.h>

void Iplay(int, int);
void youPlay(int);

void Iplay(int sticks, int youpicked){
		if(sticks  ==  0){
				printf("You lose! Please restart this game to try again. Also, goodbye if you are bored! :P\n");
		}
		else{
			int number = 5 - youpicked;
			printf("I pick %d sticks.\n", number);
			youPlay(sticks - number);
		}		
}

void youPlay(int sticks){
		if(sticks == 0){
				printf("You win! To claim the surprise, please enter y :P");
		}
		else{
				printf("It is your turn and there are %d sticks left.\n", sticks);
				printf("Please enter the number of sticks you want to pick up: ");
				int number;
				scanf("%d", &number);
				while((number > 4)||(number >	{
						printf("The number needs to be among 1, 2, 3 and 4! Please try again :\).");
						printf("Please enter the number of sticks you want to pick up: ");
						scanf("%d", &number);
				}
				Iplay(sticks - number, number);
		}
}
		
int main(){
		printf("Hello, welcome to this rather pointless game. Defeat the game for a nice surprise at the end.\n");
		printf("The objective of the game is simple. There are 26 sticks. I take one turn, you take the other turn, in each round.\n");
		printf("You have to pick at least one stick, but less than or equal to foir sticks. The same rules apply to me, and none of us are allowed to pass a turn.\n");
		printf("The person who picks up the last stick loses! (I assume that you didn't see that coming, and also that the previous assumption is incorrect :P.\n");
		youPlay(26);
		return 0;
}
