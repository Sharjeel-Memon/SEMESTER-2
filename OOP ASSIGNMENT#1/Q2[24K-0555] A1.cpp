#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
// BALL CLASS
class Ball {
private:
	//ATTRIBUTES
    int x, y;
    static const int fieldMin = -9;
    static const int fieldMax = 9;
public:
	//CONSTRUCTORS
    Ball() : x(0), y(0) {}
    Ball(int x, int y) : x(x), y(y) {}
	//METHODS
    void move(int dx, int dy) {
        int newX = x + dx;
        int newY = y + dy;

        if (newX >= fieldMin && newX <= fieldMax && newY >= fieldMin && newY <= fieldMax) {
            x = newX;
            y = newY;
        } else {
            cout << "Out of bounds! Ball reset to center." << endl;
            x = 0;
            y = 0;
        }
    }
	//GETTERS
    int getX() const { return x; }
    int getY() const { return y; }
	//SETTERS
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
	//GETTER
    void getPosition() const {
        cout << "(" << x << ", " << y << ")";
    }
};
//GOAL CLASS
class Goal {
private:
	//ATTRIBUTES
    int goalX, goalY;
public:
	//CONSTRUCTOR
    Goal() : goalX(3), goalY(3) {}
	//METHODS
    bool isGoalReached(int ballX, int ballY) const {
        return ballX == goalX && ballY == goalY;
    }
	//SETTER
    void setGoalX(int x) { goalX = x; }
    void setGoalY(int y) { goalY = y; }
	//GETTER
    int getGoalX() const { return goalX; }
    int getGoalY() const { return goalY; }
};
//ROBOT CLASS
class Robot {
private:
	//ATTRIBUTES
    string name;
    int hits;
public:
	//CONSTRUCTOR
    Robot(string n) : name(n), hits(0) {}
	//METHODS
    void hitBall(Ball &ball, string direction) {
        transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
        int moveX = rand() % 3 + 1;
        int moveY = rand() % 3 + 1;

        if (direction == "up") ball.move(0, moveY);
        else if (direction == "down") ball.move(0, -moveY);
        else if (direction == "left") ball.move(-moveX, 0);
        else if (direction == "right") ball.move(moveX, 0);
        else {
            cout << "Invalid direction! Please enter up, down, left, or right." << endl;
            return;
        }

        hits++;
        cout << name << " hit the ball. Ball is now at: ";
        ball.getPosition();
        cout << endl;
    }
	//GETTER
    int getHits() const { return hits; }
    string getName() const { return name; }
	//SETTER
    void setHits(int hits) { this->hits = hits; }
    void setName(string name) { this->name = name; }
};
//TEAM CLASS
class Team {
private:
	//ATTRIBUTES
    string teamName;
    Robot* player;
public:
	//CONSTRUCTOR
    Team(string name, Robot* r) : teamName(name), player(r) {}
    ~Team() { delete player; }
	//GETTER
    Robot* getPlayer() const { return player; }
    string getTeamName() const { return teamName; }
};
//GAME CLASS
class Game {
private:
	//ATTRIBUTES/PROPERTIES
    Team* teamOne;
    Team* teamTwo;
    Ball ball;
    Goal goal;
public:
	//CONSTRUCTORS/DESTRUCTORS
    Game(Team* t1, Team* t2) : teamOne(t1), teamTwo(t2) {}
    ~Game() { delete teamOne; delete teamTwo; }
	//METHOD
    void play(Team* team) {
        Robot* player = team->getPlayer();
        string direction;
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            cout << "Enter direction (up, down, left, right): ";
            cin >> direction;
            player->hitBall(ball, direction);
        }
    }

    void startGame(int playerChoice) {
        ball = Ball();
        if (playerChoice == 1) play(teamOne);
        else play(teamTwo);
    }

    void declareWinner() const {
        int hits1 = teamOne->getPlayer()->getHits();
        int hits2 = teamTwo->getPlayer()->getHits();

        cout << "Scoreboard:" << endl;
        cout << teamOne->getTeamName() << " hits: " << hits1 << endl;
        cout << teamTwo->getTeamName() << " hits: " << hits2 << endl;

        if (hits1 < hits2)
            cout << "Winner: " << teamOne->getTeamName() << "!" << endl;
        else if (hits2 < hits1)
            cout << "Winner: " << teamTwo->getTeamName() << "!" << endl;
        else
            cout << "It's a tie!" << endl;
    }

    void updateGoalPosition() {
        int newX, newY;
        cout << "Enter new goal X position: ";
        cin >> newX;
        cout << "Enter new goal Y position: ";
        cin >> newY;

        if (newX >= -9 && newX <= 9 && newY >= -9 && newY <= 9) {
            goal.setGoalX(newX);
            goal.setGoalY(newY);
            cout << "Goal position updated to (" << newX << ", " << newY << ")." << endl;
        } else {
            cout << "Invalid goal position! Goal must be within (-9, -9) and (9, 9)." << endl;
        }
    }
};

int main() {
    Robot* r1 = new Robot("Alpha");
    Robot* r2 = new Robot("Beta");
    Team* t1 = new Team("Red", r1);
    Team* t2 = new Team("Blue", r2);
    Game* game = new Game(t1, t2);

    int choice;
    do {
        cout << "\nFootball Game Menu:" << endl;
        cout << "1. Play as Player 1 (Red)" << endl;
        cout << "2. Play as Player 2 (Blue)" << endl;
        cout << "3. Declare Winner" << endl;
        cout << "4. Update Goal Position" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
                game->startGame(choice);
                break;
            case 3:
                game->declareWinner();
                break;
            case 4:
                game->updateGoalPosition();
                break;
            case 5:
                cout << "Exiting game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    delete game;
    return 0;
}
