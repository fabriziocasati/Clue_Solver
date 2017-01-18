#ifndef NEWINQUIRYWINDOW_H
#define NEWINQUIRYWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QHBoxLayout>
#include <Game.h>
#include <gui/GameWindow.h>

class Game;
class GameWindow;

class NewInquiryWindow : public QWidget
{
    Q_OBJECT

public:
    NewInquiryWindow(Game *g, QWidget *parent = 0);
    Game *game;
    GameWindow *gw;

public slots:
    void openNewWindow();
};

#endif // NEWINQUIRYWINDOW_H
