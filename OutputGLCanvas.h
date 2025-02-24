/*
 * OutputGLCanvas.h
 *
 * (c) 2013 Sofian Audry -- info(@)sofianaudry(.)com
 * (c) 2013 Alexandre Quessy -- alexandre(@)quessy(.)net
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OUTPUTGLCANVAS_H_
#define OUTPUTGLCANVAS_H_

#include "MapperGLCanvas.h"

MM_BEGIN_NAMESPACE

class OutputGLCanvas: public MapperGLCanvas
{
  Q_OBJECT

public:
  OutputGLCanvas(MainWindow* mainWindow, QWidget* parent = 0, const QGLWidget* shareWidget = 0, QGraphicsScene* scene = 0);
  virtual ~OutputGLCanvas() {}

  // Adjust viewable scene to correspond to absolute coordinates.
  void setSceneRectToViewportGeometry();

  // Draws foreground (displays crosshair if needed).
  void drawForeground(QPainter *painter , const QRectF &rect);

public:
  void setDisplayCrosshair(bool displayCrosshair) {
    _displayCrosshair = displayCrosshair;
  }

  void setDisplayTestSignal(bool displayTestSignal) {
    _displayTestSignal = displayTestSignal;
  }

private:
  void _drawTestSignal(QPainter* painter);

  bool _displayCrosshair;
  bool _displayTestSignal;
  QImage _svg_test_signal;
  QBrush _brush_test_signal;

protected:
  // overriden from QGlWidget:
  virtual void resizeGL(int width, int height);

  void wheelEvent(QWheelEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
};

MM_END_NAMESPACE

#endif /* OutputGLCanvas_H_ */
