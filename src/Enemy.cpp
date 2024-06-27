#include "Enemy.h"

Enemy::Enemy()
    :m_isPlayed(false)
{
}

bool Enemy::getIsPlayed()
{
    return m_isPlayed;
}

bool Enemy::setIsPlayed(bool state)
{
    m_isPlayed = state;
    return m_isPlayed;
}
