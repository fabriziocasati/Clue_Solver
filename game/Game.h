#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include "Inquiry.h"
#include "game/Player.h"
#include "gui/CardTableWindow.h"
#include "gui/MainWindow.h"
#include <QString>
#include "gui/InquiryHistoryWindow.h"
#include "reasoner/Reasoner.h"

class Inquiry;
class MainWindow;
class Reasoner;

class Game
{
public:
    Game(MainWindow *mainWindow, int numberOfPlayers, std::vector<QString> playerName, std::vector<int> playerCardsNumber, std::vector<QString> userCards);

    std::vector<QString> suspectCardList;
    std::vector<QString> weaponCardList;
    std::vector<QString> roomCardList;

    QList<QString> roomCardQList;
    QList<QString> suspectCardQList;
    QList<QString> weaponCardQList;
    QList<QString> userCardQList;

    //int playerNumberOfCards[];
    int numberOfPlayers;
    std::list<Inquiry*> *inquiryList;
    Player player[6];

    void addInquiry(Inquiry *q, InquiryHistoryWindow *i);
    std::vector<QString> getUserCards();

    std::vector<QString> userCards;
    std::vector<QString> playerName;

    std::vector<QString> getRoomCardList();
    std::vector<QString> getSuspectCardList();
    std::vector<QString> getWeaponCardList();
    std::vector<QString> getPlayerList();

    MainWindow *mainWindow;

    int turnNumber;

    int getTurnNumber();

    Reasoner* reasoner;

    QList<QString> getRoomCardQList();
    QList<QString> getSuspectCardQList();
    QList<QString> getWeaponCardQList();
    QList<QString> getUserCardQList();

};

#endif // GAME_H


