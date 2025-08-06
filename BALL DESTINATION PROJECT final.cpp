# include "iGraphics.h"
#include <stdlib.h>
#include <time.h>



void game_page();
void home_page();
void maze();
int x=325,y=25;
int dx=2;
int dy=2;
int p=0;
int q=0;
int dp=2;
int dq=2;
int l=0;
int hit(int a, int b);
int i;
int mon1x=201;
int mon1y=251;
int m1=1;
int m2=2;
int m3=1;
int m4=3;
int m5=0;
int mon2x=101;
int mon2y=551;
int mon3x=351;
int mon3y=301;
int mon4x=551;
int mon4y=201;
int mon5x=51;
int mon5y=101;
int h1=0;
int h2=0;
int h3=0;
int h4=0;
int h5=0;
int numb=0;
int page_control=0;
int random();
int monsterdir1();
int monsterdir2();
int monsterdir3();
int monsterdir4();
int monsterdir5();
int horizontal;
int vertical;
int life = 6;
int mtime=0;
char TIME[20];
int game=-1;
int touch=0;
typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} MAZE;
MAZE mazeAr[500];


void readScoreboard();
void appendScoreboard();
void showScoreboard();
void sortScoreboard();
int nmb=0;
int index=0;
char player_name[300];
char result[1000];



struct highscore
{
    char name[300];
    int score;
} highscore[10000];



