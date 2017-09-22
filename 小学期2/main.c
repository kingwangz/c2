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
#include<time.h>

void registered();//注册主函数
void personal();//用户注册界面
void administrator();//管理员注册界面
void logins();//登录主函数
void userlogin();//用户登录界面
void administratorlogin();//管理员登录界面
char * userIDverification(char *);//验证用户ID和密码是否匹配
char * administratorIDverification(char *);//验证管理员ID和密码是否匹配
void userinterface(char *);//用户界面
void administratorinterface(char *);//管理员界面
void goodsadd(char *);//商品添加
void Commoditysearch(char *,int,int);//商品查找
void goodsinquiries(char *);//用户商品查找界面
void recommendation(char *);//热门推荐
void goodsmanagement(char *);//商品管理界面
void userinformation(char *);//用户修改信息界面
void administratorinformation(char *);//管理员修改信息界面
void Order(char *);//用户订单查找
void ordermanagement(char *,int);//管理员订单查找
void Recharge(char *);//充值界面
void purchase(char *);//购买界面
char * timeas();//获取标准格式的当地时间

int main() {//主程序
    char phantom;
    char a[2];
    int valid=0;
    while(valid==0)
    {
        printf("(a)Registered\n");
        printf("(b)Logins\n");
        printf("(c)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);//验证幻影符
        if(strcmp(a,"a")==0)//选择注册界面
        {registered();//进入注册界面
        }
        else if(strcmp(a,"b")==0)//选择登录界面
        {logins();//进入登录界面
        }
        else if(strcmp(a,"c")==0)//退出系统
        {valid=1;
        }
    }
    
    return 0;
}



void registered(){
    char phantom;
    char code[10],a[2];
    int valid=0;
    while(valid==0)
    {
        printf("(a)Individual user registration\n");
        printf("(b)Administrator registration\n");
        printf("(c)	Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);//验证幻影符
        if(strcmp(a,"a")==0)
        {personal();//进入用户注册界面
        }
        else if(strcmp(a,"b")==0)
        {   printf("Enter the administrator invitation code\n");
            scanf("%s",code);
            scanf("%c",&phantom);
            if(strcmp(code,"kingwang")==0){//进行管理码验证,管理码为kingwang
                administrator();//进入管理员注册界面
            }
            else{
                printf("Invitation code error\n");
            }
        }
        else if(strcmp(a,"c")==0)
        {valid=1;}//返回程序上一级
    }
}


void personal(){
    char ID[20],name[15],gender[15],phone[15],pass[15],mailbox[15],IDF[15],address[15],Balance[15];
    int valid=0;
    char phantom;
    strcpy(Balance,"0.00");//初始化账户余额
    char file[]=".txt";
    FILE *infile;
    while(valid==0){//进行ID输入的容错机制
        printf("User ID\n");
        printf("Length 6-10 characters\n");
        scanf("%s",ID);
        scanf("%c",&phantom);
        if(strlen(ID)>5&&strlen(ID)<11){//验证输入长度
            valid=1;
        }
        for(int k=0;k<11&&valid==1;k++) {//验证输入是否为字母或数字
            if(ispunct(ID[k])!=0){
                printf("The input must be a letter or a number\n");
                valid=0;
            }
        }

        strcpy(IDF, ID);
        strcat(IDF, file);
        infile=fopen(IDF,"r");
        if (valid==1&&infile!=NULL) {//使同一ID只能出现一次
            printf("ID already exists, please re-enter\n");
            valid=0;
        }
        fclose(infile);
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
            valid=0;
        }
    }
    printf("Name\n");
    scanf("%s",name);
    while (valid==1) {//进行性别输入的容错机制
        printf("Gender\n");
        printf("Please choose a man or a lady\n");
        scanf("%s",gender);
        scanf("%c",&phantom);
        if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {//验证输入只能为man 或lady
            valid=0;
        }
        if(valid==0&&phantom==' '){//防止scanf不能识别空格
            valid=1;
        }
    }
    while(valid==0){//进行电话输入的容错机制
        printf("Phone\n");
        printf("The telephone number should be 11 digits\n");
        scanf("%s",phone);
        scanf("%c",&phantom);
        valid=1;
        if(strlen(phone)!=11){//验证输入长度
            valid=0;
        }
        for(int k=0;k<11&&valid==1;k++) {//验证输入是否为数字
            if(isdigit(phone[k])==0){
                printf("The input must be a number\n");
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
            valid=0;
        }
    }
    printf("Password\n");
    scanf("%s",pass);
    while(valid==1){
        printf("Mailbox\n");//进行邮箱输入的容错机制
        printf("The correct format is ***@***.***\n");
        scanf("%s",mailbox);
        scanf("%c",&phantom);
        valid=0;
        if(strlen(mailbox)!=11){//验证输入长度
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
        if(valid==0&&phantom==' '){//防止scanf不能识别空格
            valid=1;
        }
    }
    printf("Address\n");
    scanf("%s",address);
    
    strcpy(IDF, ID);
    strcat(IDF, file);
    infile=fopen(IDF,"a+" );
    if(infile==NULL){//防止文件不能被打开
        printf("system error\n");
        exit(1);
    }
    fprintf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address,Balance);
    fclose(infile);//关闭文件
    Recharge(ID);//进行余额充值
}



void administrator(){
    char IDA[20],name[15],gender[15],phone[15],pass[15],mailbox[15],supermarket[15],IDF[15];
    int valid=0;
    char phantom;
    char file[]="a.txt";
    FILE *infile;
    while(valid==0){//进行ID输入的容错机制
        printf("Administrator ID\n");
        printf("Length 6-10 characters\n");
        scanf("%s",IDA);
        scanf("%c",&phantom);
        if(strlen(IDA)>5&&strlen(IDA)<11){//验证输入长度
            valid=1;
        }
        for(int k=0;k<11&&valid==1;k++) {//验证输入是否为字母或数字
            if(ispunct(IDA[k])!=0){
                printf("The input must be a letter or a number\n");
                valid=0;
            }
        }
        strcpy(IDF, IDA);
        strcat(IDF, file);
        infile=fopen(IDF,"r");
        if (valid==1&&infile!=NULL) {//使同一ID只能出现一次
            printf("ID already exists, please re-enter\n");
            valid=0;
        }
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
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
        if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {//验证输入只能为man 或lady
            valid=0;
        }
        if(valid==0&&phantom==' '){//防止scanf不能识别空格
            valid=1;
        }
    }
    while(valid==0){//进行电话输入的容错机制
        printf("Phone\n");
        printf("The telephone number should be 11 digits\n");
        scanf("%s",phone);
        scanf("%c",&phantom);
        valid=1;
        if(strlen(phone)!=11){//验证输入长度
            valid=0;
        }
        for(int k=0;k<11&&valid==1;k++) {//验证输入是否为数字
            if(isdigit(phone[k])==0){
                printf("The input must be a number\n");
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
            valid=0;
        }
    }
    printf("Password\n");
    scanf("%s",pass);
    while(valid==1){//进行邮箱输入的容错机制
        printf("Mailbox\n");
        printf("The correct format is ***@***.***\n");
        scanf("%s",mailbox);
        scanf("%c",&phantom);
        valid=0;
        if(strlen(mailbox)!=11){//验证输入长度
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
        if(valid==0&&phantom==' '){//防止scanf不能识别空格
            valid=1;
        }
    }
    while (valid==0) {//进行超市输入的容错机制
        printf("Supermarket\n");
        printf("Currently supports the top ten supermarket nationwide\n");
        scanf("%s",supermarket);
        scanf("%c",&phantom);
        if (strcmp(supermarket,"WM")==0||strcmp(supermarket,"CF")==0||strcmp(supermarket,"SN")==0) {//验证输入超市名
            valid=1;
        }
        if (strcmp(supermarket,"GM")==0||strcmp(supermarket,"VG")==0||strcmp(supermarket,"RT")==0) {//验证输入超市名
            valid=1;
        }
        if (strcmp(supermarket,"BL")==0||strcmp(supermarket,"YH")==0||strcmp(supermarket,"IZ")==0) {//验证输入超市名
            valid=1;
        }
        if (strcmp(supermarket,"WU")==0) {//验证输入超市名
            valid=1;
        }
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
            valid=0;
        }
    }
    
    strcpy(IDF, IDA);
    strcat(IDF, file);
    infile=fopen(IDF,"a+" );
    if(infile==NULL){//防止文件不能被打开
        printf("system error\n");
        exit(1);
    }
    fprintf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,pass,mailbox,supermarket);
    fclose(infile);//关闭文件
}



void logins(){
    char phantom;
    char a[2];
    int valid=0;
    while(valid==0)
    {
        printf("(a)Individual user login\n");
        printf("(b)Administrator login\n");
        printf("(c)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {userlogin();//进入用户登录界面
        }
        else if(strcmp(a,"b")==0)
        {administratorlogin();//进入管理员登录界面
        }
        else if(strcmp(a,"c")==0)
        {valid=1;}//返回程序上一级
    }
    
}



void userlogin(){
    char ID[15],password[15];
    int valid=0;
    char * IDpassword;
    printf("Please enter the user ID\n");
    scanf("%s",ID);
    IDpassword=userIDverification(ID);//验证用户密码是否正确
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
            userinterface(ID);//登录用户界面
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
    IDpassword=administratorIDverification(ID);//验证管理员密码是否正确
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
            administratorinterface(ID);//进入管理员界面
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
    infile=fopen(IDF,"r");//读取用户信息
    if (infile==NULL) {//验证用户密码是否正确
        strcpy(passwold, valid);
    }
    else{
        fscanf(infile,"%s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address);
        strcpy(passwold, pass);
        fclose(infile);
    }
    return passwold;//返回正确用户密码
}


char  * administratorIDverification(char * IDA){
    static char passwold[15];
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15],supermarket[15],Balance[15];
    FILE *infile;
    char file[]="a.txt";
    char IDF[20];
    char valid[]="h";
    strcpy(IDF, IDA);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//读取管理员信息
    if (infile==NULL) {//验证管理员密码是否正确
        strcpy(passwold, valid);
    }
    else{
        fscanf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,supermarket,Balance);
        strcpy(passwold, pass);
        fclose(infile);
    }
    return passwold;//返回正确管理员密码
}



void userinterface(char * ID){
    char phantom;
    char a[2];
    int valid=0;
    while(valid==0)
    {
        printf("(a)Goods inquiries\n");
        printf("(b)Recommendation\n");
        printf("(c)Personal information\n");
        printf("(d)Order\n");
        printf("(e)Balance inquiries and recharge\n");
        printf("(f)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {goodsinquiries(ID);//进入商品查找界面
        }
        else if(strcmp(a,"b")==0)
        {recommendation(ID);//进入热门推荐界面
        }
        else if(strcmp(a,"c")==0)
        {userinformation(ID);//进入用户信息界面
        }
        else if(strcmp(a,"d")==0)
        {Order(ID);//进入订单界面
        }
        else if(strcmp(a,"e")==0)
        {Recharge(ID);//进入余额查看和充值界面
        }
        else if(strcmp(a,"f")==0)
        {valid=1;
        }
    }
    
    
}


void administratorinterface(char * ID){
    char phantom;
    char a[2];
    int valid=0;
    char IDA[20],name[15],gender[15],phone[15],pass[15],mailbox[15],supermarket[15];
    char IDF[55];
    char file[]="a.txt";
    FILE *infile;
    strcpy(IDF, ID);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//获取管理员账户信息
    if (infile==NULL) {
        printf("system error\n");
        exit(1);
    }
    fscanf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,pass,mailbox,supermarket);
    fclose(infile);
    while(valid==0)
    {
        printf("(a)Order management\n");
        printf("(b)goods management\n");
        printf("(c)Personal information\n");
        printf("(d)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {printf("(a)Order order\n");//订单查看与过滤
            printf("(b)Sort of goods\n");//商品查看与过滤
            scanf("%s",a);
            scanf("%c",&phantom);
            if(strcmp(a,"a")==0)
            {printf("(a)Filter by retail price\n");//按照商品零售价过滤
                printf("(b)Filter by discountratea\n");//按照商品打折率过滤
                scanf("%s",a);
                scanf("%c",&phantom);
                if(strcmp(a,"a")==0)
                {ordermanagement(ID,1);//进入订单管理界面
                }
                else if(strcmp(a,"b")==0)
                {ordermanagement(ID,2);//进入订单管理界面
                }
            }
            else if(strcmp(a,"b")==0)
            {printf("(a)Filter by retail price\n");//按照商品零售价过滤
                printf("(b)Filter by Sales\n");//按照商品销量过滤
                scanf("%s",a);
                scanf("%c",&phantom);
                if(strcmp(a,"a")==0)
                {Commoditysearch(supermarket,2, 1);//进入商品排序界面
                }
                else if(strcmp(a,"b")==0)
                {Commoditysearch(supermarket,2, 2);//进入商品排序界面
                }
                
            }
        }
        else if(strcmp(a,"b")==0)
        {goodsmanagement(ID);//进入商品管理界面
        }
        else if(strcmp(a,"c")==0)
        {administratorinformation(ID);//进入管理员信息界面
        }
        else if(strcmp(a,"d")==0)//返回程序上一级
        {valid=1;
        }
    }
    
    
}



