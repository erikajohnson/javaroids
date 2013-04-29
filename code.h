#ifndef CODE_H
#define CODE_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <cstdlib>
#include "object.h"
#include "bug.h"
#include <vector>

using namespace std;

/** Code class inherits from Object class */
class Code : public Object {
public:
  /** Code constructor
   *@param *pm QPixmap to set image of object
   *@param nx desired x position of object
   *@param ny desired y position of object */
  Code(QPixmap *pm, int nx, int ny);
  /** Code's move function */
  void move();
  /** Checks to see if object is a Code object
   *@return true */
  bool isCode() {return true;}
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
   *@return false */
  bool isDebugger() {return false;}

};

#endif // CODE_H
