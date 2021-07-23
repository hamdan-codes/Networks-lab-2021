#include<stdio.h>
#include<string.h>

struct info {
	int roll_no;
	char name[50];
	float CGPA;
};

void print(struct info *stud) {

	printf("Roll Number: %d\n", stud->roll_no);
	printf("Name: %s\n", stud->name);
	printf("CGPA: %.2f\n", stud->CGPA);

}


int main() {

	struct info stud;

	stud.roll_no = 1905387;
	strcpy(stud.name , "Hamdan");
	stud.CGPA = 9.60;

	print(&stud);


	return 0;
}
