#include <cstdio>
using namespace std;

int a, b, c, y1, y2;
int days[2][12] = {{31, 28, 31, 30, 31, 30,  31, 31, 30, 31, 30, 31}, 
					{31, 29, 31, 30, 31, 30,  31, 31, 30, 31, 30, 31}};
					
bool is_leap(int year){
	if((year%4==0 && year%100!=0) || year%400==0)
		return true;
	return false;
}

int main()
{
	
	scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
	int cur_day = 2;
	int cur_date = 1;
	for(int i=1850; i<y1; i++){
		cur_day = (cur_day + 365 + is_leap(i))%7;
	} //y1年1月1日 是星期cur_day
	for(int i=y1; i<=y2; i++){
		int temp_day = cur_day;	
		int flag = 0;
		if(is_leap(i)) {
			flag = 1;	
		}
		
		for(int j=1; j<a; j++){
			cur_day = (cur_day+days[flag][j-1])%7; //注意是j-1不是j 
		} //i年a月1日是星期cur_Day 
		
		if(cur_day == 0) cur_day = 7;
		if(cur_day <= c) cur_date = 1+(c - cur_day); //a月第1个星期c 
		else cur_date = 1+7-(cur_day - c); 
		cur_date += 7*(b-1);
		if(cur_date > days[flag][a-1]){
			printf("none\n"); //不要随意写continue! 
		}else{
			printf("%d/%02d/%02d\n", i, a, cur_date);
		}
		
		cur_day = (temp_day + 365 + flag)%7; //下一年 
		//printf("%d: %d\n", i+1, cur_day);
	}
	return 0;
}
