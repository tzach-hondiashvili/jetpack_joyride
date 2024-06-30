#include "Enemy.h"

Enemy::Enemy()
    :m_isLaunchPlayed(false), m_isWarningPlayed(false), m_passedTheScreen(false)
{
}

bool Enemy::getIsWarningPlayed()
{
    return m_isWarningPlayed;
}

bool Enemy::getPassedTheScreenPlayed()
{
    return m_passedTheScreen;
}

bool Enemy::setPassedTheScreen(bool state)
{
    m_passedTheScreen = state;
    return m_passedTheScreen;
}


bool Enemy::setIsWarningPlayed(bool state)
{
    m_isWarningPlayed = state;
    return m_isLaunchPlayed;
}

bool Enemy::getIsLaunchPlayed()
{
    return m_isLaunchPlayed;
}

bool Enemy::setIsLaunchPlayed(bool state)
{
    m_isLaunchPlayed = state;
    return m_isLaunchPlayed;
}
