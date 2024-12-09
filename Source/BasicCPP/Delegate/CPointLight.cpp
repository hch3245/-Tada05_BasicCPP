#include "CPointLight.h"
#include "Components/PointLightComponent.h"

ACPointLight::ACPointLight()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;

	LightComp1 = CreateDefaultSubobject<UPointLightComponent>("LightComp1");
	LightComp1->SetupAttachment(RootComp);
	LightComp1->SetIntensity(1e+4f);
	LightComp1->SetAttenuationRadius(200.f);
	LightComp1->SetLightColor(FLinearColor(1.f, 0.5f, 0.f));

	LightComp2 = CreateDefaultSubobject<UPointLightComponent>("LightComp2");
	LightComp2->SetupAttachment(RootComp);
	LightComp2->SetIntensity(1e+4f);
	LightComp2->SetAttenuationRadius(200.f);
	LightComp2->SetLightColor(FLinearColor(1.f, 0.5f, 0.f));
	LightComp2->SetRelativeLocation(FVector(0, 200, 0));

}

void ACPointLight::BeginPlay()
{
	Super::BeginPlay();
	
	//Todo. Binding
}

void ACPointLight::OnLights()
{
}

void ACPointLight::OffLights()
{
}
