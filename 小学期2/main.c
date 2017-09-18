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
void Commoditysearch(char *,int,int);

int main() {
    char commoditytype[15];
    //registered();
    //logins();
    //goodsadd();
    scanf("%s",commoditytype);
    Commoditysearch(commoditytype,1, 4);
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
    char Commoditynumber[20],marketname[15],discountstarttime[55],discountendtime[55],commoditytype[15],brand[15],retailprice[15],purchaseprice[55],inventory[55],discountrate[55],determine[15],Commoditynumberb[20];
    int valid=0,leapyear=0;
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
        while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s",Commoditynumberb,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime)!=EOF){
            if(valid==1&&strcmp(Commoditynumber, Commoditynumberb)==0){
                printf("Flight number already exists, please re-enter\n");
                valid=0;
            }
        }
        fclose(infile);
        
    }
    while (valid==1) {
        printf("Supermarket\n");
        printf("Currently supports the top ten supermarket nationwide\n");
        scanf("%s",marketname);
        scanf("%c",&phantom);
        if (strcmp(marketname,"WM")==0||strcmp(marketname,"CF")==0||strcmp(marketname,"SN")==0) {
            valid=0;
        }
        if (strcmp(marketname,"GM")==0||strcmp(marketname,"VG")==0||strcmp(marketname,"RT")==0) {
            valid=0;
        }
        if (strcmp(marketname,"BL")==0||strcmp(marketname,"YH")==0||strcmp(marketname,"IZ")==0) {
            valid=0;
        }
        if (strcmp(marketname,"WU")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    printf("Commoditytype\n");
    scanf("%s",commoditytype);
    printf("Brand\n");
    scanf("%s",brand);
    while (valid==0) {
        int k=1;
        printf("Retail price\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",retailprice);
        scanf("%c",&phantom);
        if(isdigit(retailprice[0])!=0){
            valid=1;
        }
        while (valid==1&&k<15) {
            if(isdigit(retailprice[k])==0){
                valid=0;
            }
            k++;
            if(retailprice[k]=='.'){
                break;
            }
        }
        if(valid==1&&retailprice[k]!='.'){
            valid=0;
        }
        if(valid==1&&isdigit(retailprice[k+1])==0&&isdigit(retailprice[k+2])==0){
            valid=0;
        }
        if(valid==1&&strlen(retailprice)!=k+3){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        int k=1;
        printf("Purchase price\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",purchaseprice);
        scanf("%c",&phantom);
        if(isdigit(purchaseprice[0])!=0){
            valid=0;
        }
        while (valid==0&&k<15) {
            if(isdigit(purchaseprice[k])==0){
                valid=1;
            }
            k++;
            if(purchaseprice[k]=='.'){
                break;
            }
        }
        if(valid==0&&purchaseprice[k]!='.'){
            valid=1;
        }
        if(valid==0&&isdigit(purchaseprice[k+1])==0&&isdigit(purchaseprice[k+2])==0){
            valid=1;
        }
        if(valid==0&&strlen(purchaseprice)!=k+3){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    
    while (valid==0) {
        int k=1;
        printf("Inventory\n");
        printf("According  format: xxx\n");
        scanf("%s",inventory);
        scanf("%c",&phantom);
        if(isdigit(inventory[0])!=0){
            valid=1;
        }
        while (valid==1&&k<15) {
            if(isdigit(inventory[k])==0){
                valid=0;
            }
            k++;
            if(inventory[k]=='\0'){
                break;
            }
        }
        if(valid==1&&strlen(inventory)!=k){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("Discount rate\n");
        printf("According to the percentage format: xx.x%% \n");
        scanf("%s",discountrate);
        scanf("%c",&phantom);
        if(isdigit(discountrate[0])!=0&&isdigit(discountrate[1])!=0){
            valid=0;
        }
        if(valid==0&&discountrate[2]!='.'){
            valid=1;
        }
        if(valid==0&&isdigit(discountrate[3])==0){
            valid=1;
        }
        if(valid==0&&discountrate[4]!='%'){
            valid=1;
        }
        if(valid==0&&strlen(discountrate)!=5){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("Discount start time\n");
        printf("Match the time format yyyy:mm:dd:hh:mm\n");
        scanf("%s",discountstarttime);
        scanf("%c",&phantom);
        for(int k=0;k<4;k++) {
            if(isdigit(discountstarttime[k])!=0){
                valid=1;
            }
        }
        if(valid==1&&discountstarttime[4]!=':'){
            valid=0;
        }
        if(valid==1&&isdigit(discountstarttime[5])==0&&isdigit(discountstarttime[6])==0){
            valid=0;
        }
        if(valid==1&&discountstarttime[5]!='0'&&discountstarttime[5]!='1'){
            valid=0;
        }
        if(valid==1&&discountstarttime[5]=='0'){
            if(discountstarttime[6]=='0'){
                valid=0;
            }
        }
        if(valid==1&&discountstarttime[5]=='1'){
            if(discountstarttime[6]>'2'){
                valid=0;
            }
        }
        if(valid==1&&discountstarttime[7]!=':'){
            valid=0;
        }
        if(valid==1&&isdigit(discountstarttime[8])==0&&isdigit(discountstarttime[9])==0){
            valid=0;
        }
        if(valid==1&&discountstarttime[8]>'3'){
            valid=0;
        }
        if(valid==1&&atoi(discountstarttime)%400==0){
            leapyear=1;
        }
        if(valid==1&&atoi(discountstarttime)%4==0){
            leapyear=2;
        }
        if(valid==1&&atoi(discountstarttime)%100==0&&leapyear==2){
            leapyear=0;
        }
        if(valid==1&&leapyear==2&&leapyear==1){
            if(discountstarttime[5]=='0'&&discountstarttime[6]=='2'){
                if(discountstarttime[8]>'2'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&leapyear==0){
            if(discountstarttime[5]=='0'&&discountstarttime[6]=='2'){
                if(discountstarttime[8]=='2'){
                    if(discountstarttime[9]>'8'){
                        valid=0;
                    }
                }
                if(discountstarttime[8]>'2'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&(discountstarttime[6]=='1'||discountstarttime[6]=='3')&&discountstarttime[5]=='0'){
            if(discountstarttime[8]=='3'){
                if(discountstarttime[9]>'1'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&(discountstarttime[6]=='5'||discountstarttime[6]=='7')&&discountstarttime[5]=='0'){
            if(discountstarttime[8]=='3'){
                if(discountstarttime[9]>'1'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&discountstarttime[6]=='8'&&discountstarttime[5]=='0'){
            if(discountstarttime[8]=='3'){
                if(discountstarttime[9]>'1'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&(discountstarttime[6]=='0'||discountstarttime[6]=='2')&&discountstarttime[5]=='1'){
            if(discountstarttime[8]=='3'){
                if(discountstarttime[9]>'1'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&(discountstarttime[6]=='4'||discountstarttime[6]=='6')&&discountstarttime[5]=='0'){
            if(discountstarttime[8]=='3'){
                if(discountstarttime[9]!='0'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&discountstarttime[6]=='9'&&discountstarttime[5]=='0'){
            if(discountstarttime[8]=='3'){
                if(discountstarttime[9]!='0'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&discountstarttime[6]=='1'&&discountstarttime[5]=='1'){
            if(discountstarttime[8]=='3'){
                if(discountstarttime[9]!='0'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&discountstarttime[10]!=':'){
            valid=0;
        }
        if(valid==1&&discountstarttime[13]!=':'){
            valid=0;
        }
        if(valid==1&&isdigit(discountstarttime[11])==0&&isdigit(discountstarttime[12])==0){
            valid=0;
        }
        if(valid==1&&isdigit(discountstarttime[14])==0&&isdigit(discountstarttime[15])==0){
            valid=0;
        }
        if(valid==1&&discountstarttime[11]>'2'){
            valid=0;
        }
        if(valid==1&&discountstarttime[11]=='2'){
            if(discountstarttime[12]>'4'){
                valid=0;
            }
        }
        if(valid==1&&discountstarttime[11]=='2'&&discountstarttime[12]=='4'){
            if(discountstarttime[14]!='0'||discountstarttime[15]!='0'){
                valid=0;
            }
        }
        if(valid==1&&discountstarttime[14]>'6'){
            valid=0;
        }
        if(valid==1&&discountstarttime[14]=='6'){
            if(discountstarttime[15]!='0'){
                valid=0;
            }
        }
        if(valid==1&&strlen(discountstarttime)!=16){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    
    while (valid==1) {
        printf("Discount end time\n");
        printf("Match the time format yyyy:mm:dd:hh:mm\n");
        scanf("%s",discountendtime);
        scanf("%c",&phantom);
        for(int k=0;k<4;k++) {
            if(isdigit(discountendtime[k])!=0){
                valid=0;
            }
        }
        if(valid==0&&discountendtime[4]!=':'){
            valid=1;
        }
        if(valid==0&&isdigit(discountendtime[5])==0&&isdigit(discountendtime[6])==0){
            valid=1;
        }
        if(valid==0&&discountendtime[5]!='0'&&discountendtime[5]!='1'){
            valid=1;
        }
        if(valid==0&&discountendtime[5]=='0'){
            if(discountendtime[6]=='0'){
                valid=1;
            }
        }
        if(valid==0&&discountendtime[5]=='1'){
            if(discountendtime[6]>'2'){
                valid=1;
            }
        }
        if(valid==0&&discountendtime[7]!=':'){
            valid=1;
        }
        if(valid==0&&isdigit(discountendtime[8])==0&&isdigit(discountendtime[9])==0){
            valid=1;
        }
        if(valid==0&&discountendtime[8]>'3'){
            valid=1;
        }
        if(valid==0&&atoi(discountendtime)%400==0){
            leapyear=1;
        }
        if(valid==0&&atoi(discountendtime)%4==0){
            leapyear=2;
        }
        if(valid==0&&atoi(discountendtime)%100==0&&leapyear==2){
            leapyear=0;
        }
        if(valid==0&&leapyear==2&&leapyear==1){
            if(discountendtime[5]=='0'&&discountendtime[6]=='2'){
                if(discountendtime[8]>'2'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&leapyear==0){
            if(discountendtime[5]=='0'&&discountendtime[6]=='2'){
                if(discountendtime[8]=='2'){
                    if(discountendtime[9]>'8'){
                        valid=1;
                    }
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&(discountendtime[6]=='1'||discountendtime[6]=='3')&&discountendtime[5]=='0'){
            if(discountendtime[8]=='3'){
                if(discountendtime[9]>'1'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&(discountendtime[6]=='5'||discountendtime[6]=='7')&&discountendtime[5]=='0'){
            if(discountendtime[8]=='3'){
                if(discountendtime[9]>'1'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&discountendtime[6]=='8'&&discountendtime[5]=='0'){
            if(discountendtime[8]=='3'){
                if(discountendtime[9]>'1'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&(discountendtime[6]=='0'||discountendtime[6]=='2')&&discountendtime[5]=='1'){
            if(discountendtime[8]=='3'){
                if(discountendtime[9]>'1'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&(discountendtime[6]=='4'||discountendtime[6]=='6')&&discountendtime[5]=='0'){
            if(discountendtime[8]=='3'){
                if(discountendtime[9]!='0'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&discountendtime[6]=='9'&&discountendtime[5]=='0'){
            if(discountendtime[8]=='3'){
                if(discountendtime[9]!='0'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&discountendtime[6]=='1'&&discountendtime[5]=='1'){
            if(discountendtime[8]=='3'){
                if(discountendtime[9]!='0'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&discountendtime[10]!=':'){
            valid=1;
        }
        if(valid==0&&discountendtime[13]!=':'){
            valid=1;
        }
        if(valid==0&&isdigit(discountendtime[11])==0&&isdigit(discountendtime[12])==0){
            valid=1;
        }
        if(valid==0&&isdigit(discountendtime[14])==0&&isdigit(discountendtime[15])==0){
            valid=1;
        }
        if(valid==0&&discountendtime[11]>'2'){
            valid=1;
        }
        if(valid==0&&discountendtime[11]=='2'){
            if(discountendtime[12]>'4'){
                valid=1;
            }
        }
        if(valid==0&&discountendtime[11]=='2'&&discountendtime[12]=='4'){
            if(discountendtime[14]!='0'||discountendtime[15]!='0'){
                valid=1;
            }
        }
        if(valid==0&&discountendtime[14]>'6'){
            valid=1;
        }
        if(valid==0&&discountendtime[14]=='6'){
            if(discountendtime[15]!='0'){
                valid=1;
            }
        }
        if(valid==0&&strlen(discountendtime)!=16){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
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
        infile=fopen("goods.txt","a+");
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        fprintf(infile,"%s %s %s %s %s %s %s %s %s %s\n",Commoditynumber,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime);
        fclose(infile);
    }
}





void Commoditysearch(char * COM,int x,int y){
    char Commoditynumber[20],marketname[15],discountstarttime[55],discountendtime[55],commoditytype[15],brand[15],retailprice[15],purchaseprice[55],inventory[55],discountrate[55];
    
    char Commoditynumbera[500][20],marketnamea[500][15],discountstarttimea[500][55],discountendtimea[500][55],commoditytypea[500][15],branda[500][15],retailpricea[500][15],purchasepricea[500][15],inventorya[500][15],discountratea[500][15];
    char Comparison[55],Comparisonb[55],tempa[55],tempb[55],tempc[55],tempd[55],tempe[55],tempf[55],tempg[55],temph[55],tempi[55],tempj[55];
    FILE *infile;
    int k=0;
    infile=fopen("goods.txt","r");
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    strcpy(Comparison, COM);
    while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s",Commoditynumber,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime)!=EOF){
        if(x==1){
            strcpy(Comparisonb, commoditytype);
        }
        if(x==2){
            strcpy(Comparisonb, marketname);
        }
        if(x==3){
            strcpy(Comparisonb, brand);
        }
        if(x==4){
            strcpy(Comparisonb, retailprice);
        }
        if(x==5){
            strcpy(Comparisonb, discountrate);
        }
        
        if( strcmp(Comparisonb,Comparison)==0){
            strcpy(Commoditynumbera[k],Commoditynumber);
            strcpy(marketnamea[k],marketname);
            strcpy(commoditytypea[k],commoditytype);
            strcpy(branda[k],brand);
            strcpy(retailpricea[k],retailprice);
            strcpy(purchasepricea[k],purchaseprice);
            strcpy(inventorya[k],inventory);
            strcpy(discountratea[k],discountrate);
            strcpy(discountstarttimea[k],discountstarttime);
            strcpy(discountendtimea[k],discountendtime);
            k++;
        }
    }
    fclose(infile);
    if(y==1){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(strcmp(retailpricea[i],retailpricea[j])>0){
                    
                    strcpy(tempa, Commoditynumbera[i]);
                    strcpy(tempb, marketnamea[i]);
                    strcpy(tempc, commoditytypea[i]);
                    strcpy(tempd, branda[i]);
                    strcpy(tempe, retailpricea[i]);
                    strcpy(tempf, purchasepricea[i]);
                    strcpy(tempg, inventorya[i]);
                    strcpy(temph, discountratea[i]);
                    strcpy(tempi, discountstarttimea[i]);
                    strcpy(tempj, discountendtimea[i]);
                    
                    strcpy(Commoditynumbera[i], Commoditynumbera[j]);
                    strcpy(marketnamea[i], marketnamea[j]);
                    strcpy(commoditytypea[i], commoditytypea[j]);
                    strcpy(branda[i], branda[j]);
                    strcpy(retailpricea[i], retailpricea[j]);
                    strcpy(purchasepricea[i], purchasepricea[j]);
                    strcpy(inventorya[i], inventorya[j]);
                    strcpy(discountratea[i], discountratea[j]);
                    strcpy(discountstarttimea[i], discountstarttimea[j]);
                    strcpy(discountendtimea[i], discountendtimea[j]);
                    
                    strcpy(Commoditynumbera[j], tempa);
                    strcpy(marketnamea[j], tempb);
                    strcpy(commoditytypea[j], tempc);
                    strcpy(branda[j], tempd);
                    strcpy(retailpricea[j], tempe);
                    strcpy(purchasepricea[j], tempf);
                    strcpy(inventorya[j], tempg);
                    strcpy(discountratea[j], temph);
                    strcpy(discountstarttimea[j], tempi);
                    strcpy(discountendtimea[j], tempj);
                    
                }
            }
        }
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g]);
        }
    }
    if(y==2){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(strcmp(inventorya[i],inventorya[j])>0){
                    
                    strcpy(tempa, Commoditynumbera[i]);
                    strcpy(tempb, marketnamea[i]);
                    strcpy(tempc, commoditytypea[i]);
                    strcpy(tempd, branda[i]);
                    strcpy(tempe, retailpricea[i]);
                    strcpy(tempf, purchasepricea[i]);
                    strcpy(tempg, inventorya[i]);
                    strcpy(temph, discountratea[i]);
                    strcpy(tempi, discountstarttimea[i]);
                    strcpy(tempj, discountendtimea[i]);
                    
                    strcpy(Commoditynumbera[i], Commoditynumbera[j]);
                    strcpy(marketnamea[i], marketnamea[j]);
                    strcpy(commoditytypea[i], commoditytypea[j]);
                    strcpy(branda[i], branda[j]);
                    strcpy(retailpricea[i], retailpricea[j]);
                    strcpy(purchasepricea[i], purchasepricea[j]);
                    strcpy(inventorya[i], inventorya[j]);
                    strcpy(discountratea[i], discountratea[j]);
                    strcpy(discountstarttimea[i], discountstarttimea[j]);
                    strcpy(discountendtimea[i], discountendtimea[j]);
                    
                    strcpy(Commoditynumbera[j], tempa);
                    strcpy(marketnamea[j], tempb);
                    strcpy(commoditytypea[j], tempc);
                    strcpy(branda[j], tempd);
                    strcpy(retailpricea[j], tempe);
                    strcpy(purchasepricea[j], tempf);
                    strcpy(inventorya[j], tempg);
                    strcpy(discountratea[j], temph);
                    strcpy(discountstarttimea[j], tempi);
                    strcpy(discountendtimea[j], tempj);
                    
                }
            }
        }
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g]);
        }
    }
    if(y==3){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(strcmp(discountratea[i],discountratea[j])>0){
                    
                    strcpy(tempa, Commoditynumbera[i]);
                    strcpy(tempb, marketnamea[i]);
                    strcpy(tempc, commoditytypea[i]);
                    strcpy(tempd, branda[i]);
                    strcpy(tempe, retailpricea[i]);
                    strcpy(tempf, purchasepricea[i]);
                    strcpy(tempg, inventorya[i]);
                    strcpy(temph, discountratea[i]);
                    strcpy(tempi, discountstarttimea[i]);
                    strcpy(tempj, discountendtimea[i]);
                    
                    strcpy(Commoditynumbera[i], Commoditynumbera[j]);
                    strcpy(marketnamea[i], marketnamea[j]);
                    strcpy(commoditytypea[i], commoditytypea[j]);
                    strcpy(branda[i], branda[j]);
                    strcpy(retailpricea[i], retailpricea[j]);
                    strcpy(purchasepricea[i], purchasepricea[j]);
                    strcpy(inventorya[i], inventorya[j]);
                    strcpy(discountratea[i], discountratea[j]);
                    strcpy(discountstarttimea[i], discountstarttimea[j]);
                    strcpy(discountendtimea[i], discountendtimea[j]);
                    
                    strcpy(Commoditynumbera[j], tempa);
                    strcpy(marketnamea[j], tempb);
                    strcpy(commoditytypea[j], tempc);
                    strcpy(branda[j], tempd);
                    strcpy(retailpricea[j], tempe);
                    strcpy(purchasepricea[j], tempf);
                    strcpy(inventorya[j], tempg);
                    strcpy(discountratea[j], temph);
                    strcpy(discountstarttimea[j], tempi);
                    strcpy(discountendtimea[j], tempj);
                    
                }
            }
        }
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g]);
        }

    }
    if(y==4){
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g]);
        }
        
    }
    
    
}
