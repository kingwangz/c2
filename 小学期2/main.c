//
//  main.c
//  小学期2
//
//  Created by kingwang on 2017/9/13.
//  Copyright © 2017年 kingwang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void registered();
void personal();
void administrator();
void logins();
void userlogin();
void administratorlogin();
char * userIDverification(char *);
char * administratorIDverification(char *);
void userinterface();
void administratorinterface();
void goodsadd();

int main() {
    //registered();
    logins();
    return 0;
}



void registered(){
    char phantom;
    char code[10],a[2];
    while(1)
    {
        printf("(a)Individual user registration\n");
        printf("(b)Administrator registration\n");
        printf("(c)	Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {personal();
        }
        else if(a[0]=='b')
        {   printf("Enter the administrator invitation code\n");
            scanf("%s",code);
            scanf("%c",&phantom);
            if(strcmp(code,"kingwang")==0){
                administrator();
            }
            else{
                printf("Invitation code error\n");
            }
        }
        else if(a[0]=='c')
        {exit(1);}
    }
}


void personal(){
    char ID[20],name[15],gender[15],phone[15],password[15],mailbox[15],IDF[15],address[15];
    int valid=0;
    char phantom;
    char file[]=".txt";
    FILE *infile;
    while(valid==0){
        printf("User ID\n");
        printf("Length 6-10 characters\n");
        scanf("%s",ID);
        scanf("%c",&phantom);
        if(strlen(ID)>5&&strlen(ID)<11){
            valid=1;
        }
        for(int k=0;k<11&&valid==1;k++) {
            if(ispunct(ID[k])!=0){
                valid=0;
            }
        }
        strcpy(IDF, ID);
        strcat(IDF, file);
        infile=fopen(IDF,"r");
        if (valid==1&&infile!=NULL) {
            printf("ID already exists, please re-enter\n");
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Name\n");
    scanf("%s",name);
    while (valid==1) {
        printf("Gender\n");
        printf("Please choose a man or a lady\n");
        scanf("%s",gender);
        scanf("%c",&phantom);
        if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while(valid==0){
        printf("Phone\n");
        printf("The telephone number should be 11 digits\n");
        scanf("%s",phone);
        scanf("%c",&phantom);
        valid=1;
        if(strlen(phone)!=11){
            valid=0;
        }
        for(int k=0;k<11&&valid==1;k++) {
            if(isdigit(phone[k])==0){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Password\n");
    scanf("%s",password);
    while(valid==1){
        printf("Mailbox\n");
        printf("The correct format is ***@***.***\n");
        scanf("%s",mailbox);
        scanf("%c",&phantom);
        valid=0;
        if(strlen(mailbox)!=11){
            valid=1;
        }
        for(int k=0;k<3&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0 && mailbox[3]!='@'){
            valid=1;
        }
        for(int k=4;k<7&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(mailbox[7]!='.'&&valid==0){
            valid=1;
        }
        for(int k=8;k<11&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    printf("Address\n");
    scanf("%s",address);
    
    strcpy(IDF, ID);
    strcat(IDF, file);
    infile=fopen(IDF,"a+" );
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    fprintf(infile,"%s %s %s %s %s %s %s",ID,name,gender,phone,password,mailbox,address);
    fclose(infile);
}



void administrator(){
    char IDA[20],name[15],gender[15],phone[15],password[15],mailbox[15],supermarket[15],IDF[15];
    int valid=0;
    char phantom;
    char file[]="a.txt";
    FILE *infile;
    while(valid==0){
        printf("Administrator ID\n");
        printf("Length 6-10 characters\n");
        scanf("%s",IDA);
        scanf("%c",&phantom);
        if(strlen(IDA)>5&&strlen(IDA)<11){
            valid=1;
        }
        for(int k=0; k<11 && valid==1 ;k++) {
            if(ispunct(IDA[k])!=0){
                valid=0;
            }
        }
        strcpy(IDF, IDA);
        strcat(IDF, file);
        infile=fopen(IDF,"r");
        if (valid==1&&infile!=NULL) {
            printf("ID already exists, please re-enter\n");
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Name\n");
    scanf("%s",name);
    while (valid==1) {
        printf("Gender\n");
        printf("Please choose a man or a lady\n");
        scanf("%s",gender);
        scanf("%c",&phantom);
        if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while(valid==0){
        printf("Phone\n");
        printf("The telephone number should be 11 digits\n");
        scanf("%s",phone);
        scanf("%c",&phantom);
        valid=1;
        if(strlen(phone)!=11){
            valid=0;
        }
        for(int k=0;k<11&&valid==1;k++) {
            if(isdigit(phone[k])==0){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Password\n");
    scanf("%s",password);
    while(valid==1){
        printf("Mailbox\n");
        printf("The correct format is ***@***.***\n");
        scanf("%s",mailbox);
        scanf("%c",&phantom);
        valid=0;
        if(strlen(mailbox)!=11){
            valid=1;
        }
        for(int k=0;k<3&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0 && mailbox[3]!='@'){
            valid=1;
        }
        for(int k=4;k<7&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(mailbox[7]!='.'&&valid==0){
            valid=1;
        }
        for(int k=8;k<11&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("Supermarket\n");
        printf("Currently supports the top ten supermarket nationwide\n");
        scanf("%s",supermarket);
        scanf("%c",&phantom);
        if (strcmp(supermarket,"WM")==0||strcmp(supermarket,"CF")==0||strcmp(supermarket,"SN")==0) {
            valid=1;
        }
        if (strcmp(supermarket,"GM")==0||strcmp(supermarket,"VG")==0||strcmp(supermarket,"RT")==0) {
            valid=1;
        }
        if (strcmp(supermarket,"BL")==0||strcmp(supermarket,"YH")==0||strcmp(supermarket,"IZ")==0) {
            valid=1;
        }
        if (strcmp(supermarket,"WU")==0) {
            valid=1;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    
    strcpy(IDF, IDA);
    strcat(IDF, file);
    infile=fopen(IDF,"a+" );
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    fprintf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,password,mailbox,supermarket);
    fclose(infile);
}



void logins(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Individual user login\n");
        printf("(b)Administrator login\n");
        printf("(c)	Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {userlogin();
        }
        else if(a[0]=='b')
        {administratorlogin();
        }
        else if(a[0]=='c')
        {exit(1);}
    }
    
}



void userlogin(){
    char ID[15],password[15];
    int valid=0;
    char * IDpassword;
    printf("Please enter the user ID\n");
    scanf("%s",ID);
    IDpassword=userIDverification(ID);
    if(strcmp(IDpassword, "h")==0){
        printf("The user does not exist, please register.\n");
    }
    else{
        valid=1;
    }
    if(valid==1){
        printf("Please enter the user password\n");
        scanf("%s",password);
        if(strcmp(IDpassword,password)==0){
            printf("Welcome back!\n");
            //userinterface();
        }
        else{
            printf("Password is wrong, please try again.\n");
        }
    }
}



void administratorlogin(){
    char ID[15],password[15];
    int valid=0;
    char * IDpassword;
    printf("Please enter the administrator ID\n");
    scanf("%s",ID);
    IDpassword=administratorIDverification(ID);
    if(strcmp(IDpassword, "h")==0){
        printf("The administrator does not exist, please register.\n");
    }
    else{
        valid=1;
    }
    if(valid==1){
        printf("Please enter the administrator password\n");
        scanf("%s",password);
        if(strcmp(IDpassword,password)==0){
            printf("Welcome back!\n");
            //administratorinterface();
        }
        else{
            printf("Password is wrong, please try again.\n");
        }
    }
}



char * userIDverification(char * IDU){
    static char passwold[15];
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15],address[15];
    FILE *infile;
    char file[]=".txt";
    char IDF[20];
    char valid[]="h";
    strcpy(IDF, IDU);
    strcat(IDF, file);
    infile=fopen(IDF,"r");
    if (infile==NULL) {
        strcpy(passwold, valid);
    }
    else{
        fscanf(infile,"%s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address);
        strcpy(passwold, pass);
        fclose(infile);
    }
    return passwold;
}


char  * administratorIDverification(char * IDA){
    static char passwold[15];
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15],supermarket[15];
    FILE *infile;
    char file[]="a.txt";
    char IDF[20];
    char valid[]="h";
    strcpy(IDF, IDA);
    strcat(IDF, file);
    infile=fopen(IDF,"r");
    if (infile==NULL) {
        strcpy(passwold, valid);
    }
    else{
        fscanf(infile,"%s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,supermarket);
        strcpy(passwold, pass);
        fclose(infile);
    }
    return passwold;
}




void goodsadd(){
    char Commoditynumber[20],marketname[15],discountstarttime[15],landing[15],departuretime[15],flighttime[15],firstseatnumber[55],bussinessseatnumber[55],economyseatnumber[55],modela[15],modelb[15],punctualityrate[15],firstfares[15],bussinessfares[15],economyfares[55],seat[55],determine[15],votes[15],Commoditynumberb[20],pilotsaa[15],pilotsbb[15],departuretimea[15],departuretimeb[15],departuretimec[15];
    int valid=0;
    char phantom;
    FILE *infile;
    while (valid==0) {
        printf("Commoditynumber\n");
        printf("Requires two letters four digits\n");
        scanf("%s",Commoditynumber);
        scanf("%c",&phantom);
        if (isalpha(Commoditynumber[0])!=0&&isalpha(Commoditynumber[1])!=0){
            valid=1;
        }
        for(int k=2;k<6&&valid==1;k++) {
            if(isdigit(Commoditynumber[k])==0){
                valid=0;
            }
        }
        if(valid==1&&strlen(Commoditynumber)!=6){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
        infile=fopen("goods.txt","r");
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",Commoditynumberb,takeoff,landing,departuretime,flighttime,modela,modelb,punctualityrate,firstfares,bussinessfares,economyfares,airline,votes,pilotsa,pilotsb)!=EOF){
            if(valid==1&&strcmp(Commoditynumber, Commoditynumberb)==0){
                printf("Flight number already exists, please re-enter\n");
                valid=0;
            }
        }
        fclose(infile);
        
    }


    while (valid==1) {
        printf("Discount start time\n");
        printf("Match the time format yyyy:mm:dd:hh:mm\n");
        scanf("%s",discountstarttime);
        scanf("%c",&phantom);
        for(int k=0;k<4;k++) {
            if(isdigit(discountstarttime[k])==0){
                valid=0;
            }
        }
        if(valid==0&&departuretime[4]!=':'){
            valid=1;
        }
        if(valid==0&&(isdigit(departuretime[3])==0||isdigit(departuretime[4])==0)){
            valid=1;
        }
        if(valid==0&&departuretime[3]>'6'){
            valid=1;
        }
        if(valid==0&&departuretime[3]=='6'&&departuretime[4]!='0'){
            valid=1;
        }
        if(valid==0&&strlen(departuretime)!=5){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
        if(valid==0&&abs(atoi(departuretime)-atoi(departuretimeb))<10){
            printf("The pilot is flying, please re-enter the flight time\n");
            valid=1;
        }
        if(valid==0&&abs(atoi(departuretime)-atoi(departuretimec))<10){
            printf("The pilot is flying, please re-enter the flight time\n");
            valid=1;
        }
    }
    while (valid==0) {
        printf("Flighttime\n");
        printf("Match the time format hh:mm\n");
        scanf("%s",flighttime);
        scanf("%c",&phantom);
        if(isdigit(flighttime[0])!=0&&isdigit(flighttime[1])!=0){
            valid=1;
        }
        if(valid==1&&flighttime[2]!=':'){
            valid=0;
        }
        if(valid==1&&(isdigit(flighttime[3])==0||isdigit(flighttime[4])==0)){
            valid=0;
        }
        if(valid==1&&flighttime[3]>'6'){
            valid=0;
        }
        if(valid==1&&flighttime[3]=='6'&&flighttime[4]!='0'){
            valid=0;
        }
        if(valid==1&&strlen(flighttime)!=5){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("Model\n");
        printf("Choose models: large, medium and small\n");
        scanf("%s",modela);
        scanf("%c",&phantom);
        if(strcmp(modela,"large")==0||strcmp(modela,"medium")==0||strcmp(modela,"small")==0){
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("Model\n");
        if(strcmp(modela,"large")==0){
            printf("Choose models: BY747,BY767,BY777\n");
            scanf("%s",modelb);
            scanf("%c",&phantom);
            if(strcmp(modelb,"BY747")==0||strcmp(modelb,"BY767")==0|| strcmp(modelb,"BY777")==0){
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
        else if(strcmp(modela,"medium")==0){
            printf("Choose models: BY737,BY738,TU5\n");
            scanf("%s",modelb);
            scanf("%c",&phantom);
            if(strcmp(modelb,"BY737")==0||strcmp(modelb,"BY738")==0|| strcmp(modelb,"TU5")==0){
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
        else{
            printf("Choose models: YN7,AN4\n");
            scanf("%s",modelb);
            scanf("%c",&phantom);
            if(strcmp(modelb,"YN7")==0||strcmp(modelb,"AN4")==0){
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
    }
    while (valid==1) {
        printf("Punctualityrate\n");
        printf("According to the percentage format: xx.x%% \n");
        scanf("%s",punctualityrate);
        scanf("%c",&phantom);
        if(isdigit(punctualityrate[0])!=0&&isdigit(punctualityrate[1])!=0){
            valid=0;
        }
        if(valid==0&&punctualityrate[2]!='.'){
            valid=1;
        }
        if(valid==0&&isdigit(punctualityrate[3])==0){
            valid=1;
        }
        if(valid==0&&punctualityrate[4]!='%'){
            valid=1;
        }
        if(valid==0&&strlen(punctualityrate)!=5){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("FirstClass pilots\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",firstfares);
        scanf("%c",&phantom);
        if(isdigit(firstfares[0])!=0&&isdigit(firstfares[1])!=0){
            valid=1;
        }
        if(isdigit(firstfares[2])==0&&firstfares[2]!='.'&&valid==1){
            valid=0;
        }
        if(valid==1&&firstfares[2]=='.'){
            if(isdigit(firstfares[3])==0||isdigit(firstfares[4])==0){
                valid=0;
                if(valid==1&&strlen(firstfares)!=5){
                    valid=0;
                }
            }
        }
        if(valid==1&&isdigit(firstfares[2])!=0){
            if(firstfares[3]!='.'||isdigit(firstfares[4])==0||isdigit(firstfares[5])==0){
                valid=0;
            }
            if(valid==1&&strlen(firstfares)!=6){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("BussinessseatClass pilots\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",bussinessfares);
        scanf("%c",&phantom);
        if(isdigit(bussinessfares[0])!=0&&isdigit(bussinessfares[1])!=0){
            valid=0;
        }
        if(isdigit(bussinessfares[2])==0&&bussinessfares[2]!='.'&&valid==0){
            valid=1;
        }
        if(valid==0&&bussinessfares[2]=='.'){
            if(isdigit(bussinessfares[3])==0||isdigit(bussinessfares[4])==0){
                valid=1;
            }
            if(valid==0&&strlen(bussinessfares)!=5){
                valid=1;
            }
        }
        if(valid==0&&isdigit(bussinessfares[2])!=0){
            if(bussinessfares[3]!='.'||isdigit(bussinessfares[4])==0||isdigit(bussinessfares[5])==0){
                valid=1;
            }
            if(valid==0&&strlen(bussinessfares)!=6){
                valid=1;
            }
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("EconomyClass pilots\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",economyfares);
        scanf("%c",&phantom);
        if(isdigit(economyfares[0])!=0&&isdigit(economyfares[1])!=0){
            valid=1;
        }
        if(isdigit(economyfares[2])==0&&economyfares[2]!='.'&&valid==1){
            valid=0;
        }
        if(valid==1&&economyfares[2]=='.'){
            if(isdigit(economyfares[3])==0||isdigit(economyfares[4])==0){
                valid=0;
            }
            if(valid==1&&strlen(economyfares)!=5){
                valid=0;
            }
        }
        if(valid==1&&isdigit(economyfares[2])!=0){
            if(economyfares[3]!='.'||isdigit(economyfares[4])==0||isdigit(economyfares[5])==0){
                valid=0;
            }
            if(valid==1&&strlen(economyfares)!=6){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("Airline\n");
        printf("Currently supports the top ten airlines nationwide\n");
        scanf("%s",airline);
        scanf("%c",&phantom);
        if (strcmp(airline,"CA")==0||strcmp(airline,"MU")==0||strcmp(airline,"CZ")==0) {
            valid=0;
        }
        if (strcmp(airline,"HU")==0||strcmp(airline,"ZH")==0||strcmp(airline,"FM")==0) {
            valid=0;
        }
        if (strcmp(airline,"MF")==0||strcmp(airline,"3U")==0||strcmp(airline,"SC")==0) {
            valid=0;
        }
        if (strcmp(airline,"9C")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    if(strcmp(modela,"large")==0){
        strcpy(votes, "360");
        for(int i=0;i<55;i++){
            firstseatnumber[i]='F';
        }
        for(int i=0;i<55;i++){
            bussinessseatnumber[i]='C';
        }
        for(int i=0;i<55;i++){
            economyseatnumber[i]='Y';
        }
        for(int i=0;i<55;i=i+6){
            seat[i]='a';
            seat[i+1]='b';
            seat[i+2]='c';
            seat[i+3]='d';
            seat[i+4]='e';
            seat[i+5]='f';
        }
        
    }
    if(strcmp(modela,"medium")==0){
        strcpy(votes, "200");
        for(int i=0;i<55;i++){
            firstseatnumber[i]='F';
        }
        for(int i=0;i<55;i++){
            bussinessseatnumber[i]='C';
        }
        for(int i=0;i<55;i++){
            economyseatnumber[i]='Y';
        }
        for(int i=0;i<55;i=i+6){
            seat[i]='a';
            seat[i+1]='b';
            seat[i+2]='c';
            seat[i+3]='d';
            seat[i+4]='e';
            seat[i+5]='f';
        }
    }
    if(strcmp(modela,"small")==0){
        strcpy(votes, "100");
        for(int i=0;i<55;i++){
            firstseatnumber[i]='F';
        }
        for(int i=0;i<55;i++){
            bussinessseatnumber[i]='C';
        }
        for(int i=0;i<55;i++){
            economyseatnumber[i]='Y';
        }
        for(int i=0;i<55;i=i+6){
            seat[i]='a';
            seat[i+1]='b';
            seat[i+2]='c';
            seat[i+3]='d';
            seat[i+4]='e';
            seat[i+5]='f';
        }
    }
    while (valid==0) {
        printf("determine\n");
        printf("Make a change: determine or negative\n");
        scanf("%s",determine);
        scanf("%c",&phantom);
        if (strcmp(determine,"determine")==0||strcmp(determine,"negative")==0) {
            valid=1;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    if(strcmp(determine,"determine")==0){
        infile=fopen("flight.txt","a+");
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",Flightnumber,takeoff,landing,departuretime,flighttime,modela,modelb,punctualityrate,firstfares,bussinessfares,economyfares,airline,votes,pilotsa,pilotsb);
        fclose(infile);
    }
}