void goodsinquiries(char * ID){
    char commoditytype[15],marketname[15],brand[15];
    char phantom;
    char a[2];
    int valid=1,valida=0;
    while(valida==0)
    {
        printf("(a)Commoditytype\n");
        printf("(b)Marketname\n");
        printf("(c)Brand\n");
        printf("(d)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {   printf("Commoditytype\n");
            scanf("%s",commoditytype);
            printf("(a)Filter by retail price\n");//按照商品零售价过滤
            printf("(b)Filter by Sales\n");//按照商品销量过滤
            printf("(c)Filter by discount rate\n");//按照商品打折率过滤
            scanf("%s",a);
            scanf("%c",&phantom);
            if(strcmp(a,"a")==0)
            {Commoditysearch(commoditytype,1, 1);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
            else if(strcmp(a,"b")==0)
            {Commoditysearch(commoditytype, 1, 2);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
            else if(strcmp(a,"c")==0)
            {Commoditysearch(commoditytype, 1, 3);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
        }
        else if(strcmp(a,"b")==0)
        {while (valid==1) {
            printf("Supermarket\n");
            printf("Currently supports the top ten supermarket nationwide\n");
            scanf("%s",marketname);
            scanf("%c",&phantom);
            if (strcmp(marketname,"WM")==0||strcmp(marketname,"CF")==0||strcmp(marketname,"SN")==0) {//验证商品名称的输入
                valid=0;
            }
            if (strcmp(marketname,"GM")==0||strcmp(marketname,"VG")==0||strcmp(marketname,"RT")==0) {//验证商品名称的输入
                valid=0;
            }
            if (strcmp(marketname,"BL")==0||strcmp(marketname,"YH")==0||strcmp(marketname,"IZ")==0) {//验证商品名称的输入
                valid=0;
            }
            if (strcmp(marketname,"WU")==0) {//验证商品名称的输入
                valid=0;
            }
            if(valid==0&&phantom==' '){
                valid=1;
            }
            printf("(a)Filter by retail price\n");//按照商品零售价过滤
            printf("(b)Filter by Sales\n");//按照商品销量过滤
            printf("(c)Filter by discount rate\n");//按照商品打折率过滤
            scanf("%s",a);
            scanf("%c",&phantom);
            if(strcmp(a,"a")==0)
            {Commoditysearch(marketname,2, 1);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
            else if(strcmp(a,"b")==0)
            {Commoditysearch(marketname,2, 2);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
            else if(strcmp(a,"c")==0)
            {Commoditysearch(marketname,2, 3);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
        }
            
        }
        else if(strcmp(a,"c")==0)
        {printf("Brand\n");
            scanf("%s",brand);
            printf("(a)Filter by retail price\n");//按照商品零售价过滤
            printf("(b)Filter by Sales\n");//按照商品销量过滤
            printf("(c)Filter by discount rate\n");//按照商品打折率过滤
            scanf("%s",a);
            scanf("%c",&phantom);
            if(strcmp(a,"a")==0)
            {Commoditysearch(brand,3, 1);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
            else if(strcmp(a,"b")==0)
            {Commoditysearch(brand,3, 2);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
            else if(strcmp(a,"c")==0)
            {Commoditysearch(brand,3, 3);//进入商品排序界面
                purchase(ID);//进入购买界面
            }
            
        }
        else if(strcmp(a,"d")==0)//返回程序上一级
        {valida=1;
        }
    }
}

void recommendation(char * ID){
    char Commoditynumber[20],retailprice[15];
    char phantom;
    char a[2];
    int valid=0;
    while(valid==0)
    {
        printf("(a)Commodity price\n");//按照商品价格过滤
        printf("(b)Hot items\n");//按照热门商品过滤
        printf("(c)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {Commoditysearch(retailprice,4, 4);//进入商品排序界面
            purchase(ID);//进入购买界面
        }
        else if(strcmp(a,"b")==0)
        {Commoditysearch(Commoditynumber,4, 1);//进入商品排序界面
            purchase(ID);//进入购买界面
        }
        else if(strcmp(a,"c")==0)//返回程序上一级
        {valid=1;
        }
    }
}

void goodsmanagement(char * ID){
    char IDA[20],name[15],gender[15],phone[15],pass[15],mailbox[15],supermarket[15];
    char phantom;
    char a[2];
    int valid=0;
    char IDF[55];
    char file[]="a.txt";
    FILE *infile;
    strcpy(IDF, ID);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//获取管理员账户信息
    if (infile==NULL) {
        printf("system error\n");
        exit(1);
    }
    fscanf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,pass,mailbox,supermarket);
    fclose(infile);
    while(valid==0)
    {
        printf("(a)All goods\n");
        printf("(b)Goods add\n");
        printf("(c)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {Commoditysearch(supermarket,2, 2);//进入商品排序界面
        }
        else if(strcmp(a,"b")==0)
        {goodsadd(ID);//进入商品添加界面
        }
        else if(strcmp(a,"c")==0)//返回程序上一级
        {valid=1;
        }
        
    }
    
}

void userinformation(char * IDU){
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15],address[15],Balance[15];
    char IDF[55];
    char file[]=".txt";
    char phantom;
    char a[2];
    int valida=0,valid=1;
    double Balancea;
    FILE *infile;
    strcpy(IDF, IDU);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//获取用户账户信息
    if (infile==NULL) {
        printf("system error\n");
        exit(1);
    }
    fscanf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address,Balance);
    fclose(infile);
    Balancea=(atof(Balance));
    while(valida==0)
    {
        printf("(a)View personal information\n");
        printf("(b)Modify Personal Information\n");
        printf("(c)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {printf("ID:%s name:%s gender:%s phone:%s pass:%s mailbox%s address:%s Balancea:%5.2f\n",ID,name,gender,phone,pass,mailbox,address,Balancea);//输出用户信息
        }
        else if(strcmp(a,"b")==0)//修改用户账户信息内容
        {
            printf("Name\n");
            scanf("%s",name);
            while (valid==1) {
                printf("Gender\n");
                printf("Please choose a man or a lady\n");
                scanf("%s",gender);
                scanf("%c",&phantom);
                if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {//验证输入只能为man 或lady
                    valid=0;
                }
                if(valid==0&&phantom==' '){//防止scanf不能识别空格
                    valid=1;
                }
            }
            while(valid==0){
                printf("Phone\n");
                printf("The telephone number should be 11 digits\n");
                scanf("%s",phone);
                scanf("%c",&phantom);
                valid=1;
                if(strlen(phone)!=11){//验证输入长度
                    valid=0;
                }
                for(int k=0;k<11&&valid==1;k++) {//验证输入只能为字母或数字
                    if(isdigit(phone[k])==0){
                        valid=0;
                    }
                }
                if(valid==1&&phantom==' '){//防止scanf不能识别空格
                    valid=0;
                }
            }
            printf("Password\n");
            scanf("%s",pass);
            while(valid==1){
                printf("Mailbox\n");
                printf("The correct format is ***@***.***\n");
                scanf("%s",mailbox);
                scanf("%c",&phantom);
                valid=0;
                if(strlen(mailbox)!=11){//验证输入长度
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
                if(valid==0&&phantom==' '){//防止scanf不能识别空格
                    valid=1;
                }
            }
            printf("Address\n");
            scanf("%s",address);
            infile=fopen(IDF,"w" );
            if(infile==NULL){
                printf("system error\n");
                exit(1);
            }
            fprintf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address,Balance);
            fclose(infile);//关闭文件
        }
        else if(strcmp(a,"c")==0)
        {valida=1;
        }
    }
    
}


void administratorinformation(char * IDU){
    char IDA[20],name[15],gender[15],phone[15],pass[15],mailbox[15],supermarket[15];
    char IDF[55];
    char file[]="a.txt";
    char phantom;
    char a[2];
    int valida=0,valid=1;
    FILE *infile;
    strcpy(IDF, IDU);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//修改管理员信息
    if (infile==NULL) {
        printf("system error\n");
        exit(1);
    }
    fscanf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,pass,mailbox,supermarket);
    fclose(infile);
    while(valida==0)
    {
        printf("(a)View personal information\n");
        printf("(b)Modify Personal Information\n");
        printf("(c)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {printf("ID:%s name:%s gender:%s phone:%s pass:%s mailbox:%s supermarket:%s\n",IDA,name,gender,phone,pass,mailbox,supermarket);
        }//输出管理员信息
        else if(strcmp(a,"b")==0)
        {
            printf("Name\n");
            scanf("%s",name);
            while (valid==1) {
                printf("Gender\n");
                printf("Please choose a man or a lady\n");
                scanf("%s",gender);
                scanf("%c",&phantom);
                if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {//验证输入只能为man 或lady
                    valid=0;
                }
                if(valid==0&&phantom==' '){//防止scanf不能识别空格
                    valid=1;
                }
            }
            while(valid==0){
                printf("Phone\n");
                printf("The telephone number should be 11 digits\n");
                scanf("%s",phone);
                scanf("%c",&phantom);
                valid=1;
                if(strlen(phone)!=11){//验证输入长度
                    valid=0;
                }
                for(int k=0;k<11&&valid==1;k++) {//验证输入只能为字母或数字
                    if(isdigit(phone[k])==0){
                        valid=0;
                    }
                }
                if(valid==1&&phantom==' '){//防止scanf不能识别空格
                    valid=0;
                }
            }
            printf("Password\n");
            scanf("%s",pass);
            while(valid==1){
                printf("Mailbox\n");
                printf("The correct format is ***@***.***\n");
                scanf("%s",mailbox);
                scanf("%c",&phantom);
                valid=0;
                if(strlen(mailbox)!=11){//验证输入长度
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
                if(valid==0&&phantom==' '){//防止scanf不能识别空格
                    valid=1;
                }
            }
            infile=fopen(IDF,"w" );
            if(infile==NULL){
                printf("system error\n");
                exit(1);
            }
            fprintf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,pass,mailbox,supermarket);
            fclose(infile);//关闭文件
        }
        else if(strcmp(a,"c")==0)
        {valida=1;
        }
    }
    
}




void goodsadd(char *IDH){
    char Commoditynumber[20],marketname[15],discountstarttime[55],discountendtime[55],commoditytype[15],brand[15],retailprice[15],purchaseprice[55],inventory[55],discountrate[55],determine[15],Commoditynumberb[20],Sales[55];
    strcpy(Sales,"0");
    char IDA[20],name[15],gender[15],phone[15],pass[15],mailbox[15],supermarket[15];
    char IDF[55];
    char file[]="a.txt";
    char phantom;
    int valid=0;
    FILE *infile;
    strcpy(IDF, IDH);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//获取管理员账户信息
    if (infile==NULL) {
        printf("system error\n");
        exit(1);
    }
    fscanf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,pass,mailbox,supermarket);
    fclose(infile);
    while (valid==0) {
        printf("Commoditynumber\n");
        printf("Requires two letters four digits\n");
        scanf("%s",Commoditynumber);
        scanf("%c",&phantom);
        if (isalpha(Commoditynumber[0])!=0&&isalpha(Commoditynumber[1])!=0){//验证输入前两位为字母
            valid=1;
        }
        for(int k=2;k<6&&valid==1;k++) {
            if(isdigit(Commoditynumber[k])==0){//验证输入后四位为数字
                valid=0;
            }
        }
        if(valid==1&&strlen(Commoditynumber)!=6){//验证输入长度
            valid=0;
        }
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
            valid=0;
        }
        infile=fopen("goods.txt","r");//使商品号不能重复
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",Commoditynumberb,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime,Sales)!=EOF){
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
        if (strcmp(marketname,supermarket)==0) {//验证同一超市管理员只能添加自己超市商品
            valid=0;
        }
        if(valid==0&&phantom==' '){//防止scanf不能识别空格
            valid=1;
        }
    }
    printf("Commoditytype\n");
    scanf("%s",commoditytype);
    printf("Brand\n");
    scanf("%s",brand);
    while (valid==0) {
        int k=0;
        printf("Retail price\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",retailprice);
        scanf("%c",&phantom);
        if(isdigit(retailprice[0])!=0){//验证第一位为数字
            valid=1;
        }
        while (valid==1&&k<15) {
            if(isdigit(retailprice[k])==0){//使输入长度不受控并保证都为数字
                valid=0;
            }
            k++;
            if(retailprice[k]=='.'){//保证小数点位置
                break;
            }
        }
        if(valid==1&&retailprice[k]!='.'){//保证小数点位置
            valid=0;
        }
        if(valid==1&&(isdigit(retailprice[k+1])==0||isdigit(retailprice[k+2])==0)){//保证小数点后两位为数字
            valid=0;
        }
        if(valid==1&&strlen(retailprice)!=k+3){//验证输入长度
            valid=0;
        }
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
            valid=0;
        }
    }
    while (valid==1) {
        int k=0;
        printf("Purchase price\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",purchaseprice);
        scanf("%c",&phantom);
        if(isdigit(purchaseprice[0])!=0){//验证第一位为数字
            valid=0;
        }
        while (valid==0&&k<15) {
            if(isdigit(purchaseprice[k])==0){//使输入长度不受控并保证都为数字
                valid=1;
            }
            k++;
            if(purchaseprice[k]=='.'){//保证小数点位置
                break;
            }
        }
        if(valid==0&&purchaseprice[k]!='.'){//保证小数点位置
            valid=1;
        }
        if(valid==0&&(isdigit(purchaseprice[k+1])==0||isdigit(purchaseprice[k+2])==0)){//保证小数点后两位为数字
            valid=1;
        }
        if(valid==0&&strlen(purchaseprice)!=k+3){//验证输入长度
            valid=1;
        }
        if(valid==0&&phantom==' '){//防止scanf不能识别空格
            valid=1;
        }
    }
    
    while (valid==0) {
        int k=0;
        printf("Inventory\n");
        printf("According  format: xxx\n");
        scanf("%s",inventory);
        scanf("%c",&phantom);
        if(isdigit(inventory[0])!=0){//验证第一位为数字
            valid=1;
        }
        while (valid==1&&k<15) {
            if(isdigit(inventory[k])==0){//使输入长度不受控并保证都为数字
                valid=0;
            }
            k++;
            if(inventory[k]=='\0'){//验证输入最后一为
                break;
            }
        }
        if(valid==1&&strlen(inventory)!=k){//验证输入长度
            valid=0;
        }
        if(valid==1&&phantom==' '){//防止scanf不能识别空格
            valid=0;
        }
    }
    while (valid==1) {
        printf("Discount rate\n");
        printf("According to the percentage format: xx.x%% \n");
        scanf("%s",discountrate);
        scanf("%c",&phantom);
        if(isdigit(discountrate[0])!=0&&isdigit(discountrate[1])!=0){//验证输入前两位为字母
            valid=0;
        }
        if(valid==0&&discountrate[2]!='.'){//保证小数点位置
            valid=1;
        }
        if(valid==0&&isdigit(discountrate[3])==0){
            valid=1;
        }
        if(valid==0&&discountrate[4]!='%'){//保证百分号位置
            valid=1;
        }
        if(valid==0&&strlen(discountrate)!=5){//验证输入长度
            valid=1;
        }
        if(strcmp(discountrate,"100.00%")==0){//保证可以输入100%
            valid=0;
        }
        if(valid==0&&phantom==' '){//防止scanf不能识别空格
            valid=1;
        }
    }
    while (valid==0) {
        int leapyear=0;
        printf("Discount start time\n");
        printf("Match the time format yyyy:mm:dd:hh:mm\n");
        scanf("%s",discountstarttime);
        scanf("%c",&phantom);
        for(int k=0;k<4;k++) {
            if(isdigit(discountstarttime[k])!=0){//保证前四位是数字
                valid=1;
            }
        }
        if(valid==1&&discountstarttime[4]!=':'){//保证冒号位置
            valid=0;
        }
        if(valid==1&&isdigit(discountstarttime[5])==0&&isdigit(discountstarttime[6])==0){
            valid=0;
        }
        if(valid==1&&discountstarttime[5]!='0'&&discountstarttime[5]!='1'){//保证月份不能大于12
            valid=0;
        }
        if(valid==1&&discountstarttime[5]=='0'){
            if(discountstarttime[6]=='0'){
                valid=0;
            }
        }
        if(valid==1&&discountstarttime[5]=='1'){//保证月份不能大于12
            if(discountstarttime[6]>'2'){
                valid=0;
            }
        }
        if(valid==1&&discountstarttime[7]!=':'){//保证冒号位置
            valid=0;
        }
        if(valid==1&&isdigit(discountstarttime[8])==0&&isdigit(discountstarttime[9])==0){
            valid=0;
        }
        if(valid==1&&discountstarttime[8]>'3'){
            valid=0;
        }
        if(valid==1&&atoi(discountstarttime)%400==0){//判断是非为闰年
            leapyear=1;
        }
        if(valid==1&&atoi(discountstarttime)%4==0){
            leapyear=2;
        }
        if(valid==1&&atoi(discountstarttime)%100==0&&leapyear==2){//判断是非为闰年
            leapyear=0;
        }
        if(valid==1&&(leapyear==2||leapyear==1)){//判定闰年的2月份输入
            if(discountstarttime[5]=='0'&&discountstarttime[6]=='2'){
                if(discountstarttime[8]>'2'){
                    valid=0;
                }
                if(discountstarttime[8]=='0'&&discountstarttime[9]=='0'){
                    valid=0;
                }
            }
        }
        if(valid==1&&leapyear==0){//判定不是闰年的2月份输入
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
        if(valid==1&&(discountstarttime[6]=='1'||discountstarttime[6]=='3')&&discountstarttime[5]=='0'){//判定大月
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
        if(valid==1&&(discountstarttime[6]=='4'||discountstarttime[6]=='6')&&discountstarttime[5]=='0'){//判定小月
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
        if(valid==1&&discountstarttime[10]!=':'){//保证冒号位置
            valid=0;
        }
        if(valid==1&&discountstarttime[13]!=':'){//保证冒号位置
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
        if(valid==1&&discountstarttime[11]=='2'&&discountstarttime[12]=='4'){//判定时钟不能超过24
            if(discountstarttime[14]!='0'||discountstarttime[15]!='0'){
                valid=0;
            }
        }
        if(valid==1&&discountstarttime[14]>'6'){
            valid=0;
        }
        if(valid==1&&discountstarttime[14]=='6'){//判定分钟不能超过60
            if(discountstarttime[15]!='0'){
                valid=0;
            }
        }
        if(valid==1&&strlen(discountstarttime)!=16){
            valid=0;
        }
        if(strcmp(discountstarttime,"0000:00:00:00:00")==0){//保证可以输入0000:00:00:00:00
            valid=1;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    
    while (valid==1) {
        int leapyear=0;
        printf("Discount end time\n");
        printf("Match the time format yyyy:mm:dd:hh:mm\n");
        scanf("%s",discountendtime);
        scanf("%c",&phantom);
        for(int k=0;k<4;k++) {
            if(isdigit(discountendtime[k])!=0){//保证前四位是数字
                valid=0;
            }
        }
        if(valid==0&&strcmp(discountendtime,discountstarttime)<0){
            valid=1;
        }
        if(valid==0&&discountendtime[4]!=':'){//保证冒号位置
            valid=1;
        }
        if(valid==0&&isdigit(discountendtime[5])==0&&isdigit(discountendtime[6])==0){//保证月份不能大于12
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
        if(valid==0&&discountendtime[7]!=':'){//保证冒号位置
            valid=1;
        }
        if(valid==0&&isdigit(discountendtime[8])==0&&isdigit(discountendtime[9])==0){//保证月份不能大于12
            valid=1;
        }
        if(valid==0&&discountendtime[8]>'3'){
            valid=1;
        }
        if(valid==0&&atoi(discountendtime)%400==0){//判断是非为闰年
            leapyear=1;
        }
        if(valid==0&&atoi(discountendtime)%4==0){
            leapyear=2;
        }
        if(valid==0&&atoi(discountendtime)%100==0&&leapyear==2){//判断是非为闰年
            leapyear=0;
        }
        if(valid==0&&(leapyear==2||leapyear==1)){
            if(discountendtime[5]=='0'&&discountendtime[6]=='2'){//判定闰年的2月份输入
                if(discountendtime[8]>'2'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&leapyear==0){
            if(discountendtime[5]=='0'&&discountendtime[6]=='2'){//判定不是闰年的2月份输入
                if(discountendtime[8]=='2'){
                    if(discountendtime[9]>'8'){
                        valid=1;
                    }
                }
                if(discountendtime[8]>'2'){
                    valid=1;
                }
                if(discountendtime[8]=='0'&&discountendtime[9]=='0'){
                    valid=1;
                }
            }
        }
        if(valid==0&&(discountendtime[6]=='1'||discountendtime[6]=='3')&&discountendtime[5]=='0'){//判定大月
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
        if(valid==0&&(discountendtime[6]=='0'||discountendtime[6]=='2')&&discountendtime[5]=='1'){//判定小月
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
        if(valid==0&&discountendtime[10]!=':'){//保证冒号位置
            valid=1;
        }
        if(valid==0&&discountendtime[13]!=':'){//保证冒号位置
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
        if(valid==0&&discountendtime[11]=='2'&&discountendtime[12]=='4'){//判定时钟不能超过24
            if(discountendtime[14]!='0'||discountendtime[15]!='0'){
                valid=1;
            }
        }
        if(valid==0&&discountendtime[14]>'6'){
            valid=1;
        }
        if(valid==0&&discountendtime[14]=='6'){//判定分钟不能超过60
            if(discountendtime[15]!='0'){
                valid=1;
            }
        }
        if(valid==0&&strlen(discountendtime)!=16){
            valid=1;
        }
        if(strcmp(discountendtime,"0000:00:00:00:00")==0){//保证可以输入0000:00:00:00:00
            valid=0;
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
        if (strcmp(determine,"determine")==0||strcmp(determine,"negative")==0) {//做修改前最后的判定
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
        fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",Commoditynumber,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime,Sales);
        fclose(infile);//关闭文件
    }
}





void Commoditysearch(char * COM,int x,int y){
    char Commoditynumber[20],marketname[15],discountstarttime[55],discountendtime[55],commoditytype[15],brand[15],retailprice[15],purchaseprice[55],inventory[55],discountrate[55],Sales[55];
    
    char Commoditynumbera[500][20],marketnamea[500][15],discountstarttimea[500][55],discountendtimea[500][55],commoditytypea[500][15],branda[500][15],retailpricea[500][15],purchasepricea[500][15],inventorya[500][15],discountratea[500][15],Salesa[500][55];
    char Comparison[55],Comparisonb[55],tempa[55],tempb[55],tempc[55],tempd[55],tempe[55],tempf[55],tempg[55],temph[55],tempi[55],tempj[55],tempk[55];
    FILE *infile;
    int k=0;
    infile=fopen("goods.txt","r");//获取原来的商品信息
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    strcpy(Comparison, COM);
    while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",Commoditynumber,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime,Sales)!=EOF){
        if(x==1){
            strcpy(Comparisonb, commoditytype);//按商品类别查找
        }
        if(x==2){
            strcpy(Comparisonb, marketname);//按商品名称查找
        }
        if(x==3){
            strcpy(Comparisonb, brand);//按商品品牌查找
        }
        
        if( strcmp(Comparisonb,Comparison)==0&&(x==1||x==2||x==3)){//判定给出的变量
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
            strcpy(Salesa[k],Sales);
            k++;
        }
        if( x==4){
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
            strcpy(Salesa[k],Sales);
            k++;
        }
    }
    fclose(infile);
    if(y==1){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(atof(retailpricea[i])<atof(retailpricea[j])){//使用冒泡排序按商品零售价排序
                    
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
                    strcpy(tempk, Salesa[i]);
                    
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
                    strcpy(Salesa[i], Salesa[j]);
                    
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
                    strcpy(Salesa[j], tempk);
                    
                }
            }
        }
        printf("Commoditynumber  marketname  commoditytype  brand  retailprice  purchaseprice  inventory  discountrate  discountstarttime    discountendtime  Sales\n");//美化程序外观
        for (int g=0; g<k; g++) {
            printf("%9s %13s %13s %11s %9s %11s %11s %15s %20s %20s %3s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g],Salesa[g]);
        }
    }
    if(y==2){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(atoi(Salesa[i])<atoi(Salesa[j])){//使用冒泡排序按商品销量排序
                    
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
                    strcpy(tempk, Salesa[i]);
                    
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
                    strcpy(Salesa[i], Salesa[j]);
                    
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
                    strcpy(Salesa[j], tempk);
                    
                }
            }
        }
        printf("Commoditynumber  marketname  commoditytype  brand  retailprice  purchaseprice  inventory  discountrate  discountstarttime    discountendtime  Sales\n");
        for (int g=0; g<k; g++) {//美化程序外观
            printf("%9s %13s %13s %11s %9s %11s %11s %15s %20s %20s %3s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g],Salesa[g]);
        }
    }
    if(y==3){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(atof(discountratea[i])<atof(discountratea[j])){//使用冒泡排序按商品打折率排序
                    
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
                    strcpy(tempk, Salesa[i]);
                    
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
                    strcpy(Salesa[i], Salesa[j]);
                    
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
                    strcpy(Salesa[j], tempk);
                    
                }
            }
        }
        printf("Commoditynumber  marketname  commoditytype  brand  retailprice  purchaseprice  inventory  discountrate  discountstarttime    discountendtime  Sales\n");//美化程序外观
        for (int g=0; g<k; g++) {
            printf("%9s %13s %13s %11s %9s %11s %11s %15s %20s %20s %3s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g],Salesa[g]);
        }
    }
    if(y==4){
        printf("Commoditynumber  marketname  commoditytype  brand  retailprice  purchaseprice  inventory  discountrate  discountstarttime    discountendtime  Sales\n");//美化程序外观
        for (int g=0; g<k; g++) {
            printf("%9s %13s %13s %11s %9s %11s %11s %15s %20s %20s %3s\n",Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g],Salesa[g]);
        }
        
    }
    
    
}



void Recharge(char * IDU){
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15],address[15],Balance[15],code[15];
    FILE *infile;
    char file[]=".txt";
    char IDF[20];
    char phantom;
    char a[2];
    double balancea;
    strcpy(IDF, IDU);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//获取用户信息
    if (infile==NULL) {
        exit(1);
    }
    fscanf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address,Balance);
    fclose(infile);
    balancea=(atof(Balance));//将字符型转化为浮点型
    printf("The balance of your account is %5.2f\n",balancea);
    
    printf("Please choose the amount of recharge\n");
    printf("(a)1\n");
    printf("(b)5\n");
    printf("(c)50\n");
    printf("(d)100\n");
    printf("(e)500\n");
    printf("(f)5000\n");
    printf("(g)Return\n");
    scanf("%s",a);
    scanf("%c",&phantom);
    if(strcmp(a,"a")==0)
    {balancea=balancea+1;
        sprintf( Balance, "%f", balancea );//将浮点型转换为字符型
    }
    else if(strcmp(a,"b")==0)
    {balancea=balancea+5;
        sprintf( Balance, "%f", balancea );//将浮点型转换为字符型
    }
    else if(strcmp(a,"c")==0)
    {balancea=balancea+50;
        sprintf( Balance, "%f", balancea );//将浮点型转换为字符型
    }
    else if(strcmp(a,"d")==0)
    {balancea=balancea+100;
        sprintf( Balance, "%f", balancea );//将浮点型转换为字符型
    }
    else if(strcmp(a,"e")==0)
    {balancea=balancea+500;
        sprintf( Balance, "%f", balancea );//将浮点型转换为字符型
    }
    else if(strcmp(a,"f")==0)
    {balancea=balancea+5000;
        sprintf( Balance, "%f", balancea );//将浮点型转换为字符型
    }
    else if(strcmp(a,"g")==0)
    { return;//返回程序上一级
    }
    else{
        printf("Illegal input\n");
        return;//判定错误输入
    }
    printf("Enter the pass\n");
    scanf("%s",code);
    scanf("%c",&phantom);
    if(strcmp(code,pass)==0){//判定密码是否正确
        infile=fopen(IDF,"w");//将信息写入文件
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        fprintf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address,Balance);
        fclose(infile);
    }
    else{
        printf("Invitation code error\n");
    }
    
}

void purchase(char * IDU){
    char Commoditynumber[20],marketname[15],discountstarttime[55],discountendtime[55],commoditytype[15],brand[15],retailprice[15],purchaseprice[55],inventory[55],inventoryb[55],inventoryd[55],discountrate[55],Commoditynumberb[20],Sales[55],code[55],Ordernumber[55],Ordernumbera[55];
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15],address[15],Balance[15],a[2];
    char Commoditynumbere[500][20],marketnamee[500][15],discountstarttimee[500][55],discountendtimee[500][55],commoditytypee[500][15],brande[500][15],retailpricee[500][15],retailpricef[500][15],purchasepricee[500][15],inventorye[500][15],discountratee[500][15],Salese[500][55],inventoryh[500][55];
    char Commoditynumberf[500][20],marketnamef[500][15],discountstarttimef[500][55],discountendtimef[500][55],commoditytypef[500][15],brandf[500][15],retailpriceg[500][15],purchasepricef[500][15],inventoryf[500][15],discountratef[500][15],Salesf[500][55];
    char * Local;
    char * Locala;
    int valid=1,validb=0,validc=0,k=0,g=0,inventorya=0,inventoryc = 0,Salesa;
    double balancea,retailpricea,retailpriceb=0,discountratea;
    char phantom;
    char file[]=".txt";
    char IDF[55];
    FILE *infile;
    Local=timeas();
    while(validb==0)
    {   printf("(a)add to Shopping Cart\n");
        printf("(b)Settlement\n");
        printf("(c)Return\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(strcmp(a,"a")==0)
        {valid=0;
        }
        else if(strcmp(a,"b")==0)
        {  validb=2;
            valid=1;
        }
        else if(strcmp(a,"c")==0)
        {  return;
        }
        while (valid==0) {//判定输入的商品编号
            printf("Please enter the goods number\n");
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
            if(valid==1){
                int k=0;
                printf("Please enter the quantity purchased\n");
                scanf("%s",inventoryb);
                scanf("%c",&phantom);
                if(isdigit(inventoryb[0])!=0){//判定购买数是否符合要求
                    valid=1;
                }
                while (valid==1&&k<15) {
                    if(isdigit(inventoryb[k])==0){
                        valid=0;
                    }
                    k++;
                    if(inventoryb[k]=='\0'){
                        break;
                    }
                }
                if(valid==1&&strlen(inventoryb)!=k){
                    valid=0;
                }
                if(valid==1&&phantom==' '){
                    valid=0;
                }
            }
            if(valid==1){
                infile=fopen("goods.txt","r");//读取原有的商品信息
                if(infile==NULL){
                    printf("system error\n");
                    exit(1);
                }
                while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",Commoditynumberb,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime,Sales)!=EOF){
                    if(valid==1&&strcmp(Commoditynumber, Commoditynumberb)==0){
                        fclose(infile);
                        validc=1;
                        break;
                    }
                    
                    
                }
                if(validc==0){
                    printf("Goods do not exist\n");
                    break;
                }
            }
            if(valid==1){//判定购买量是否大于库存
                inventorya=(atoi(inventory));
                inventoryc=(atoi(inventoryb));
                if(inventorya<inventoryc){
                    printf("Inventory shortage\n");
                    return;
                }
            }
        }
        if(validb!=2){
            strcpy(IDF, IDU);
            strcat(IDF, file);
            infile=fopen(IDF,"r");//读取原有的用户信息
            if (infile==NULL) {
                exit(1);
            }
            fscanf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address,Balance);
            fclose(infile);
            inventorya=inventorya-inventoryc;//获得新的仓库商品数
            sprintf( inventory, "%d", inventorya );
            Salesa=(atoi(Sales));
            Salesa=Salesa+inventoryc;//获得新的销量
            sprintf( Sales, "%d", Salesa );
            sprintf( inventoryd, "%d", inventoryc );
            
            strcpy(Commoditynumbere[k],Commoditynumberb);//将信息存储到二维字符串中
            strcpy(marketnamee[k],marketname);
            strcpy(commoditytypee[k],commoditytype);
            strcpy(brande[k],brand);
            strcpy(retailpricee[k],retailprice);
            strcpy(purchasepricee[k],purchaseprice);
            strcpy(inventorye[k],inventory);
            strcpy(discountratee[k],discountrate);
            strcpy(discountstarttimee[k],discountstarttime);
            strcpy(discountendtimee[k],discountendtime);
            strcpy(Salese[k],Sales);
            strcpy(inventoryh[k],inventoryd);
            if(strcmp(Local,discountstarttime)>0&&strcmp(Local,discountendtime)<0){//判定当前时间是否为折扣时间
                retailpricea=(atof(retailprice));
                discountratea=(atof(discountrate)/100);
                retailpricea=retailpricea*discountratea;//计算购买商品的价格
            }
            else{
                retailpricea=(atof(retailprice));
            }
            sprintf( retailpricef[k], "%f", retailpricea );
            k++;
        }
    }
    printf("Enter the pass\n");
    scanf("%s",code);
    scanf("%c",&phantom);
    if(strcmp(code,pass)!=0){//验证密码是否正确
        printf("wrong password\n");
        return;
    }
    for(int i=0;i<k;i++){
        retailpriceb=retailpriceb+(atof(retailpricef[i]));//计算所有商品的总价值
    }
    balancea=(atof(Balance));//判定账户中余额是否足够支付
    if(balancea<retailpriceb){
        printf("Insufficient balance, please recharge\n");
        return;
    }
    else{
        balancea=balancea-retailpriceb;//扣钱
        printf("Purchase success!\n");
        printf("Account Balance:%5.2f\n",balancea);
        sprintf( Balance, "%f", balancea );
    }
    infile=fopen(IDF,"w");//将新文件写入文本中
    if (infile==NULL) {
        exit(1);
    }
    fprintf(infile,"%s %s %s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox,address,Balance);
    fclose(infile);
    infile=fopen("goods.txt","r");
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s",Commoditynumberb,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime,Sales)!=EOF){//读取原有文件
        strcpy(Commoditynumberf[g],Commoditynumberb);
        strcpy(marketnamef[g],marketname);
        strcpy(commoditytypef[g],commoditytype);
        strcpy(brandf[g],brand);
        strcpy(retailpriceg[g],retailprice);
        strcpy(purchasepricef[g],purchaseprice);
        strcpy(inventoryf[g],inventory);
        strcpy(discountratef[g],discountrate);
        strcpy(discountstarttimef[g],discountstarttime);
        strcpy(discountendtimef[g],discountendtime);
        strcpy(Salesf[g],Sales);
        g++;
    }
    fclose(infile);
    for(int i=0;i<k;i++){
        for(int l=0;l<g;l++){
            if(strcmp(Commoditynumberf[l],Commoditynumbere[i])==0){//将有变化的属性写入文件
                strcpy(marketnamef[l],marketnamee[i]);
                strcpy(commoditytypef[l],commoditytypee[i]);
                strcpy(brandf[l],brande[i]);
                strcpy(retailpriceg[l],retailpricee[i]);
                strcpy(purchasepricef[l],purchasepricee[i]);
                strcpy(inventoryf[l],inventorye[i]);
                strcpy(discountratef[l],discountratee[i]);
                strcpy(discountstarttimef[l],discountstarttimee[i]);
                strcpy(discountendtimef[l],discountendtimee[i]);
                strcpy(Salesf[l],Salese[i]);
            }
        }
    }
    infile=fopen("goods.txt","w");//将更新后文件写入文档
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    for(int i=0;i<g;i++){//进行程序外观的美化
        fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s\n",Commoditynumberf[i],marketnamef[i],commoditytypef[i],brandf[i],retailpriceg[i],purchasepricef[i],inventoryf[i],discountratef[i],discountstarttimef[i],discountendtimef[i],Salesf[i]);
    }
    fclose(infile);
    infile=fopen("Order.txt","a");//将更新后文件写入文档
    strcpy(Ordernumber," ");
    strcat(Ordernumber, ID);
    strcat(Ordernumber, Local);
    for(int i=0;i<k;i++){
        if(strcmp(marketnamee[0],marketnamee[i])==0){//做订单不同超市的自动整理
            fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",Ordernumber,Commoditynumbere[i],marketnamee[i],commoditytypee[i],brande[i],retailpricee[i],purchasepricee[i],inventorye[i],discountratee[i],discountstarttimee[i],discountendtimee[i],Salese[i],inventoryh[i]);
            
        }
        else{//如果超市不同订单号的最后两位加二
            Locala=timeas();
            Locala[15]=Locala[15]+2;
            strcpy(Ordernumbera," ");
            strcat(Ordernumbera, ID);
            strcat(Ordernumbera, Locala);
            fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",Ordernumbera,Commoditynumbere[i],marketnamee[i],commoditytypee[i],brande[i],retailpricee[i],purchasepricee[i],inventorye[i],discountratee[i],discountstarttimee[i],discountendtimee[i],Salese[i],inventoryh[i]);
            
        }
    }
    fclose(infile);
}



void Order(char * ID){
    char Commoditynumber[20],marketname[15],discountstarttime[55],discountendtime[55],commoditytype[15],brand[15],retailprice[15],purchaseprice[55],inventory[55],inventoryb[55],discountrate[55],Sales[55],Ordernumber[55];
    char Commoditynumbera[500][20],marketnamea[500][15],discountstarttimea[500][55],discountendtimea[500][55],commoditytypea[500][15],branda[500][15],retailpricea[500][15],purchasepricea[500][55],inventorya[500][55],inventoryba[500][55],discountratea[500][55],Salesa[500][55],Ordernumbera[500][55];
    char Comparison[55];
    int k=0,l=1,valid=0;
    FILE *infile;
    infile=fopen("Order.txt","r");//读取订单信息
    strcat(Comparison, ID);
    while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",Ordernumber,Commoditynumber,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime,Sales,inventoryb)!=EOF){
        valid=0;
        l=1;
        while (ispunct(Ordernumber[l])==0) {//读取订单号中的用户名
            l++;
        }
        for(int i=1;i<l-4;i++){
            if(Comparison[i]!=Ordernumber[i]){//判定用户名和订单号中的用户名是否一致
                valid=1;
            }
        }
        if(valid==0){//过滤使每个用户只能看到自己的订单
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
            strcpy(Salesa[k],Sales);
            strcpy(Ordernumbera[k],Ordernumber);
            strcpy(inventoryba[k],inventoryb);
            k++;
        }
    }
    fclose(infile);
    
    printf("        Ordernumber       Commoditynumber  marketname  commoditytype  brand  retailprice  purchaseprice  inventory  discountrate  discountstarttime    discountendtime  Sales  purchase\n");//进行界面的美化
    for (int g=0; g<k; g++) {
        printf("%25s %9s %13s %15s %9s %11s %11s %11s %13s %20s %20s %3s %6s\n",Ordernumbera[g],Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g],Salesa[g],inventoryba[g]);
    }
    
    
    
}

void ordermanagement(char * ID,int y){
    char IDA[20],name[15],gender[15],phone[15],pass[15],mailbox[15],supermarket[15];
    char IDF[55];
    char Commoditynumber[20],marketname[15],discountstarttime[55],discountendtime[55],commoditytype[15],brand[15],retailprice[15],purchaseprice[55],inventory[55],inventoryb[55],discountrate[55],Sales[55],Ordernumber[55];
    char Commoditynumbera[500][20],marketnamea[500][15],discountstarttimea[500][55],discountendtimea[500][55],commoditytypea[500][15],branda[500][15],retailpricea[500][15],purchasepricea[500][55],inventorya[500][55],inventoryba[500][55],discountratea[500][55],Salesa[500][55],Ordernumbera[500][55];
    char Comparison[55],Comparisonb[55],tempa[55],tempb[55],tempc[55],tempd[55],tempe[55],tempf[55],tempg[55],temph[55],tempi[55],tempj[55],tempk[55],templ[55],tempm[55];
    int k=0;
    double profit=0;
    char file[]="a.txt";
    FILE *infile;
    strcpy(IDF, ID);
    strcat(IDF, file);
    infile=fopen(IDF,"r");//读取管理员信息
    if (infile==NULL) {
        printf("system error\n");
        exit(1);
    }
    fscanf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,pass,mailbox,supermarket);
    fclose(infile);
    infile=fopen("Order.txt","r");
    strcpy(Comparison,supermarket);
    while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",Ordernumber,Commoditynumber,marketname,commoditytype,brand,retailprice,purchaseprice,inventory,discountrate,discountstarttime,discountendtime,Sales,inventoryb)!=EOF){
        strcpy(Comparisonb,marketname);
        if(strcmp(Comparisonb,Comparison)==0){//使每个超市只能查看自己的订单
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
            strcpy(Salesa[k],Sales);
            strcpy(Ordernumbera[k],Ordernumber);
            strcpy(inventoryba[k],inventoryb);
            k++;
        }
    }
    fclose(infile);
    if(y==1){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(strcmp(retailpricea[i],retailpricea[j])>0){//按零售价给订单排序
                    
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
                    strcpy(tempk, Salesa[i]);
                    strcpy(templ, Ordernumbera[i]);
                    strcpy(tempm, inventoryba[i]);
                    
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
                    strcpy(Salesa[i], Salesa[j]);
                    strcpy(Ordernumbera[i], Ordernumbera[j]);
                    strcpy(inventoryba[i], inventoryba[j]);
                    
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
                    strcpy(Salesa[j], tempk);
                    strcpy(Ordernumbera[j], templ);
                    strcpy(inventoryba[j], tempm);
                    
                }
            }
        }
        printf("        Ordernumber       Commoditynumber  marketname  commoditytype  brand  retailprice  purchaseprice  inventory  discountrate  discountstarttime    discountendtime  Sales  purchase\n");
        for (int g=0; g<k; g++) {//进行程序外观的美化
            printf("%25s %9s %13s %15s %11s %9s %11s %11s %13s %20s %20s %3s %6s\n",Ordernumbera[g],Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g],Salesa[g],inventoryba[g]);
        }
    }
    if(y==2){
        for(int i=0;i<k-1;i++) {
            for(int j=i+1;j<k;j++){
                if(strcmp(discountratea[i],discountratea[j])>0){//按打折率给订单排序
                    
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
                    strcpy(tempk, Salesa[i]);
                    strcpy(templ, Ordernumbera[i]);
                    strcpy(tempm, inventoryba[i]);
                    
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
                    strcpy(Salesa[i], Salesa[j]);
                    strcpy(Ordernumbera[i], Ordernumbera[j]);
                    strcpy(inventoryba[i], inventoryba[j]);
                    
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
                    strcpy(Salesa[j], tempk);
                    strcpy(Ordernumbera[j], templ);
                    strcpy(inventoryba[j], tempm);
                }
            }
        }
        printf("        Ordernumber       Commoditynumber  marketname  commoditytype  brand  retailprice  purchaseprice  inventory  discountrate  discountstarttime    discountendtime  Sales  purchase\n");
        for (int g=0; g<k; g++) {//进行程序外观的美化
            printf("%25s %9s %13s %15s %11s %9s %11s %11s %13s %20s %20s %3s %6s\n",Ordernumbera[g],Commoditynumbera[g],marketnamea[g],commoditytypea[g],branda[g],retailpricea[g],purchasepricea[g],inventorya[g],discountratea[g],discountstarttimea[g],discountendtimea[g],Salesa[g],inventoryba[g]);
        }
    }
    for(int i=0;i<k;i++){//加和营业时间中的总利润
        if(strcmp(supermarket,marketnamea[i])==0){
            profit=profit+(((atof(retailpricea[i]))-(atof(purchasepricea[i])))*(atof(inventorya[i])));
        }
    }
    printf("Full profit %5.2f\n",profit);
    
}


