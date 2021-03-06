#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage Erika Johnson's CS102 PA5: Qt Game 
* @section purpose Overview
* Implements GUI for gameplay of an "Asteroids"-like computer video game
* called "Javaroids". In "Javaroids", the user becomes the "coder" and controls
* the Coder object by moving around the screen while trying to (1) fire Debugger
* objects at Bug objects to kill bugs and "debug code", which wins the player
* 10 points per bug killed; (2) avoid being hit by Bug and SuperBug objects, as 
* a deduction of 10 points is applied each time the Coder object is hit by a Bug
* or SuperBug (note: if the player has 0 points and 1 or more lives, a life will
* be deducted instead; if the player has 0 lives, the game ends; negative points
* or lives are not allowed); (3) avoid being hit by Code objects, as a life is
* lost each time the Coder object is hit by a "piece of Code"; (4) collect
* Coffee objects, which wins the player 1 extra life per coffee collected; (5)
* chase the evasive CoderGirl objects, which win the player 100 points; and (7)
* avoid being hit by the Bluescreen object at all costs, as being hit by the
* "blue screen of death" immediately ends gameplay. Otherwise, gameplay ends
* when the player runs out of lives (i.e. has 0 lives).
* @section requirements Requirements
* User must enter a username containing 2-20 characters. Gameplay is
* based on keyboard input; player uses the arrow keys (left, up, right, down)
* to move and the space bar to fire Debugger objects at Bug objects in the game. */

int main(int argc, char *argv[]){

  if (argc != 2){
    std::cerr << "usage: ./game_erikajoh filename" << std::endl;
    return 0;
  }

  QApplication a(argc, argv);
  a.setApplicationName("Javaroids");
  
  MainWindow w(argv[1]);
  w.show();
  
  if (!(a.exec())){
    if (w.getScore() != -1){
      Score* scoreObj = new Score(w.getUsername(),w.getScore());
      if ( w.getHighScores()->size() < 10 ) w.getHighScores()->push(scoreObj);
      else if ( scoreObj->getScore() >= w.getHighScores()->top()->getScore() ) {
	w.getHighScores()->pop();
	w.getHighScores()->push(scoreObj);
      }
      w.writeScores();
    }
    return 0;
  }

}
