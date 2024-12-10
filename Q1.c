#include <stdio.h>
#include<string.h>

struct Employee {

  int code;
  char name[30];
  char join_date[20];
  };

void assign(struct Employee *e) {
  printf("Enter employee name: ");
  scanf("%s", e->name);
  printf("Enter employee code: ");
  scanf("%d", &e->code);
  printf("Enter joining date (YYYY-MM-DD): ");
  scanf("%s", e->join_date);
  }

void date(struct Employee e[], int size, char *cdate) {
int cyear, cmonth, cday, i;
int t = 0, c= 0;
int jyear, jmonth, jday;

sscanf(cdate, "%d-%d-%d", &cyear, &cmonth, &cdate);

for(i = 0; i < size; i++) {
  

  sscanf(e[i].join_date, "%d-%d-%d", &jyear, &jmonth, &jday);

  t = cyear - jyear;
  if (cmonth < jmonth || (cmonth == jmonth && cday < jday)) {
    t--;
    }

  if(t > 3) {
    c++;
  
  printf("Employee code: %d\n", e[i].code);
  printf("Employee name: %s\n", e[i].name);
  printf("Joining date: %s\n", e[i].join_date);
  printf("Tenure: %d years\n", t);
  printf("\n");
  }
}

printf("Number of employees for more than 3 years: %d\n", c);
}

int main() {
struct Employee e[4];
int i;
char cdate[11];

for(i = 0; i < 4; i++) {
  printf("Enter employee %d details: \n", i + 1);
  assign(&e[i]);
  printf("\n");
}

printf("Enter current date (YYYY-MM-DD): ");
scanf("%s", &cdate);

date(e, 4, cdate);

return 0;
}
  
