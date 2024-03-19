#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
char *dayName;
int date;
char *activityDescription;
};
struct Day *create() {
struct Day *calendar = (struct Day *)malloc(7 * sizeof(struct Day));
if (calendar == NULL) {
printf("Memory allocation failed.\n");
exit(1);
}
return calendar;
}
void read(struct Day *calendar) {
for (int i = 0; i < 7; ++i) {
printf("Enter the name of the day: ");
char tempName[50];
scanf("%s", tempName);
calendar[i].dayName = (char *)malloc((strlen(tempName) + 1) * sizeof(char));
strcpy(calendar[i].dayName, tempName);
printf("Enter the date of the day: ");
scanf("%d", &calendar[i].date);
printf("Enter the activity description for %s: ", calendar[i].dayName);
char tempDesc[100];
scanf(" %[^\n]s", tempDesc);
calendar[i].activityDescription = (char *)malloc((strlen(tempDesc) + 1) * sizeof(char));
strcpy(calendar[i].activityDescription, tempDesc);
}
}
void display(struct Day *calendar) {
printf("\nCalendar Details:\n");
for (int i = 0; i < 7; ++i) {
printf("Day: %s\n", calendar[i].dayName);
printf("Date: %d\n", calendar[i].date);
printf("Activity: %s\n\n", calendar[i].activityDescription);
}
}
void freeMemory(struct Day *calendar) {
for (int i = 0; i < 7; ++i) {
free(calendar[i].dayName);
free(calendar[i].activityDescription);
}
free(calendar);
}
int main() {
struct Day *myCalendar = create();
printf("Please enter the details for each day of the week:\n");
read(myCalendar);
display(myCalendar);
freeMemory(myCalendar);
return0;
