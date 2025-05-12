#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void display_board(char**);
void display_current_board(char**);
void choose(int,int*,int*);
void check_win(char**,int*,int*);
int main(){
    char **board,*player1_name=malloc(30*sizeof(char)),*player2_name=malloc(30*sizeof(char));
    int chances=0,player_choice=0,box=0,*r=malloc(sizeof(int)),*c=malloc(sizeof(int)),*f_X=malloc(sizeof(int)),*f_O=malloc(sizeof(int));
    *f_O=*f_X=0;
    board=(char**)malloc(3*sizeof(int));
    for(int i=0;i<3;i++){
        board[i]=(char*)malloc(3*sizeof(int));
        for(int j=0;j<3;j++)
            board[i][j]='.';
    }
    printf("**PLAYER 1 WILL START FROM 'X'\n");
    printf("Enter Player 1 Name : ");
    fgets(player1_name,30,stdin);
    printf("Enter Player 2 Name : ");
    fgets(player2_name,30,stdin);
    player1_name[strlen(player1_name)-1]='\0';
    player2_name[strlen(player2_name)-1]='\0';
    printf("Player 1 Name: %s\n",player1_name);
    printf("Player 2 Name: %s\ns",player2_name);
    printf("Board Currently is:\n");
    display_board(board);
    printf("****GAME BEGINS****\n");
    for(chances=0;chances<9;chances++){
        display_current_board(board);
        if(chances%2==0){
            printf("%s your chance: ",player1_name);
            scanf("%d",&box);
            choose(box,r,c);
            if(board[*r][*c]=='.')
                board[*r][*c]='X';
            else{
                printf("Box Already Acquired\n");
                chances--;
            }
        }
        else if(chances%2!=0){
            printf("%s your chance: ",player2_name);
            scanf("%d",&box);
            choose(box,r,c);
            if(board[*r][*c]=='.')
                board[*r][*c]='O';
            else{
                printf("Box Already Acquired\n");
                chances--;
            }
        }
        if(chances>=4){
            check_win(board,f_X,f_O);
            if(*f_X==1){
                printf("%s WON!!\n",player1_name);
                return 0;
            }
            else if(*f_O==1){
                printf("%s WON!!\n",player2_name);
                return 0;
            }
        }
    }
    printf("Game Tied!!!\n");
    free(board);
    free(player1_name);
    free(player2_name);
    free(r);
    free(c);
}
void display_board(char **board){
    printf("This is the board right now:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%c\t",board[i][j]);
        printf("\n");
    }
}
void display_current_board(char **board){
    int count=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='.')
                printf("%d\t",count);
            else
                printf("%c\t",board[i][j]);
            count++;
        }
        printf("\n");
    }
}
void choose(int box,int* r,int* c){
    switch(box){
        case 1:*r=0,*c=0; break;
        case 2:*r=0,*c=1; break;
        case 3:*r=0,*c=2; break;
        case 4:*r=1,*c=0; break;
        case 5:*r=1,*c=1; break;
        case 6:*r=1,*c=2; break;
        case 7:*r=2,*c=0; break;
        case 8:*r=2,*c=1; break;
        case 9:*r=2,*c=2; break;
        default:printf("Please Enter Valid Choice:\n"); break;
    }
}
void check_win(char** board,int* f_X,int* f_O){
    int count_x_x=0,count_x_y=0,count_o_x=0,count_o_y=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='X')
                count_x_x++;
            if(board[j][i]=='X')
                count_x_y++;
            if(board[i][j]=='O')
                count_o_x++;
            if(board[j][i]=='O')
                count_o_y++;
            if(count_x_y==3 || count_x_x==3)
                *f_X=1;
            else if(count_o_x==3 || count_o_y==3)
                *f_O=1;
        }
        count_o_y=count_o_x=count_x_x=count_x_y=0;
    }
    if((board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') || (board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X'))
        *f_X=1;
    if((board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O') || (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O'))
        *f_O=1;
}   