bool musicOn=true;

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    // if(musicOn)
    // PlaySound("game_music.wav",NULL,SND_ASYNC|SND_LOOP);




    //place your drawing codes here
    iClear();
    iSetColor(255,255,255);


    if(page_control==0 )
    {

        iShowBMP(0,0,"game_name.bmp");
    }


    if(page_control==1 )
    {
        iShowBMP(0,0,"intro_page.bmp");
    }


    if(page_control==2)
    {
        if(touch==0)
            iShowBMP(0,0,"ghost41.bmp");



        if(touch==1)
            iShowBMP(0,0,"ghost23.bmp");


        if(touch==2)
            iShowBMP(0,0,"bg11.bmp");

        if(touch==3)
            iShowBMP(0,0,"bg12.bmp");


        if(touch==4)
            iShowBMP(0,0,"ghost70.bmp");



        if(touch==5)
            iShowBMP(0,0,"ghost90.bmp");





        maze();
        iText(302, 0, "Start", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(251, 580, "Finish", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(10, 620, TIME, GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(200, 00, 055);
        iFilledCircle(x, y, 10);
        iShowBMP(mon1x, mon1y,"voot1.bmp");
        iShowBMP(mon2x, mon2y,"Untitled-11.bmp");
        iShowBMP(mon3x, mon3y,"Untitled-11.bmp");
        iShowBMP(mon4x, mon4y,"Untitled-11.bmp");
        iShowBMP(mon5x, mon5y,"Untitled-11.bmp");
        if(life==1)
        {
            iShowBMP(470, 620, "life-1.bmp");
        }
        if(life==2)
        {
            iShowBMP(470, 620, "life-2.bmp");
        }
        if(life==3)
        {
            iShowBMP(470, 620, "life-3.bmp");
        }
        if(life==4)
        {
            iShowBMP(470, 620, "life-4.bmp");
        }
        if(life==5)
        {
            iShowBMP(470, 620, "life-5.bmp");
        }
        if(life==6)
        {
            iShowBMP(470, 620, "life-6.bmp");
        }
        if(life==0)
        {
            page_control=6;
            l=0;
        }


    }

    if(page_control==6)
    {
        iShowBMP(0, 0, "lost_game.bmp");
        iSetColor(0,0,0);
        iText(126, 477, TIME, GLUT_BITMAP_TIMES_ROMAN_24);


    }




    if(page_control==5)
    {
        iSetColor(0,0,0);
        iShowBMP(0, 0, "score41.bmp");
        iText(232, 510,TIME, GLUT_BITMAP_TIMES_ROMAN_24);
        life=6;
        iText(300,400,player_name,GLUT_BITMAP_TIMES_ROMAN_24);
    }


    if(page_control==4)
    {
        iShowBMP(0,0,"score22.bmp");
        showScoreboard();
    }

    if(page_control==3)
    {
        iShowBMP(0,0,"help_page.bmp");
    }



    if(page_control==7)
    {
        iShowBMP(0,0,"about_page.bmp");
    }


    if(page_control==8)
    {
        iShowBMP(0,0,"help_page2.bmp");
    }


}


void maze()
{
    int f;
    for(f=0; f<i; f++)
    {
        iLine(mazeAr[f].x1, mazeAr[f].y1, mazeAr[f].x2, mazeAr[f].y2);
    }
    iSetColor(255, 255, 255);

}


void change()
{
    if(l==1)
    {
        y=y+5;
    }
    else if(l==2)
    {
        y=y-5;
    }
    else if(l==3)
    {
        x=x+5;
    }
    else if(l==4)
    {
        x=x-5;
    }
    else if(l==0)
    {
        x=x;
        y=y;
    }

    if(hit(x,y)==1)
    {
        if(l==1)
        {
            y=y-5;
            x=x;
            l=0;
        }
        else if(l==2)
        {
            y=y+5;
            x=x;
            l=0;
        }
        else if(l==3)
        {
            y=y;
            x=x-5;
            l=0;
        }
        else if(l==4)
        {
            y=y;
            x=x+5;
            l=0;
        }
    }

    if(l != 0)
    {
        mtime=mtime+20;
        sprintf(TIME, "TIME %d: %d", mtime/1000, mtime%1000);


        if(numb%50==0)
        {
            m1 = monsterdir1();
            m2 = monsterdir2();
            m3 = monsterdir3();
            m4 = monsterdir4();
            m5 = monsterdir5();
            numb=0;
        }

        if(m1==0)
        {
            mon1x = mon1x + 5;
            mon1y = mon1y;
        }
        else if(m1==2)
        {
            mon1x = mon1x - 5;
            mon1y = mon1y;
        }
        else if(m1==1)
        {
            mon1x = mon1x;
            mon1y = mon1y + 5;
        }
        else if(m1==3)
        {
            mon1x = mon1x;
            mon1y = mon1y - 5;
        }


        if(m2==0)
        {
            mon2x = mon2x + 5;
            mon2y = mon2y;
        }
        else if(m2==2)
        {
            mon2x = mon2x - 5;
            mon2y = mon2y;
        }
        else if(m2==1)
        {
            mon2x = mon2x;
            mon2y = mon2y + 5;
        }
        else if(m2==3)
        {
            mon2x = mon2x;
            mon2y = mon2y - 5;
        }

        if(m3==0)
        {
            mon3x = mon3x + 5;
            mon3y = mon3y;
        }
        else if(m3==2)
        {
            mon3x = mon3x - 5;
            mon3y = mon3y;
        }
        else if(m3==1)
        {
            mon3x = mon3x;
            mon3y = mon3y + 5;
        }
        else if(m3==3)
        {
            mon3x = mon3x;
            mon3y = mon3y - 5;
        }


        if(m4==0)
        {
            mon4x = mon4x + 5;
            mon4y = mon4y;
        }
        else if(m4==2)
        {
            mon4x = mon4x - 5;
            mon4y = mon4y;
        }
        else if(m4==1)
        {
            mon4x = mon4x;
            mon4y = mon4y + 5;
        }
        else if(m4==3)
        {
            mon4x = mon4x;
            mon4y = mon4y - 5;
        }



        if(m5==0)
        {
            mon5x = mon5x + 5;
            mon5y = mon5y;
        }
        else if(m5==2)
        {
            mon5x = mon5x - 5;
            mon5y = mon5y;
        }
        else if(m5==1)
        {
            mon5x = mon5x;
            mon5y = mon5y + 5;
        }
        else if(m5==3)
        {
            mon5x = mon5x;
            mon5y = mon5y - 5;
        }
        numb=numb+5;

    }
}

int random1()
{
    int f;
    time_t t;
    srand((unsigned) time(&t));
    f=rand();
    return f;
}
int random2()
{
    int f;
    time_t t;
    srand((unsigned) time(&t));
    f=rand();
    return f;
}


int monsterdir1()
{
    int k, p;
    k=rand()%4;
    if(k==0)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon1x+49==mazeAr[p].x1 && mon1y>mazeAr[p].y1 && mon1y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==2)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon1x-1==mazeAr[p].x1 && mon1y>mazeAr[p].y1 && mon1y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==1)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon1y+49==mazeAr[p].y1 && mon1x>mazeAr[p].x1 && mon1x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    if(k==3)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon1y-1==mazeAr[p].y1 && mon1x>mazeAr[p].x1 && mon1x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(mon1y-1==100 && mon1x>200 && mon1x+48<250)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    monsterdir1();


}
int monsterdir2()
{
    int k, p;
    k=rand()%4;
    if(k==0)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon2x+49==mazeAr[p].x1 && mon2y>mazeAr[p].y1 && mon2y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==2)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon2x-1==mazeAr[p].x1 && mon2y>mazeAr[p].y1 && mon2y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==1)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon2y+49==mazeAr[p].y1 && mon2x>mazeAr[p].x1 && mon2x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    if(k==3)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon2y-1==mazeAr[p].y1 && mon2x>mazeAr[p].x1 && mon2x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(mon2y-1==100 && mon2x>200 && mon2x+48<250)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    monsterdir2();


}

