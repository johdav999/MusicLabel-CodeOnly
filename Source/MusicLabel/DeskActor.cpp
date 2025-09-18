#include "DeskActor.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "InputCoreTypes.h"

#define LOCTEXT_NAMESPACE "DeskActor"

namespace
{
    constexpr float DefaultBoxExtent = 75.0f;
}

ADeskActor::ADeskActor()
{
    PrimaryActorTick.bCanEverTick = false;

    DeskMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DeskMesh"));
    SetRootComponent(DeskMesh);
    DeskMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    DeskMesh->SetGenerateOverlapEvents(false);

    InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
    InteractionBox->SetupAttachment(RootComponent);
    InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    InteractionBox->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    InteractionBox->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);
    InteractionBox->SetBoxExtent(FVector(DefaultBoxExtent));
    InteractionBox->SetHiddenInGame(true);
    InteractionBox->SetGenerateOverlapEvents(false);
    InteractionBox->SetCanEverAffectNavigation(false);

    InteractionBox->OnClicked.AddDynamic(this, &ADeskActor::HandleDeskClicked);
}

void ADeskActor::SetCompanyFunction(EDeskCompanyFunction NewFunction, FText NewCustomLabel)
{
    CompanyFunction = NewFunction;

    if (CompanyFunction == EDeskCompanyFunction::Custom)
    {
        CustomFunctionLabel = MoveTemp(NewCustomLabel);
    }
}

FText ADeskActor::GetCompanyFunctionLabel() const
{
    switch (CompanyFunction)
    {
    case EDeskCompanyFunction::Finance:
        return LOCTEXT("DeskFunctionFinance", "Finance");
    case EDeskCompanyFunction::Marketing:
        return LOCTEXT("DeskFunctionMarketing", "Marketing");
    case EDeskCompanyFunction::StudioManagement:
        return LOCTEXT("DeskFunctionStudio", "Studio Management");
    case EDeskCompanyFunction::TourPlanning:
        return LOCTEXT("DeskFunctionTour", "Tour Planning");
    case EDeskCompanyFunction::ArtistRelations:
        return LOCTEXT("DeskFunctionArtistRelations", "Artist Relations");
    case EDeskCompanyFunction::HumanResources:
        return LOCTEXT("DeskFunctionHR", "Human Resources");
    case EDeskCompanyFunction::Custom:
        return !CustomFunctionLabel.IsEmpty() ? CustomFunctionLabel : LOCTEXT("DeskFunctionCustom", "Custom");
    default:
        break;
    }

    return FText::GetEmpty();
}

void ADeskActor::HandleDeskClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
    OnDeskClicked.Broadcast(this, CompanyFunction, GetCompanyFunctionLabel());
}

#if WITH_EDITOR
void ADeskActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    if (!PropertyChangedEvent.Property)
    {
        return;
    }

    const FName PropertyName = PropertyChangedEvent.Property->GetFName();
    if (PropertyName == GET_MEMBER_NAME_CHECKED(ADeskActor, CompanyFunction) && CompanyFunction != EDeskCompanyFunction::Custom)
    {
        CustomFunctionLabel = FText();
    }
}
#endif

#undef LOCTEXT_NAMESPACE