char * timeas(){
    char timea[551];
    static char Local[55];
    time_t timer;
    struct tm *tblock;
    timer=time(NULL);
    tblock=localtime(&timer);//读取系统本地的时间
    strcpy(timea, asctime(tblock));//将时间转换成标准格式
    if(timea[4]=='J'&&timea[5]=='a'&&timea[6]=='n'){
        Local[5]='0';
        Local[6]='1';
    }
    if(timea[4]=='F'&&timea[5]=='e'&&timea[6]=='b'){
        Local[5]='0';
        Local[6]='2';
    }
    if(timea[4]=='M'&&timea[5]=='a'&&timea[6]=='r'){
        Local[5]='0';
        Local[6]='3';
    }
    if(timea[4]=='A'&&timea[5]=='p'&&timea[6]=='r'){
        Local[5]='0';
        Local[6]='4';
    }
    if(timea[4]=='M'&&timea[5]=='a'&&timea[6]=='y'){
        Local[5]='0';
        Local[6]='5';
    }
    if(timea[4]=='J'&&timea[5]=='u'&&timea[6]=='n'){
        Local[5]='0';
        Local[6]='6';
    }
    if(timea[4]=='J'&&timea[5]=='u'&&timea[6]=='l'){
        Local[5]='0';
        Local[6]='7';
    }
    if(timea[4]=='A'&&timea[5]=='u'&&timea[6]=='g'){
        Local[5]='0';
        Local[6]='8';
    }
    if(timea[4]=='S'&&timea[5]=='e'&&timea[6]=='p'){
        Local[5]='0';
        Local[6]='9';
    }
    if(timea[4]=='O'&&timea[5]=='c'&&timea[6]=='t'){
        Local[5]='1';
        Local[6]='0';
    }
    if(timea[4]=='N'&&timea[5]=='o'&&timea[6]=='v'){
        Local[5]='1';
        Local[6]='1';
    }
    if(timea[4]=='D'&&timea[5]=='e'&&timea[6]=='c'){
        Local[5]='1';
        Local[6]='2';
    }
    Local[0]=timea[20];
    Local[1]=timea[21];
    Local[2]=timea[22];
    Local[3]=timea[23];
    Local[4]=':';
    Local[7]=':';
    Local[8]=timea[8];
    Local[9]=timea[9];
    Local[10]=':';
    Local[11]=timea[11];
    Local[12]=timea[12];
    Local[13]=':';
    Local[14]=timea[14];
    Local[15]=timea[15];
    return Local;
}