int monsterdir3()
{
    int k, p;
    k=rand()%4;
    if(k==0)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon3x+49==mazeAr[p].x1 && mon3y>mazeAr[p].y1 && mon3y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==2)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon3x-1==mazeAr[p].x1 && mon3y>mazeAr[p].y1 && mon3y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==1)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon3y+49==mazeAr[p].y1 && mon3x>mazeAr[p].x1 && mon3x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    if(k==3)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon3y-1==mazeAr[p].y1 && mon3x>mazeAr[p].x1 && mon3x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(mon3y-1==100 && mon3x>200 && mon3x+48<250)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    monsterdir3();


}

int monsterdir4()
{
    int k, p;
    k=rand()%4;
    if(k==0)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon4x+49==mazeAr[p].x1 && mon4y>mazeAr[p].y1 && mon4y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==2)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon4x-1==mazeAr[p].x1 && mon4y>mazeAr[p].y1 && mon4y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==1)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon4y+49==mazeAr[p].y1 && mon4x>mazeAr[p].x1 && mon4x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    if(k==3)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon4y-1==mazeAr[p].y1 && mon4x>mazeAr[p].x1 && mon4x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(mon4y-1==100 && mon4x>200 && mon4x+48<250)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    monsterdir4();


}

int monsterdir5()
{
    int k, p;
    k=rand()%4;
    if(k==0)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon5x+49==mazeAr[p].x1 && mon5y>mazeAr[p].y1 && mon5y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==2)
    {
        for(p=horizontal; p<=i; p++)
        {
            if(mon5x-1==mazeAr[p].x1 && mon5y>mazeAr[p].y1 && mon5y+48<mazeAr[p].y2)
            {
                break;
            }
            else if(p==i)
            {
                return k;
            }

        }
    }
    if(k==1)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon5y+49==mazeAr[p].y1 && mon5x>mazeAr[p].x1 && mon5x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    if(k==3)
    {
        for(p=0; p<=horizontal; p++)
        {
            if(mon5y-1==mazeAr[p].y1 && mon5x>mazeAr[p].x1 && mon5x+48<mazeAr[p].x2)
            {
                break;
            }
            else if(mon5y-1==100 && mon5x>200 && mon5x+48<250)
            {
                break;
            }
            else if(p==horizontal)
            {
                return k;
            }

        }
    }
    monsterdir5();


}

int hit(int a, int b)
{
    int k;
    for(k=0; k<i; k++)
    {
        if(x>= (mazeAr[k].x1-9) && y>= (mazeAr[k].y1 -9) && x<= (mazeAr[k].x2 +9) && y<=(mazeAr[k].y2 +9))
        {
            life= life-1;
            return 1;
        }
    }
    if(x>=mon1x && x<=mon1x+48 && y>=mon1y && y<=mon1y+48)
    {
        touch=1;
        x=325;
        y=25;
        life= life-1;
        return 1;
    }
    if(x>=mon2x && x<=mon2x+48 && y>=mon2y && y<=mon2y+48)
    {
        touch=2;
        x=325;
        y=25;
        life= life-1;
        return 1;
    }
    if(x>=mon3x && x<=mon3x+48 && y>=mon3y && y<=mon3y+48)
    {
        touch=3;
        x=325;
        y=25;
        life= life-1;
        return 1;
    }
    if(x>=mon4x && x<=mon4x+48 && y>=mon4y && y<=mon4y+48)
    {
        touch=4;
        x=325;
        y=25;
        life= life-1;
        return 1;
    }
    if(x>=mon5x && x<=mon5x+48 && y>=mon5y && y<=mon5y+48)
    {
        touch=5;
        x=325;
        y=25;
        life= life-1;
        return 1;
    }
    if(x+5>=250 && x-5<=300 && y+20>=600)
    {
        page_control=5;
        x=325;
        y=25;
        return 1;
    }

    return 0;
}



