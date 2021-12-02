#include <iostream>
#include <fstream>
#include <vector>

int part1();
int part2();

int main() {

    std::cout << "part1: " << part1() << std::endl;
    std::cout << "part2: " << part2() << std::endl;

    return 0;
}


int part1() {

    std::fstream wej("input", std::ios::in);

    int measurement, previous;

    // read one line to skip it
    wej >> previous;

    int counter = 0;

    while(wej>>measurement) {

        if(measurement > previous)
            counter++;

        previous = measurement;
    }

    return counter;

}

int part2() {

    std::fstream wej("input", std::ios::in);

    int counter = 0;

    std::vector<int> measurements;
    int measurement;

    while(wej>>measurement)
        measurements.push_back(measurement);

    int *p1 = &measurements[0], *p2 = &measurements[1], *p3 = &measurements[2];

    int previous_measurement = *p1 + *p2 + *p3;
    p1++; p2++; p3++;

    for(int i = 0; i < measurements.size(); ++i) {

        int current_measurement = *p1 + *p2 + *p3;
        p1++; p2++; p3++;

        if(current_measurement > previous_measurement)
            counter++;

        previous_measurement = current_measurement;
    }

    return counter;
}
