#include<stdio.h>
#include<stdlib.h>
#include"board.h"

static char board[7][44] = { // char *board[7] 안에 있는 내용 수정할땐 xx
    "------------------------------------------",  //0
    "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  |",  //1
    "------------------------------------------",  //2
    "| | | | | | | | | | | | | | | | | | | | | |", //3
    "------------------------------------------",  //4
    "|   |   |   |   |   |   |   |   |   |     |", //5
    "------------------------------------------"
};


void setScore (int frame, int cast, int score){
    // board[3][???] = [0-9] or '/', 'x'  //int score -->char
    //int i = 0;
    //while (board[1][i] != frame + '0') ++i;
    char c;
    if(cast != 1 && (cast_int(frame, 1)) + score == 10){
        c = 47; // "/"
    }else if(cast == 1 && score == 10 || frame == 10 && score == 10){
        c = 120;    // "x"
    }else{
        c = score +     '0';
    }
    board[3][4 * (frame-1) + 2*cast - 1] = c;
}

void setFrameScore(int frame, int frameScore){
    // board[5] 
    char buf[10];
    sprintf(buf, "%3d", frameScore);
    for(int i = 1; i <= 3; ++i){
        board[5][4*(frame-1)+i] = buf[i-1];
    }// == strncpy(&board[5][0] + 4*(frame-1) + 1, buf, 3);
}

int cast_int(int frame, int cast){
    return board[3][4 * (frame-1) + 2*cast - 1] - '0';
}

void printBoard(void){
    system("clear");
    for(int i = 0; i < 7; ++i){
        printf("%s\n", board[i]); // board[i][0];
    }
}

