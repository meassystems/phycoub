#ifndef PHYSCALARCONTROLLERWIDGETBASE_H
#define PHYSCALARCONTROLLERWIDGETBASE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "ValueControllerAdapterIface.h"
#include "PhyScalarPhyCoubControllerSubscriber.h"
#include "PhyCoubControllerSubscriberIface.h"

namespace phywidgets
{

template< typename ValueType >
class PhyScalarControllerWidgetBase : public QWidget
{
  public:
    explicit PhyScalarControllerWidgetBase( QWidget* parent = nullptr );
    virtual ~PhyScalarControllerWidgetBase();

    using ScalarTypeControllerAdapterWeakPtr
        = std::weak_ptr< ValueControllerAdapterIface< ValueType > >;

    void setScalarController(
        ScalarTypeControllerAdapterWeakPtr scalarControllerAdapterWeak );
    void setScalarValueLabel( const QString& scalarValueLabel );

    PhyCoubControllerSubscriberWeakPtr getPhyCoubControllerSubscriber();

  protected:
    friend class PhyScalarPhyCoubControllerSubscriber< ValueType >;

    QLineEdit* getValueEdit();
    QPushButton* getSetValueButton();
    ScalarTypeControllerAdapterWeakPtr getScalarControllerAdapter();

    QPushButton* setScalarValueButton_ = nullptr;

  private:
    void configureScalarVaule();

    ScalarTypeControllerAdapterWeakPtr scalarConrollerAdapterWeak_;
    PhyScalarPhyCoubControllerSubscriberPtr< ValueType > controllerSubscriber_ = nullptr;

    QHBoxLayout* scalarLayout_ = nullptr;
    QVBoxLayout* scalarEditLayout_ = nullptr;
    QLabel* scalarLabel_ = nullptr;
    QLineEdit* scalarValueEdit_ = nullptr;
};

template< typename ValueType >
PhyScalarControllerWidgetBase< ValueType >::PhyScalarControllerWidgetBase(
    QWidget* parent )
    : QWidget( parent )
    , scalarLayout_( new QHBoxLayout( this ) )
    , scalarEditLayout_( new QVBoxLayout( this ) )
    , scalarLabel_( new QLabel( this ) )
    , scalarValueEdit_( new QLineEdit( this ) )
    , setScalarValueButton_( new QPushButton( this ) )
    , controllerSubscriber_(
          std::make_shared< PhyScalarPhyCoubControllerSubscriber< ValueType > >( this ) )
{
    configureScalarVaule();
    setLayout( scalarLayout_ );
}

template< typename ValueType >
PhyScalarControllerWidgetBase< ValueType >::~PhyScalarControllerWidgetBase()
{
    controllerSubscriber_->release();
}

template< typename ValueType >
void PhyScalarControllerWidgetBase< ValueType >::setScalarController(
    ScalarTypeControllerAdapterWeakPtr scalarConrollerAdapterWeak )
{
    scalarConrollerAdapterWeak_ = scalarConrollerAdapterWeak;
    if ( auto scalarConrollerAdapter = scalarConrollerAdapterWeak_.lock() )
    {
        scalarValueEdit_->setText(
            QString::number( scalarConrollerAdapter->getValue() ) );
    }
}

template< typename ValueType >
void PhyScalarControllerWidgetBase< ValueType >::setScalarValueLabel(
    const QString& scalarValueLabel )
{
    scalarLabel_->setText( scalarValueLabel );
}

template< typename ValueType >
PhyCoubControllerSubscriberWeakPtr
PhyScalarControllerWidgetBase< ValueType >::getPhyCoubControllerSubscriber()
{
    return controllerSubscriber_;
}

template< typename ValueType >
QLineEdit* PhyScalarControllerWidgetBase< ValueType >::getValueEdit()
{
    return scalarValueEdit_;
}

template< typename ValueType >
QPushButton* PhyScalarControllerWidgetBase< ValueType >::getSetValueButton()
{
    return setScalarValueButton_;
}

template< typename ValueType >
typename PhyScalarControllerWidgetBase< ValueType >::ScalarTypeControllerAdapterWeakPtr
PhyScalarControllerWidgetBase< ValueType >::getScalarControllerAdapter()
{
    return scalarConrollerAdapterWeak_;
}

template< typename ValueType >
void PhyScalarControllerWidgetBase< ValueType >::configureScalarVaule()
{
    scalarLayout_->addLayout( scalarEditLayout_ );
    scalarLayout_->addWidget( setScalarValueButton_ );

    scalarEditLayout_->addWidget( scalarLabel_ );
    scalarEditLayout_->addWidget( scalarValueEdit_ );

    setScalarValueButton_->setText( "Установить" );
}

} // namespace phywidgets

#endif // PHYSCALARCONTROLLERWIDGETBASE_H
