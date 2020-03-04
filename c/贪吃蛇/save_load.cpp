#include "tcs.h"

FILE * mem;     //游戏存档文件句柄
FILE *fp;

struct savescore {
	char name[20];
	int grade;
}person[3], temp, t;

void Save() {
	if ((mem = fopen("memory.txt", "wb")) == NULL) {
		printf("无法打开memory.txt!\n");
		fclose(mem);
	}
	else {
		fwrite(&sleeptime, sizeof(sleeptime), 1, mem);
		fwrite(&score, sizeof(score), 1, mem);
		fclose(mem);
	}
}

void Load() {//读取游戏存档
	if ((mem = fopen("memory.txt", "rb")) == NULL) {
		printf("\n\n\n\n\t\t无存档\n");
		fclose(mem);
	}
	else {
		fread(&sleeptime, sizeof(sleeptime), 1, mem);
		fread(&score, sizeof(score), 1, mem);
		fclose(mem);
	}
}


void ScoreSave() {
	int i;
	if ((fp = fopen("排行榜.txt", "ab+")) == NULL) {
		printf("无法打开排行榜.txt!\n");
		fclose(fp);
	}
	else {
		Pos(12, 5);
		printf("请输入玩家的名字：\n\n\t\t");
		scanf("%s", temp.name);
		fp = fopen("排行榜.txt", "ab+");
		fread(&person[0], sizeof(person[0]), 1, fp);
		fread(&person[1], sizeof(person[1]), 1, fp);
		fread(&person[2], sizeof(person[2]), 1, fp);
		fclose(fp);
		if (person[0].grade == 0)
		{
			person[0].grade = score;
			person[1].grade = 0;
			person[2].grade = 0;
			strcpy(person[0].name, temp.name);
		}
		else if (person[1].grade == 0) {
			person[1].grade = score;
			person[2].grade = 0;
			strcpy(person[1].name, temp.name);
		}
		else if (person[2].grade == 0) {
			person[2].grade = score;
			strcpy(person[2].name, temp.name);
		}
		else if (score > person[2].grade) {
			person[2].grade = score;
			strcpy(person[2].name, temp.name);
		}
		if (person[2].grade > person[1].grade) {
			t.grade = person[2].grade;
			person[2].grade = person[1].grade;
			person[1].grade = t.grade;
			strcpy(t.name, person[2].name);
			strcpy(person[2].name, person[1].name);
			strcpy(person[1].name, t.name);
		}
		if (person[1].grade > person[0].grade) {
			t.grade = person[1].grade;
			person[1].grade = person[0].grade;
			person[0].grade = t.grade;
			strcpy(t.name, person[1].name);
			strcpy(person[1].name, person[0].name);
			strcpy(person[0].name, t.name);
		}
		if ((fp = fopen("排行榜.txt", "wb")) == NULL) {
			printf("无法打开排行榜.txt!\n");
			fclose(fp);
		}
		else {
			for (i = 0; i < 3; i++)
				fwrite(&person[i], sizeof(savescore), 1, fp);
			fclose(fp);
		}
	}
	printf("\n\n\t  ");
	system("cls");
}

void ScoreLoad() {
	int i, flag = 0;
	if ((fp = fopen("排行榜.txt", "rb+")) == NULL) {
		printf("\n\n\n\t\t\t\t  暂无游戏记录\n");
		fclose(fp);
	}
	else {
		fp = fopen("排行榜.txt", "rb+");
		for (i = 0; i < 3; i++)
			fread(&person[i], sizeof(savescore), 1, fp);
		Pos(50, 5);
		printf("   排行榜\n");
		for (i = 0; i < 3; i++) {
			Pos(50, 7 + 2 * i);
			printf("第%d名  %-10s：%6d", i + 1, person[i].name, person[i].grade);
		}
		fclose(fp);
	}
}
