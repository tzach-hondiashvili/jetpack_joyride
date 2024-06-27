#include "Enemy.h"

bool Enemy::getIsPlayed()
{
    return m_isPlayed;
}

bool Enemy::setIsPlayed(bool state)
{
    m_isPlayed = state;
    return m_isPlayed;
}
