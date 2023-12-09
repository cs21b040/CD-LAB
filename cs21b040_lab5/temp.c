#include<stdio.h>
#include<stdlib.h>
int main(){
    // char** month=(char**)malloc(sizeof(char*)*12);
    // for(int i=0;i<12;i++){
    //     month[i]=(char*)malloc(sizeof(char)*3);
    // }
    // month={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // char month[12][3]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char* month[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    if(month[0]=="Jan")printf("%s",month[0]);
}