//Codes for score

void readScoreboard()
{
    FILE *fp;
    fp = fopen("nmb.txt","r");

    fscanf(fp, "%d",&nmb);
    fclose(fp);
    fp=fopen("score.txt","r");
    for (int i=0; i<nmb; i++)
    {
        fscanf(fp,"%s %d",&highscore[i].name,&highscore[i].score);
    }
    fclose(fp);
}


void appendScoreboard()
{
    FILE *fp;
    fp = fopen("score.txt", "a");
    fprintf(fp,"%s %d", highscore[0].name,highscore[0].score);
    fprintf(fp,"\n");
    fclose(fp);
    fp=fopen("nmb.txt","r");
    fscanf(fp,"%d",&nmb);
    fclose(fp);
    fp=fopen("nmb.txt","w");
    fprintf(fp,"%d",++nmb);
    fclose(fp);

}


void sortScoreboard()
{
    for (int i=0; i<nmb-1; i++)
    {
        for (int j=i+1; j<nmb; j++)
        {
            if (highscore[i].score > highscore[j].score)
            {
                int temp;
                temp = highscore[i].score;
                highscore[i].score = highscore[j].score;
                highscore[j].score = temp;
                char player_name[100];
                strcpy(player_name, highscore[i].name);
                strcpy(highscore[i].name, highscore[j].name);
                strcpy(highscore[j].name, player_name);
            }
        }
    }
}


void showScoreboard()
{
    int position = 290, times;;
    if(nmb>=3)
    {
        nmb=3;
    }
    for (int i=0; i<nmb; i++,position -= 70)
    {
        char player[100];

        sprintf(player,"%d : %d", highscore[i].score/1000, highscore[i].score%1000);

        iSetColor(0,0,0);

        iText(107, position, highscore[i].name, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(250, position, player, GLUT_BITMAP_TIMES_ROMAN_24);

    }


}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{
    // printf("x = %d, y= %d\n",mx,my);
    //place your codes here
    //x=mx-0;
    // y=my-0;
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    /*if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        x += 5;
        y += 5;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 5;
        y -= 5;
    }*/

    if((mx>=484 && mx<=586) && (my>=32 && my<=90) && page_control==0)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=1;
        }

    }

    /*game name page>page control=0
    intro page>page control=1
    game start >page control=2
    help page>page control=3
    help page 2 page control 8
    about page page control 7

    result page>page control=4
    congratulations page page control =5
    lost page page control 6



    */
    if((mx>=112 && mx<=395) && (my>=496 && my<=562) && (page_control==1))
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=2;
        }

    }




    if((mx>=112&& mx<=395) && (my>=307&& my<=372) && page_control==1)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=3;
        }

    }
//help page 1 to help page 2

    if((mx>=453&& mx<=600) && (my>=15&& my<=95) && page_control==3)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=8;
        }

    }


//back from help page 2 to help page 1

    //back from help page 1 to intro page
    if((mx>=3&& mx<=160) && (my>=14&& my<=99) && page_control==3)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=1;
        }

    }


    //page_control 7=about_page

    if((mx>=122&& mx<=400) && (my>=126&& my<=197) && page_control==1)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=7;
        }

    }



    if((mx>=23&& mx<=128) && (my>=36&& my<=92) && page_control==7)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=1;
        }

    }
    //back from help page 2 to 1

    if((mx>=22&& mx<=178) && (my>=17&& my<=90) && page_control==8)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=3;
        }

    }












