#include <stdio.h>
//user-defined type
struct date {
	int year;
	int month;
	int day;
}

void printDate(int year, int month, int day)
{
	printf("%d/%d/%d\n", year, month, day);
}
void printDate2(struct date d)
{
	printf("%d/%d/%d\n", d.year, d.month, d.day);
}

int main(void)
{
	int today_year = 2023;
	int today_month = 3;
	int today_day = 6;
	
	int birthday_year = 2005;
	int birthday_month = 8;
	int birthday_day = 2;
	
	int tem_year;
	int tem_month;
	int tem_day;
	tem_year = today_year;
	tem_month = today_month;
	tem_dat = today_day;
	
	printDate(today_year, today_month, today_day);
	printDate(birthday_year, birthday_month, birthday_day);
///
	
	struct date today;
	today.year = 2023;
	today.month = 3;
	today.day = 6;
	
	struct date birthday = {2005, 8, 2};
	
	struct date tmp;
	tmp = today;
	
	printDate2(today);
	printDate2(birthday);
	return 0;
}
