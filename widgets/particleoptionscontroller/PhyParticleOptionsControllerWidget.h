#ifndef PHYPARTICLEOPTIONSCONTROLLERWIDGET_H
#define PHYPARTICLEOPTIONSCONTROLLERWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <ValueControllerAdapterIface.h>

namespace phywidgets
{

class PhyParticleOptionsControllerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit PhyParticleOptionsControllerWidget( QWidget* widget );
    virtual ~PhyParticleOptionsControllerWidget() override = default;

    void setParticleOptionsControllerAdapter(
        ParticleOptionsControllerAdapterWeakPtr particleOptionstControllerAdapterWeak );

    void setTitle( QString label );

  private slots:
    void onApplyChangeClicked();

  private:
    void config();

    ParticleOptionsControllerAdapterWeakPtr particleOptionstControllerAdapterWeak_;

    QVBoxLayout* widgetLayout_ = nullptr;
    QGroupBox* mainBox_ = nullptr;
    QVBoxLayout* mainVerticalLayout_ = nullptr;

    QLineEdit* weightLineEdit_ = nullptr;
    QLabel* weightLabel_ = nullptr;
    QVBoxLayout* weightLayout_ = nullptr;

    QLineEdit* chargeLineEdit_ = nullptr;
    QLabel* chargeLabel_ = nullptr;
    QVBoxLayout* chargeLayout_ = nullptr;

    QPushButton* applyChangesButton_ = nullptr;
};

} // namespace phywidgets

#endif // PHYPARTICLEOPTIONSCONTROLLERWIDGET_H
