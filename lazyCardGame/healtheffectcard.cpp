#include "healtheffectcard.h"

HealthEffectCard::HealthEffectCard(int h): hearts_number(h)
{
    if(h<=0)
        throw std::domain_error("HealtEffectCard::HealthEffectCard(int): parameter int must be >= 0");
};

HealthEffectCard::~HealthEffectCard()= default;

int HealthEffectCard::getHeartsNumber() const
{
    return hearts_number;
};

bool HealthEffectCard::operator==(const Card& c) const
{
    return Card::operator==(c) && static_cast<const HealthEffectCard&>(c).getHeartsNumber()==getHeartsNumber();
};

bool HealthEffectCard::operator!=(const Card& c) const
{
    return Card::operator!=(c) && static_cast<const HealthEffectCard&>(c).getHeartsNumber()!=getHeartsNumber();
};
