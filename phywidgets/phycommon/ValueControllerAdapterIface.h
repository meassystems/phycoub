#ifndef SCALARVALUECONTROLLERADAPTERIFACE_H
#define SCALARVALUECONTROLLERADAPTERIFACE_H

#include <memory>

#include "Vector.h"
#include "ParticleOptions.h"

namespace phywidgets
{

template< typename ValueType >
class ValueControllerAdapterIface
{
  public:
    virtual ~ValueControllerAdapterIface() = default;

    virtual ValueType getValue() const = 0;
    virtual void setValue( ValueType value ) = 0;
};

using BoolControllerAdapterWeakPtr = std::weak_ptr< ValueControllerAdapterIface< bool > >;

using DoubleControllerAdapterWeakPtr
    = std::weak_ptr< ValueControllerAdapterIface< double > >;

using LongControllerAdapterWeakPtr = std::weak_ptr< ValueControllerAdapterIface< long > >;

using VectorControllerAdapterWeakPtr
    = std::weak_ptr< ValueControllerAdapterIface< phycoub::Vector > >;

using ParticleOptionsControllerAdapterWeakPtr
    = std::weak_ptr< ValueControllerAdapterIface< phycoub::ParticleOptions > >;

template< typename ValueType, typename Type, ValueType ( Type::*getValueMethod )() const,
    void ( Type::*setValueMethod )( ValueType ) >
class ValueControllerAdapter : public ValueControllerAdapterIface< ValueType >
{
  public:
    using TypePtr = std::shared_ptr< Type >;

    ValueControllerAdapter( TypePtr coub );
    virtual ~ValueControllerAdapter() override = default;

    // Implementation of ScalarValueControllerAdapterIface
    virtual ValueType getValue() const override;
    virtual void setValue( ValueType value ) override;

  private:
    TypePtr coub_ = nullptr;
};

template< typename ValueType, typename Type, ValueType ( Type::*getValueMethod )() const,
    void ( Type::*setValueMethod )( ValueType ) >
ValueControllerAdapter< ValueType, Type, getValueMethod,
    setValueMethod >::ValueControllerAdapter( TypePtr coub )
    : coub_( coub )
{
}

// virtual override
template< typename ValueType, typename Type, ValueType ( Type::*getValueMethod )() const,
    void ( Type::*setValueMethod )( ValueType ) >
ValueType
ValueControllerAdapter< ValueType, Type, getValueMethod, setValueMethod >::getValue()
    const
{
    ValueType value{};
    if ( coub_ )
    {
        value = ( ( *coub_ ).*getValueMethod )();
    }
    return value;
}

// virtual override
template< typename ValueType, typename Type, ValueType ( Type::*getValueMethod )() const,
    void ( Type::*setValueMethod )( ValueType ) >
void ValueControllerAdapter< ValueType, Type, getValueMethod, setValueMethod >::setValue(
    ValueType value )
{
    if ( coub_ )
    {
        ( ( *coub_ ).*setValueMethod )( value );
    }
}

} // namespace phywidgets

#endif // SCALARVALUECONTROLLERADAPTERIFACE_H
