#include <stdio.h>

int main(void){
	struct Human{
		char name[100];
		int age;
	};

	struct Human human;
	printf("氏名：");
	scanf("%s", human.name);
	printf("年齢：");
	scanf("%d", &human.age);

	//int miseinen = (human.name > 17) ? 1: 0;
	printf("%sは%sです！\n", human.name, human.age > 17 ? "成年": "未成年");
	return 0;
}
