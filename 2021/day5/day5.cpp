#include <iostream>
#include <fstream>
#include <vector>


class Line {

private:
    int x1, y1;
    int x2, y2;

public:
    Line() {
        x1 = y1 = x2 = y2 = 0;
    }

    Line(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    void show() const {
        std::cout << "(" << x1 << "," << y1 << ")" << std::endl;
        std::cout << "(" << x2 << "," << y2 << ")" << std::endl;
        std::cout << std::endl;
    }

    bool is_horizontal() const {
        if(y1 == y2) return true;
        else return false;
    }

    bool is_vertical() const {
        if(x1 == x2) return true;
        else return false;
    }

    std::pair<int, int> get_start() const {
        return std::pair<int, int>(x1, y1);
    }

    std::pair<int, int> get_end() const {
        return std::pair<int, int>(x2, y2);
    }
};


int part1(std::vector<Line> lines) {

    int diagram[1000][1000] = {0};

    for(auto& line : lines) {

        std::pair<int, int> start = line.get_start();
        std::pair<int, int> end = line.get_end();


        if(line.is_vertical()) {

            for(int y = std::min(start.second, end.second); y <= std::max(start.second, end.second); ++y) {
                diagram[start.first][y]++;
            }

        } else if(line.is_horizontal()) {

            for(int x = std::min(start.first, end.first); x <= std::max(start.first, end.first); ++x) {
                diagram[x][start.second]++;
            }

        }

    }

    // search diagram
    int count = 0;
    for(int x = 0; x < 1000; ++x) {
        for(int y = 0; y < 1000; ++y) {
            if(diagram[x][y] > 1) count++;
        }
    }

    return count;
}

int part2(std::vector<Line> lines) {

    int diagram[1000][1000] = {0};

    for(auto& line : lines) {

        std::pair<int, int> start = line.get_start();
        std::pair<int, int> end = line.get_end();

        if(line.is_vertical()) {

            for(int y = std::min(start.second, end.second); y <= std::max(start.second, end.second); ++y) {
                diagram[start.first][y]++;
            }

        } else if(line.is_horizontal()) {

            for(int x = std::min(start.first, end.first); x <= std::max(start.first, end.first); ++x) {
                diagram[x][start.second]++;
            }

        } if(!line.is_vertical() and !line.is_horizontal()) {

            int change_of_x;
            if(start.first > end.first) change_of_x = -1;
            else change_of_x = 1;

            int change_of_y;
            if(start.second > end.second) change_of_y = -1;
            else change_of_y = 1;

            for(int x = start.first, y = start.second; x != end.first + change_of_x and y != end.second + change_of_y; x += change_of_x, y += change_of_y) {

                diagram[x][y]++;

            }

        }

    }

    // search diagram
    int count = 0;
    for(int x = 0; x < 1000; ++x) {
        for(int y = 0; y < 1000; ++y) {
            if(diagram[x][y] > 1) count++;
        }
    }

    return count;
}

int main() {

    std::vector<Line> lines;

    // load data
    std::fstream wej("input", std::ios::in);

    char waste;
    int x1, y1, x2, y2;
    while(wej >> x1 >> waste >> y1 >> waste >> waste >> x2 >> waste >> y2) {

        Line l(x1, y1, x2, y2);
        lines.push_back(l);

    }

    std::cout << part1(lines) << std::endl;
    std::cout << part2(lines) << std::endl;

    return 0;
}
