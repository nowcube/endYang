#include <stdio.h>
#include <stdlib.h>

int score_i = 0;
int scores[100];
int count;

void loginFunction() {
  int password = 123456;
  int x;
  int chance = 3;
  printf("********************************\n");
  printf("欢迎您使用本系统\n");
  do {
    printf("请输入密码：");
    scanf("%d", &x);
    if (x == password) {
      printf("密码正确，登陆成功！\n");
      break;
    } else {
      printf("密码错误。\n");
      if (chance > 1) {
        chance = chance - 1;
        printf("你当前还剩%d次机会\n", chance);
      } else {
        exit(0);
      }
    }
  } while (1 == 1);
}

void printFunction() {
  printf("********************************\n");
  printf("\t学生成绩管理系统\t\n");
  printf("********************************\n");
  printf("\t1 - 录入学生成绩\t\n");
  printf("\t2 - 显示学生成绩\t\n");
  printf("\t3 - 统计总分和平均分\t\n");
  printf("\t4 - 统计最高分和最低分\t\n");
  printf("\t5 - 统计各分段人数\t\n");
  printf("\t0 - 退出\t\n");
  // printf("********************************\n");
}

void inputStudentScore() {
  for (count = 0; count < 100; count++) {
    printf("请输入第%d个同学的分数：", count + 1);
    scanf("%d", &score_i);
    scores[count] = score_i;
    if (score_i == -1) {
      break;
    }
  }
}

void showStudentScore() {
  for (int i = 0; i < count; i++) {
    printf("第%d个同学的分数：%d\n", i + 1, scores[i]);
  }
}

void scoreAndAvg() {
  int score_all = 0;
  for (int i = 0; i < count; i++) {
    score_all += scores[i];
  }
  printf("总分为：%d    ", score_all);
  int score_per;
  score_per = score_all / count;
  printf("平均分为：%d\n", score_per);
}

void maxAndMin() {
  int max = scores[0];
  for(int i=0;i<count;i++){
    if(scores[i]>max){
      max = scores[i];
    }  
  }
  printf("最大值是：%d  ",max);
  int min = scores[0];
  for(int i=0;i<count;i++){
    if(scores[i]<min){
      min = scores[i];
    }
  }
  printf("最小值是：%d  \n",min);
}

void scoreGroup() {
  int a=0,b=0,c=0,d=0,e=0;
  for(int i=0;i<count;i++){
    if(scores[i]>90){a+=1;}
    if(scores[i]>80){b+=1;}
    if(scores[i]>70){c+=1;}
    if(scores[i]>60){d+=1;}
    else{e+=1;}
  }
  printf("优秀的人数是：%d\n",a);
  printf("良的人数是：%d\n" ,b);
  printf("只的人数是：%d\n",c);
  printf("合格的人数是：%d\n",d);
  printf("不合格的人数是：%d\n",e);
}

void selectFunction() {
  int input_number;
  while (1) {
    printf("********************************\n");
    printf("请输入数字以选择功能：");
    scanf("%d", &input_number);
    switch (input_number) {
    case 1:
      inputStudentScore();
      break;
    case 2:
      showStudentScore();
      break;
    case 3:
      scoreAndAvg();
      break;
    case 4:
      maxAndMin();
      break;
    case 5:
      scoreGroup();
      break;
    case 0:
      exit(0);
      break;
    }
  }
}

int main() {
  loginFunction();
  printFunction();
  selectFunction();
  return 0;
}
