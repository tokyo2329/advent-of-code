#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int toDecimal(char*, const int&);
void flipBits(char*, const int&);

int main() {

    std::fstream wej("input", std::ios::in);

    std::vector<std::string> data;

    std::string curr_data;

    while(wej >> curr_data)
        data.push_back(curr_data);


    int data_length = curr_data.size();


    char gamma_rate[data_length];


    for(int i = 0; i < data_length; ++i) {

        int times_1 = 0, times_0 = 0;

        for(std::string binary_string : data) {

            if(binary_string[i]=='1') times_1++;
            else times_0++;

        }

        if(times_0 > times_1)
            gamma_rate[i] = '0';
        else
            gamma_rate[i] = '1';

    }

    int decimal_gamma_rate = toDecimal(gamma_rate, data_length);
    flipBits(gamma_rate, data_length);
    int decimal_epsilon_rate = toDecimal(gamma_rate, data_length);

    std::cout << decimal_gamma_rate * decimal_epsilon_rate << std::endl;

    wej.close();
    return 0;
}

int toDecimal(char* p, const int& length) {

    int decimal = 0;

    // setting the pointer to the end
    for(int i = 0; i < length - 1; ++i)
        p++;

    for(int i = length, power = 0; i > 0; --i, ++power) {

        decimal += (*p - '0') * pow(2, power);
        p--;

    }

    return decimal;
}

void flipBits(char *p, const int& length) {

    for(int i = 0; i < length; ++i) {

        if(*p == '0')
            *p = '1';
        else *p = '0';

        p++;
    }

}