//music

    if(page_control==1)
    {

        if((mx>=467&& mx<=566) && (my>=203&& my<=278))
        {
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                musicOn=false;
                if(!musicOn)
                {
                    PlaySound(0,0,0);
                }
            }

        }


        if((mx>=467&& mx<=566) && (my>=75&& my<=150))
        {
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                musicOn=true;
                if(musicOn)
                {
                    PlaySound("game_music.wav",NULL,SND_ASYNC|SND_LOOP);
                }
            }

        }


        if(mx>=112  &&  mx<=395  && my>=400  && my <=465 )
        {
            if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                readScoreboard();
                sortScoreboard();
                page_control=4;

            }
        }
    }

//back from score
    if(page_control==4 && mx>= 164 &&  mx<= 340 && my>= 17 && my <=97 )
    {

        page_control=1;
    }


//end page and back from end page
    if((page_control==5)&&(mx>=115&& mx<=493) && (my>=165&& my<=250))
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {


            strcpy(highscore[0].name,player_name);
            highscore[0].score=mtime;
            //updateleaderboard();
            appendScoreboard();
            page_control=2;
            x=325;
            y=25;
            mtime=0;
        }

    }


    if((mx>=115&& mx<=493) && (my>=55&& my<=120) && (page_control==5))
    {

        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            strcpy(highscore[0].name,player_name);
            highscore[0].score=mtime;
            //updateleaderboard();


            appendScoreboard();
            page_control=1;
            x=325;
            y=25;
            mtime=0;
        }

    }

//back from lost page


    if((mx>=80&& mx<=523) && (my>=225&& my<=320) && (page_control==6) )
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=2;
            x=325;
            y=25;
            life=6;
            mtime=0;
        }

    }




    if((mx>=80&& mx<=530) && (my>=100&& my<=182) && page_control==6)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            page_control=1;
            x=325;
            y=25;
            life=6;
            mtime=0;
        }

    }





    if((mx>=112 && mx<=395) && (my>=223 && my<=288) && (page_control==1))
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            exit(0);
        }

    }


}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    if(key == 'b' && life == 0)
    {
        x=325;
        y=25;
        page_control = 1;
        life=6;
        mtime=0;

    }

    if(key == 'n' && life == 0)
    {
        x=325;
        y=25;
        page_control = 2;
        life=6;
        mtime=0;

    }

    if(key=='b' && page_control==2)
    {
        page_control=1;
        // x=325;
        // y=25;
    }

    if(key=='n' && page_control==1)
    {
        page_control=2;
    }

    if(key=='n' && page_control==0)
    {
        page_control=1;
    }



    if(key=='b' && page_control==6)
    {
        x=325;
        y=25;
        page_control=1;
    }


    //player er name input neyar jnno

    if(page_control==5)
    {

        //appendScoreboard();

        if(key!='\b')
        {
            player_name[index]=key;
            player_name[index+1]='\0';
            index++;

        }
        else
        {
            if(index >= 0)
            {
                player_name[index]='\0';
                index--;
                if(index <0)
                {
                    index=0;
                }
            }
        }

//iText(300,400,player_name,GLUT_BITMAP_TIMES_ROMAN_24);



    }



}


void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
    else if(key == GLUT_KEY_UP)
    {
        l=1;
    }
    else if(key == GLUT_KEY_DOWN )
    {

        l=2;
    }
    else if(key == GLUT_KEY_RIGHT )
    {

        l=3;
    }
    else if(key == GLUT_KEY_LEFT )
    {
        l=4;
    }

}


int main()
{
    int f, m1, n;
    FILE *maze;
    char *in_file = "maze.txt";
    maze = fopen(in_file, "r");
    fscanf(maze, "%d", &horizontal);
    for(f=0; f<horizontal; f++)
    {
        fscanf(maze, "%d %d %d %d", &mazeAr[f].x1, &mazeAr[f].y1, &mazeAr[f].x2, &mazeAr[f].y2);
    }
    printf("\n\n\n");
    fscanf(maze, "%d", &vertical);
    for(n=0; n<vertical; n++)
    {
        fscanf(maze, "%d %d %d %d", &mazeAr[f+n].x1, &mazeAr[f+n].y1, &mazeAr[f+n].x2, &mazeAr[f+n].y2);
    }
    i = horizontal + vertical;
    fclose(maze);

    if(musicOn)
        PlaySound("game_music.wav",NULL,SND_ASYNC|SND_LOOP);
    iSetTimer(40,change);
    //place your own initialization codes here.
    iInitialize(600, 650, "DESTINATION");
    return 0;
}
