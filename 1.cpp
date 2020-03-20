#include<stdio.h>
#include<iostream>
#include<time.h>
int alive_days(int year_now, int month_now, int day_now, int year_b,int month_b, int day_b);
int month_days(int year, int month);
int decide_year(int year);
int alive_days(int year_now, int month_now, int day_now, int year_b,
        int month_b, int day_b) {
    int sum = 0; 
    int years = 0; 
    int years_arry[200]; 
    int pingNian = 0;    
    int runNian = 0;    
    years = year_now - year_b - 1;
    years_arry[0] = 0;
   
    for (int i = 0; i < years; i++) {
        years_arry[i] = year_now - i - 1;
    }
    if (years_arry[0] > 0) {    
        for (int i = 0; i < years; i++) {
            if (decide_year(years_arry[i]) == 1) {
                runNian++;
            } else {
                pingNian++;
            }
        }
        sum = pingNian * 365 + runNian * 366;
        sum = (sum + month_days(year_b, month_b) - day_b);
        while (++month_b <= 12) {
            sum = sum + month_days(year_b, month_b);
        }

        sum = sum + day_now;
        while (--month_now >= 1) {
            sum = sum + month_days(year_now, month_now);
        }
    } else {    
        if (month_now == month_b) {
            sum = day_now - day_b;
        } else {
            sum = sum + month_days(year_b, month_b) - day_b;
            while (++month_b < month_now) {
                sum = sum + month_days(year_b, month_b);
            }
            sum = sum + day_now;
        }
    }

    return sum;
}

int month_days(int year, int month) {
    int sum = 0;
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        sum = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        sum = 30;
        break;
    case 2:
        if (decide_year(year) == 1) {
            sum = 29;
        } else {
            sum = 28;
        }
    }
    return sum;
}
int decide_year(int year) {
    int flag = -1;
    if ((year % 4 == 0) && (year % 100 != 0)) {
        flag = 1;
    } else if (year % 400 == 0 && year % 100 == 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    return flag;
}
int main() {
    int year_now;   
    int month_now;    
    int day_now;    
    int year_b;   
    int month_b;    
    int day_b;    
    int days = 0;    
    int physical_days;
    int emotion_days;
    int intelligence_days;

   
    printf("请输入您的出生日期:\n");
    scanf_s("%d%d%d", &year_b, &month_b, &day_b);
    printf("--------------------\n");
    printf("请输入今天的日期是:\n");
    scanf_s("%d%d%d",&year_now, &month_now, &day_now);
    printf("--------------------\n");
    printf("您的出生日期为：%d-%d-%d\n", year_b, month_b, day_b);
    printf("今天的日期为：%d-%d-%d\n", year_now, month_now, day_now);
    days = alive_days(year_now, month_now, day_now, year_b, month_b, day_b);
    physical_days = days%28;
    emotion_days = days%33;
    intelligence_days = days%23;
	printf("今天您的体力处于周期的第%d天\n",physical_days);
	printf("今天您的情绪处于周期的第%d天\n",emotion_days);
	printf("今天您的智力处于周期的第%d天\n",intelligence_days);
    system("pause"）
    return0;
	
}
