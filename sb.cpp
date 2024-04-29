#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// 定义学生结构体
struct Student {
    int id;
    char name[50];
    int age;
};

// 全局变量，用于存储学生信息
struct Student students[MAX_STUDENTS];
int num_students = 0;

// 函数声明
void addStudent();
void modifyStudent();
void deleteStudent();
void displayStudents();

int main() {
    int choice;

    while (1) {
        printf("\n学生信息管理系统\n");
        printf("1. 添加学生\n");
        printf("2. 修改学生信息\n");
        printf("3. 删除学生\n");
        printf("4. 显示所有学生\n");
        printf("5. 退出\n");
        printf("请选择操作：");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            modifyStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            displayStudents();
            break;
        case 5:
            printf("谢谢使用，再见！\n");
            return 0;
        default:
            printf("无效的选项，请重新选择。\n");
        }
    }

    return 0;
}

void addStudent() {
    if (num_students >= MAX_STUDENTS) {
        printf("学生信息已满，无法添加。\n");
        return;
    }

    struct Student newStudent;
    printf("请输入学生信息：\n");
    printf("学号：");
    scanf_s("%d", &newStudent.id);
    printf("姓名：");
    scanf_s("%s", newStudent.name,sizeof(newStudent.name));
    printf("年龄：");
    scanf_s("%d", &newStudent.age);

    students[num_students++] = newStudent;
    printf("学生信息添加成功。\n");
}

void modifyStudent() {
    int id, i;
    printf("请输入要修改的学生学号：");
    scanf_s("%d", &id);

    for (i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("请输入修改后的信息：\n");
            printf("姓名：");
            scanf_s("%s", students[i].name);
            printf("年龄：");
            scanf_s("%d", &students[i].age);
            printf("学生信息修改成功。\n");
            return;
        }
    }

    printf("未找到对应学生学号的信息。\n");
}

void deleteStudent() {
    int id, i, found = 0;
    printf("请输入要删除的学生学号：");
    scanf_s("%d", &id);

    for (i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = 1;
            // 将后面的学生信息向前移动
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("学生信息删除成功。\n");
            break;
        }
    }

    if (!found) {
        printf("未找到对应学生学号的信息。\n");
    }
}

void displayStudents() {
    if (num_students == 0) {
        printf("暂无学生信息。\n");
        return;
    }

    printf("学生信息如下：\n");
    printf("学号\t姓名\t年龄\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t%d\n", students[i].id, students[i].name, students[i].age);
    }
}
