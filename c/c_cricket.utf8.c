#include<stdio.h>
int main()
{
    int user,cpu,wicket=0,scoreu=0,scorec=0,ball=1;
    printf("Welcome to C cricket!\n\n");
    printf("Rules:\nYou are batting and chasing the given target. you can score runs by entering either 0,1,2,3,4,5,6. if your entered value matches with the value of cpu, then you are out! Else you score that many runs. You have 10 wickets in hand and the match will be of 5 overs only.\n\n\n");

    srand(time(NULL));
    scorec=rand()%60 + 40;
    printf("Target: %d\n", scorec);
    for(;;)
    {
        printf("ball %d\n", ball);
        printf("Your turn: ");
        scanf("%d", &user);
        if(user>6 || user<0)
        {
            printf("invalid input. Try again\n");
            continue;
        }
        srand(time(NULL));
        cpu=rand()%6;
        if(user==6 || user==5)
        {
            cpu=rand()%2 + 5;
        }
        if(user==4 || user==3)
        {
            cpu=rand()%3 + 3;
        }
        if(user==2)
        {
            cpu=rand()%4;
        }
        if(user==cpu)
        {
            printf("You are out!\n");
            wicket++;
        }
        if(user!=cpu)
        {
            if(user==4)
                printf("Its a four!\n");
            if(user==6)
                printf("Its a six!\n");
            scoreu=scoreu+user;
        }
        if(wicket==10)
        {
            printf("You are all out!\n");
            printf("Your score: %d/%d\n",scoreu,wicket);
            if(scoreu<scorec)
                printf("You lose!\n");
            if(scoreu==scorec)
                printf("Its a draw!\n");
            break;
        }
        printf("User %d/%d\n", scoreu,wicket);
        ball++;
        if(ball==31)
        {
            printf("Innings over!\nYour score : %d/%d\n", scoreu,wicket);
            if(scoreu<scorec)
                printf("You lose!\n");
            if(scoreu==scorec)
                printf("Its a draw!\n");
            break;
        }
        if(scoreu>scorec)
        {
            printf("You win!\n");
            break;
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    return 0;
}
