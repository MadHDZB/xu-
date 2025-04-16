//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//static int scanf_back;//全局变量用于接收scanf返回值
//static int fscanf_back;//全局变量用于接收fscanf返回值
//static int STUDENT_ERROR;//student文件为空标志
//static int COURSE_SELECTON_ERROR;//course selection文件为空标志
//static int MARK_ERROR;//mark文件为空标志
//static int COURSE_INFORMATION_ERROR;//course information文件为空标志
////结构体定义课程信息
//typedef struct course{
//	int cnum;//课程编号，共6位
//	char cname[31];	//课程名称，假设最多10个字，一个汉字占3个字节
//	int score1;	//考试成绩
//	int score2;	//平时成绩
//	int score3;	//综合成绩
//	int creHour;//学分（credit hour）
//	char jud[4];//判断是否要重修
//	char semester1[16];//记录第一次重修学期，如：大一下学期。5个汉字
//	int score4; //记录第一次重修成绩
//	char semester2[16];//记录第二次重修学期，如：大一下学期。5个汉字
//	int score5; //记录第二次重修成绩
//	long long stuNum[200]; //选这门课的学生学号，假设最多选200个人
//	char judge[4];//判断成绩是否录入
//}course;
////结构体定义学生基本信息
//typedef struct student{
//	long long stuNum;//学号，共12位
//	char name[13];//姓名，汉字占三个字节，假设名字最多有4个字
//	char sex[4];//性别，使用“男”、“女”表示，一个汉字占3个字节
//	int age;//年龄
//	int dorm;//宿舍号
//	long long teleNum;//电话号码，共11位
//	course c[12];//选课信息，假设最多选12门课
//	char subject[31];//专业名称，最多十个字
//	struct student* next;	//链表的下一个节点
//}student;
////初始化链表
//student* initList()
//{
//	student* s = (student*)malloc(sizeof(student));
//	if (s == NULL) {
//		perror("创建节点失败");
//	}
//	s->stuNum = 0;
// 	strcpy(s->name, "0");
//	strcpy(s->sex, "0");
//	s->age = 0;
//	s->dorm = 0;
//	s->teleNum = 0;
//	s->next = NULL;
//	return s;
//}
////插入学生信息 -- 尾插法
//void insertTail(student* s, long long stuNum, char name[13], char sex[4], int age, int dorm, long long teleNum, char subject[31])
//{
//	//创建节点
//	student* p = (student*)malloc(sizeof(student));
//	if (p == NULL) {
//		printf("内存分配失败\n");
//		return;
//	}
//	//每个学生的12门课全部初始化
//	for (int i = 0; i < 12; i++) {
//		p->c[i].cnum = 0;
//		strcpy(p->c[i].cname, "\0");
//		p->c[i].score1 = 0;
//		p->c[i].score2 = 0;
//		p->c[i].score3 = 0;
//		p->c[i].creHour = 0;
//		strcpy(p->c[i].jud, "否\0");
//		strcpy(p->c[i].semester1, "\0");
//		p->c[i].score4 = 0;
//		strcpy(p->c[i].semester2, "\0");
//		p->c[i].score5 = 0;
//		strcpy(p->c[i].judge, "否\0");
//	}
//	//录入信息
//	p->stuNum = stuNum;
//	strncpy(p->name, name, 13);
//	strncpy(p->sex, sex, 4);
//	p->age = age;
//	p->dorm = dorm;
//	p->teleNum = teleNum;
//	strncpy(p->subject, subject, 31);
//	p->next = NULL;
//	//插入链表
//	while (s->next != NULL) {
//		s = s->next;
//	}
//	s->next = p;
//}
////增加链表节点
//void appendListToFile(student* s, const char* filename)
//{
//	FILE* file = fopen(filename, "a+");
//	if (file == NULL) {
//		printf("无法打开文件\n");
//		return;
//	}
//	//判断文件是否为空
//	fseek(file, 0, SEEK_END);//将文件指针移到文件末尾
//	long int fileSize = ftell(file);//得到文件总字节数
//	if (fileSize == 0) {
//		//文件为空，写入表头
//		fprintf(file, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		fprintf(file, "%-18s%-20s%-20s%-20s%-24s%-24s%-29s\n", "学号", "姓名", "性别", "年龄", "宿舍号码", "电话号码", "专业");
//		fprintf(file, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//	char choose[4] = { 0 };//选择开关
//	long long stuNum = 0;//学号
//	char name[13] = { 0 };//姓名
//	char sex[4] = { 0 };//性别
//	int age = 0;//年龄
//	int dorm = 0;//宿舍号
//	long long teleNum = 0;//电话号码
//	char subject[31] = { 0 };//专业
//
//	do {
//		//输入学生信息并写入文件
//		printf("请输入学生信息：\n");
//
//		printf("学号（请输入12位数字）：");
//		while (scanf("%lld", &stuNum) != 1 || stuNum < 100000000000 || stuNum >= 1000000000000) {
//			printf("输入错误，请输入12位数字的学号：");
//			while ((getchar()) != '\n');//清空输入缓存区中残留的字符，否则当输入其他字符（如字母a）时，程序会进入死循环，以下同理
//		}
//
//		printf("姓名（请输入汉字或字符，不多于4个字）：");
//		while (scanf("%s", name) != 1 || strlen(name) > 20) {
//			printf("输入错误，请输入不多于4个字的姓名：");
//			while ((getchar()) != '\n');
//		}
//
//		printf("性别（请输入“男”或“女”）：");
//		while (scanf("%s", sex) != 1 || (strcmp(sex, "男") != 0 && strcmp(sex, "女") != 0)) {
//			printf("输入错误，请输入“男”或“女”：");
//			while ((getchar()) != '\n');
//		}
//
//		printf("年龄：");
//		while (scanf("%d", &age) != 1 || age < 0 || age > 60) {
//			printf("输入错误，请输入正确的年龄：");
//			while ((getchar()) != '\n');
//		}
//
//		printf("宿舍号码（3位数字，范围：101-516，如：501）：");
//		while (scanf("%d", &dorm) != 1 || dorm / 100 < 1 || dorm / 100 > 5 || dorm % 100 > 16) {
//			printf("输入错误，请输入101-516之间的宿舍号码：");
//			while ((getchar()) != '\n');
//		}
//
//		printf("电话号码（请输入11位数字）：");
//		while (scanf("%lld", &teleNum) != 1 || teleNum < 10000000000 || teleNum >= 100000000000) {
//			printf("输入错误，请输入11位数字的电话号码：");
//			while ((getchar()) != '\n');
//		}
//
//		printf("专业（请输入汉字或字符，不多于10个汉字）：");
//		while (scanf("%s", subject) != 1 || strlen(subject) > 20) {
//			printf("输入错误，请输入不多于10个字的专业：");
//			while ((getchar()) != '\n');
//		}
//
//		fprintf(file, "%-18lld%-20s%-21s%-21d%-22d%-24lld%-29s\n", stuNum, name, sex, age, dorm, teleNum, subject);
//		fprintf(file, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		//插入节点
//		insertTail(s, stuNum, name, sex, age, dorm, teleNum, subject);
//		printf("录入信息成功！\n是否继续录入？（是/否）：");
//		scanf_back = scanf("%s", choose);
//		printf("\n");
//	} while (strcmp(choose, "是") == 0);
//	fclose(file);
//}
////删除链表节点
//int deleList(student* s, long long data)
//{
//	student* p = s;
//	int flag = 0;
//	while (p != NULL && p->next != NULL) {
//		if (p->next->stuNum == data) {
//			student* p1 = p->next;
//			p->next = p1->next;
//			free(p1);
//			flag = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (flag) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
////查询链表中的学生信息
//void findList(student* s, long long data)
//{
//	student* p = s->next;
//	int flag = 0;//标志
//	while (p != NULL) {
//		if (p->stuNum == data) {
//			flag = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (flag) {
//		printf("查询成功！\n");
//		printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		printf("%-18s%-20s%-20s%-20s%-24s%-24s%-29s\n", "学号", "姓名", "性别", "年龄", "宿舍号码", "电话号码", "专业");
//		printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		printf("%-18lld%-20s%-21s%-21d%-22d%-24lld%-29s\n", p->stuNum, p->name, p->sex, p->age, p->dorm, p->teleNum, p->subject);
//		printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//	else {
//		printf("名单中无此学生！");
//	}
//}
////更改链表中的学生信息
//student* alterList(student* s, long long data)
//{
//	student* p = s->next;
//	int flag = 0;//标志
//	int choose = 0;//选择开关
//	//找到该学生节点
//	while (p != NULL) {
//		if (p->stuNum == data) {
//			flag = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (flag) {
//		printf("学生姓名：%s\n", p->name);
//	site2:
//		//菜单
//		printf(" ___________________________________________________________________________________________________________\n");
//		printf("|                 请选择你要更改的信息:                                                                     |\n");
//		printf("|                 1.学号                    2.姓名                    3.性别                                |\n");
//		printf("|                 4.年龄                    5.宿舍号                  6.电话号码                            |\n");
//		printf("|                 7.专业                                                                                    |\n");
//		printf("|___________________________________________________________________________________________________________|\n");
//		printf("请输入你要执行的操作：");
//		scanf_back = scanf("%d", &choose);
//		switch (choose) {
//		case 1: {
//			printf("更改前学号：%lld\n", p->stuNum);
//			printf("请输入更改后的学号（共12位数字）：");
//			while (scanf("%lld", &p->stuNum) != 1 || p->stuNum < 100000000000 || p->stuNum >= 1000000000000) {
//				printf("输入错误，请输入12位数字的学号：");
//				while ((getchar()) != '\n');//清空输入缓存区中残留的字符，否则当输入其他字符（如字母a）时，程序会进入死循环，以下同理
//			}
//			break;
//		}
//		case 2: {
//			printf("更改前姓名：%s\n", p->name);
//			printf("请输入更改后的姓名（不多于4个字）：");
//			while (scanf("%s", p->name) != 1 || strlen(p->name) > 20) {
//				printf("输入错误，请输入不多于4个字的姓名：");
//				while ((getchar()) != '\n');
//			}
//			break;
//		}
//		case 3: {
//			printf("更改前姓别：%s\n", p->sex);
//			printf("请输入更改后的性别（“男”或“女”）：");
//			while (scanf("%s", p->sex) != 1 || (strcmp(p->sex, "男") != 0 && strcmp(p->sex, "女") != 0)) {
//				printf("输入错误，请输入“男”或“女”：");
//				while ((getchar()) != '\n');
//			}
//			break;
//		}
//		case 4: {
//			printf("更改前年龄：%d\n", p->age);
//			printf("请输入更改后的年龄：");
//			while (scanf("%d", &p->age) != 1 || p->age < 0 || p->age > 60) {
//				printf("输入错误，请输入正确的年龄：");
//				while ((getchar()) != '\n');
//			}
//			break;
//		}
//		case 5: {
//			printf("更改前宿舍号：%d\n", p->dorm);
//			printf("请输入更改后的宿舍号码（3位数字，范围：101-516，如：501）：");
//			while (scanf("%d", &p->dorm) != 1 || p->dorm / 100 < 1 || p->dorm / 100 > 5 || p->dorm % 100 > 16) {
//				printf("输入错误，请输入101-516之间的宿舍号码：");
//				while ((getchar()) != '\n');
//			}
//			break;
//		}
//		case 6: {
//			printf("更改前电话号码：%lld\n", p->teleNum);
//			printf("请输入更改后的电话号码（共11位数字）：");
//			while (scanf("%lld", &p->teleNum) != 1 || p->teleNum < 10000000000 || p->teleNum >= 100000000000) {
//				printf("输入错误，请输入11位数字的电话号码：");
//				while ((getchar()) != '\n');
//			}
//			break;
//		}
//		case 7: {
//			printf("更改前专业：%s\n", p->subject);
//			printf("请输入更改后的专业（不多于10个汉字）：");
//			while (scanf("%s", p->subject) != 1 || strlen(p->subject) > 20) {
//				printf("输入错误，请输入不多于10个字的专业：");
//				while ((getchar()) != '\n');
//			}
//			break;
//		}
//		default:
//			printf("输入错误！请重新输入\n");
//			goto site2;
//		}
//		printf("更改成功！\n");
//	}
//	else {
//		printf("名单中无此学生！");
//	}
//	return s;
//}
////将链表信息读入文件中
//void ListToFile(student* s, const char* filename)
//{
//	FILE* file = fopen(filename, "w");
//	//录入表头
//	fprintf(file, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fprintf(file, "%-18s%-20s%-20s%-20s%-24s%-24s%-29s\n", "学号", "姓名", "性别", "年龄", "宿舍号码", "电话号码", "专业");
//	fprintf(file, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	//录入信息
//	student* p = s->next;
//	while (p != NULL) {
//		fprintf(file, "%-18lld%-20s%-21s%-21d%-22d%-24lld%-29s\n", p->stuNum, p->name, p->sex, p->age, p->dorm, p->teleNum, p->subject);
//		fprintf(file, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		p = p->next;
//	}
//}
////增加数组中的课程信息并录入文件
//void appendArrayToFile(course c[100], const char* filename)
//{
//	FILE* file = fopen(filename, "a+");
//	if (file == NULL) {
//		printf("无法打开文件\n");
//		return;
//	}
//	//判断文件是否为空
//	fseek(file, 0, SEEK_END);
//	long int fileSize = ftell(file);
//	if (fileSize == 0) {
//		//文件为空，写入表头
//		fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		fprintf(file, "%-35s%s\n", "课程编号", "课程名称");
//		fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//	int i = 0;//记录已录入的课程数
//	char choose[4] = { 0 };//选择开关
//	do {
//		//输入课程信息并写入文件
//		printf("请输入课程信息：\n");
//
//		printf("课程编号（请输入6位数字）：");
//		while (scanf("%d", &c[i].cnum) != 1 || c[i].cnum < 100000 || c[i].cnum>1000000) {
//			printf("输入错误，请输入6位数字的课程编号：");
//			while ((getchar()) != '\n');
//		}
//
//		printf("课程名称（请输入汉字，不多于10个字）：");
//		while (scanf("%s", &c[i].cname) != 1 || strlen(c[i].cname) > 20) {
//			printf("输入错误，请输入不多于10个字的课程名称：");
//			while ((getchar()) != '\n');
//		}
//		fprintf(file, "%-35d%s\n", c[i].cnum, c[i].cname);
//		fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		i++;
//		printf("录入信息成功！\n是否继续录入？（是/否）：");
//		scanf_back = scanf("%s", choose);
//		printf("\n");
//	} while (strcmp(choose, "是") == 0);
//	fclose(file);
//}
////删除数组中的课程信息
//int deleArray(course c[], int cnum)
//{
//	int flag = 0;//标志
//	for (int i = 0; c[i].cnum != 0; i++) {
//		if (c[i].cnum == cnum) {
//			for (int j = i; c[j].cnum != 0; j++) {
//				c[j] = c[j + 1];
//			}
//			flag = 1;
//			break;
//		}
//	}
//	if (flag) {//成功删除
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
////将数组信息读入文件
//void ArrayToFile(course c[], const char* filename)
//{
//	FILE* file = fopen(filename, "w");
//	//录入表头
//	fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fprintf(file, "%-35s%s\n", "课程编号", "课程名称");
//	fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	//录入信息
//	for (int i = 0; c[i].cnum != 0; i++) {
//		fprintf(file, "%-35d%s\n", c[i].cnum, c[i].cname);
//		fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//}
////添加链表及数组中的选课信息
//void appendCourse(student* s, course c[])
//{
//	long long stuNum = 0;//学号
//	int cnum = 0;//课程编号
//	char cname[31] = { 0 };//课程名称
//	char choose[4] = { 0 };//选择开关
//	student* p = s->next;
//	printf("请选择要录入选课信息的学生（请输入学号）：");
//	while (scanf("%lld", &stuNum) != 1 || stuNum < 100000000000 || stuNum >= 1000000000000) {
//		printf("输入错误，请输入12位数字的学号：");
//		while ((getchar()) != '\n');
//	}
//	//将输入的学号与学生信息作匹配			
//	int sign = 0;//标志
//	while (p != NULL) {
//		if (stuNum == p->stuNum) {
//			sign = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (sign) {//输入学号存在，进行信息录入
//		printf("学生姓名：%s\n", p->name);
//		//fprintf(file1, "%-25lld%-27s", stuNum, p->name);
//		do {
//			while (1) {
//				printf("请输入你要录入的课程编号：");
//				scanf_back = scanf("%d", &cnum);
//				//将输入的课程编号与课程信息做匹配
//				int flag = 0;//标志
//				for (int i = 0; c[i].cnum != 0; i++) {
//					if (cnum == c[i].cnum) {
//						strncpy(cname, c[i].cname, 31);//记录课程名称
//						//将选该门课的学生记录在课程数组中
//						int j = 0;
//						while (1) {
//							if (c[i].stuNum[j] != 0) {
//								j++;
//							}
//							else {
//								c[i].stuNum[j] = stuNum;
//								break;
//							}
//						}
//						//将选该门课的学生记录在链表中
//						int k = 0;
//						while (strcmp(p->c[k].cname, "\0") != 0) {
//							k++;
//						}
//						strncpy(p->c[k].cname, cname, 30);
//						printf("成功录入：%s\n", c[i].cname);
//						flag = 1;
//						break;
//					}
//				}
//				if (!flag) {
//					printf("输入课程编号不存在，请重新输入!\n");
//				}
//				else {
//					printf("录入信息成功！\n");
//					break;
//				}
//			}
//			//循环控制，该学生是否要继续录入选课信息
//			printf("是否继续录入该学生信息？（是/否）：");
//			scanf_back = scanf("%s", choose);
//		} while (strcmp(choose, "是") == 0);
//	}
//	else {
//		printf("输入错误，名单中无此学生\n");
//	}
//}
////将选课信息和选课学生录入文件
//void CourseToFile(student* s, course c[], const char* filename1, const char* filename2)
//{
//	FILE* file1 = fopen(filename1, "w");
//	FILE* file2 = fopen(filename2, "w");
//	if (file1 == NULL || file2 == NULL) {
//		printf("无法打开文件\n");
//		return;
//	}
//	//将链表中的选课信息录入文件
//	fprintf(file1, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fprintf(file1, "%-25s%-27s%s\n", "学号", "姓名", "已选课程");
//	fprintf(file1, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	student* p = s->next;
//	while (p != NULL) {
//		if (strcmp(p->c[0].cname, "\0") == 0) {//如果该学生没有选课，则信息不录入
//			p = p->next;
//			continue;
//		}
//		fprintf(file1, "%-25lld%-27s", p->stuNum, p->name);
//		for (int i = 0; strcmp(p->c[i].cname, "\0") != 0; i++) {
//			fprintf(file1, "%s     ", p->c[i].cname);
//		}
//		fprintf(file1, "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		p = p->next;
//	}
//	//将课程数组中的选课学生录入文件
//	fprintf(file2, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fprintf(file2, "%-25s%s\n", "课程", "选课学生");
//	fprintf(file2, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	for (int i = 0; c[i].cnum != 0; i++) {
//		fprintf(file2, "%-25s", c[i].cname);
//		for (int j = 0; c[i].stuNum[j] != 0; j++) {
//			fprintf(file2, "%-15lld", c[i].stuNum[j]);
//		}
//		fprintf(file2, "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//}
////删除选课信息
//int deleCourse(long long stuNum, student* s, course c[])
//{
//	//将输入的学号与学生信息作匹配
//	int sign = 0;//学号存在标志
//	int cnum = 0;//课程编号
//	char cname[31] = { 0 };//课程名称
//	int flag1 = 0;//课程存在标志
//	int flag2 = 0;//学生确实选了该门课标志
//	student* p = s->next;
//	while (p != NULL) {
//		if (stuNum == p->stuNum) {
//			sign = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (sign) {//输入学号存在，进行删除操作
//		printf("进行删除选课操作的学生姓名：%s\n", p->name);
//		printf("该学生选课如下：[");
//		int i = 0;//索引
//		//在屏幕上输出该学生的所有选课，以供选择
//		while (strcmp(p->c[i + 1].cname, "") != 0) {
//			printf("%s  ", p->c[i].cname);
//			i++;
//		}
//		printf("%s]\n", p->c[i].cname);
//		printf("请输入你想删除的课程名称:");
//		scanf_back = scanf("%s", cname);
//		//删除课程数组中选该门课的学生
//		//将输入的课程编号与课程信息做匹配
//		for (int i = 0; strcmp(c[i].cname,"") != 0; i++) {
//			if (strcmp(c[i].cname, cname) == 0) {
//				//将输入的学号与选该门课的学生学号做匹配
//				for (int j = 0; c[i].stuNum[j] != 0; j++) {
//					if (c[i].stuNum[j] == stuNum) {
//						//将选该门课的学生从该课程数组的选课学生中删除
//						for (int k = j; c[i].stuNum[k] != 0; k++) {
//							c[i].stuNum[k] = c[i].stuNum[k + 1];
//						}
//						flag2 = 1;
//						break;
//					}
//				}
//				flag1 = 1;
//				break;
//			}
//		}
//		//删除学生选课数组中的该门课
//		for (int i = 0; strcmp(p->c[i].cname, "\0") != 0; i++) {
//			if (strcmp(p->c[i].cname, cname) == 0) {
//				//将该门课从该学生选课数组中删除
//				for (int j = i; strcmp(p->c[j].cname, "\0") != 0; j++) {
//					p->c[j] = p->c[j + 1];
//				}
//				break;
//			}
//		}
//		//错误处理
//		if (!flag1) {//课程不存在
//			return -1;
//		}
//		else;
//		if (!flag2) {//学生未选此课程
//			return -2;
//		}
//		else;
//	}
//	else {//学号不存在
//		return 0;
//	}
//	return 1;
//}
////添加学生成绩
//void appendMark(student* s)
//{
//	long long stuNum = 0;//学号
//	char cname[31] = { 0 };//课程名称
//	char choice[4] = { 0 };//选择开关
//	printf("请选择你要录入成绩的学生学号：");
//	while (scanf("%lld", &stuNum) != 1 || stuNum < 100000000000 || stuNum >= 1000000000000) {
//		printf("输入错误，请输入12位数字的学号：");
//		while ((getchar()) != '\n');
//	}
//	//将输入的学号与学生信息作匹配
//	student* p = s->next;
//	int sign = 0;//标志
//	while (p != NULL) {
//		if (stuNum == p->stuNum) {
//			sign = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (sign) {//输入学号存在，进行信息录入
//		printf("姓名：%s\n", p->name);
//		printf("该学生选课如下：[");
//		int i = 0;//索引
//		//在屏幕上输出该学生的所有选课，以供选择
//		while (strcmp(p->c[i + 1].cname, "") != 0) {
//			printf("%s  ", p->c[i].cname);
//			i++;
//		}
//		printf("%s]\n", p->c[i].cname);
//		printf("请输入你想录入成绩的课程名称:");
//		scanf_back = scanf("%s", cname);
//		int flag = 0;//标志
//		i = 0;//初始化
//		while (1) {
//			if (strcmp(cname, p->c[i].cname) == 0) {//与已录入的课程进行比对
//				flag = 1;
//				break;
//			}
//			i++;
//			if (strcmp(p->c[i].cname, "") == 0) {//字符为空说明该学生录入的课程比对完了
//				break;
//			}
//		}
//		if (!flag) {
//			printf("输入课程不存在，请重新输入");
//		}
//		else {
//			//输入数据并写入文件中
//			printf("请输入考试成绩：");
//			scanf_back = scanf("%d", &p->c[i].score1);
//
//			printf("请输入平时成绩：");
//			scanf_back = scanf("%d", &p->c[i].score2);
//
//			printf("请输入综合成绩：");
//			scanf_back = scanf("%d", &p->c[i].score3);
//
//			printf("请输入学分：");
//			scanf_back = scanf("%d", &p->c[i].creHour);
//
//			printf("请输入是否重修（“是”或“否”）：");
//			scanf_back = scanf("%s", p->c[i].jud);
//			//如果重修
//			if (strcmp(p->c[i].jud, "是") == 0) {
//				printf("请输入重修学期：");
//				scanf_back = scanf("%s", p->c[i].semester1);
//
//				printf("请输入重修成绩：");
//				scanf_back = scanf("%d", &p->c[i].score4);
//
//				printf("请输入是否第二次重修（“是”或“否”）：");
//				scanf_back = scanf("%s", p->c[i].jud);
//				//如果再次重修		假设最大重修次数为两次
//				if (strcmp(p->c[i].jud, "是") == 0) {
//					printf("请输入重修学期：");
//					scanf_back = scanf("%s", p->c[i].semester2);
//
//					printf("请输入重修成绩：");
//					scanf_back = scanf("%d", &p->c[i].score5);
//				}
//				else;
//			}
//			else;
//			strcpy(p->c[i].judge, "是\0");//标记这门课成绩已录入
//		}
//	}
//	else {
//		printf("输入错误，名单中无此学生\n");
//
//	}
//}
////将学生成绩录入文件
//void MarkToFile(student* s, const char* filename)
//{
//	FILE* file = fopen("mark.txt", "w");
//	if (file == NULL) {
//		printf("无法打开文件\n");
//		return;
//	}
//	//录入表头
//	fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fprintf(file, "%-23s%-20s%-25s%-26s%-24s%-23s%-26s%-23s%-21s%-20s%-20s%-20s%s\n", "学号", "姓名", "科目", "是否已录入成绩", "考试成绩", "平时成绩", "综合成绩", "学分", "是否重修", "重修学期1", "重修成绩1", "重修学期2", "重修成绩2");
//	fprintf(file, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	//录入信息
//	student* p = s->next;
//	while (p != NULL) {
//		for (int i = 0; strcmp(p->c[i].cname, "") != 0; i++) {
//			if (strcmp(p->c[i].judge, "是") == 0) {//成绩已录入时才将其录入文件
//				fprintf(file, "%-23lld%-20s%-30s%-23s%-24d%-23d%-25d%-24d%-19s", p->stuNum, p->name, p->c[i].cname, p->c[i].judge, p->c[i].score1, p->c[i].score2, p->c[i].score3, p->c[i].creHour, p->c[i].jud);
//				//如果重修则录入重修信息
//				if (strcmp(p->c[i].jud, "是") == 0) {
//					fprintf(file, "%-22s%-18d", p->c[i].semester1, p->c[i].score4);
//					//如果有第二次重修
//					if (strcmp(p->c[i].semester2, "\0") != 0) {
//						fprintf(file, "%-22s%d", p->c[i].semester2, p->c[i].score5);
//					}
//				}
//				fprintf(file, "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//			}
//		}
//		p = p->next;
//	}
//}
////删除学生成绩
//int deleMark(long long stuNum, student* s)
//{
//	int sign = 0;//标志
//	int flag = 0;//课程存在标志
//	char cname[31] = { 0 };//课程名称
//	student* p = s->next;
//	while (p != NULL) {
//		if (p->stuNum == stuNum) {
//			sign = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (sign) {//输入学号存在，进行删除操作
//		printf("进行删除选课操作的学生姓名：%s\n", p->name);
//		printf("该学生的选课如下：[");
//		int i = 0;//索引
//		//在屏幕上输出该学生的所有选课，以供选择
//		while (strcmp(p->c[i + 1].cname, "") != 0) {
//			printf("%s  ", p->c[i].cname);
//			i++;
//		}
//		printf("%s]\n", p->c[i].cname);
//		//输入课程名称
//		printf("请输入你想删除成绩的课程名称:");
//		scanf_back = scanf("%s", cname);
//		//将输入的课程编号与课程信息做匹配
//		for (int i = 0; strcmp(p->c[i].cname, "") != 0; i++) {
//			if (strcmp(p->c[i].cname, cname) == 0) {
//				//删除信息（初始化）
//				p->c[i].score1 = 0;
//				p->c[i].score2 = 0;
//				p->c[i].score3 = 0;
//				p->c[i].creHour = 0;
//				strcpy(p->c[i].jud, "否\0");
//				strcpy(p->c[i].semester1, "\0");
//				p->c[i].score4 = 0;
//				strcpy(p->c[i].semester2, "\0");
//				p->c[i].score5 = 0;
//				strcpy(p->c[i].judge, "否\0");
//				flag = 1;
//				break;
//			}
//			else;
//		}
//		if (!flag) {//课程不存在
//			return -1;
//		}
//		else;
//	}
//	else {
//		return 0;
//	}
//	return 1;
//}
////查询学生成绩
//void findMark(student* s, long long stuNum)
//{
//	student* p = s->next;
//	int flag = 0;//标志 
//	int flag1 = 0;//标志
//	while (p != NULL) {
//		if (p->stuNum == stuNum) {
//			flag = 1;//学生存在
//			break;
//		}
//		p = p->next;
//	}
//	if (strcmp(p->c[0].cname, "") != 0) {
//		flag1 = 1;//学生有选课
//	}
//	if (flag) {
//		if (flag1) {
//			printf("查询成功！\n");
//			//打印表头
//			printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//			printf("%-20s%-17s%-21s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%s\n", "学号", "姓名", "科目", "考试成绩", "平时成绩", "综合成绩", "学分", "是否重修", "重修学期1", "重修成绩1", "重修学期2", "重修成绩2");
//			printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//			//打印成绩信息
//			for (int i = 0; strcmp(p->c[i].cname, "") != 0; i++) {
//				if (strcmp(p->c[i].judge, "是") == 0) {//已录入成绩的信息才会打印出来
//					printf("%-20lld%-17s%-21s%-20d%-20d%-20d%-20d%-20s", p->stuNum, p->name, p->c[i].cname, p->c[i].score1, p->c[i].score2, p->c[i].score3, p->c[i].creHour, p->c[i].jud);
//					//如果重修则录入重修信息
//					if (strcmp(p->c[i].jud, "是") == 0) {
//						printf("%-20s%-20d", p->c[i].semester1, p->c[i].score4);
//						//如果有第二次重修
//						if (strcmp(p->c[i].semester2, "\0") != 0) {
//							printf("%-20s%-20d", p->c[i].semester2, p->c[i].score5);
//						}
//						else;
//					}
//					else;
//					printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//				}
//				else;
//			}
//		}
//		else {
//			printf("该学生没有选课!\n");
//		}
//	}
//	else {
//		printf("该学生不存在！\n");
//	}
//}
////从文件中读取数据恢复链表
//student* loadList(const char* filename1, const char* filename2, const char* filename3)
//{
//	FILE* file1 = fopen(filename1, "r");
//	FILE* file2 = fopen(filename2, "r");
//	FILE* file3 = fopen(filename3, "r");
//	if ((file1 == NULL) || (file2 == NULL) || (file3 == NULL)) {
//		printf("无法打开文件\n");
//		return NULL;
//	}
//	student* s = initList();//初始化
//	long long stuNum = 0;//学号
//	char name[13] = { 0 };//姓名
//	char sex[4] = { 0 };//性别
//	int age = 0;//年龄
//	int dorm = 0;//宿舍号
//	long long teleNum = 0;//电话号码
//	char subject[31] = { 0 };//专业
//	char cname[31] = { 0 };//课程名称
//	char nextchar = 0;//存储下一个字符
//	int score1 = 0;//考试成绩
//	int score2 = 0;//平时成绩
//	int score3 = 0;//综合成绩
//	int creHour = 0;//学分
//	char jud[4] = { 0 };//重修判断
//	char judge[4] = { 0 };//录入成绩判断
//
//	//恢复学生基本信息
//	//判断文件是否为空
//	fseek(file1, 0, SEEK_END);//将文件指针移到文件末尾
//	long int fileSize = ftell(file1);//得到文件总字节数
//	if (fileSize == 0) {
//		//文件为空
//		printf("学生基本信息为空！\n");
//		STUDENT_ERROR = 1;
//		return s;
//	}
//	rewind(file1);//恢复指针到文件开头
//	//读取表头
//	fscanf_back= fscanf(file1, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fscanf_back = fscanf(file1, "学号              姓名                性别                年龄                宿舍号码                电话号码                专业                         \n");
//	fscanf_back = fscanf(file1, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	do {
//		//读取数据及分隔符
//		fscanf_back = fscanf(file1, "%lld%s%s%d%d%lld%s", &stuNum, name, sex, &age, &dorm, &teleNum, subject);
//		while ((nextchar = fgetc(file1)) == ' ');//扫掉空格，读到非空格字符跳出循环（已知空格后面就是换行符，故此时刚好扫掉换行符）
//		fscanf_back = fscanf(file1, "--------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		//将数据输入到链表中
//		insertTail(s, stuNum, name, sex, age, dorm, teleNum, subject);
//		//循环条件
//		if ((nextchar = fgetc(file1)) == EOF) {//读取下一个字符，若文件结束则跳出循环
//			break;
//		}
//		else {
//			ungetc(nextchar, file1);//文件未结束，返回读到的字符
//		}
//	} while (1);
//	fclose(file1);
//
//	//恢复学生选课信息
//	//判断文件是否为空
//	fseek(file2, 0, SEEK_END);//将文件指针移到文件末尾
//	fileSize = ftell(file2);//得到文件总字节数
//	if (fileSize == 0) {
//		//文件为空
//		COURSE_SELECTON_ERROR = 1;
//		return s;
//	}
//	rewind(file2);//恢复指针到文件开头
//	//读取表头
//	fscanf_back = fscanf(file2, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fscanf_back = fscanf(file2, "学号                            姓名                       已选课程\n");
//	fscanf_back = fscanf(file2, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	while (1) {
//		//外循环条件
//		if ((nextchar = fgetc(file2)) == EOF) {//此时文件为空，不进入循环
//			break;
//		}
//		else {
//			ungetc(nextchar, file2);//文件未结束，返回读到的字符
//		}
//		//读取数据
//		fscanf_back = fscanf(file2, "%lld%s", &stuNum, name);
//		//找到链表对应节点
//		student* p = s->next;
//		while (p != NULL) {
//			if (p->stuNum == stuNum) {
//				break;
//			}
//			p = p->next;
//		}
//		int i = 0;//内循环索引
//		do {
//			//内循环条件
//			if ((nextchar = fgetc(file2)) == '\n') {
//				break;
//			}
//			else {
//				ungetc(nextchar, file2);
//			}
//			//读取数据并输入链表
//			fscanf_back = fscanf(file2, "%s", cname);
//			strncpy(p->c[i++].cname, cname, 30);
//			//扫去空格
//			while ((nextchar = fgetc(file2)) == ' ');
//			ungetc(nextchar, file2);
//		} while (1);
//		//读取分隔符
//		fscanf_back = fscanf(file2, "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//	fclose(file2);
//
//	//恢复学生成绩信息
//	//判断文件是否为空
//	fseek(file3, 0, SEEK_END);//将文件指针移到文件末尾
//	fileSize = ftell(file3);//得到文件总字节数
//	if (fileSize == 0) {
//		//文件为空
//		MARK_ERROR = 1;
//		return s;
//	}
//	rewind(file3);//恢复指针到文件开头
//	//读取表头
//	fscanf_back = fscanf(file3, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fscanf_back = fscanf(file3, "学号                   姓名                科目                     是否已录入成绩            考试成绩                平时成绩               综合成绩                  学分                   是否重修             重修学期1           重修成绩1           重修学期2           重修成绩2\n");
//	fscanf_back = fscanf(file3, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	while (1) {
//		//循环条件
//		if ((nextchar = fgetc(file3)) == EOF) {//此时文件为空，不进入循环
//			break;
//		}
//		else {
//			ungetc(nextchar, file3);//文件未结束，返回读到的字符
//		}
//		//读取数据
//		fscanf_back = fscanf(file3, "%lld%s%s%s%d%d%d%d%s", &stuNum, name, cname, judge, &score1, &score2, &score3, &creHour, jud);
//		//找到链表对应节点
//		student* p = s->next;
//		while (p != NULL) {
//			if (p->stuNum == stuNum) {	
//				break;
//			}
//			p = p->next;
//		}
//		int i = 0;//内循环索引
//		while (1) {
//			//匹配对应课程并录入数据
//			if (strcmp(cname, p->c[i].cname) == 0) {
//				strncpy(p->c[i].judge, judge, 3);
//				p->c[i].score1 = score1;
//				p->c[i].score2 = score2;
//				p->c[i].score3 = score3;
//				p->c[i].creHour = creHour;
//				strncpy(p->c[i].jud, jud, 3);
//				if (strcmp(jud, "是") == 0) {//判断是否重修
//					//记录重修
//					fscanf_back = fscanf(file3, "%s%d", p->c[i].semester1, &p->c[i].score4);//读取第一次重修信息
//					while ((nextchar = fgetc(file3)) == ' ');
//					ungetc(nextchar, file3);
//					if ((nextchar = fgetc(file3)) == '\n') {//判断第二次重修
//						break;
//					}
//					else {
//						ungetc(nextchar, file3);
//					}
//					fscanf_back = fscanf(file3, "%s%d", p->c[i].semester2, &p->c[i].score5);//读取第二次重修信息
//					break;
//				}
//				else {
//					break;
//				}
//			}
//			i++;
//		}
//		//读取分隔符
//		fscanf_back = fscanf(file3, "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	}
//	fclose(file3);
//	return s;
//}
////从文件中读取数据恢复数组
//course* LoadArray(const char* filename1, const char* filename2, course c[])
//{
//	FILE* file1 = fopen(filename1, "r");
//	FILE* file2 = fopen(filename2, "r");
//	if (file1 == NULL || file2 == NULL) {
//		printf("无法打开文件\n");
//		return NULL;
//	}
//	char nextchar;//存储下一个字符
//	int index = 0;//数组索引
//	//恢复课程基本信息
//	//判断文件是否为空
//	fseek(file1, 0, SEEK_END);//将文件指针移到文件末尾
//	long int fileSize = ftell(file1);//得到文件总字节数
//	if (fileSize == 0) {
//		//文件为空
//		COURSE_INFORMATION_ERROR = 1;
//		return c;
//	}
//	rewind(file1);//恢复指针到文件开头
//	//读取表头
//	fscanf_back = fscanf(file1, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fscanf_back = fscanf(file1, "课程编号                           课程名称\n");
//	fscanf_back = fscanf(file1, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	do {
//		//读取数据到数组中，并读取分隔符
//		fscanf_back = fscanf(file1, "%d%s", &c[index].cnum, c[index].cname);
//		while ((nextchar = fgetc(file1)) == ' ');//扫掉空格及换行符
//		fscanf_back = fscanf(file1, "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");		//循环条件
//		if ((nextchar = fgetc(file1)) == EOF) {//读取下一个字符，若文件结束则跳出循环
//			break;
//		}
//		else {
//			ungetc(nextchar, file1);//文件未结束，返回读到的字符
//		}
//		index++;
//	} while (1);
//	fclose(file1);
//	
//	//恢复选课学生
//	index = 0;//初始化
//	//读取表头
//	fscanf_back = fscanf(file2, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	fscanf_back = fscanf(file2, "课程                     选课学生\n");
//	fscanf_back = fscanf(file2, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//	do {
//		//循环条件
//		if ((nextchar = fgetc(file2)) == EOF) {//文件结束
//			break;
//		}
//		else {
//			ungetc(nextchar, file2);
//		}
//		//读取数据到数组中
//		fscanf_back = fscanf(file2, "%s", c[index].cname);
//		int j = 0;//选课学生数组的索引
//		while (1) {
//			if ((fscanf_back = fscanf(file2, "%lld", &c[index].stuNum[j])) == 0) {//读取失败，说明这一行读取完了
//				while ((nextchar = fgetc(file2)) == ' ');//扫掉空格及换行符
//				fscanf_back = fscanf(file2, "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
//				break;
//			}
//			j++;
//		}
//		index++;
//		fgetc(file2);//扫掉换行符
//	} while (1);
//	return c;
//}
////交换节点的数据
//void swap(student* p1, student* p2)
//{
//	long long stuNum = 0;//学号
//	char name[13] = { 0 };//姓名
//	char sex[4] = { 0 };//性别
//	int age = 0;//年龄
//	int dorm = 0;//宿舍号
//	long long teleNum = 0;//电话号码
//	course c[12] = { 0 };//课程数组
//	char subject[31] = { 0 };//专业
//
//	stuNum = p1->stuNum;
//	strncpy(name, p1->name, 12);
//	name[12] = '\0';
//	strncpy(sex, p1->sex, 3);
//	sex[3] = '\0';
//	age = p1->age;
//	dorm = p1->dorm;
//	teleNum = p1->teleNum;
//	memcpy(c, p1->c, sizeof(p1->c));//使用memcpy复制整个结构体数组的内容
//	strncpy(subject, p1->subject, 30);
//	subject[30] = '\0';
//
//	p1->stuNum = p2->stuNum;
//	strncpy(p1->name, p2->name, 12);
//	p1->subject[30] = '\0';
//	strncpy(p1->sex, p2->sex, 3);
//	p1->subject[30] = '\0';
//	p1->age = p2->age;
//	p1->dorm = p2->dorm;
//	p1->teleNum = p2->teleNum;
//	memcpy(p1->c, p2->c, sizeof(p2->c));//使用memcpy复制整个结构体数组的内容
//	strncpy(p1->subject, p2->subject, 30);
//	p1->subject[30] = '\0';
//
//	p2->stuNum = stuNum;
//	strncpy(p2->name, name, 12);	
//	p2->name[12] = '\0';
//	strncpy(p2->sex, sex, 3);
//	p2->sex[3] = '\0';
//	p2->age = age;
//	p2->dorm = dorm;
//	p2->teleNum = teleNum;
//	memcpy(p2->c, c, sizeof(c));//使用memcpy复制整个结构体数组的内容
//	strncpy(p2->subject, subject, 30);
//	p2->subject[30] = '\0';
//}
////链表排序
//void sort(student * s)
//{
//	student* p = s->next;
//	student* p1 = p;
//
//	//按年级进行排序
//	for (p1; p1->next != NULL; p1 = p1->next) {
//		p = s->next;
//		while (p->next != NULL) {
//			if ((p->stuNum / 100000000 % 100) > (p->next->stuNum / 100000000 % 100)) {
//				//交换节点的内容
//				swap(p, p->next);
//			}
//			p = p->next;
//		}
//	}
//	//按专业进行排序
//	p1 = s->next;
//	for (p1; p1->next != NULL; p1 = p1->next) {
//		p = s->next;
//		while (p->next != NULL) {
//			//年级相同时才进行专业的比较
//			if ((p->stuNum / 10000 % 100 > p->next->stuNum / 10000 % 100) && (p->stuNum / 100000000 % 100 == p->next->stuNum / 100000000 % 100)) {
//				//交换节点的内容
//				swap(p, p->next);
//			}
//			p = p->next;
//		}
//	}
//	//按班级进行排序
//	p1 = s->next;
//	for (p1; p1->next != NULL; p1 = p1->next) {
//		p = s->next;
//		while (p->next != NULL) {
//			//专业相同时才进行班级比较
//			if ((p->stuNum / 100 % 100 > p->next->stuNum / 100 % 100) && (p->stuNum / 10000 % 100 == p->next->stuNum / 10000 % 100)) {
//				//交换节点的内容
//				swap(p, p->next);
//			}
//			p = p->next;
//		}
//	}
//	//按座位号进行排序
//	p1 = s->next;
//	for (p1; p1->next != NULL; p1 = p1->next) {
//		p = s->next;
//		while (p->next != NULL) {
//			//班级相同时才进行座位号比较
//			if ((p->stuNum % 100 > p->next->stuNum % 100) && (p->stuNum / 100 % 100 == p->next->stuNum / 100 % 100)) {
//				//交换节点的内容
//				swap(p, p->next);
//			}
//			p = p->next;
//		}
//	}
//}
////释放链表空间
//void freeList(student* s)
//{
//	if (s == NULL)  return;
//	student* p = s->next;
//	while (p != NULL) {
//		student* p1 = p;
//		p = p->next;
//		free(p1);
//	}
//	s->next = NULL;
//}
//int main()
//{
//	course cc[100] = { 0 };//假设有100门课可供选择
//	student* s = initList();//链表初始化
//site:
//	//菜单
//	printf(" ___________________________________________________________________________________________________________\n");
//	printf("|                 请选择你要使用的功能:                                                                     |\n");
//	printf("|                 1.学生信息管理                               2.课程信息管理                               |\n");
//	printf("|                 3.选课信息管理                               4.学生成绩管理                               |\n");
//	printf("|                 5.获取各班选课情况及考试成绩                 6.获取各课程学生名单及考试成绩               |\n");
//	printf("|                 7.获取所有同学学分和不及格课程               8.退出                                       |\n");
//	printf("|___________________________________________________________________________________________________________|\n");
//	//选择功能
//	printf("请选择功能：");
//	int choose = 0;
//	scanf_back = scanf("%d", &choose);
//	switch (choose) {
//	//学生信息
//	case 1: {
//	site1:
//		//菜单
//		printf(" ___________________________________________________________________________________________________________\n");
//		printf("|                 请选择你要使用的功能:                                                                     |\n");
//		printf("|                 1.添加学生信息                               2.删除学生信息                               |\n");
//		printf("|                 3.查询学生信息                               4.更改学生信息                               |\n");
//		printf("|                 5.返回主菜单                                                                              |\n");
//		printf("|___________________________________________________________________________________________________________|\n");
//		printf("请输入你要执行的操作：");
//		scanf_back = scanf("%d", &choose);
//		switch (choose) {
//		//添加
//		case 1: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表信息
//			//添加节点并录入文件
//			appendListToFile(s, "student.txt");
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site1;
//			break;
//		}
//		//删除
//		case 2: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表信息
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site1;
//			}
//			long long stuNum = 0;//学号
//			printf("请输入你要删除学生的学号：");
//			while (scanf("%lld", &stuNum) != 1 || stuNum < 100000000000 || stuNum >= 1000000000000) {
//				printf("输入错误，请输入12位数字的学号：");
//				while ((getchar()) != '\n');
//			}
//			//删除节点
//			int result = deleList(s, stuNum);
//			if (result) {
//				printf("删除成功！\n");
//			}
//			else {
//				printf("名单中无此学生！\n");
//			}
//			//将链表录入文件
//			ListToFile(s, "student.txt");
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site1;
//			break;
//		}
//		//查询
//		case 3: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表信息
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site1;
//			}
//			long long stuNum = 0;//学号
//			printf("请输入你要查询的学生学号：");
//			scanf_back = scanf("%lld", &stuNum);
//			//查询并打印节点
//			findList(s, stuNum);
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site1;
//			break;
//		}
//		//更改
//		case 4: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表信息
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site1;
//			}
//			long long stuNum = 0;//学号
//			printf("请输入你要更改信息的学生学号：");
//			scanf_back = scanf("%lld", &stuNum);
//			//更改节点并返回头节点
//			student* p = alterList(s, stuNum);
//			//将链表录入文件
//			ListToFile(s, "student.txt");
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site1;
//			break;
//		}
//		//返回主菜单
//		case 5:
//			goto site;
//		default:
//			printf("输入错误！请重新输入\n");
//			goto site1;
//		}
//		//返回
//		printf("已自动返回上一级菜单\n");
//		goto site1;
//		break;
//	}
//	//课程信息
//	case 2: {
//	site3:
//		//菜单
//		printf(" ___________________________________________________________________________________________________________\n");
//		printf("|                 请选择你要使用的功能:                                                                     |\n");
//		printf("|                 1.添加课程信息                               2.删除课程信息                               |\n");
//		printf("|                 3.返回主菜单                                                                              |\n");
//		printf("|___________________________________________________________________________________________________________|\n");
//		printf("请输入你要执行的操作：");
//		scanf_back = scanf("%d", &choose);
//		switch (choose) {
//		//添加
//		case 1: {
//			//添加数组信息并录入文件
//			appendArrayToFile(cc, "course information.txt");
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site3;
//			break;
//		}
//		//删除
//		case 2: {
//			course* c = LoadArray("course information.txt", "course people.txt", cc);//恢复数组信息
//			//文件为空导致数组为空的判断与处理
//			if (COURSE_INFORMATION_ERROR == 1) {
//				printf("错误：课程信息为空！\n");
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site3;
//			}
//			int cnum = 0;//课程编号
//			printf("请输入你要删除的课程编号：");
//			while (scanf("%d", &cnum) != 1 || cnum < 100000 || cnum>1000000) {
//				printf("输入错误，请输入6位数字的课程编号：");
//				while ((getchar()) != '\n');
//			}
//			//删除课程信息
//			int result = deleArray(c, cnum);
//			if (result) {
//				printf("删除成功！\n");
//			}
//			else {
//				printf("名单中无此课程！\n");
//			}
//			//将数组录入文件
//			ArrayToFile(c, "course information.txt");
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site3;
//			break;
//			//释放数组内存
//			free(c);
//			break;
//		}
//		//返回主菜单
//		case 3:
//			goto site;
//		default:
//			printf("输入错误！请重新输入\n");
//			goto site3;
//		}
//		//返回
//		printf("已自动返回上一级菜单\n");
//		goto site3;
//		break;
//	}
//		//选课信息
//	case 3: {
//	site4:
//		//菜单
//		printf(" ___________________________________________________________________________________________________________\n");
//		printf("|                 请选择你要使用的功能:                                                                     |\n");
//		printf("|                 1.添加选课信息                               2.删除选课信息                               |\n");
//		printf("|                 3.返回主菜单                                                                              |\n");
//		printf("|___________________________________________________________________________________________________________|\n");
//		printf("请输入你要执行的操作：");
//		scanf_back = scanf("%d", &choose);
//		switch (choose) {
//		//添加
//		case 1: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//			course* c = LoadArray("course information.txt", "course people.txt", cc);//恢复数组
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			//文件为空导致数组为空的判断与处理
//			if (COURSE_INFORMATION_ERROR == 1) {
//				printf("错误：课程信息为空！\n");
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			//添加选课信息
//			appendCourse(s, c);
//			//将更新后的选课信息录入文件
//			CourseToFile(s, c, "course selection.txt", "course people.txt");
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site4;
//			break;
//			//释放数组内存
//			free(c);
//			break;
//		}
//		//删除
//		case 2: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//			course* c = LoadArray("course information.txt", "course people.txt", cc);//恢复数组
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			if (COURSE_SELECTON_ERROR == 1) {
//				printf("错误：学生选课信息为空！\n");
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site4;
//			}
//			//文件为空导致数组为空的判断与处理
//			if (COURSE_INFORMATION_ERROR == 1) {
//				printf("错误：课程信息为空！\n");
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site3;
//			}
//			//删除选课信息
//			long long stuNum = 0;//学号
//			printf("请输入你要删除选课信息的学生学号：");
//			while (scanf("%lld", &stuNum) != 1 || stuNum < 100000000000 || stuNum >= 1000000000000) {
//				printf("输入错误，请输入12位数字的学号：");
//				while ((getchar()) != '\n');
//			}
//			int result = deleCourse(stuNum, s, c);
//			if (result == 1) {
//				printf("删除成功！\n");
//				//将更新后的选课信息录入文件
//				CourseToFile(s, c, "course selection.txt", "course people.txt");
//			}
//			else if (result == -1) {
//				printf("名单中无此课程!\n");
//			}
//			else if (result == -2) {
//				printf("该学生选课中无此课程!\n");
//			}
//			else if (!result) {
//				printf("学号不存在！\n");
//			}
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site4;
//			break;
//			//释放数组内存
//			free(c);
//			break;
//		}
//    	//返回主菜单
//		case 3:
//			goto site;
//		default:
//			printf("输入错误！请重新输入\n");
//			goto site4;
//		}
//		//返回
//		printf("已自动返回上一级菜单\n");
//		goto site4;
//		break;
//	}
//	//学生成绩
//	case 4: {
//	site5:
//		//菜单
//		printf(" ___________________________________________________________________________________________________________\n");
//		printf("|                 请选择你要使用的功能:                                                                     |\n");
//		printf("|                 1.添加成绩信息                               2.删除成绩信息                               |\n");
//		printf("|                 3.查询成绩信息                               4.返回主菜单                                 |\n");
//		printf("|___________________________________________________________________________________________________________|\n");
//		printf("请输入你要执行的操作：");
//		scanf_back = scanf("%d", &choose);
//		switch (choose) {
//		//添加
//		case 1: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			if (COURSE_SELECTON_ERROR == 1) {
//				printf("错误：学生选课信息为空！\n");
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			//添加学生成绩
//			appendMark(s);
//			//将成绩信息录入文件
//			MarkToFile(s, "mark.txt");
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site5;
//			break;
//		}
//		//删除
//		case 2: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			if (COURSE_SELECTON_ERROR == 1) {
//				printf("错误：学生选课信息为空！\n");
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			if (MARK_ERROR == 1) {
//				printf("错误：学生成绩信息为空！\n");
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site5;
//			}
//			//删除成绩信息
//			long long stuNum = 0;//学号
//			printf("请输入你要删除成绩信息的学生学号：");
//			while (scanf("%lld", &stuNum) != 1 || stuNum < 100000000000 || stuNum >= 1000000000000) {
//				printf("输入错误，请输入12位数字的学号：");
//				while ((getchar()) != '\n');
//			}
//			int result = deleMark(stuNum, s);
//			if (result == 1) {
//				printf("删除成功！\n");
//				//将更新后的选课信息录入文件
//				MarkToFile(s, "mark.txt");
//			}
//			else if (result == -1) {
//				printf("名单中无此课程!\n");
//			}
//			else if (!result) {
//				printf("学号不存在！\n");
//			}
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site5;
//			break;
//		}
//		//查询
//		case 3: {
//			s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//			//文件为空导致链表为空的判断与处理
//			if (STUDENT_ERROR == 1) {
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			if (COURSE_SELECTON_ERROR == 1) {
//				printf("错误：学生选课信息为空！\n");
//				printf("访问错误，已自动返回主菜单\n");
//				goto site;
//			}
//			if (MARK_ERROR == 1) {
//				printf("错误：学生成绩信息为空！\n");
//				printf("访问错误，已自动返回上一级菜单\n");
//				goto site5;
//			}
//			//查询学生成绩
//			long long stuNum = 0;//学号
//			printf("请输入你要查询成绩信息的学生学号：");
//			while (scanf("%lld", &stuNum) != 1 || stuNum < 100000000000 || stuNum >= 1000000000000) {
//				printf("输入错误，请输入12位数字的学号：");
//				while ((getchar()) != '\n');
//			}
//			findMark(s, stuNum);
//			//返回
//			printf("已自动返回上一级菜单\n");
//			goto site5;
//			break;
//		}
//			  //返回主菜单
//		case 4: {
//			goto site;
//			break;
//		}
//		default:
//			printf("输入错误！请重新输入\n");
//			goto site5;
//		}
//	}
//	//获取各班情况
//	case 5: {
//		s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//		//文件为空导致链表为空的判断与处理
//		if (STUDENT_ERROR == 1) {
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		if (COURSE_SELECTON_ERROR == 1) {
//			printf("错误：学生选课信息为空！\n");
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		if (MARK_ERROR == 1) {
//			printf("错误：学生成绩信息为空！\n");
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		sort(s);//链表排序
//		//录入表头
//		FILE* file = fopen("class information.txt", "w");
//		fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		fprintf(file, "%-32s%-32s%-34s%-28s%-20s\n", "科目", "班级", "学号", "姓名", "考试成绩");
//		fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		//录入信息
//		int class;//班级编号
//		student* p = s->next;
//		while (p != NULL) {
//			int i = 0;//索引
//			while (strcmp(p->c[i].cname, "\0") != 0) {//课程存在，进行信息录入
//				class = p->stuNum / 100 % 100;
//				fprintf(file, "%-32s", p->c[i].cname);
//				//动态处理空格（方便“班”字录入文件时对齐表头）
//				int total_width = 32;
//				char tmp[256];
//				int actual_used = snprintf(tmp, sizeof(tmp), "%s%d班", p->subject, class);
//				if (actual_used < total_width) {
//					fprintf(file, "%s%*s", tmp, total_width - actual_used, ""); //填充空格
//				}
//
//				fprintf(file, "%-34lld%-30s%d\n", p->stuNum, p->name, p->c[i].score1);
//				fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//				i++;
//			}
//			p = p->next;
//		}
//		//返回
//		printf("成功将信息录入文件！\n已自动返回主菜单\n");
//		goto site;
//		break;
//	}
//	//获取各课程情况
//	case 6: {
//		s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//		course* c = LoadArray("course information.txt", "course people.txt", cc);//恢复数组
//		//文件为空导致链表为空的判断与处理
//		if (STUDENT_ERROR == 1) {
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		if (COURSE_SELECTON_ERROR == 1) {
//			printf("错误：学生选课信息为空！\n");
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		if (MARK_ERROR == 1) {
//			printf("错误：学生成绩信息为空！\n");
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		//文件为空导致数组为空的判断与处理
//		if (COURSE_INFORMATION_ERROR == 1) {
//			printf("错误：课程信息为空！\n");
//			printf("访问错误，已自动返回上一级菜单\n");
//			goto site3;
//		}
//		FILE* file = fopen("subject list.txt", "w");
//		if (file == NULL) {
//			printf("文件打开失败\n");
//			return -1;
//		}
//
//		fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		fprintf(file, "%-26s%-26s%-26s%s\n", "科目", "学号", "姓名", "考试成绩");
//		fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		student* p = s->next;
//		int i = 0;
//		while (strcmp(c[i].cname, "") != 0) {//循环得到不同课程
//			int j = 0;
//			while (c[i].stuNum[j]) {//循环得到选同一课程的学生
//				p = s->next;
//				fprintf(file, "%-26s%-26lld", c[i].cname, c[i].stuNum[j]);
//				//找到链表中对应学生
//				while (p != NULL) {
//					if (p->stuNum == c[i].stuNum[j]) {
//						break;
//					}
//					p = p->next;
//				}
//				fprintf(file, "%-27s", p->name);
//				//找到链表中对应课程
//				int k = 0;
//				while (1) {
//					if (strcmp(c[i].cname, p->c[k].cname) == 0) {
//						break;
//					}
//					k++;
//				}
//				fprintf(file, "%d\n", p->c[k].score1);
//				fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//				j++;
//			}
//			i++;
//		}
//		//返回
//		printf("成功将信息录入文件！\n已自动返回主菜单\n");
//		goto site;
//		break;
//		//释放数组内存
//		free(c);
//		break;
//	}
//	//统计并输出学分及不及格课程
//	case 7: {
//		s = loadList("student.txt", "course selection.txt", "mark.txt");//恢复链表
//		//文件为空导致链表为空的判断与处理
//		if (STUDENT_ERROR == 1) {
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		if (COURSE_SELECTON_ERROR == 1) {
//			printf("错误：学生选课信息为空！\n");
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		if (MARK_ERROR == 1) {
//			printf("错误：学生成绩信息为空！\n");
//			printf("访问错误，已自动返回主菜单\n");
//			goto site;
//		}
//		FILE* file = fopen("student creHour.txt", "w");
//		if (file == NULL) {
//			printf("文件无法打开\n");
//			return -1;
//		}
//		printf("输出如下：\n");
//		//录入表头并输出到屏幕上
//		fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		fprintf(file, "%-26s%-26s%-26s%s\n", "学号", "姓名", "已修学分", "不及级课程");
//		fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		printf("%-26s%-26s%-26s%s\n", "学号", "姓名", "已修学分", "不及级课程");
//		printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
//		student* p = s->next;
//		int sum = 0;//学分总和
//		while (p != NULL) {
//			sum = 0;
//			//计算总学分并录入文件
//			for (int i = 0; strcmp(p->c[i].cname, "\0") != 0; i++) {
//				sum += p->c[i].creHour;
//			}
//			//录入学分信息并输出到屏幕上
//			fprintf(file, "%-26lld%-26s%-26d", p->stuNum, p->name, sum);
//			printf("%-26lld%-26s%-26d", p->stuNum, p->name, sum);
//			//录入不及级课程信息并输出到屏幕上
//			for (int j = 0; strcmp(p->c[j].cname, "\0") != 0; j++) {
//				if (strcmp(p->c[j].jud, "是") == 0) {//判断是否重修过
//					fprintf(file, "%-5s", p->c[j].cname);
//					printf("%-5s", p->c[j].cname);
//				}
//			}
//			fprintf(file, "\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
//			printf("\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
//			p = p->next;
//		}
//		//返回
//		printf("成功将信息录入文件！\n已自动返回主菜单\n");
//		goto site;
//		break;
//	}
//	//退出程序
//	case 8: {
//		printf("成功退出！\n");
//		break;
//	}
//	default:
//		printf("输入错误！请重新输入\n");
//		goto site;
//	}
//	//释放链表
//	freeList(s);
//	return 0;
//}
////要退出的话按程序正常退出！不要直接关掉控制台！
////由于文件是程序结束后才录入信息的，所以每次操作完建议关闭程序重新打开程序，再继续操作
////选课时不同学生要一门一门选（退出程序重新启动）
////选课信息会重复录入（即输入两次高等数学文件也会显示两次），自己注意不要重复！
////如果要删除选课，一定要先把成绩信息删掉，不然会bug
////输入结束方式：按回车键结束（写在菜单里面）