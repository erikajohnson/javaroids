#ifndef DEBUGGER_H
#define DEBUGGER_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <cstdlib>
#include "object.h"

/** Debugger class inherits from Object class */
class Debugger : public Object {
public:
  /** Debugger constructor
   *@param *pm QPixmap to set image of object
   *@param nx desired x position of object
   *@param ny desired y position of object */
  Debugger(QPixmap *pm, int nx, int ny);
  /** Debugger's move function */
  void move();
  /** Checks to see if object is a Code object
   *@return false */
  bool isCode() {return false;}
  /** Checks to see if object is a Coffee object
   *@return false */
  bool isCoffee() {return false;}
  /** Checks to see if object is a Bluescreen object
   *@return false */
  bool isBluescreen() {return false;}
  /** Checks to see if object is a Bug object
   *@return false */
  bool isBug() {return false;}
  /** Checks to see if object is a Debugger object
   *@return true */
  bool isDebugger() {return true;}

};

#endif // DEBUGGER_H
