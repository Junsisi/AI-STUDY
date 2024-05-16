#include <stdio.h>

// �� ����� ���¸� ��Ÿ���� ������
enum State {
    LEFT, // ���� ����
    RIGHT // ���� ������
};

// ��Ҹ� ��Ÿ���� ����ü
struct Element {
    enum State state; // ���� ��ġ
    const char* name; // �̸�
};

// ��ҵ�
struct Element person = { LEFT, "���" };
struct Element wolf = { LEFT, "����" };
struct Element goat = { LEFT, "����" };
struct Element cabbage = { LEFT, "�����" };

// ��� �̵� �Լ�
void move(struct Element* element) {
    if (element->state == LEFT)
        element->state = RIGHT;
    else
        element->state = LEFT;
}

// ���� ��� �Լ�
void print_state() {
    printf("���� ����: ���(%s) ����(%s) ����(%s) �����(%s)\n",
        person.state == LEFT ? "����" : "������",
        wolf.state == LEFT ? "����" : "������",
        goat.state == LEFT ? "����" : "������",
        cabbage.state == LEFT ? "����" : "������");
}

// �̵� �ó����� �Լ�
void solution() {
    printf("���Ұ� ����� ���������� �̵�\n");
    move(&goat);
    move(&person);
    print_state();

    printf("����� �������� �̵�\n");
    move(&person);
    print_state();

    printf("����� ���밡 ���������� �̵�\n");
    move(&wolf);
    move(&person);
    print_state();

    printf("����� ���Ұ� �������� �̵�\n");
    move(&goat);
    move(&person);
    print_state();

    printf("����߿� ����� ���������� �̵�\n");
    move(&cabbage);
    move(&person);
    print_state();

    printf("����� �������� �̵�\n");
    move(&person);
    print_state();

    printf("����� ���Ұ� ���������� �̵� (��)\n");
    move(&goat);
    move(&person);
    print_state();
}

int main() {
    printf("����:\n");
    printf("- ����� ����, ����, ����߿� ���� ���ʿ� ����\n");
    printf("- ����� �� �� �ϳ��� ������ ����, ���� ����/���������� �̵�����\n");
    printf("- ��� ȥ�ڼ� �ǳ� ���� ����\n");
    printf("- ����� ���Ҹ� ���� �θ� ���밡 ���Ҹ� ��Ƹ���\n");
    printf("- ���ҿ� ����߸� ���� �θ� ���Ұ� ����߸� ����\n");
    printf("- ���ҳ� ����߰� ������ �ʰ� ��� ���� �ǳʴ� ���\n\n");

    printf("�̵� ����:\n");
    solution();
    return 0;
}