#include "Identity/BloodstreamEntityId.h"

FBloodstreamEntityId FBloodstreamEntityId::NewId()
{
    return FBloodstreamEntityId(FGuid::NewGuid());
}

bool FBloodstreamEntityId::TryParse(const FString& Text, FBloodstreamEntityId& OutId)
{
    FGuid Parsed;
    if (!FGuid::Parse(Text, Parsed))
    {
        return false;
    }

    OutId = FBloodstreamEntityId(Parsed);
    return true;
}

FString FBloodstreamEntityId::ToString() const
{
    return Value.ToString(EGuidFormats::DigitsWithHyphensLower);
}

bool FBloodstreamEntityId::Serialize(FArchive& Archive)
{
    Archive << Value;
    return true;
}
