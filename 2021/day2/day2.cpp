#include <iostream>
#include <fstream>

int part1();
int part2();

int main() {

    std::cout << part1() << std::endl;
    std::cout << part2() << std::endl;;

    return 0;
}

int part1() {

    std::fstream wej("input", std::ios::in);

    int horizontal = 0, depth = 0;

    std::string command;
    int value;

    while(wej >> command >> value) {

        char type = command[0];

        switch (type) {
            case 'f':
                horizontal += value;
                break;
            case 'u':
                depth -= value;
                break;
            case 'd':
                depth += value;
                break;
            default:
                std::cout<<"ERROR!"<<std::endl;
                break;
        }

    }

    return horizontal * depth;
}

int part2() {

    std::fstream wej("input", std::ios::in);

    int horizontal = 0, depth = 0, aim = 0;

    std::string command;
    int value;

    while(wej >> command >> value) {

        char type = command[0];

        switch(type) {

            case 'd':
                aim += value;
                break;

            case 'u':
                aim -= value;
                break;

            case 'f':
                horizontal += value;
                depth += aim * value;
        }

    }

    return horizontal * depth;
}
