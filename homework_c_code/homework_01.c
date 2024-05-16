#include <stdio.h>

// 각 요소의 상태를 나타내는 열거형
enum State {
    LEFT, // 강의 왼쪽
    RIGHT // 강의 오른쪽
};

// 요소를 나타내는 구조체
struct Element {
    enum State state; // 현재 위치
    const char* name; // 이름
};

// 요소들
struct Element person = { LEFT, "사람" };
struct Element wolf = { LEFT, "늑대" };
struct Element goat = { LEFT, "염소" };
struct Element cabbage = { LEFT, "양배추" };

// 요소 이동 함수
void move(struct Element* element) {
    if (element->state == LEFT)
        element->state = RIGHT;
    else
        element->state = LEFT;
}

// 상태 출력 함수
void print_state() {
    printf("현재 상태: 사람(%s) 늑대(%s) 염소(%s) 양배추(%s)\n",
        person.state == LEFT ? "왼쪽" : "오른쪽",
        wolf.state == LEFT ? "왼쪽" : "오른쪽",
        goat.state == LEFT ? "왼쪽" : "오른쪽",
        cabbage.state == LEFT ? "왼쪽" : "오른쪽");
}

// 이동 시나리오 함수
void solution() {
    printf("염소과 사람이 오른쪽으로 이동\n");
    move(&goat);
    move(&person);
    print_state();

    printf("사람만 왼쪽으로 이동\n");
    move(&person);
    print_state();

    printf("사람과 늑대가 오른쪽으로 이동\n");
    move(&wolf);
    move(&person);
    print_state();

    printf("사람과 염소가 왼쪽으로 이동\n");
    move(&goat);
    move(&person);
    print_state();

    printf("양배추와 사람이 오른쪽으로 이동\n");
    move(&cabbage);
    move(&person);
    print_state();

    printf("사람만 왼쪽으로 이동\n");
    move(&person);
    print_state();

    printf("사람과 염소가 오른쪽으로 이동 (끝)\n");
    move(&goat);
    move(&person);
    print_state();
}

int main() {
    printf("조건:\n");
    printf("- 사람이 늑대, 염소, 양배추와 강의 왼쪽에 있음\n");
    printf("- 사람은 이 중 하나만 선택해 같이, 강의 왼쪽/오른쪽으로 이동가능\n");
    printf("- 사람 혼자서 건널 수도 있음\n");
    printf("- 늑대와 염소만 남겨 두면 늑대가 염소를 잡아먹음\n");
    printf("- 염소와 양배추만 남겨 두면 염소가 양배추를 먹음\n");
    printf("- 염소나 양배추가 먹히지 않고 모두 강을 건너는 방법\n\n");

    printf("이동 과정:\n");
    solution();
    return 0;
}