#include "GameEntities.hpp"
#include "Player.hpp"
#include "PlayerWeapon.hpp"
#include "AlienWeapon.hpp"
#include "AlienShip.hpp"
#include "List.hpp"
#include "BackGround.hpp"
#include "Enemy.hpp"
#include <ctime>
#include <math.h>
#include <sstream>
#include <unistd.h>

void printTime(WINDOW *win, clock_t _time) {
   std::stringstream s;
   s << int((_time)/ CLOCKS_PER_SEC);
   std::string timeStr(s.str());
   mvwprintw(win,  LINES - 3, LINES - 15, "TIME: %s", timeStr.c_str());
}


void addRandomEnemies(List *enemies, Player * player) {
    GameEntities::Position pos;
    GameEntities::Speed speed;

    pos.y = 0;
    speed.x = 0;
    speed.y = 1;
    pos.x = (player->getPosition().x - 15) + (rand() % 25) + 1;
    std::string typeEnnemies[] = {"1", "2", "3"};
    int randDone = rand() % 3;
    GameEntities *enemy = new AlienShip(randDone + 1, 10, typeEnnemies[randDone], NULL, GameEntities::Position(), GameEntities::Speed());
    enemies->createNode(enemy);
}

int main()
{
    int c;
    unsigned int difficultyTime = 0;
    unsigned int difficultySpawn = 50000;
    unsigned int difficultySpeed = 99000;
    int _clock = 0;
    int tmp_clock = 0;
    int life = 3;
    clock_t begin = clock();
    unsigned int speedBackGround = 0;
    List enemies;
    List allies;

    WINDOW *window;
    WINDOW *window2;
    initscr();
    noecho();
    curs_set(0);

    if(has_colors() == FALSE)
    {	endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    use_default_colors();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    window = newwin(LINES, LINES, 0, ((COLS / 2) - (LINES / 2)));
    window2 = newwin(LINES - 2, LINES - 4, 1, ((COLS / 2) - (LINES / 2) + 2));
    COLS = LINES;
    box(window, 0, 0);
    keypad(window, TRUE);
    GameEntities::MAX_Y = LINES;
    GameEntities::MAX_X = COLS;
    Player* bob = new Player();
    BackGround* scereny = new BackGround[30];

    while(1)
    {
        werase(window2);
        nodelay(window, TRUE);
        c = wgetch(window);
        switch (c)
        {
            case 32:
                bob->shoot(&allies);
                break;
            case KEY_LEFT:
                bob->move(-1, 0);
                break;
            case KEY_RESIZE:
                endwin();
                break;
            case KEY_RIGHT:
                bob->move(1, 0);
                break;
            case KEY_UP:
                bob->move(0, -1);
                break;
            case KEY_DOWN:
                bob->move(0, 1);
                break;
            case 27:
                endwin();
                return 0;
        }
        if (speedBackGround % 70000 == 0 && speedBackGround != 0) {
            for(int i = 0; i < 50; i++) {
                scereny[i].move();
            }
            speedBackGround = 0;
        }
        if ((difficultyTime % difficultySpawn) == 0) {
            difficultyTime = 0;
            Enemy * test = (Enemy *)enemies.getRandomShooter(window2);
            addRandomEnemies(&enemies, bob);
            if (test != 0)
                test->shoot(&enemies);
        }
        if (difficultyTime && difficultyTime % difficultySpeed == 0) {
            enemies.updateList(&allies);
        }
        if (difficultyTime % 5000 == 0 && difficultyTime != 0) {
            allies.updateList(&enemies);
        }
        _clock = (int)((clock() - begin)/ (double)CLOCKS_PER_SEC);
        if (_clock != tmp_clock) {
            tmp_clock = _clock;
            bob->setTotalScore(10);
        }
        usleep(100);
        for(int i=0; i<30;i++) {
            scereny[i].print(window2);
        }
        enemies.printList(window2);
        if (!(enemies.updatePlayer(*bob))) {
            if (life) {
                life--;
                delete bob;
                bob = new Player();
            } else {
                endwin();
                std::cout << "LOSER" << std::endl;
                return 0;
            }

        }
        allies.printList(window2);
        bob->print(window2);
        mvwprintw(window2, LINES - 3, 1, "SCORE: %d", bob->getTotalScore());
        mvwprintw(window2, LINES - 3, 15, "LIFE: %d", life);
        printTime(window2, clock());
        wrefresh(window2);
        difficultySpawn = (500000 <= (bob->getTotalScore() * 40)) ? 50000 : (500000 - bob->getTotalScore() * 40);
        difficultySpeed = (99000 <= (bob->getTotalScore() * 10)) ? 10000  : (99000 - bob->getTotalScore() * 10);
        difficultyTime += 100;
        speedBackGround += 100;
    }
}