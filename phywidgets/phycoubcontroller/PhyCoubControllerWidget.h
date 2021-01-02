#ifndef PHYCOUBCONTROLLERWIDGET_H
#define PHYCOUBCONTROLLERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QTimer>
#include <QCheckBox>

#include "PhyCoubController.h"
#include "PhyCoubControllerSubscriber.h"

namespace phywidgets
{

class PhyCoubControllerSubscriber;

class PhyCoubControllerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PhyCoubControllerWidget( QWidget* parent = nullptr );
    virtual ~PhyCoubControllerWidget() override;

    void setPhyCoubController( PhyCoubControllerWeakPtr phyCoubController );

  protected:
    friend class PhyCoubControllerSubscriber;

  private slots:
    void onStartClicked();
    void onIterationClicked();
    void onStopClicked();

    void onSetDeltaTimeClicked();
    void onResetExperimentTimeClicked();

    void updateExperimentTime();

    void configureControlGroup();
    void configureOptionsGroup();

  private:
    QTimer updateExperimentTimeTimer_;

    PhyCoubControllerWeakPtr phyCoubControllerWeak_;
    std::shared_ptr< PhyCoubControllerSubscriber > controllerSubscriber_ = nullptr;

    QVBoxLayout* layout_ = nullptr;

    QGroupBox* controlGroup_ = nullptr;
    QVBoxLayout* controlGroupLayout_ = nullptr;
    QPushButton* startButton_ = nullptr;
    QPushButton* iterationButton_ = nullptr;
    QPushButton* stopButton_ = nullptr;

    QGroupBox* optionGroup_ = nullptr;
    QVBoxLayout* optionGroupLayout_ = nullptr;

    QHBoxLayout* deltaTimeLayout_ = nullptr;
    QVBoxLayout* deltaTimeEditLayout_ = nullptr;
    QLabel* deltaTimeLabel_ = nullptr;
    QLineEdit* deltaTimeEdit_ = nullptr;
    QPushButton* setDeltaTimeButton_ = nullptr;

    QHBoxLayout* experimentTimeLayout_ = nullptr;
    QVBoxLayout* experimentTimeViewLayout_ = nullptr;
    QLabel* experimentTimeLabel_ = nullptr;
    QLineEdit* experimentTimeView_ = nullptr;
    QPushButton* resetExperimentTimeButton_ = nullptr;
};

} // namespace phywidgets

#endif // PHYCOUBCONTROLLERWIDGET_H
