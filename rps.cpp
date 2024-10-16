#include <iostream>
#include <random>

using namespace std;

void printWelcomeMessage() {
    cout << "===============================" << endl;
    cout << "     Welcome to Rock, Paper,    " << endl;
    cout << "          Scissors Game!        " << endl;
    cout << "===============================" << endl;
}

void printMainMenu() {
    cout << "\nMain Menu:" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. View Statistics" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}

void printRoundSeparator() {
    cout << "\n-------------------------------" << endl;
    cout << "          Next Round            " << endl;
    cout << "-------------------------------" << endl;
}

void printStatistics(int total_rounds, int total_games, int player_wins, int computer_wins, int ties, int rock_count, int paper_count, int scissors_count) {
    cout << "\n========= Game Statistics =========" << endl;
    cout << "Total Rounds Played: " << total_rounds << endl;
    cout << "Total Games Played: " << total_games << endl;
    cout << "Player Wins: " << player_wins << endl;
    cout << "Computer Wins: " << computer_wins << endl;
    cout << "Total Amount of Ties: " << ties << endl;

    string most_used;

    if (rock_count >= paper_count && rock_count >= scissors_count) {
        most_used = "Rock";
    } 
    else if (paper_count >= rock_count && paper_count >= scissors_count) {
        most_used = "Paper";
    } 
    else {
        most_used = "Scissors";
    }

    cout << "Most Used Option by Player: " << most_used << endl;
    cout << "====================================\n" << endl;
}

int main() {
    const string rps[] = {"Rock", "Paper", "Scissors"};
    int player_choice, main_menu_choice, computer_choice, player_score = 0, computer_score = 0, total_games = 0;
    int total_rounds = 0, player_wins = 0, computer_wins = 0, ties = 0, rock_count = 0, paper_count = 0, scissors_count = 0;
    char play_again;

    printWelcomeMessage();

    while (true) {
        printMainMenu();
        cin >> main_menu_choice;

        if (main_menu_choice == 1) {
            player_score = 0;
            computer_score = 0;
            
            while (true) {
                printRoundSeparator();
                
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(0, 2);
                computer_choice = dis(gen);

                cout << "Choose your weapon:" << endl;
                cout << "1. Rock" << endl;
                cout << "2. Paper" << endl;
                cout << "3. Scissors" << endl;
                cout << "Enter your choice (1-3): " << endl;
                cout << "===============================" << endl;
                cin >> player_choice;

                if (player_choice < 1 || player_choice > 3) {
                    cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
                    continue;
                }

                switch (player_choice) {
                    case 1:
                        rock_count++;
                        break;
                    case 2:
                        paper_count++;
                        break;
                    case 3:
                        scissors_count++;
                        break;
                }

                player_choice--;

                cout << "Player: " << rps[player_choice] << endl;
                cout << "Computer: " << rps[computer_choice] << endl;

                if (player_choice == computer_choice) {
                    cout << "It's a tie!" << endl;
                    ties++;
                    total_rounds++;
                } 
                else if ((player_choice == 0 && computer_choice == 2) || (player_choice == 1 && computer_choice == 0) || (player_choice == 2 && computer_choice == 1)) {
                    cout << "Player wins!" << endl;
                    player_score++;
                    total_rounds++;
                } 
                else {
                    cout << "Computer wins!" << endl;
                    computer_score++;
                    total_rounds++;
                }

                cout << "Player Score: " << player_score << endl;
                cout << "Computer Score: " << computer_score << endl;
                
                if (player_score == 3 || computer_score == 3) {
                    if (player_score == 3) {
                        cout << "Congratulations! You won the game!" << endl;
                        player_wins++;
                        total_games++;
                    } 
                    else {
                        cout << "Computer wins the game! Better luck next time!" << endl;
                        computer_wins++;
                        total_games++;
                    }
                    cout << "===============================" << endl;
                    cout << "Do you want to play again? (y/n): ";
                    cin >> play_again;

                    if (play_again == 'n' || play_again == 'N') {
                        break;
                    } 
                    else if (play_again == 'y' || play_again == 'Y') {
                        player_score = 0;
                        computer_score = 0;
                    } 
                    else {
                        cout << "\nInvalid choice. Returning to main menu." << endl;
                        break;
                    }
                }
            }
        } 
        else if (main_menu_choice == 2) {
            printStatistics(total_rounds, total_games, player_wins, computer_wins, ties, rock_count, paper_count, scissors_count);
        } 
        else if (main_menu_choice == 3) {
            cout << "Thank you for playing! Goodbye!" << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}