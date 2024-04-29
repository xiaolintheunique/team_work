#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// ����ѧ���ṹ��
struct Student {
    int id;
    char name[50];
    int age;
};

// ȫ�ֱ��������ڴ洢ѧ����Ϣ
struct Student students[MAX_STUDENTS];
int num_students = 0;

// ��������
void addStudent();
void modifyStudent();
void deleteStudent();
void displayStudents();

int main() {
    int choice;

    while (1) {
        printf("\nѧ����Ϣ����ϵͳ\n");
        printf("1. ���ѧ��\n");
        printf("2. �޸�ѧ����Ϣ\n");
        printf("3. ɾ��ѧ��\n");
        printf("4. ��ʾ����ѧ��\n");
        printf("5. �˳�\n");
        printf("��ѡ�������");
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
            printf("ллʹ�ã��ټ���\n");
            return 0;
        default:
            printf("��Ч��ѡ�������ѡ��\n");
        }
    }

    return 0;
}

void addStudent() {
    if (num_students >= MAX_STUDENTS) {
        printf("ѧ����Ϣ�������޷���ӡ�\n");
        return;
    }

    struct Student newStudent;
    printf("������ѧ����Ϣ��\n");
    printf("ѧ�ţ�");
    scanf_s("%d", &newStudent.id);
    printf("������");
    scanf_s("%s", newStudent.name,sizeof(newStudent.name));
    printf("���䣺");
    scanf_s("%d", &newStudent.age);

    students[num_students++] = newStudent;
    printf("ѧ����Ϣ��ӳɹ���\n");
}

void modifyStudent() {
    int id, i;
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
    scanf_s("%d", &id);

    for (i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("�������޸ĺ����Ϣ��\n");
            printf("������");
            scanf_s("%s", students[i].name);
            printf("���䣺");
            scanf_s("%d", &students[i].age);
            printf("ѧ����Ϣ�޸ĳɹ���\n");
            return;
        }
    }

    printf("δ�ҵ���Ӧѧ��ѧ�ŵ���Ϣ��\n");
}

void deleteStudent() {
    int id, i, found = 0;
    printf("������Ҫɾ����ѧ��ѧ�ţ�");
    scanf_s("%d", &id);

    for (i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = 1;
            // �������ѧ����Ϣ��ǰ�ƶ�
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("ѧ����Ϣɾ���ɹ���\n");
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ���Ӧѧ��ѧ�ŵ���Ϣ��\n");
    }
}

void displayStudents() {
    if (num_students == 0) {
        printf("����ѧ����Ϣ��\n");
        return;
    }

    printf("ѧ����Ϣ���£�\n");
    printf("ѧ��\t����\t����\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t%d\n", students[i].id, students[i].name, students[i].age);
    }
}
