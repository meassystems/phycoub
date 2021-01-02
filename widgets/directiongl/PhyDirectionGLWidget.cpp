#include <QGL>
#include <QOpenGLFunctions>
#if defined(WIN32)
#include <GL/glu.h>
#elif defined(DARWIN)
#include <OpenGL/glu.h>
#endif
#include <QMouseEvent>

#include "PhyDirectionGLWidget.h"

namespace phywidgets {

// static
const phycoub::Vector PhyDirectionGLWidget::origin_ =
    phycoub::Vector{0.5, 0.5, 0.5};

PhyDirectionGLWidget::PhyDirectionGLWidget(QWidget *parent /* = nullptr */)
    : QGLWidget(parent) {
  setMinimumSize(100, 100);

  gLRotationDirectionViewAdapter_ =
      std::make_shared<GLRotationDirectionViewAdapter>(this);

  QObject::connect(&timerPlot_, SIGNAL(timeout()), this, SLOT(updateGL()));
  timerPlot_.start(200);
}

// virtual override
void PhyDirectionGLWidget::updateGlRotation(int xRot, int yRot, int zRot) {
  xRot_ = xRot;
  yRot_ = yRot;
  zRot_ = zRot;

  updateGL();
}

void PhyDirectionGLWidget::setGLRotattionController(
    GLRotationControllerWeakPtr gLRotationControllerWeak) {
  gLRotationControllerWeak_ = gLRotationControllerWeak;
  if (auto gLRotationController = gLRotationControllerWeak_.lock()) {
    gLRotationController->subscribeForUpdates(gLRotationDirectionViewAdapter_);
  }
}

void PhyDirectionGLWidget::setDirectionController(
    VectorControllerAdapterWeakPtr directionControllerWeak) {
  directionControllerWeak_ = directionControllerWeak;
  updateGL();
}

void PhyDirectionGLWidget::setXRotation(int angle) {
  if (auto gLRotationController = gLRotationControllerWeak_.lock()) {
    gLRotationController->updateRotationX(angle);
  }
}

void PhyDirectionGLWidget::setYRotation(int angle) {
  if (auto gLRotationController = gLRotationControllerWeak_.lock()) {
    gLRotationController->updateRotationY(angle);
  }
}

void PhyDirectionGLWidget::setZRotation(int angle) {
  if (auto gLRotationController = gLRotationControllerWeak_.lock()) {
    gLRotationController->updateRotationZ(angle);
  }
}

// virtual override
void PhyDirectionGLWidget::initializeGL() { qglClearColor(Qt::black); }

// virtual override
void PhyDirectionGLWidget::resizeGL(int width, int height) {
  int side = qMin(width, height);
  glViewport((width - side) / 2, (height - side) / 2, side, side);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
#ifdef QT_OPENGL_ES_1
  glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
  glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
  glMatrixMode(GL_MODELVIEW);
}

// virtual override
void PhyDirectionGLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -10.0);

  glScaled(zoomScale_, zoomScale_, zoomScale_);

  glRotatef(static_cast<float>(xRot_ / 16.0), 1.0, 0.0, 0.0);
  glRotatef(static_cast<float>(yRot_ / 16.0), 0.0, 1.0, 0.0);
  glRotatef(static_cast<float>(zRot_ / 16.0), 0.0, 0.0, 1.0);

  drowCoordinateSystem();
  drowDirectionVector();
}

// virtual override
void PhyDirectionGLWidget::mousePressEvent(QMouseEvent *event) {
  lastPos_ = event->pos();
}

// virtual override
void PhyDirectionGLWidget::mouseMoveEvent(QMouseEvent *event) {
  int dx = event->x() - lastPos_.x();
  int dy = event->y() - lastPos_.y();

  if (event->buttons() & Qt::LeftButton) {
    setXRotation(xRot_ + 8 * dy);
    setYRotation(yRot_ + 8 * dx);
  } else if (event->buttons() & Qt::RightButton) {
    setXRotation(xRot_ + 8 * dy);
    setZRotation(zRot_ + 8 * dx);
  }
  lastPos_ = event->pos();
}

void PhyDirectionGLWidget::drowCoordinateSystem() {
  static const phycoub::Vector xVector = phycoub::Vector{1., 0., 0.};
  static const phycoub::Vector yVector = phycoub::Vector{0., 1., 0.};
  static const phycoub::Vector zVector = phycoub::Vector{0., 0., 1.};

  phycoub::Vector startOrdinate;

  glLineWidth(2.0f);
  glBegin(GL_LINES);

  // ось x
  startOrdinate = xVector * -1;

  qglColor(Qt::green);
  glVertex3f(static_cast<float>(startOrdinate.x_),
             static_cast<float>(startOrdinate.y_),
             static_cast<float>(startOrdinate.z_));
  glVertex3f(static_cast<float>(xVector.x_), static_cast<float>(xVector.y_),
             static_cast<float>(xVector.z_));

  // ось y
  startOrdinate = yVector * -1;

  qglColor(Qt::blue);
  glVertex3f(static_cast<float>(startOrdinate.x_),
             static_cast<float>(startOrdinate.y_),
             static_cast<float>(startOrdinate.z_));
  glVertex3f(static_cast<float>(yVector.x_), static_cast<float>(yVector.y_),
             static_cast<float>(yVector.z_));

  // ось z
  startOrdinate = zVector * -1;

  qglColor(Qt::red);
  glVertex3f(static_cast<float>(startOrdinate.x_),
             static_cast<float>(startOrdinate.y_),
             static_cast<float>(startOrdinate.z_));
  glVertex3f(static_cast<float>(zVector.x_), static_cast<float>(zVector.y_),
             static_cast<float>(zVector.z_));

  glEnd();

  qglColor(Qt::green);
  drowSphere(xVector, 0.03);

  qglColor(Qt::blue);
  drowSphere(yVector, 0.03);

  qglColor(Qt::red);
  drowSphere(zVector, 0.03);
}

void PhyDirectionGLWidget::drowDirectionVector() {
  if (auto directionController = directionControllerWeak_.lock()) {
    const phycoub::Vector direction = directionController->getValue();

    glLineWidth(2.0f);
    glBegin(GL_LINES);

    qglColor(Qt::cyan);
    glVertex3f(.0f, .0f, .0f);
    glVertex3f(static_cast<float>(direction.x_),
               static_cast<float>(direction.y_),
               static_cast<float>(direction.z_));

    glEnd();

    drowSphere(direction, 0.03);
  }
}

void PhyDirectionGLWidget::drowSphere(const phycoub::Vector &coordinate,
                                      double radius) {
  glPushMatrix();
  glScalef(1, 1, 1);
  GLUquadricObj *quadric = gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluQuadricDrawStyle(quadric, GLU_LINE);
  glTranslatef(static_cast<float>(coordinate.x_),
               static_cast<float>(coordinate.y_),
               static_cast<float>(coordinate.z_));
  gluSphere(quadric, radius, 36, 36);
  gluDeleteQuadric(quadric);
  glPopMatrix();
}

} // namespace phywidgets
