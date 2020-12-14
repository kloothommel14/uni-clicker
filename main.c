#include <stdio.h>
#include <rpc.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"
int random(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int click(){
    int ms = 200;
    printf("enter cps please");
    scanf ("%d",&ms);
    printf("cps: %d", ms);
    boolean click = FALSE;
    if (ms < 10){
        ms = 10;
    }
    while (1==1){
        if(GetAsyncKeyState(VK_LBUTTON) > 0){
            click = FALSE;
        }
        if(GetAsyncKeyState(VK_LBUTTON) < 0){
            click = TRUE;
        }
        if(click == TRUE){
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
            Sleep(random(10,30));
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            Sleep(1000/ms);
        }
    }
}
int clickRand(){
    int msMax = 200;
    int msMin = 200;
    printf("enter max delay in milliseconds");

    scanf("%d", msMax);
    printf("enter min delay in milliseconds");
    scanf("%d", msMin);

    boolean click = FALSE;


    while (1==1){
        if(GetAsyncKeyState(VK_LBUTTON) > 0){
            click = FALSE;
        }
        if(GetAsyncKeyState(VK_LBUTTON) < 0){
            click = TRUE;
        }
        if(click == TRUE){
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
            Sleep(random(10,30));
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            Sleep(random(msMin,msMax));
        }
    }
}
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("          _       _________     _______  _       _________ _______  _        _______  _______ \n"
           "|\\     /|( (    /|\\__   __/    (  ____ \\( \\      \\__   __/(  ____ \\| \\    /\\(  ____ \\(  ____ )\n"
           "| )   ( ||  \\  ( |   ) (       | (    \\/| (         ) (   | (    \\/|  \\  / /| (    \\/| (    )|\n"
           "| |   | ||   \\ | |   | | _____ | |      | |         | |   | |      |  (_/ / | (__    | (____)|\n"
           "| |   | || (\\ \\) |   | |(_____)| |      | |         | |   | |      |   _ (  |  __)   |     __)\n"
           "| |   | || | \\   |   | |       | |      | |         | |   | |      |  ( \\ \\ | (      | (\\ (   \n"
           "| (___) || )  \\  |___) (___    | (____/\\| (____/\\___) (___| (____/\\|  /  \\ \\| (____/\\| ) \\ \\__\n"
           "(_______)|/    )_)\\_______/    (_______/(_______/\\_______/(_______/|_/    \\/(_______/|/   \\__/\n");
    printf("\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("enter 1 for a not random autoclicker, enter 2 for a random autoclicker.\n");
    int selection = 0;
    scanf ("%d",&selection);
    if(selection==1){
        click();
    }else if(selection==2){
        clickRand();
    }else{
        printf("invalid option. rerun and provide valid options");
        return 0;
    }
    return 0;
}
