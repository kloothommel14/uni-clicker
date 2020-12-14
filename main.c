#include <stdio.h>
#include <windowsx.h>
#include <rpc.h>
#include <zconf.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"

int click(int ms){
    boolean click = FALSE;
    if (ms < 10){
        ms = 10;
    }
    while (1==1){
        if(GetAsyncKeyState(VK_LBUTTON) > 0){
            printf("false");
            click = FALSE;
        }
        if(GetAsyncKeyState(VK_LBUTTON) < 0){
            printf("true");
            click = TRUE;
        }
        if(click == TRUE){
            printf("pressed");
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            Sleep(1000/ms);
        }
    }
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    int msdelay = 200;
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
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("DO NOT CLICK IN THE CONSOLE, YOU CAN PUT IN INPUT WITHOUT CLICKING.");
    printf("\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("enter CPS please.\n");
    scanf ("%d",&msdelay);
    printf("cps: %d", msdelay);
    click(msdelay);
    return 0;
}
