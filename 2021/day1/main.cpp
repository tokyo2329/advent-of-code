#include <iostream>
#include <fstream>

int main() {

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

    std::cout << counter;
    return 0;
}
