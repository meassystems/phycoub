#include "GLRotationController.h"

namespace phywidgets
{

void GLRotationController::updateRotationX( int angle )
{
    normalizeAngle( &angle );
    if ( angle != xRot_ )
    {
        xRot_ = angle;
        notifySubscribers();
    }
}

void GLRotationController::updateRotationY( int angle )
{
    normalizeAngle( &angle );
    if ( angle != yRot_ )
    {
        yRot_ = angle;
        notifySubscribers();
    }
}

void GLRotationController::updateRotationZ( int angle )
{
    normalizeAngle( &angle );
    if ( angle != zRot_ )
    {
        zRot_ = angle;
        notifySubscribers();
    }
}

void GLRotationController::subscribeForUpdates( GLRotationPtr glSubscriber )
{
    glSubscribers_.push_back( glSubscriber );
}

void GLRotationController::notifySubscribers()
{
    for ( auto glSubscriberWeak : glSubscribers_ )
    {
        if ( auto glSubscriber = glSubscriberWeak.lock() )
        {
            glSubscriber->updateGlRotation( xRot_, yRot_, zRot_ );
        }
    }
}

// static
void GLRotationController::normalizeAngle( int* angle )
{
    while ( *angle < 0 )
    {
        *angle += 360 * 16;
    }
    while ( *angle > 360 * 16 )
    {
        *angle -= 360 * 16;
    }
}

} // namespace phywidgets
