#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


class Board {

// checked values are marked -1
// winner -> if rows' or columns' sum is equal to -5 (-1 * 5 = -5)

private:
    int nums[5][5];
    bool winner = false;
    int winning_number;

public:
    Board() {
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                nums[i][j] = 0;
    }

    Board(int* numbers) {
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j) {
                nums[i][j] = *numbers;
                numbers++;
            }
    }

    Board(const Board& board) {
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                nums[i][j] = board.get_value_at(i, j);

        winning_number = board.winning_number;
        winner = board.winner;
    }

    int get_value_at(int idx_i, int idx_j) const {
        return nums[idx_i][idx_j];
    }

    void show() const {
        std::cout << std::endl;
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j)
                std::cout << nums[i][j] << " ";
            std::cout << std::endl;
        }
    }

    void mark(const int& value) {

        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                if(nums[i][j] == value) {
                    winning_number = value;
                    nums[i][j] = -1;
                }

    }

    int get_winning_number() {
        return winning_number;
    }

    bool is_winner() {

        if(winner) return true;

        // columns
        for(int i = 0; i < 5; ++i) {
            int sum = 0;
            for(int j = 0; j < 5; ++j)
                sum += nums[i][j];

            if(sum == -5) {
                winner = true;
                return true;
            }
        }

        // rows
        for(int j = 0; j < 5; ++j) {
            int sum = 0;
            for(int i = 0; i < 5; ++i)
                sum += nums[i][j];

                if(sum == -5) {
                    winner = true;
                    return true;
                }
        }

        return false;
    }

    int calculate_points() const {

        int points = 0;

        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                if(nums[i][j] != -1)
                    points += nums[i][j];

        return points * winning_number;
    }

};

int part1(std::vector<Board> boards, std::vector<int> random_numbers) {

    // game
    for(int i = random_numbers.size() - 1; i >= 0; --i) {

        for(int j = 0; j < boards.size(); ++j) {

            boards[j].mark(random_numbers[i]);

            if(boards[j].is_winner()) {
                return boards[j].calculate_points();
            }

        }

    }

    return -1;
}

int part2(std::vector<Board> boards, std::vector<int> random_numbers) {

    std::vector<int> winning_boards_idxs;

    // game
    for(int i = random_numbers.size() - 1; i >= 0; --i) {

        for(int j = 0; j < boards.size(); ++j) {

            if(!boards[j].is_winner())
                boards[j].mark(random_numbers[i]);

            if(boards[j].is_winner()) {
                bool already_added = false;

                for(int idx : winning_boards_idxs)
                    if(j == idx) already_added = true;

                if(!already_added)
                    winning_boards_idxs.push_back(j);
            }

        }

    }

    Board last = boards[winning_boards_idxs.back()];

    last.show();
    std::cout << last.get_winning_number() << std::endl;

    return last.calculate_points();
}

int main() {

    std::fstream wej("input", std::ios::in);

    std::vector<int> random_numbers;
    std::string random_numbers_input;

    wej >> random_numbers_input;

    // convert string to vector of ints (reverse order)
    int current = 0;
    int inc = 0;
    for(int i = random_numbers_input.size() - 1; i >= 0; --i) {
        if(random_numbers_input[i] == ',') {
            random_numbers.push_back(current);
            inc = 0;
            current = 0;
        } else {
            current += (random_numbers_input[i] - '0') * pow(10, inc);
            inc++;
        }
    }
    random_numbers.push_back(current);

    // load boards
    std::vector<Board> boards;

    int current_board[25];
    while(wej) {

        for(int i = 0; i < 25; ++i)
            wej >> current_board[i];

        Board b(current_board);
        boards.push_back(b);

    }

    std::cout << part1(boards, random_numbers) << std::endl;
    std::cout << part2(boards, random_numbers) << std::endl;

    return 0;
}
